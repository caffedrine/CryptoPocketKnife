#include "RawHttpWebRequest.h"

#include <QSslSocket>

namespace Services { namespace Web
{

    Services::Web::RawHttpWebRequest::RawHttpWebRequest(QString host, quint16 port) : host(host), port(port)
    {

    }

    QByteArray RawHttpWebRequest::SendHttps(QByteArray rawHttpRequest)
    {
        QSslSocket socket;
        socket.connectToHostEncrypted(host, port);
        if(!socket.waitForEncrypted(30000))
        {
            return QByteArray();
        }

        socket.write(rawHttpRequest);
        socket.waitForReadyRead();
        return socket.readAll();
    }

    QByteArray RawHttpWebRequest::SendHttp(QByteArray rawHttpRequest)
    {
        QTcpSocket socket;

        socket.connectToHost(host, port);
        if(!socket.waitForConnected(30000))
        {
            return QByteArray();
        }

        socket.write(rawHttpRequest);
        socket.waitForReadyRead();
        return socket.readAll();
    }
}}; //namespaces
