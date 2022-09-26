#include "UiHttpWebRequests.h"
#include "ui_UiHttpWebRequests.h"
#include "RawHttpWebRequest.h"
#include "utils.h"
#include "qjsonmodel.h"
#include "DomModel.h"
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
}

UiHttpWebRequests::~UiHttpWebRequests()
{
    delete ui;
}

void UiHttpWebRequests::on_pushButton_Composer_Submit_clicked()
{
    bool errorDetected = false;
    QByteArray RAW_Request, RAW_Response;

    QEventLoop waitLoop;
    Services::Web::RawHttpWebRequest http("254.ro", 443);

    if( this->ui->lineEdit_Composer_TargetHost->text().isEmpty() )
    {
        Utils_Alert("Empty URL", "Please provide target URL");
        return;
    }

    QObject::connect(&http, &Services::Web::RawHttpWebRequest::RequestReturnedError, [&errorDetected, &RAW_Response, &RAW_Request, &waitLoop](QTcpSocket *socket, const QByteArray &rawHttpRequest, const QString &errorDescription)
    {
        errorDetected = true;
        RAW_Request = rawHttpRequest;
        RAW_Response = errorDescription.toUtf8();
        waitLoop.quit();
    });

    QObject::connect(&http, &Services::Web::RawHttpWebRequest::RequestFinished, [&RAW_Response, &RAW_Request, &waitLoop](QTcpSocket *socket, const QByteArray &rawHttpRequest, const QByteArray &response)
    {
        RAW_Request = rawHttpRequest;
        RAW_Response = response;
        waitLoop.quit();
    });

    Utils_PushButtonStartLoading(this->ui->pushButton_Composer_Submit);

    http.SendHttps("GET / HTTP/1.0\r\nHost: 254.ro\r\n\r\na=123");
    waitLoop.exec();

    qDebug().nospace().noquote() << "REQ: " << RAW_Request;
    qDebug().nospace().noquote() << "RES: " << RAW_Response;

    // Save history
    web_request_t req;
    req.RAW = RAW_Request;
    QByteArray firstReqLine = RAW_Request.first(RAW_Request.contains("\r\n") > 0 ?RAW_Request.indexOf("\r\n") : 0 );
    req.Method = firstReqLine.split(' ').count() >= 1 ? firstReqLine.split(' ')[0] : "UNKNOWN";
    req.Header = RAW_Request.indexOf("\r\n\r\n") > 0 ? RAW_Request.first(RAW_Request.indexOf("\r\n\r\n")) : RAW_Request;
    req.Body = RAW_Request.indexOf("\r\n\r\n") > 0 ? RAW_Request.last(RAW_Request.count() - RAW_Request.indexOf("\r\n\r\n") - 4) : QByteArray();

    web_response_t res;
    if( !errorDetected )
    {
        res.RAW = RAW_Response;
        QByteArray firstResLine = RAW_Response.first(RAW_Request.contains("\r\n") > 0 ? RAW_Request.indexOf("\r\n") : 0);
        res.HttpCode = QString(firstResLine.split(' ').count() >= 1 ? firstResLine.split(' ')[1] : "-1").toUInt();
        res.Header = RAW_Response.indexOf("\r\n\r\n") > 0 ? RAW_Response.first(RAW_Response.indexOf("\r\n\r\n")) : RAW_Response;
        res.Body = RAW_Response.indexOf("\r\n\r\n") > 0 ? RAW_Response.last(RAW_Response.count() - RAW_Response.indexOf("\r\n\r\n") - 4) : QByteArray();
    }
    else
    {
        res.RAW = RAW_Response;
        res.HttpCode = -1;
        res.Header = RAW_Response;
        res.Body = "";
    }

    this->RequestsHistory.append( {{ req, {{res}} }} );
    this->CurrentRequestIdx = this->RequestsHistory.count() - 1;
    this->ShowRequestOutput(3);

    // Populate tree widget
    QTreeWidgetItem *root = new QTreeWidgetItem(this->ui->treeWidget_HistoryList);
    root->setText(0, errorDetected ? "ERROR" : QString::number(res.HttpCode));
    if( errorDetected || res.HttpCode >= 400 || res.HttpCode < 0)
        root->setForeground(0, QColor("red"));
    else if( res.HttpCode >= 300 && res.HttpCode <= 399)
        root->setForeground(0, QColor("orange"));
    else if( res.HttpCode == 200 )
        root->setForeground(0, QColor("green"));
    root->setText(1, this->ui->lineEdit_Composer_HttpMethod->text());
    root->setText(2, "" );
    root->setText(3, this->locale().formattedDataSize(RAW_Response.count()));
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
