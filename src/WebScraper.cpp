#include "WebScraper.h"

#include <QFuture>
#include <QtConcurrent>

bool WebScraper::EnqueueGetRequest(const QString &uniqueRequestId, const QString &requestUrl)
{
    // Check if openssl is supported
    static bool sslWarningOnce = true;
    if( !QSslSocket::supportsSsl() && sslWarningOnce )
    {
        sslWarningOnce = false;
        qDebug() << QString("[ERROR] Couldn't load SSL (" + QSslSocket::sslLibraryBuildVersionString() + QSslSocket::sslLibraryVersionString() + ") for this action");
    }

    // Add record to queue to be execute by the threads pool

    this->Task(uniqueRequestId, requestUrl);
    return true;
}

HttpResponse WebScraper::HttpGet(const QString &url_str, QMap<QString, QString> *AdditionalHeaders)
{
    HttpResponse response;
    QNetworkAccessManager manager;

    QUrl url(url_str);
    QNetworkRequest request(url);
    request.setAttribute(QNetworkRequest::RedirectPolicyAttribute, true);

    QNetworkReply *reply = manager.get(request);
    reply->ignoreSslErrors();

    // Wait for the response
    QEventLoop eventLoop;
    QObject::connect(reply, SIGNAL(finished()), &eventLoop, SLOT(quit()));
    eventLoop.exec();

    // Fetch host IP
    response.HostIp = "";
    foreach(QHostAddress address, QHostInfo::fromName(url.host()).addresses())
    {
        response.HostIp += address.toString() + ", ";
    }
    if( response.HostIp.endsWith(", ") )
    {
        response.HostIp.chop(2);
    }

    QVariant statusCode = reply->attribute( QNetworkRequest::HttpStatusCodeAttribute );

    if( reply->error() && !statusCode.isValid() )
    {
        response.NetworkErrorDetected = true;
        response.errorDescription = "ERR " + QString::number(reply->error()) + ": " + reply->errorString();
        return response;
    }

    response.Code = (qint16)statusCode.toInt();
    response.CodeDesc = ((!statusCode.isValid())?("Invalid HTTP code"):(reply->attribute( QNetworkRequest::HttpReasonPhraseAttribute ).toString()));
    if( response.CodeDesc.isEmpty() )
        response.CodeDesc = HttpStatus::reasonPhrase(response.Code);

    response.Headers = "";
    foreach(QByteArray head, reply->rawHeaderList())
    {
        response.Headers += QString(head) + ": " + reply->rawHeader(head) + "\n";
    }
    response.Body = QString(reply->readAll());

    return response;
}

void WebScraper::Task(QString uniqueRequestId, QString requestUrl)
{
   emit OnRequestStarted(uniqueRequestId, requestUrl);
   HttpResponse response = WebScraper::HttpGet(requestUrl);

   if( response.NetworkErrorDetected )
   {
       emit OnRequestError(uniqueRequestId, requestUrl, response);
   }
   else
   {
       emit OnRequestFinished(uniqueRequestId, requestUrl, response);
   }
}
