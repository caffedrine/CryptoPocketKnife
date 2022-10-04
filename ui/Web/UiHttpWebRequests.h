#ifndef CRYPTOPOCKETKNIFE_UIHTTPWEBREQUESTS_H
#define CRYPTOPOCKETKNIFE_UIHTTPWEBREQUESTS_H

#include <QWidget>

#include "HttpWebRequest.h"
#include "Uri.h"
#include "RawHttpResponseParser.h"

using Services::Parsers::RawHttpResponseParser;

QT_BEGIN_NAMESPACE
namespace Ui
{
    class UiHttpWebRequests;
}

struct web_response_metadata_t
{
    QHostAddress remoteHost;
    quint16 remotePort;
    QString remoteName;
    quint64 Timestamp;
};

struct web_request_t
{
    QByteArray Method;
    QByteArray Header;
    QByteArray Body;
    QByteArray RAW;
};

struct web_response_t
{
    web_response_metadata_t Metadata;
    Services::Parsers::RawHttpResponseParser Data;
    bool ErrorOccurred = false;
    QString ErrorDesc = "";
};

QT_END_NAMESPACE

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
