#ifndef _RAWHTTPWEBREQUEST_H_
#define _RAWHTTPWEBREQUEST_H_

#include <QString>
#include <QByteArray>

namespace Services { namespace Web
{
    class RawHttpWebRequest
    {
    public:
        RawHttpWebRequest(QString host, quint16 port);

        QByteArray SendHttp(QByteArray rawHttpRequest);
        QByteArray SendHttps(QByteArray rawHttpRequest);

    private:
        QString host;
        quint16 port;

    signals:
        void RequestFinished(const QByteArray &rawHttpRequest, const QByteArray &response) const;
        void RequestReturnedError(const QString &errorDescription) const;
    };
}} // namespaces

#endif //_RAWHTTPWEBREQUEST_H_
