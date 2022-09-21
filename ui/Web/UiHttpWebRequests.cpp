#include "UiHttpWebRequests.h"
#include "ui_UiHttpWebRequests.h"

#include "RawHttpWebRequest.h"
#include "utils.h"
#include "qjsonmodel.h"
#include "DomModel.h"

UiHttpWebRequests::UiHttpWebRequests(QWidget *parent): QWidget(parent), ui(new Ui::UiHttpWebRequests)
{
    ui->setupUi(this);
    connect(this->ui->treeWidget_HistoryList, &QTreeWidget::itemSelectionChanged, [this](){
        this->CurrentRequestIdx = this->ui->treeWidget_HistoryList->currentIndex().row();
        this->ShowRequestOutput(3);
    });

    connect(this->ui->tabWidget_RESPONSE, &QTabWidget::currentChanged, [this](int new_idx){
        this->ShowRequestOutput(2);
    });

    connect(this->ui->tabWidget_REQUEST, &QTabWidget::currentChanged, [this](int new_idx){
        this->ShowRequestOutput(1);
    });
}

UiHttpWebRequests::~UiHttpWebRequests()
{
    delete ui;
}

void UiHttpWebRequests::on_pushButton_Composer_Submit_clicked()
{

    Services::Web::RawHttpWebRequest http("254.ro", 443);

    QByteArray ret =  http.SendHttps("GET / HTTP/1.0\r\nHost: 254.ro\r\n\r\n");

    qDebug().nospace().noquote() << ret;

    Utils_Alert("Response", QString(ret));













    return;

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

    this->ui->plainTextEdit_REQUEST_OutputRAW->setPlainText( RAW_Request );
    this->ui->plainTextEdit_RESPONSE_OutputRAW->setPlainText( RAW_Response );

    // Save history
    web_request_t req;
    req.Method = this->ui->lineEdit_Composer_HttpMethod->text().toUtf8();
    req.Header = requestHeaders;
    req.Body = requestBody_;
    web_response_t res;
    res.HttpCode = resp.HttpCode;
    res.Header = resp.GetResponseHeaders();
    res.Body = resp.responseBody;

    this->RequestsHistory.append( {{ req, {{res}} }} );
    this->CurrentRequestIdx = this->RequestsHistory.count() - 1;
    this->ShowRequestOutput(3);

    // Populate tree widget
    QTreeWidgetItem *root = new QTreeWidgetItem(this->ui->treeWidget_HistoryList);
    root->setText(0, ((resp.NetworkErrorDetected || resp.AppErrorDetected) ? "ERROR" : QString::number(resp.HttpCode)));
    if( (resp.NetworkErrorDetected || resp.AppErrorDetected) || resp.HttpCode >= 400)
        root->setForeground(0, QColor("red"));
    else if( resp.HttpCode >= 300 && resp.HttpCode <= 399)
        root->setForeground(0, QColor("orange"));
    else if( resp.HttpCode == 200 )
        root->setForeground(0, QColor("green"));
    root->setText(1, this->ui->lineEdit_Composer_HttpMethod->text());
    root->setText(2, resp.reply->url().toString() );
    root->setText(3, this->locale().formattedDataSize(resp.GetResponseHeaders().size() + resp.responseBody.size()));
    this->ui->treeWidget_HistoryList->addTopLevelItem(root);

    Utils_PushButtonEndLoading(this->ui->pushButton_Composer_Submit);
}

void UiHttpWebRequests::ShowRequestOutput(int which)
{
    static QJsonModel jsonModelRequest;
    static QJsonModel jsonModelResponse;

    static DomModel xmlModelRequest;
    static DomModel xmlModelResponse;

    QString borderRed = "border-top: 1px solid red; border-bottom: 1px solid red; border-left: 1px solid red; border-right: 1px solid red;";

    // Clean up all outputs for request
    if(which == 1 || which >= 3)
    {
        this->ui->plainTextEdit_REQUEST_Headers->clear();
        this->ui->plainTextEdit_REQUEST_Body->clear();
        this->ui->plainTextEdit_REQUEST_OutputRAW->clear();
        jsonModelRequest.clear();
        this->ui->treeView_REQUEST_Json->setStyleSheet("");
        xmlModelRequest.clear();
        this->ui->treeView_REQUEST_Xml->setModel(nullptr);
        this->ui->treeView_REQUEST_Xml->setStyleSheet("");
    }

    // Clean up all output or response
    if(which >= 2)
    {
        this->ui->plainTextEdit_RESPONSE_OutputRAW->clear();
        this->ui->plainTextEdit_RESPONSE_Body->clear();
        this->ui->plainTextEdit_RESPONSE_Header->clear();
        jsonModelResponse.clear();
        this->ui->treeView_RESPONSE_Json->setStyleSheet("");
        xmlModelResponse.clear();
        this->ui->treeView_RESPONSE_Xml->setModel(nullptr);
        this->ui->treeView_RESPONSE_Xml->setStyleSheet("");
    }

    if(this->RequestsHistory.isEmpty())
        return;

    // Update request
    if(which == 1 || which >= 3)
    {
        web_request_t CurrRequest = this->RequestsHistory.at(this->CurrentRequestIdx).first;

        if(this->ui->tabWidget_REQUEST->currentIndex() == 0)
        {
            this->ui->plainTextEdit_REQUEST_Headers->setPlainText(CurrRequest.Header);
        }
        if(this->ui->tabWidget_REQUEST->currentIndex() == 1)
        {
            this->ui->plainTextEdit_REQUEST_Body->setPlainText(CurrRequest.Body);
        }
        else if ( this->ui->tabWidget_REQUEST->currentIndex() == 2 )
        {
            QDomDocument doc;
            if(!doc.setContent( CurrRequest.Body.trimmed() ) || !xmlModelRequest.loadDom(doc) )
            {
                this->ui->treeView_REQUEST_Xml->setStyleSheet(borderRed);
                this->ui->treeView_REQUEST_Xml->setModel(nullptr );
            }
            else
            {
                this->ui->treeView_REQUEST_Xml->setModel(&xmlModelRequest);
            }
        }
        else if( this->ui->tabWidget_REQUEST->currentIndex() == 3 )
        {
            if( !jsonModelRequest.loadJson(CurrRequest.Body.trimmed()) )
            {
                this->ui->treeView_REQUEST_Json->setModel(nullptr);
                this->ui->treeView_REQUEST_Json->setStyleSheet(borderRed);
            }
            else
            {
                this->ui->treeView_REQUEST_Json->setModel(&jsonModelRequest);
            }
        }
        else
        {
            this->ui->plainTextEdit_REQUEST_OutputRAW->setPlainText(CurrRequest.Header + "\n\n\n" + CurrRequest.Body);
        }
    }

    // Update response
    if(which >= 2)
    {
        web_response_t CurrResponse = this->RequestsHistory.at(this->CurrentRequestIdx).second[0];

        if(this->ui->tabWidget_RESPONSE->currentIndex() == 1)
        {
            QDomDocument doc;
            if(!doc.setContent( CurrResponse.Body.trimmed() ) || !xmlModelResponse.loadDom(doc) )
            {
                this->ui->treeView_RESPONSE_Xml->setStyleSheet(borderRed);
                this->ui->treeView_RESPONSE_Xml->setModel(nullptr);
            }
            else
            {
                this->ui->treeView_RESPONSE_Xml->setModel(&xmlModelResponse);
            }
        }
        else if(this->ui->tabWidget_RESPONSE->currentIndex() == 2)
        {
            if( !jsonModelResponse.loadJson(CurrResponse.Body.trimmed()) )
            {
                this->ui->treeView_RESPONSE_Json->setStyleSheet(borderRed);
                this->ui->treeView_RESPONSE_Json->setModel(nullptr);
            }
            else
            {
                this->ui->treeView_RESPONSE_Json->setModel(&jsonModelResponse);
            }
        }
        else if(this->ui->tabWidget_RESPONSE->currentIndex() == 3)
        {
            this->ui->plainTextEdit_RESPONSE_Header->setPlainText(CurrResponse.Header);
        }
        else if(this->ui->tabWidget_RESPONSE->currentIndex() == 4)
        {
            this->ui->plainTextEdit_RESPONSE_Body->setPlainText(CurrResponse.Body);
        }
        else
        {
            this->ui->plainTextEdit_RESPONSE_OutputRAW->setPlainText(CurrResponse.Header + "\n\n\n" + CurrResponse.Body);
        }
    }
}