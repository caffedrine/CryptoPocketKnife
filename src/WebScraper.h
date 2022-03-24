#ifndef WEBSCRAPER_H
#define WEBSCRAPER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QTimer>
#include <QNetworkReply>
#include <QtGlobal>
#include <QSslSocket>
#include <QHostInfo>

#include "Singleton.h"
#include "HttpStatusCodes.h"
#include "AdvancedTableWidget.h"

class HttpResponse
{
    public:
        HttpResponse() = default;
        ~HttpResponse() = default;

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
        bool EnqueueGetRequest(QString uniqueRequestId, QString requestUrl);
        static HttpResponse HttpGet(QString url, QMap<QString, QString> *AdditionalHeaders = nullptr);

    private slots:

    signals:
        void OnRequestStarted(QString requestId, QString requestUrl);
        void OnRequestError(QString requestId, QString requestUrl, HttpResponse response);
        void OnRequestFinished(QString requestId, QString requestUrl, HttpResponse response);

    private:
        void Task(QString uniqueRequestId, QString requestUrl);

};

#endif // WEBSCRAPER_H
