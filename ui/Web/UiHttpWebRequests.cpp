#include "UiHttpWebRequests.h"
#include "ui_UiHttpWebRequests.h"
#include "base/data_structures/DomModel.h"
#include "base/services/Web/RawHttpWebRequest.h"
#include "base/utils/utils.h"
#include "base/thirdparty/QJsonModel/QJsonModel.h"
#include "base/services/Parsers/Uri.h"

#include <QTreeWidget>
#include <QTcpSocket>
#include <QString>
#include <QByteArray>
#include <QMenu>

using Services::Web::RawHttpWebRequest;

UiHttpWebRequests::UiHttpWebRequests(QWidget *parent): QMainWindow(parent), ui(new Ui::UiHttpWebRequests)
{
    ui->setupUi(this);

    // Some rows were deleted
    QObject::connect(this->ui->treeWidget_HistoryList->model(), SIGNAL(rowsRemoved(const QModelIndex&,int,int)), this, SLOT(treeWidget_OnRowsRmoved(const QModelIndex&,int,int)), Qt::UniqueConnection);

//    connect(this->ui->treeWidget_HistoryList->model(), &QTreeWidget::rowsRemoved, [this](const QModelIndex &parent, int start, int end){
//        this->RequestsHistory.remove(start, end-start);
//    });

    // New transaction to be added
    connect(this->ui->treeWidget_HistoryList, &QTreeWidget::currentItemChanged, [this](QTreeWidgetItem *current, QTreeWidgetItem *previous){
        this->ShowRequestOutput(3);
    });

    connect(this->ui->treeWidget_HistoryList, &QTreeWidget::currentItemChanged, [this](QTreeWidgetItem *current, QTreeWidgetItem *previous){
        this->ShowRequestOutput(3);
    });

    // Tab for RESPONSE was switched
    connect(this->ui->tabWidget_RESPONSE, &QTabWidget::currentChanged, [this](int new_idx){
        this->ShowRequestOutput(2);
    });

    // Tab for REQUEST was switched
    connect(this->ui->tabWidget_REQUEST, &QTabWidget::currentChanged, [this](int new_idx){
        this->ShowRequestOutput(1);
    });

    // Enable custom context menu for TreeWidget
    this->ui->treeWidget_HistoryList->setContextMenuPolicy(Qt::CustomContextMenu);

    // Show whitespaces
//    QTextOption option;
//    option.setFlags(QTextOption::ShowLineAndParagraphSeparators | QTextOption::ShowTabsAndSpaces);
//    this->ui->plainTextEdit_ComposerRAW->document()->setDefaultTextOption(option);

}

UiHttpWebRequests::~UiHttpWebRequests()
{
    if( this->currRequest)
    {
        this->currRequest->Abort();
    }

    delete this->currRequest;
    delete ui;
}

void UiHttpWebRequests::on_pushButton_Composer_Submit_clicked()
{
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

    bool errorDetected = false;
    web_request_t Request;
    web_response_t Response;
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

    // Parse raw request
    RawHttpRequestParser parser;
    QByteArray rawInput = this->ui->plainTextEdit_ComposerRAW->toPlainText().toUtf8();
    if( rawInput.indexOf("\n\n") > 0  )
    {
        // Replace \n with \r\n only on header (plain text edit does not automatically append \r\n requires by HTTP RFC). Leave payload untouched
        parser.addData( rawInput.left(rawInput.indexOf("\n\n")).replace("\n", "\r\n") + "\r\n\r\n" );
        if(rawInput.indexOf("\n\n") < rawInput.length() - 2)
            parser.addData(rawInput.right(rawInput.length() - rawInput.indexOf("\n\n") - 2));
    }
    else
    {
        // Only header is present and it is malformed since it misses the \n\n terminator. Treat everything as header content and replace \n with \r\n
        parser.addData(rawInput.replace("\n", "\r\n"));
    }

    // Check if data send should have Content-Length appended automatically
    QByteArray sendData = parser.GetRaw();
    if( this->ui->actionAppendContentLength->isChecked() && !parser.GetRawBody().isEmpty())
    {
        sendData = parser.GetRawHeaders() + QString("Content-Length: " + QString::number(parser.GetRawBody().length()) + "\r\n\r\n").toUtf8() + parser.GetRawBody();
    }

    this->currRequest = &http;

    if( url.scheme() == "https" )
        http.SendHttps(sendData);
    else
        http.SendHttp(sendData);
    waitLoop.exec();

    Request.DataFlowLog = http.GetLogsFlow();
    this->currRequest = nullptr;

//    qDebug().nospace().noquote() << "REQ: " << RAW_Request;
//    qDebug().nospace().noquote() << "RES: " << Response.Data.GetRaw();

    this->RequestsHistory.append( {{ Request, {{Response}} }} );

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
    root->setText(5, (!Response.ErrorOccurred ? this->locale().formattedDataSize(Response.Data.GetRaw().length()) : "") );
    root->setText(6, Request.Metadata.Host + ":" + QString::number(Request.Metadata.Port) +  " (" + (Response.Metadata.remoteHost.toString() + ":" + QString::number(Response.Metadata.remotePort)) + ")" );
    this->ui->treeWidget_HistoryList->addTopLevelItem(root);
    this->ui->treeWidget_HistoryList->setCurrentItem(root);

    Utils_PushButtonEndLoading(this->ui->pushButton_Composer_Submit);
}

void UiHttpWebRequests::ShowRequestOutput(int which)
{
    // which = 3: New transaction to be added
    // which = 2: Tab for RESPONSE was switched
    // which = 1: Tab for REQUEST was switched

    static QJsonModel jsonModelRequest;
    static QJsonModel jsonModelResponse;

    static DomModel xmlModelRequest;
    static DomModel xmlModelResponse;

    QString borderRed = "border-top: 1px solid red; border-bottom: 1px solid red; border-left: 1px solid red; border-right: 1px solid red;";

    // Clean up all outputs for REQUEST
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

    // Clean up all outputs for RESPONSE
    if(which >= 2)
    {
        this->ui->textEdit_RESPONSE_HtmlRender->clear();
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

    int treeCurrentIndex = this->ui->treeWidget_HistoryList->currentIndex().row();
    if( treeCurrentIndex < 0 )
        return;

    if( treeCurrentIndex > this->RequestsHistory.size() - 1)
    {
        qWarning().nospace().noquote() << "Received request to show index " << treeCurrentIndex << " but history max index is " << this->RequestsHistory.size() - 1;
        return;
    }

    // Update request
    if(which == 1 || which >= 3)
    {
        web_request_t CurrRequest = this->RequestsHistory.at(treeCurrentIndex).first;

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
        web_response_t CurrResponse = this->RequestsHistory.at(treeCurrentIndex).second[0];

        if( this->ui->tabWidget_RESPONSE->currentIndex() == 0 )
        {
            this->ui->textEdit_RESPONSE_HtmlRender->setHtml(CurrResponse.Data.GetRawBody());
        }
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

void UiHttpWebRequests::on_pushButton_AbortRequest_clicked()
{
    if( this->currRequest != nullptr )
    {
        currRequest->Abort();
    }
}

void UiHttpWebRequests::on_actionShowWhitespaces_triggered()
{
    QTextOption option;
    if(this->ui->actionShowWhitespaces->isChecked())
        option.setFlags(QTextOption::ShowLineAndParagraphSeparators | QTextOption::ShowTabsAndSpaces | QTextOption::ShowDocumentTerminator);
    else
        option.setFlags(QTextOption::Flag(0));

    // Apply these settings for all PLainTextEdits
    QList<QPlainTextEdit *> plainTextEdits = this->findChildren<QPlainTextEdit *>();
    for(const QPlainTextEdit *child: plainTextEdits)
        child->document()->setDefaultTextOption(option);
}

void UiHttpWebRequests::on_actionWordWrap_triggered()
{
    QPlainTextEdit::LineWrapMode mode = (this->ui->actionWordWrap->isChecked()) ?  QPlainTextEdit::WidgetWidth :  QPlainTextEdit::NoWrap;

    // Apply these settings for all PLainTextEdits
    QList<QPlainTextEdit *> plainTextEdits = this->findChildren<QPlainTextEdit *>();
    for(QPlainTextEdit *child: plainTextEdits)
        child->setLineWrapMode(mode);
}

void UiHttpWebRequests::on_treeWidget_HistoryList_customContextMenuRequested(const QPoint &pos)
{
    int row = ui->treeWidget_HistoryList->indexAt(pos).row();
    if( row < 0 )
    {
        return;
    }

    // Show flow logs menu
    QAction Item_ShowFlowLogs("Show flow logs", this);
    connect(&Item_ShowFlowLogs, &QAction::triggered, this, [&row, this]()
    {
        QDateTime tm;
        tm.setMSecsSinceEpoch(this->RequestsHistory.at(row).first.Metadata.StartTimestampMs);

        // Output text
        QPlainTextEdit *editor = new QPlainTextEdit(this->RequestsHistory.at(row).first.DataFlowLog.join("\n"));
        editor->setWindowTitle("Flow info for request on " + this->RequestsHistory.at(row).first.Metadata.Host + ":" +
                               QString::number(this->RequestsHistory.at(row).first.Metadata.Port) + " at " + tm.toString("yyyy-MM-dd hh:mm:ss.zzz"));
        editor->resize(800, 400);
        editor->setAttribute(Qt::WA_DeleteOnClose);
        editor->show();
    });

    // Delete item menu
    QAction Item_DeleteSelection("Delete", this);
    connect(&Item_DeleteSelection, &QAction::triggered, this, [&row, this]()
    {
        this->ui->treeWidget_HistoryList->takeTopLevelItem(row);
        //this->RequestsHistory.removeAt(row);
    });

    QMenu menu("contextMenu", this);
    menu.addAction(&Item_ShowFlowLogs);
    menu.addSeparator();
    menu.addAction(&Item_DeleteSelection);
    menu.exec(ui->treeWidget_HistoryList->viewport()->mapToGlobal(pos));
}

void UiHttpWebRequests::treeWidget_OnRowsRmoved(const QModelIndex &parent, int start, int end)
{
    if( start > this->RequestsHistory.size() )
    {
        qWarning().nospace().noquote() << "TreeView model requested to delete starting from " << start << " but history max index is " << this->RequestsHistory.size() - 1;
        return;
    }

    if( start == end )
        this->RequestsHistory.remove(start);
    else
        this->RequestsHistory.remove(start, end-start-1);
}
