#ifndef WEBSCRAPER_H
#define WEBSCRAPER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QTimer>
#include <QNetworkReply>
#include <QtGlobal>
#include <QSslSocket>
#include <QHostInfo>
#include <QThreadPool>
#include <utility>

#include "Singleton.h"
#include "HttpStatusCodes.h"
#include "AdvancedTableWidget.h"

/* */
class HttpResponse
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

/* */
class WebScraper : public QObject, public Singleton<WebScraper>
{
Q_OBJECT
public:
    static const int MAX_THREADS = 20;

    int AvailableWorkers();
    int ActiveWorkers();
    bool EnqueueGetRequest(const QString &uniqueRequestId, const QString &requestUrl);
    static HttpResponse HttpGet(const QString &url, QMap<QString, QString> *AdditionalHeaders = nullptr);
signals:
    void OnRequestStarted(const QString &requestId, const QString &requestUrl);
    void OnRequestError(const QString &requestId, const QString &requestUrl, const HttpResponse &response);
    void OnRequestFinished(const QString &requestId, const QString &requestUrl, const HttpResponse &response);
    void AvailableWorkersChanged(int availableWorkers, int activeWorkers);
private:
    QThreadPool *threadsPool = nullptr;

    void OnContructorCalled() override;
    void Task(const QString& uniqueRequestId, const QString& requestUrl);
};
#endif // WEBSCRAPER_H
