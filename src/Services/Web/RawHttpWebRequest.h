#ifndef _RAWHTTPWEBREQUEST_H_
#define _RAWHTTPWEBREQUEST_H_

#include <QString>
#include <QByteArray>
#include <QSslSocket>

namespace Services { namespace Web
{
    class RawHttpWebRequest: public QObject
    {
        Q_OBJECT
    public:
        RawHttpWebRequest(QString host, quint16 port);
        ~RawHttpWebRequest();

        void SendHttp(const QByteArray &rawHttpRequest);
        void SendHttps(const QByteArray &rawHttpRequest);

    private:
        QString host;
        quint16 port;
        QSslSocket *sslSocket = nullptr;
        QTcpSocket *tcpSocket = nullptr;

    signals:
        void RequestFinished(QTcpSocket *socket, const QByteArray &rawHttpRequest, const QByteArray &response) const;
        void RequestReturnedError(QTcpSocket *socket, const QByteArray &rawHttpRequest, const QString &errorDescription) const;

    private slots:
        void ConnectedToHost(QTcpSocket *socket, const QByteArray &rawHttpRequestToBeSend);
    };
}} // namespaces

#endif //_RAWHTTPWEBREQUEST_H_
