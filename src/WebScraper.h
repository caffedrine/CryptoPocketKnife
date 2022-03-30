#ifndef WEBSCRAPER_H
#define WEBSCRAPER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QTimer>
#include <QNetworkReply>
#include <QtGlobal>
#include <QSslSocket>
#include <QHostInfo>
#include <QRunnable>
#include <QThread>

#include "Singleton.h"
#include "HttpStatusCodes.h"
#include "AdvancedTableWidget.h"

class HttpResponse
{
public:
    bool NetworkErrorDetected = false;
    QString errorDescription = "";

    qint16 Code;
    QString CodeDesc;
    bool Redirected = false;
    QString Headers;
    QString Body;
    QString HostIp;
};

class WebScraper: public QObject, public Singleton<WebScraper>
{
        Q_OBJECT
    public:
        bool EnqueueGetRequest(const QString &uniqueRequestId, const QString &requestUrl);
        static HttpResponse HttpGet(const QString &url, QMap<QString, QString> *AdditionalHeaders = nullptr);

    private slots:

    signals:
        void OnRequestStarted(const QString &requestId, const QString &requestUrl);
        void OnRequestError(const QString &requestId, const QString &requestUrl, const HttpResponse &response);
        void OnRequestFinished(const QString &requestId, const QString &requestUrl, const HttpResponse &response);

    private:
        void Task(QString uniqueRequestId, QString requestUrl);

};

class WebScraperJob : public QRunnable
{
public:

protected:
    void run() override
    {
    }
};

#endif // WEBSCRAPER_H
