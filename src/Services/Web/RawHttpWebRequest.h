#ifndef _RAWHTTPWEBREQUEST_H_
#define _RAWHTTPWEBREQUEST_H_

#include <QString>
#include <QByteArray>
#include <QSslSocket>
#include <QTimer>
#include "RawHttpResponseParser.h"

namespace Services { namespace Web
{
    class RawHttpWebRequest: public QObject
    {
        enum state
        {
            WAIT_CONNECT,
            WAIT_WRITE,
            WAIT_READ
        };

        Q_OBJECT
    public:
        RawHttpWebRequest(QString host, quint16 port);
        ~RawHttpWebRequest();

        void SendHttp(const QByteArray &rawHttpRequest);
        void SendHttps(const QByteArray &rawHttpRequest);

        void setConnectTimeoutMs(quint32 ms) { this->ConnectTimeout = ms;};
        void setReadTimeoutMs(quint32 ms) { this->ReadTimeout = ms; };
        void setMaxRetries(quint16 retries) { this->ConnectMaxRetries = retries; };

    private:
        QString targetHost;
        quint16 targetPort;
        quint32 ConnectTimeout = 10000, ReadTimeout = 5000;
        quint16 ConnectMaxRetries = 0;
        QSslSocket *sslSocket = nullptr;
        QTcpSocket *tcpSocket = nullptr;
        QTimer socketTimer;
        Services::Parsers::RawHttpResponseParser currResponse;
        bool ErrorOccurred;

    signals:
        void RequestFinished(QTcpSocket *socket, const QByteArray &rawHttpRequest, const Services::Parsers::RawHttpResponseParser &response) const;
        void RequestReturnedError(QTcpSocket *socket, const QByteArray &rawHttpRequest, const QString &errorDescription, const Services::Parsers::RawHttpResponseParser &response) const;

    private slots:
        void ConnectedToHost(QTcpSocket *socket, const QByteArray &rawHttpRequestToBeSend);
    };
}} // namespaces

#endif //_RAWHTTPWEBREQUEST_H_
