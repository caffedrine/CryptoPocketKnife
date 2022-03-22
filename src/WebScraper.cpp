#include "WebScraper.h"

bool WebScraper::EnqueueGetRequest(QString uniqueEequestId, QString requestUrl)
{
    // Check if openssl is supported
    static bool sslWarningOnce = true;
    if( !QSslSocket::supportsSsl() && sslWarningOnce )
    {
        sslWarningOnce = false;
        qDebug() << QString("[ERROR] Couldn't load SSL (" + QSslSocket::sslLibraryBuildVersionString() + QSslSocket::sslLibraryVersionString() + ") for this action");
    }

    this->Task(uniqueEequestId, requestUrl);
    return true;
}

HttpResponse WebScraper::HttpGet(QString url_str, QString AdditionalHeaders)
{
    HttpResponse response;
    QNetworkAccessManager manager;
    QUrl url (url_str);
    QNetworkRequest request(url);
    QNetworkReply *reply = manager.get(request);
    QEventLoop eventLoop;
    QObject::connect(reply, SIGNAL(finished()), &eventLoop, SLOT(quit()));
    eventLoop.exec();

    QVariant statusCode = reply->attribute( QNetworkRequest::HttpStatusCodeAttribute );
    if( statusCode.isValid() )
    {
        response.Code = statusCode.toInt();
        response.CodeDesc = reply->attribute( QNetworkRequest::HttpReasonPhraseAttribute ).toString();
        response.Headers = "";
        foreach(QByteArray head, reply->rawHeaderList())
        {
            response.Headers += QString(head) + ": " + reply->rawHeader(head) + "\n";
        }
        response.Body = QString(reply->readAll());
        response.HostIp = "";
    }
    else
    {
        response.NetworkErrorDetected = true;
        response.errorDescription = reply->errorString();
    }
    return response;
}

void WebScraper::Task(QString uniqueRequestId, QString requestUrl)
{
   emit OnRequestStarted(uniqueRequestId, requestUrl);
   HttpResponse response = WebScraper::HttpGet(requestUrl);

   if( response.NetworkErrorDetected )
   {
       emit OnRequestError(uniqueRequestId, requestUrl, response.errorDescription);
   }
   else
   {
       emit OnRequestFinished(uniqueRequestId, requestUrl, response);
   }
}
