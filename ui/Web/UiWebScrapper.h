#ifndef CRYPTOPOCKETKNIFE_UIWEBSCRAPPER_H
#define CRYPTOPOCKETKNIFE_UIWEBSCRAPPER_H

#include <QWidget>
#include <QAction>
#include <QMenu>
#include <QMessageBox>
#include <QPlainTextEdit>
#include <QtConcurrent>
#include <QFuture>

#include "Web/WebScraper.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class UiWebScrapper;
}
QT_END_NAMESPACE

class UiWebScrapper : public QWidget
{
Q_OBJECT

public:
    explicit UiWebScrapper(QWidget *parent = nullptr);
    ~UiWebScrapper() override;

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
    void webScraper_OnRequestStarted(QString requestId, QString requestUrl);
    void webScraper_OnRequestError(QString requestId, QString requestUrl, HttpResponse response);
    void webScraper_OnRequestFinished(QString requestId, QString requestUrl, HttpResponse response);
    void webScraper_OnAvailableWorkersChanged(int availableWorkers, int activeWorkers);
    void on_pushButton_WebScraping_StretchCols_clicked();

private:
    Ui::UiWebScrapper *ui;

    WebScraper *WebScrapperEngine = nullptr;
    bool CancelRequests = false;
    QMap<QString, QString> WebScraperResponseHeaders;
    QMap<QString, QString> WebScraperResponseData;

    void webScrapper_InitEngine();
};


#endif //CRYPTOPOCKETKNIFE_UIWEBSCRAPPER_H
