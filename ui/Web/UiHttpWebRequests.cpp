#include "UiHttpWebRequests.h"
#include "ui_UiHttpWebRequests.h"

#include "utils.h"

UiHttpWebRequests::UiHttpWebRequests(QWidget *parent): QWidget(parent), ui(new Ui::UiHttpWebRequests)
{
    ui->setupUi(this);
    connect(this->ui->treeWidget, &QTreeWidget::itemSelectionChanged, [this](){
        this->CurrentRequestIdx = this->ui->treeWidget->currentIndex().row();
        this->ShowRequestOutput();
    });
}

UiHttpWebRequests::~UiHttpWebRequests()
{
    delete ui;
}

void UiHttpWebRequests::on_pushButton_Composer_Submit_clicked()
{
    if( this->ui->lineEdit_Composer_TargetHost->text().isEmpty() )
    {
        Utils_Alert("Empty URL", "Please provide target URL");
        return;
    }

    Utils_PushButtonStartLoading(this->ui->pushButton_Composer_Submit);

    // Wait until response is received
    QEventLoop waitLoop;
    HttpWebRequest request;
    QByteArray requestHeaders;
    QByteArray requestBody_;
    HttpWebRequestsResponse resp;
    request.setIgnoreSslErrors(true);

    if( this->ui->plainTextEdit_ComposerRawHeaders->toPlainText().contains("\n\n") )
    {
        requestHeaders = this->ui->plainTextEdit_ComposerRawHeaders->toPlainText().split("\n\n")[0].toUtf8();
        requestBody_ = this->ui->plainTextEdit_ComposerRawHeaders->toPlainText().split("\n\n")[1].toUtf8();
    }
    else
    {
        requestHeaders = this->ui->plainTextEdit_ComposerRawHeaders->toPlainText().toUtf8();
    }

    QMap<QByteArray, QByteArray> headersMap;
    for( const QByteArray line: requestHeaders.split('\n') )
    {
        if( !line.contains(":"))
            continue;

        headersMap[line.split(':')[0]] = line.split(':')[1];
    }
    request.setHeaders(headersMap);


    // Connect signals from HTTP web request
    QObject::connect(&request, &HttpWebRequest::RequestStarted, this, [&requestHeaders, &requestBody_](const QString &requestMethod, const QNetworkRequest *request, const QByteArray &requestBody)// clazy:exclude=lambda-in-connect
    {
        requestBody_ = requestBody;
        requestHeaders = QByteArray();
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

    request.CUSTOM(this->ui->lineEdit_Composer_HttpMethod->text().toUtf8(), this->ui->lineEdit_Composer_TargetHost->text(), requestBody_);
    waitLoop.exec();

    // Remove connections as these will persist
    QObject::disconnect(&request, &HttpWebRequest::RequestStarted, this, nullptr);
    QObject::disconnect(&request, &HttpWebRequest::RequestFinished, this, nullptr);
    QObject::disconnect(&request, &HttpWebRequest::RequestReturnedError, this, nullptr);

    QByteArray RAW_Request = requestHeaders + (!requestBody_.isEmpty()?("\n\n\n"+requestBody_):(QByteArray()));
    QByteArray RAW_Response = (resp.NetworkErrorDetected || resp.AppErrorDetected) ? resp.reply->errorString().toUtf8() :  resp.GetResponseHeaders() + "\n\n\n" + resp.responseBody;

    this->ui->plainTextEdit_OutputRAW_REQUEST->setPlainText( RAW_Request );
    this->ui->plainTextEdit_OutputRAW_RESPONSE->setPlainText( RAW_Response );

    // Save history
    this->RequestsHistory.append( {{ RAW_Request, {{RAW_Response}} }} );
    this->CurrentRequestIdx = this->RequestsHistory.count() - 1;
    this->ShowRequestOutput();

    // Populate tree widget
    QTreeWidgetItem *root = new QTreeWidgetItem(this->ui->treeWidget);
    root->setText(0, ((resp.NetworkErrorDetected || resp.AppErrorDetected) ? "ERROR" : QString::number(resp.HttpCode)));
    if( (resp.NetworkErrorDetected || resp.AppErrorDetected) || resp.HttpCode >= 400)
        root->setForeground(0, QColor("red"));
    else if( resp.HttpCode >= 300 && resp.HttpCode <= 399)
        root->setForeground(0, QColor("orange"));
    else if( resp.HttpCode == 200 )
        root->setForeground(0, QColor("green"));
    root->setText(1, this->ui->lineEdit_Composer_HttpMethod->text());
    root->setText(2, resp.reply->url().toString() );
    this->ui->treeWidget->addTopLevelItem(root);

    Utils_PushButtonEndLoading(this->ui->pushButton_Composer_Submit);
}

void UiHttpWebRequests::ShowRequestOutput()
{
    // Clean up all outputs
    this->ui->plainTextEdit_OutputRAW_REQUEST->clear();
    this->ui->plainTextEdit_OutputRAW_RESPONSE->clear();

    if( this->RequestsHistory.isEmpty())
        return;

    // Update request
    this->ui->plainTextEdit_OutputRAW_REQUEST->setPlainText(this->RequestsHistory.at(this->CurrentRequestIdx).first);

    // Update response
    this->ui->plainTextEdit_OutputRAW_RESPONSE->setPlainText(this->RequestsHistory.at(this->CurrentRequestIdx).second[0]);
}