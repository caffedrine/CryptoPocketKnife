#ifndef CRYPTOPOCKETKNIFE_UIWEB_H
#define CRYPTOPOCKETKNIFE_UIWEB_H

#include <QWidget>
#include <QAction>
#include <QMenu>
#include <QMessageBox>
#include <QPlainTextEdit>
#include <QtConcurrent>
#include <QFuture>

#include "TldCountry.h"
#include "GeoIP.h"
#include "WebScraper.h"
#include "utils.h"
#include "WebUtils.h"
#include "LambdaEventFilter.h"
#include "AdvancedTableWidget.h"

using namespace Services::GeoIP;

QT_BEGIN_NAMESPACE
namespace Ui
{
    class UiWeb;
}
QT_END_NAMESPACE

class UiWeb: public QWidget
{
Q_OBJECT

public:
    explicit UiWeb(QWidget *parent = nullptr);
    ~UiWeb() override;
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
    Ui::UiWeb *ui;

    WebScraper *WebScrapperEngine = nullptr;
    bool CancelRequests = false;
    QMap<QString, QString> WebScraperResponseHeaders;
    QMap<QString, QString> WebScraperResponseData;

    void webScrapper_InitEngine();
};


#endif //CRYPTOPOCKETKNIFE_UIWEB_H
