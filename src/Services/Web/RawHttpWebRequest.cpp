#include "RawHttpWebRequest.h"

namespace Services { namespace Web
{
    RawHttpWebRequest::RawHttpWebRequest(QString host, quint16 port) : host(host), port(port)
    {

    }

    RawHttpWebRequest::~RawHttpWebRequest()
    {
        delete this->tcpSocket;
        delete this->sslSocket;
    }

    void RawHttpWebRequest::SendHttps(const QByteArray &rawHttpRequest)
    {
        QSslSocket *socket = new QSslSocket();

        // Connect TCP error signal
        QObject::connect(this->sslSocket, &QSslSocket::errorOccurred, [this, socket](const QAbstractSocket::SocketError error){
            qDebug().nospace().noquote() << "Error connecting to host " << socket->peerAddress() << ":" << socket->peerPort() << " - error " + QString::number(error) + " - " + socket->errorString();
            emit this->RequestReturnedError( "error " + QString::number(error) + " - " + socket->errorString() );
            socket->deleteLater();
        });

        // Connect TLS handshake error signal
        QObject::connect(this->sslSocket, &QSslSocket::handshakeInterruptedOnError, [this, socket](const QSslError error){
            qDebug().nospace().noquote() << "TLS error while connecting to host " << socket->peerAddress() << ":" << socket->peerPort() << " - " << error.errorString();
            emit this->RequestReturnedError( error.errorString());
            socket->deleteLater();
        });

        // Connect signal when connection was established
        QObject::connect(this->sslSocket, &QSslSocket::connected, [this, socket, &rawHttpRequest](){
            qDebug().nospace().noquote() << "Connected to host " << socket->peerAddress() << ":" << socket->peerPort();
            this->ConnectedToHost(socket, rawHttpRequest );
        });

        // Connect signal when bytes were written
        QObject::connect(this->sslSocket, &QSslSocket::bytesWritten, [this, socket, &rawHttpRequest](quint64 bytes){
            qDebug() << "bytes written: " << bytes;
        });

        // Connect signal to show the received response
        QObject::connect(this->sslSocket, &QSslSocket::readyRead, [this, socket, &rawHttpRequest](){
            qDebug() << "received: " << socket->bytesAvailable();
            emit this->RequestFinished(socket, rawHttpRequest, socket->readAll());
        });

        // Trigger connection
        socket->connectToHostEncrypted(this->host, this->port);
    }

    void RawHttpWebRequest::SendHttp(const QByteArray &rawHttpRequest)
    {
        QTcpSocket socket;

//        socket.connectToHost(this->host, this->port);
//        if(!socket.waitForConnected(30000))
//        {
//            return QByteArray();
//        }
//
//        socket.write(rawHttpRequest);
//        socket.waitForReadyRead();
//        socket.deleteLater();
//        return socket.readAll();
    }

    void RawHttpWebRequest::ConnectedToHost(QTcpSocket *socket, const QByteArray &rawHttpRequestToBeSend)
    {
        socket->write(rawHttpRequestToBeSend);
    }
}}; //namespaces
