/*  
 *  File      : Web.h
 *  Created on: 2022-03-29
 *      Author: uib74520
 */

#ifndef CRYPTOPOCKETKNIFE_WEB_H
#define CRYPTOPOCKETKNIFE_WEB_H

#include <QWidget>
#include <QAction>
#include <QMenu>
#include <QMessageBox>
#include <QPlainTextEdit>
#include <QtConcurrent>
#include <QFuture>

#include "GeoIP.h"
#include "WebScraper.h"
#include "utils.h"
#include "LambdaEventFilter.h"
#include "AdvancedTableWidget.h"

using namespace Services::GeoIP;

QT_BEGIN_NAMESPACE
namespace Ui
{
    class Web;
}
QT_END_NAMESPACE

class Web : public QWidget
{
Q_OBJECT

public:
    explicit Web(QWidget *parent = nullptr);
    ~Web() override;
    void setCurrentIndex(int index) {};

private slots:
    QString WebScraper_getFullUrlFromTable(int row);
    void tableWidget_WebScraper_OnDoubleClickWithoutSelection();
    void tableWidget_WebScraper_OnRowsCopy(const QModelIndexList& selectedRows);
    void tableWidget_WebScraper_OnTextPasted(const QString& text);
    void tableWidget_WebScraper_OnRowsInserted(const QModelIndex &parent, int first, int last);
    void tableWidget_WebScraper_OnRowsAboutToBeDeleted(const QModelIndex &parent, int first, int last);
    void tableWidget_WebScraper_OnRowsDeleted(const QModelIndex &parent, int first, int last);
    void on_tableWidget_WebScraper_customContextMenuRequested(const QPoint &pos);
    void on_pushButton_WebScraping_Clear_clicked();
    void on_pushButton_WebScraper_StopDownload_clicked();
    void on_pushButton_WebScraper_StartDownload_clicked();
    void webScraper_OnRequestStarted(const QString &requestId, const QString &requestUrl);
    void webScraper_OnRequestError(const QString &requestId, const QString &requestUrl, const HttpResponse &response);
    void webScraper_OnRequestFinished(const QString &requestId, const QString &requestUrl, const HttpResponse &response);
    void webScraper_OnAvailableWorkersChanged(int availableWorkers, int activeWorkers);
    void on_pushButton_WebScraping_StretchCols_clicked();

private:
    Ui::Web *ui;

    WebScraper *WebScrapperEngine = nullptr;
    bool CancelRequests = false;
    QMap<QString, QString> WebScraperResponseHeaders;
    QMap<QString, QString> WebScraperResponseData;

    void webScrapper_InitEngine();
};


#endif //CRYPTOPOCKETKNIFE_WEB_H
