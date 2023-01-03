#ifndef CRYPTOPOCKETKNIFE_UIHTTPWEBREQUESTS_H
#define CRYPTOPOCKETKNIFE_UIHTTPWEBREQUESTS_H

#include <QWidget>
#include <QMainWindow>

#include "Uri.h"
#include "RawHttpWebRequest.h"
#include "RawHttpResponseParser.h"
#include "RawHttpRequestParser.h"

using Services::Web::RawHttpWebRequest;
using Services::Parsers::RawHttpResponseParser;
using Services::Parsers::RawHttpRequestParser;

QT_BEGIN_NAMESPACE
namespace Ui
{
    class UiHttpWebRequests;
}
QT_END_NAMESPACE

struct web_request_t
{
    struct
    {
        QByteArray Host;
        quint16 Port;
        quint64 StartTimestampMs;
    } Metadata;

    QStringList DataFlowLog;
    RawHttpRequestParser Data;
};

struct web_response_t
{
    struct web_response_metadata_t
    {
        QHostAddress remoteHost;
        quint16 remotePort;
        QString remoteName;
        quint64 ResponseTimestamp;
    } Metadata;

    RawHttpResponseParser Data;
    bool ErrorOccurred = false;
    QString ErrorDesc = "";
};

class UiHttpWebRequests : public QMainWindow
{
Q_OBJECT

public:
    explicit UiHttpWebRequests(QWidget *parent = nullptr);
    ~UiHttpWebRequests() ;

private slots:
    void on_actionShowWhitespaces_triggered();
    void on_actionWordWrap_triggered();

    void on_pushButton_Composer_Submit_clicked();
    void on_pushButton_AbortRequest_clicked();

    void on_treeWidget_HistoryList_customContextMenuRequested(const QPoint &pos);
    void treeWidget_OnRowsRmoved(const QModelIndex &parent, int start, int end);

private:
    Ui::UiHttpWebRequests *ui;
    QList< QPair<web_request_t, QList<web_response_t> >> RequestsHistory;

    // Update output data within UI. which = request, response, all
    void ShowRequestOutput(int which);

    // Used to send custom actions from UI to current request that is running
    RawHttpWebRequest *currRequest = nullptr;
};


#endif //CRYPTOPOCKETKNIFE_UIHTTPWEBREQUESTS_H
