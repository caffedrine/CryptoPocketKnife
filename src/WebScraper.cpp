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

HttpResponse WebScraper::HttpGet(QString url_str, QMap<QString, QString> *AdditionalHeaders)
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

    if( reply->error() && reply->error() < 10)
    {
        response.NetworkErrorDetected = true;
        response.errorDescription = "ERR: " + QString::number(reply->error()) + ": " + reply->errorString();
        return response;
    }

    QVariant statusCode = reply->attribute( QNetworkRequest::HttpStatusCodeAttribute );
    response.Code = statusCode.toInt();
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
