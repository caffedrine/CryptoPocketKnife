#include "RawHttpWebRequest.h"

namespace Services { namespace Web {

RawHttpWebRequest::RawHttpWebRequest(QString host, quint16 port) : targetHost(host), targetPort(port)
{
    this->Log("Start");
    this->Log("Create HTTP request handler for " + host + ":" + QString::number(port));
}

RawHttpWebRequest::~RawHttpWebRequest()
{
    delete this->tcpSocket;
}

void RawHttpWebRequest::InitTcpSocket()
{
    if( this->tcpSocket == nullptr )
    {
        qCritical().nospace().noquote() << "[HTTP WEB REQUEST] Tcp socket not created before initialization";
        return;
    }

    this->currResponse.clear();
    this->ErrorOccurred = false;

    // Host found
    QObject::connect(this->tcpSocket, &QTcpSocket::hostFound, this, &RawHttpWebRequest::Conn_HostFound, Qt::UniqueConnection);

    // Connect TCP error signal
    QObject::connect(this->tcpSocket, &QTcpSocket::errorOccurred, this, &RawHttpWebRequest::Conn_ErrorOccurred, Qt::UniqueConnection);

    // Connect signal when connection was established
    QObject::connect(this->tcpSocket, &QTcpSocket::connected, this, &RawHttpWebRequest::Conn_TcpConnected, Qt::UniqueConnection);

    // Connect signal when connection was ended
    QObject::connect(this->tcpSocket, &QTcpSocket::disconnected, this, &RawHttpWebRequest::Conn_TcpDisconnected, Qt::UniqueConnection);

    // Connect signal when bytes were written
    QObject::connect(this->tcpSocket, &QTcpSocket::bytesWritten,  this, &RawHttpWebRequest::Conn_BytesWritten, Qt::UniqueConnection);

    // Connect signal to show the received response
    QObject::connect(this->tcpSocket, &QTcpSocket::readyRead, this, &RawHttpWebRequest::Conn_ReadyRead, Qt::UniqueConnection);

}

void RawHttpWebRequest::SendHttps(const QByteArray &rawHttpRequest)
{
    this->tcpSocket = new QSslSocket();
    this->InitTcpSocket();
    this->currRequest.clear();
    this->currRequest.addData(rawHttpRequest);

    // Connect TLS handshake error signal
    QObject::connect((QSslSocket *)this->tcpSocket, &QSslSocket::handshakeInterruptedOnError, this, &RawHttpWebRequest::Conn_SslErrorOccurred, Qt::UniqueConnection);

    // Configure timeout timer
    this->socketTimer.blockSignals(false);

    // Trigger connection
    this->Log("Resolving host to IP address");
    ((QSslSocket *)this->tcpSocket)->connectToHostEncrypted(this->targetHost, this->targetPort);
}

void RawHttpWebRequest::SendHttp(const QByteArray &rawHttpRequest)
{
    this->tcpSocket = new QTcpSocket();
    this->InitTcpSocket();
    this->currRequest.clear();
    this->currRequest.addData(rawHttpRequest);

    // Configure timeout timer
    this->socketTimer.blockSignals(false);

    // Trigger connection
    this->Log("Resolving host to IP address");
    this->tcpSocket->connectToHost(this->targetHost, this->targetPort);
}

void RawHttpWebRequest::Conn_HostFound()
{
    this->Log(this->targetHost + ":" + QString::number(this->targetPort) + " successfully resolved to " + this->tcpSocket->peerAddress().toString() + ":" + QString::number(this->tcpSocket->peerPort()));
    this->Log("Connecting to host");
}

void RawHttpWebRequest::Conn_ErrorOccurred(const QAbstractSocket::SocketError error)
{
    this->ErrorOccurred = true;
    this->Log("Error connecting to host " + this->tcpSocket->peerAddress().toString() + ":" + QString::number(this->tcpSocket->peerPort())+ " - error " + QString::number(error) + " - " + this->tcpSocket->errorString());
    emit this->RequestReturnedError(this->tcpSocket, this->currRequest, "error " + QString::number(error) + " - " + this->tcpSocket->errorString(), this->currResponse);
    this->tcpSocket->deleteLater();
}

void RawHttpWebRequest::Conn_SslErrorOccurred(const QSslError error)
{
    this->ErrorOccurred = true;
    this->Log("TLS error while connecting to host " + this->tcpSocket->peerAddress().toString() + ":" + QString::number(this->tcpSocket->peerPort()) + " - " + error.errorString());
    emit this->RequestReturnedError(this->tcpSocket, this->currRequest, error.errorString(), this->currResponse);
    this->tcpSocket->deleteLater();
}

void RawHttpWebRequest::Conn_TcpConnected()
{
    this->Log("TCP Socket connected to host " + this->tcpSocket->peerAddress().toString() + ":" + QString::number(this->tcpSocket->peerPort()));
    this->Log("Writing " + QString::number(this->currRequest.GetRaw().count()) + " to remote host");
    this->tcpSocket->write(this->currRequest.GetRaw());
}

void RawHttpWebRequest::Conn_TcpDisconnected()
{
    this->Log("Disconnected from host " + this->tcpSocket->peerAddress().toString() + ":" + QString::number(this->tcpSocket->peerPort()));

    // If error occurred, response was already send
    if(!this->ErrorOccurred)
    {
        emit this->RequestFinished(this->tcpSocket, this->currRequest, this->currResponse);
    }
    this->currResponse.clear();

    this->Log("idle");

    //this->socketTimer.blockSignals(true);
    //this->socketTimer.stop();
}

void RawHttpWebRequest::Conn_BytesWritten(quint64 bytes)
{
    this->Log("Successfully written " + QString::number(bytes) + " bytes to remote host");
}

void RawHttpWebRequest::Conn_ReadyRead()
{
    QObject::disconnect(this->tcpSocket, &QSslSocket::errorOccurred, 0, 0); // disable this as it will be triggered by TLS disconnected
    this->Log("Reading " + QString::number(this->tcpSocket->bytesAvailable()) + " from remote host");

    this->currResponse.addData(this->tcpSocket->readAll());
}

void RawHttpWebRequest::Log(const QString &str)
{
    emit this->RequestStateChangeInfo(this->tcpSocket, this->currRequest, this->currResponse, str);
    qDebug().nospace().noquote() << "[HTTP WEB REQUEST] [" << this->targetHost << ":" << this->targetPort << "] " << str;
}

}} //namespaces