#include "UiHttpWebRequests.h"
#include "ui_UiHttpWebRequests.h"
#include "RawHttpWebRequest.h"
#include "utils.h"
#include "qjsonmodel.h"
#include "DomModel.h"
#include "Uri.h"
#include "RawHttpResponseParser.h"

#include <QTcpSocket>
#include <QString>
#include <QByteArray>

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

//    // Show whitespaces
//    QTextOption option;
//    option.setFlags(QTextOption::ShowLineAndParagraphSeparators | QTextOption::ShowTabsAndSpaces);
//    this->ui->textEdit_ComposerRAW->document()->setDefaultTextOption(option);
}

UiHttpWebRequests::~UiHttpWebRequests()
{
    delete ui;
}

void UiHttpWebRequests::on_pushButton_Composer_Submit_clicked()
{
    bool errorDetected = false;
    QByteArray RAW_Request;
    web_response_t Response;

    if( this->ui->lineEdit_Composer_TargetHost->text().isEmpty() )
    {
        Utils_Alert("Empty URL", "Please provide target URL that contain a valid host");
        return;
    }

    Services::Parsers::Uri url( this->ui->lineEdit_Composer_TargetHost->text());
    if( !url.isValid() || url.host().isEmpty() )
    {
        Utils_Alert("Invalid URL", "Please provide a valid target URL containing a host");
        return;
    }

    QEventLoop waitLoop;
    Services::Web::RawHttpWebRequest http(url.host(), !url.port().isEmpty()?url.port().toUInt():(url.scheme()=="https"?443:80));

    QObject::connect(&http, &Services::Web::RawHttpWebRequest::RequestReturnedError, [&Response, &RAW_Request, &waitLoop](QTcpSocket *socket, const QByteArray &rawHttpRequest, const QString &errorDescription, const Services::Parsers::RawHttpResponseParser &response)
    {
        RAW_Request = rawHttpRequest;
        Response.Metadata.remoteHost = socket->peerAddress();
        Response.Metadata.remotePort = socket->peerPort();
        Response.Metadata.remoteName = socket->peerName();
        Response.ErrorOccurred = true;
        Response.ErrorDesc = errorDescription;
        Response.Data = response;
        waitLoop.quit();
    });

    QObject::connect(&http, &Services::Web::RawHttpWebRequest::RequestFinished, [&Response, &RAW_Request, &waitLoop](QTcpSocket *socket, const QByteArray &rawHttpRequest, const Services::Parsers::RawHttpResponseParser &response)
    {
        RAW_Request = rawHttpRequest;
        Response.Metadata.remoteHost = socket->peerAddress();
        Response.Metadata.remotePort = socket->peerPort();
        Response.Metadata.remoteName = socket->peerName();
        Response.ErrorOccurred = false;
        Response.ErrorDesc = "";
        Response.Data = response;

        waitLoop.quit();
    });

    Utils_PushButtonStartLoading(this->ui->pushButton_Composer_Submit);

    if( url.scheme() == "https" )
        http.SendHttps(this->ui->textEdit_ComposerRAW->toPlainText().toUtf8().replace('\n', "\r\n"));
    else
        http.SendHttp(this->ui->textEdit_ComposerRAW->toPlainText().toUtf8().replace('\n', "\r\n"));
    waitLoop.exec();

//    qDebug().nospace().noquote() << "REQ: " << RAW_Request;
//    qDebug().nospace().noquote() << "RES: " << Response.Data.GetRawResponse();

    // Save history
    web_request_t req;
    req.RAW = RAW_Request;
    QByteArray firstReqLine = RAW_Request.first(RAW_Request.contains("\r\n") > 0 ?RAW_Request.indexOf("\r\n") : 0 );
    req.Method = firstReqLine.split(' ').count() >= 1 ? firstReqLine.split(' ')[0] : "UNKNOWN";
    req.Header = RAW_Request.indexOf("\r\n\r\n") > 0 ? RAW_Request.first(RAW_Request.indexOf("\r\n\r\n")) : RAW_Request;
    req.Body = RAW_Request.indexOf("\r\n\r\n") > 0 ? RAW_Request.last(RAW_Request.count() - RAW_Request.indexOf("\r\n\r\n") - 4) : QByteArray();


    this->RequestsHistory.append( {{ req, {{Response}} }} );
    this->CurrentRequestIdx = this->RequestsHistory.count() - 1;
    this->ShowRequestOutput(3);

    // Populate tree widget
    QTreeWidgetItem *root = new QTreeWidgetItem(this->ui->treeWidget_HistoryList);
    root->setText(0, Response.ErrorOccurred ? "ERROR" : QString::number(Response.Data.GetResponseCode()));
    if( Response.ErrorOccurred || Response.Data.GetResponseCode() >= 400 || Response.Data.GetResponseCode() < 0)
        root->setForeground(0, QColor("red"));
    else if( Response.Data.GetResponseCode() >= 300 && Response.Data.GetResponseCode() <= 399)
        root->setForeground(0, QColor("orange"));
    else if( Response.Data.GetResponseCode() == 200 )
        root->setForeground(0, QColor("green"));
    root->setText(1, this->ui->lineEdit_Composer_HttpMethod->text());
    root->setText(2, "" );
    root->setText(3, this->locale().formattedDataSize(Response.Data.GetRawResponse().count()));
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
            if(!doc.setContent( CurrResponse.Data.GetRawBody().trimmed() ) || !xmlModelResponse.loadDom(doc) )
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
            if( !jsonModelResponse.loadJson(CurrResponse.Data.GetRawBody().trimmed()) )
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
            this->ui->plainTextEdit_RESPONSE_Header->setPlainText(CurrResponse.Data.GetRawHeaders());
        }
        else if(this->ui->tabWidget_RESPONSE->currentIndex() == 4)
        {
            this->ui->plainTextEdit_RESPONSE_Body->setPlainText(CurrResponse.Data.GetRawBody());
        }
        else
        {
            this->ui->plainTextEdit_RESPONSE_OutputRAW->setPlainText(CurrResponse.Data.GetRawResponse());
        }
    }
}
