#ifndef CRYPTOPOCKETKNIFE_UIHTTPWEBREQUESTS_H
#define CRYPTOPOCKETKNIFE_UIHTTPWEBREQUESTS_H

#include <QWidget>

#include "HttpWebRequest.h"
#include "Uri.h"
#include "RawHttpResponseParser.h"
#include "RawHttpRequestParser.h"

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

class UiHttpWebRequests : public QWidget
{
Q_OBJECT

public:
    explicit UiHttpWebRequests(QWidget *parent = nullptr);
    ~UiHttpWebRequests() override;

protected slots:
    void on_pushButton_Composer_Submit_clicked();

private:
    Ui::UiHttpWebRequests *ui;
    int CurrentRequestIdx;
    QList< QPair<web_request_t, QList<web_response_t> > > RequestsHistory;

    void ShowRequestOutput(int which);
};


#endif //CRYPTOPOCKETKNIFE_UIHTTPWEBREQUESTS_H
