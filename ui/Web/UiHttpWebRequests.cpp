#include "UiHttpWebRequests.h"
#include "ui_UiHttpWebRequests.h"

#include "utils.h"

UiHttpWebRequests::UiHttpWebRequests(QWidget *parent): QWidget(parent), ui(new Ui::UiHttpWebRequests)
{
    ui->setupUi(this);
}

UiHttpWebRequests::~UiHttpWebRequests()
{
    delete ui;
}

void UiHttpWebRequests::on_pushButton_Composer_Submit_clicked()
{
    Utils_PushButtonStartLoading(this->ui->pushButton_Composer_Submit);

    // Wait until response is received
    QEventLoop waitLoop;
    HttpWebRequest request;
    QByteArray requestHeaders;
    QByteArray requestBody_;
    HttpWebRequestsResponse resp;
    request.setIgnoreSslErrors(true);

    QMap<QByteArray, QByteArray> headers;
    QStringList lines = this->ui->plainTextEdit_ComposerRawHeaders->toPlainText().split("\n", Qt::SkipEmptyParts);
    for( const QString line: lines )
    {
        if( !line.contains(":"))
            continue;

        headers[line.split(":")[0].toUtf8()] = line.split(":")[1].toUtf8();
    }
    request.setHeaders(headers);


    // Connect signals from HTTP web request
    QObject::connect(&request, &HttpWebRequest::RequestStarted, this, [&requestHeaders, &requestBody_](const QString &requestMethod, const QNetworkRequest *request, const QByteArray &requestBody)// clazy:exclude=lambda-in-connect
    {
        requestBody_ = requestBody;
        for(const QByteArray &header: request->rawHeaderList())
        {
            requestHeaders += header + ": " + request->rawHeader(header) + "\n";
        }
        if(requestHeaders.count() > 0 )
            requestHeaders.chop(1);

        qDebug().noquote().nospace() << "REQUEST:\n" << requestMethod << " " << request->url().toString() << "\n" << requestHeaders << (requestBody.count() ? "\n\n" + requestBody.trimmed() : "");
    });
    QObject::connect(&request, &HttpWebRequest::RequestFinished, this, [&waitLoop, &resp](const HttpWebRequestsResponse *response)// clazy:exclude=lambda-in-connect
    {
        qDebug().noquote().nospace() << "RESPONSE:\n" << response->GetResponseHeaders() << (response->responseBody.count() ? "\n\n" + response->responseBody.trimmed(): "");
        resp = *response;
        waitLoop.quit();
    });
    QObject::connect(&request, &HttpWebRequest::RequestReturnedError, this, [&waitLoop, &resp](const HttpWebRequestsResponse *response)// clazy:exclude=lambda-in-connect
    {
        qDebug().noquote().nospace() << "ERROR:" << response->reply->errorString() << "\n" << response->GetResponseHeaders().trimmed() << (response->responseBody.count() ? "\n\n" + response->responseBody.trimmed() : "");
        resp = *response;
        waitLoop.quit();
    });

    request.CUSTOM(this->ui->lineEdit_Composer_HttpMethod->text().toUtf8(), this->ui->lineEdit_Composer_TargetHost->text(), this->ui->plainTextEdit_ComposerRawData->toPlainText().toUtf8());
    waitLoop.exec();

    // Remove connections as these will persist
    QObject::disconnect(&request, &HttpWebRequest::RequestStarted, this, nullptr);
    QObject::disconnect(&request, &HttpWebRequest::RequestFinished, this, nullptr);
    QObject::disconnect(&request, &HttpWebRequest::RequestReturnedError, this, nullptr);

    this->ui->plainTextEdit_OutputRAW_REQUEST->setPlainText(requestHeaders + (!requestBody_.isEmpty()?("\n\n"+QString(requestBody_)):("")) );
    this->ui->plainTextEdit_OutputRAW_RESPONSE->setPlainText( (resp.NetworkErrorDetected || resp.AppErrorDetected) ? resp.reply->errorString() :  resp.GetResponseHeaders() + "\n\n" + QString(resp.responseBody));
    this->ui->listWidget_History->addItem( ((resp.NetworkErrorDetected || resp.AppErrorDetected) ? "ERROR" : QString::number(resp.HttpCode)) + " - " + this->ui->lineEdit_Composer_HttpMethod->text() + " " + resp.reply->url().toString() );

    Utils_PushButtonEndLoading(this->ui->pushButton_Composer_Submit);
}
