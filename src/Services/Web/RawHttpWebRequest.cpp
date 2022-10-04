#include "RawHttpWebRequest.h"

namespace Services { namespace Web
{
    RawHttpWebRequest::RawHttpWebRequest(QString host, quint16 port) : targetHost(host), targetPort(port)
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
        this->currResponse.clear();

        // Connect TCP error signal
        QObject::connect(socket, &QSslSocket::errorOccurred, [this, socket, rawHttpRequest](const QAbstractSocket::SocketError error){
            qDebug().nospace().noquote() << "Error connecting to host " << socket->peerAddress().toString() << ":" << socket->peerPort() << " - error " + QString::number(error) + " - " + socket->errorString();
            emit this->RequestReturnedError(socket, rawHttpRequest, "error " + QString::number(error) + " - " + socket->errorString(), this->currResponse);
            socket->deleteLater();
        });

        // Connect TLS handshake error signal
        QObject::connect(socket, &QSslSocket::handshakeInterruptedOnError, [this, socket, rawHttpRequest](const QSslError error){
            qDebug().nospace().noquote() << "TLS error while connecting to host " << socket->peerAddress().toString() << ":" << socket->peerPort() << " - " << error.errorString();
            emit this->RequestReturnedError(socket, rawHttpRequest, error.errorString(), this->currResponse);
            socket->deleteLater();
        });

        // Connect signal when connection was established
        QObject::connect(socket, &QSslSocket::connected, [this, socket, rawHttpRequest](){
            qDebug().nospace().noquote() << "Connected to host " << socket->peerAddress().toString() << ":" << socket->peerPort();
            this->ConnectedToHost(socket, rawHttpRequest );
        });

        // Connect signal when connection was ended
        QObject::connect(socket, &QSslSocket::disconnected, [this, socket, rawHttpRequest](){
            qDebug().nospace().noquote() << "Disconnected from host " << socket->peerAddress().toString() << ":" << socket->peerPort();

            emit this->RequestFinished(socket, rawHttpRequest, this->currResponse);
            this->currResponse.clear();

            //this->socketTimer.blockSignals(true);
            //this->socketTimer.stop();
        });

        // Connect signal when bytes were written
        QObject::connect(socket, &QSslSocket::bytesWritten, [this, socket, rawHttpRequest](quint64 bytes){
//            static qint64 WrittenSoFar = 0;
//            WrittenSoFar += bytes;

            qDebug() << "bytes written: " << bytes;
        });

        // Connect signal to show the received response
        QObject::connect(socket, &QSslSocket::readyRead, [this, socket, rawHttpRequest](){
            QObject::disconnect(socket, &QSslSocket::errorOccurred, 0, 0); // disable this as it will be triggered by TLS disconnected
            qDebug().nospace().noquote() << "bytes available to read " << socket->bytesAvailable();

            this->currResponse.addData( socket->readAll() );
        });

        // Configure timeout timer
        this->socketTimer.blockSignals(false);
        //this->socketTimer.

        // Trigger connection
        socket->connectToHostEncrypted(this->targetHost, this->targetPort);
    }

    void RawHttpWebRequest::SendHttp(const QByteArray &rawHttpRequest)
    {
        QTcpSocket socket;
        this->currResponse.clear();

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
