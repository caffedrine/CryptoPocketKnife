#ifndef WEBSCRAPER_H
#define WEBSCRAPER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QtGlobal>
#include <QSslSocket>
#include <QHostInfo>
#include <QThreadPool>
#include <utility>
#include <QWidgets/QAdvancedTableWidget/QAdvancedTableWidget.h>
#include <QHttp/HttpStatusCodes.h>
#include "utils/ThreadsPool.h"

#if !defined(DLL_DECL_SPEC)
#define DLL_DECL_SPEC
#endif

/* */
class DLL_DECL_SPEC HttpResponse
{
public:
    bool AppErrorDetected = false;
    QString AppErrorDesc = "";

    bool NetworkErrorDetected = false;
    QString NetworkErrorDescription = "";

    qint16 Code;
    QString CodeDesc;
    bool Redirected = false;
    QString Headers;
    QString Body;
    QString HostIp;
};
Q_DECLARE_METATYPE(HttpResponse)

/* */
class DLL_DECL_SPEC WebScraper: public QObject, public ThreadsPool
{
Q_OBJECT
public:
    WebScraper(int max_threads_count);
    ~WebScraper() = default;

    bool EnqueueGetRequest(const QString &uniqueRequestId, const QString &requestUrl);
    static HttpResponse HttpGet(const QString &url, QMap<QString, QString> *AdditionalHeaders = nullptr);

signals:
    void OnRequestStarted(QString requestId, QString requestUrl);
    void OnRequestError(QString requestId, QString requestUrl, HttpResponse response);
    void OnRequestFinished(QString requestId, QString requestUrl, HttpResponse response);
    void AvailableWorkersChanged(int availableWorkers, int activeWorkers);
private:
    void Task(const QString& uniqueRequestId, const QString& requestUrl);
};

#endif // WEBSCRAPER_H
