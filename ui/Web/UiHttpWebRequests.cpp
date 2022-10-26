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

using Services::Web::RawHttpWebRequest;

UiHttpWebRequests::UiHttpWebRequests(QWidget *parent): QMainWindow(parent), ui(new Ui::UiHttpWebRequests)
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

    // Show whitespaces
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
    web_request_t Request;
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
    RawHttpWebRequest http(url.host(), !url.port().isEmpty()?url.port().toUInt():(url.scheme()=="https"?443:80));

    QObject::connect(&http, &RawHttpWebRequest::RequestReturnedError, [&Response, &Request, &waitLoop](QTcpSocket *socket, const RawHttpRequestParser &request, const QString &errorDescription, const RawHttpResponseParser &response)
    {
        Request.Data = request;
        Response.Metadata.remoteHost = socket->peerAddress();
        Response.Metadata.remotePort = socket->peerPort();
        Response.Metadata.remoteName = socket->peerName();
        Response.Metadata.ResponseTimestamp = QDateTime::currentMSecsSinceEpoch();
        Response.ErrorOccurred = true;
        Response.ErrorDesc = errorDescription;
        Response.Data = response;
        waitLoop.quit();
    });

    QObject::connect(&http, &RawHttpWebRequest::RequestFinished, [&Response, &Request, &waitLoop](QTcpSocket *socket, const RawHttpRequestParser &request, const RawHttpResponseParser &response)
    {
        Request.Data = request;

        Response.Metadata.remoteHost = socket->peerAddress();
        Response.Metadata.remotePort = socket->peerPort();
        Response.Metadata.remoteName = socket->peerName();
        Response.Metadata.ResponseTimestamp = QDateTime::currentMSecsSinceEpoch();
        Response.ErrorOccurred = false;
        Response.ErrorDesc = "";
        Response.Data = response;
        waitLoop.quit();
    });

    QObject::connect(&http, &RawHttpWebRequest::RequestStateChangeInfo, [this](QTcpSocket *socket, const RawHttpRequestParser &request, const RawHttpResponseParser &response, QString status){
        this->ui->label_State->setText("State: " + status);
    });

    Utils_PushButtonStartLoading(this->ui->pushButton_Composer_Submit);

    Request.Metadata.Host = url.host().toUtf8();
    Request.Metadata.Port = !url.port().isEmpty()?url.port().toUInt():(url.scheme()=="https"?443:80);
    Request.Metadata.StartTimestampMs = QDateTime::currentMSecsSinceEpoch();

    // Parse raw request if needed
    RawHttpRequestParser parser;
    QByteArray rawInput = this->ui->textEdit_ComposerRAW->toPlainText().toUtf8();
    if( rawInput.indexOf("\n\n") > 0  )
    {
        // Replace \n with \r\n only on header (plain text edit does not automatically append \r\n requires by HTTP RFC). Leave payload untouched
        parser.addData( rawInput.first(rawInput.indexOf("\n\n")).replace("\n", "\r\n") + "\r\n\r\n" );
        if(rawInput.indexOf("\n\n") < rawInput.count() - 2)
            parser.addData(rawInput.last(rawInput.count() - rawInput.indexOf("\n\n") - 2));
    }
    else
    {
        // Only header is present and it is malformed since it misses the \n\n terminator. Treat everything as header content and replace \n with \r\n
        parser.addData(rawInput.replace("\n", "\r\n"));
    }

    //qDebug() << parser.GetRaw();

    if( url.scheme() == "https" )
        http.SendHttps(parser.GetRaw());
    else
        http.SendHttp(parser.GetRaw());
    waitLoop.exec();

//    qDebug().nospace().noquote() << "REQ: " << RAW_Request;
//    qDebug().nospace().noquote() << "RES: " << Response.Data.GetRaw();

    this->RequestsHistory.append( {{ Request, {{Response}} }} );
    this->CurrentRequestIdx = this->RequestsHistory.count() - 1;
    this->ShowRequestOutput(3);

    // Populate tree widget
    QTreeWidgetItem *root = new QTreeWidgetItem(this->ui->treeWidget_HistoryList);
    root->setText(0, QDateTime::fromMSecsSinceEpoch(Request.Metadata.StartTimestampMs).toString("hh:mm:ss.zzz"));
    root->setText(1, Response.ErrorOccurred ? "ERROR" : (Response.Data.GetHttpResponseCode() < 0 ? "INVALID" : QString::number(Response.Data.GetHttpResponseCode()) + " " + Response.Data.GetHttpResponseCodeDescription()));
    if(Response.ErrorOccurred || Response.Data.GetHttpResponseCode() >= 400 || Response.Data.GetHttpResponseCode() < 0)
        root->setForeground(1, QColor("red"));
    else if(Response.Data.GetHttpResponseCode() >= 300 && Response.Data.GetHttpResponseCode() <= 399)
        root->setForeground(1, QColor("orange"));
    else if(Response.Data.GetHttpResponseCode() == 200 )
        root->setForeground(1, QColor("green"));
    root->setText(2, Request.Data.GetMethod());
    root->setText(3, Request.Data.GetHeaderByName("Host") );
    root->setText(4, Request.Data.GetPath() );
    root->setText(5, (!Response.ErrorOccurred ? this->locale().formattedDataSize(Response.Data.GetRaw().count()) : "") );
    root->setText(6, Request.Metadata.Host + ":" + QString::number(Request.Metadata.Port) +  " (" + (Response.Metadata.remoteHost.toString() + ":" + QString::number(Response.Metadata.remotePort)) + ")" );
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

        // Output HEADERS
        if(this->ui->tabWidget_REQUEST->currentIndex() == 0)
        {
            this->ui->plainTextEdit_REQUEST_Headers->setPlainText(CurrRequest.Data.GetRawHeaders());
        }
        // Output  BODY
        if(this->ui->tabWidget_REQUEST->currentIndex() == 1)
        {
            this->ui->plainTextEdit_REQUEST_Body->setPlainText(CurrRequest.Data.GetRawBody());
        }
        // Output XML
        else if ( this->ui->tabWidget_REQUEST->currentIndex() == 2 )
        {
            QDomDocument doc;
            if(!doc.setContent( CurrRequest.Data.GetRawBody().trimmed() ) || !xmlModelRequest.loadDom(doc) )
            {
                this->ui->treeView_REQUEST_Xml->setStyleSheet(borderRed);
                this->ui->treeView_REQUEST_Xml->setModel(nullptr );
            }
            else
            {
                this->ui->treeView_REQUEST_Xml->setModel(&xmlModelRequest);
            }
        }
        // Output JSON
        else if( this->ui->tabWidget_REQUEST->currentIndex() == 3 )
        {
            if( !jsonModelRequest.loadJson(CurrRequest.Data.GetRawBody().trimmed()) )
            {
                this->ui->treeView_REQUEST_Json->setModel(nullptr);
                this->ui->treeView_REQUEST_Json->setStyleSheet(borderRed);
            }
            else
            {
                this->ui->treeView_REQUEST_Json->setModel(&jsonModelRequest);
            }
        }
        // Output RAW
        else
        {
            this->ui->plainTextEdit_REQUEST_OutputRAW->setPlainText(CurrRequest.Data.GetRaw());
        }
    }

    // Update response
    if(which >= 2)
    {
        web_response_t CurrResponse = this->RequestsHistory.at(this->CurrentRequestIdx).second[0];

        // Output XML
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
        // Output JSON
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
        // Output HEADER
        else if(this->ui->tabWidget_RESPONSE->currentIndex() == 3)
        {
            this->ui->plainTextEdit_RESPONSE_Header->setPlainText(CurrResponse.Data.GetRawHeaders());
        }
        // Output BODY
        else if(this->ui->tabWidget_RESPONSE->currentIndex() == 4)
        {
            this->ui->plainTextEdit_RESPONSE_Body->setPlainText(CurrResponse.Data.GetRawBody());
        }
        // Output RAW
        else
        {
            this->ui->plainTextEdit_RESPONSE_OutputRAW->clear();
            if(CurrResponse.ErrorOccurred)
                this->ui->plainTextEdit_RESPONSE_OutputRAW->appendPlainText(CurrResponse.ErrorDesc + "\r\n----------\r\n");

            this->ui->plainTextEdit_RESPONSE_OutputRAW->appendPlainText(CurrResponse.Data.GetRaw());
        }
    }
}
