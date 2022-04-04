#include "WebScraper.h"

#include <QFuture>
#include <QtConcurrent>

void WebScraper::OnContructorCalled()
{
    this->ThreadsPoolPtr()->setMaxThreadCount(WebScraper::MAX_THREADS);
}

bool WebScraper::EnqueueGetRequest(const QString &uniqueRequestId, const QString &requestUrl)
{
    // Check if openssl is supported
    static bool sslWarningOnce = true;
    if( !QSslSocket::supportsSsl() && sslWarningOnce )
    {
        sslWarningOnce = false;
        qDebug() << QString("[ERROR] Couldn't load SSL (" + QSslSocket::sslLibraryBuildVersionString() + QSslSocket::sslLibraryVersionString() + ") for this action");
    }

    // Set maximum number of workers
    this->ThreadsPoolPtr()->setMaxThreadCount(WebScraper::MAX_THREADS);

    // Add record to queue to be executed by the threads in pool
    auto lam = [this, uniqueRequestId, requestUrl]()
    {
        emit(this->AvailableWorkersChanged(this->ThreadsPoolPtr()->AvailableThreads(), this->ThreadsPoolPtr()->ActiveThreads())); // substract current worker which will be disposed
        this->Task(uniqueRequestId, requestUrl);
        emit(this->AvailableWorkersChanged(this->ThreadsPoolPtr()->AvailableThreads(), this->ThreadsPoolPtr()->ActiveThreads() - 1)); // substract current worker which will be disposed
    };

    if(!this->ThreadsPoolPtr()->tryStart(lam))
    {
        HttpResponse response;
        response.AppErrorDetected = true;
        response.AppErrorDesc = "No threads available";

        emit this->OnRequestError(uniqueRequestId, requestUrl, response);
        return false;
    }
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
        response.NetworkErrorDescription = "ERR " + QString::number(reply->error()) + ": " + reply->errorString();
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

void WebScraper::Task(const QString& uniqueRequestId, const QString& requestUrl)
{
   emit this->OnRequestStarted(uniqueRequestId, requestUrl);
   HttpResponse response = WebScraper::HttpGet(requestUrl);

   if( response.NetworkErrorDetected || response.AppErrorDetected )
   {
       emit this->OnRequestError(uniqueRequestId, requestUrl, response);
   }
   else
   {
       emit this->OnRequestFinished(uniqueRequestId, requestUrl, response);
   }
}
