#include "UiWeb.h"
#include "ui_UiWeb.h"
#include "UiDomainWhois.h"

UiWeb::UiWeb(QWidget *parent): QWidget(parent), ui(new Ui::UiWeb)
{
    ui->setupUi(this);

    // WebScrapping table resize mode
    this->ui->tableWidget_WebScraper->setContextMenuPolicy(Qt::CustomContextMenu);
    //this->ui->tableWidget_WebScraper->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch);

    QObject::connect(this->ui->tableWidget_WebScraper, SIGNAL( OnRowsCopy(QModelIndexList) ), this, SLOT(tableWidget_WebScraper_OnRowsCopy(QModelIndexList)) );
    QObject::connect(this->ui->tableWidget_WebScraper, SIGNAL( OnTextPasted(QString) ), this, SLOT(tableWidget_WebScraper_OnTextPasted(QString)) );
    QObject::connect(this->ui->tableWidget_WebScraper->model(), SIGNAL( rowsInserted(const QModelIndex &, int, int) ), this, SLOT(tableWidget_WebScraper_OnRowsInserted(const QModelIndex &, int, int)) );
    QObject::connect(this->ui->tableWidget_WebScraper->model(), SIGNAL( rowsAboutToBeRemoved(const QModelIndex &, int, int) ), this, SLOT(tableWidget_WebScraper_OnRowsAboutToBeDeleted(const QModelIndex &, int, int)) );
    QObject::connect(this->ui->tableWidget_WebScraper->model(), SIGNAL( rowsRemoved(const QModelIndex &, int, int) ), this, SLOT(tableWidget_WebScraper_OnRowsDeleted(const QModelIndex &, int, int)) );
    QObject::connect(this->ui->tableWidget_WebScraper, SIGNAL( OnDoubleClickWithoutSelection() ), this, SLOT(tableWidget_WebScraper_OnDoubleClickWithoutSelection()) );
}

UiWeb::~UiWeb()
{
    GeoIP::DestroyInstance();
    delete this->WebScrapperEngine;
    delete ui;
}

QString UiWeb::WebScraper_getFullUrlFromTable(int row)
{
    QString protocol = ui->tableWidget_WebScraper->model()->index(row, 0).data().toString();
    QString domain = ui->tableWidget_WebScraper->model()->index(row, 1).data().toString();
    QString url = ui->tableWidget_WebScraper->model()->index(row, 2).data().toString();

    return (!protocol.isEmpty() ? protocol + "://" : "") + domain + (!url.isEmpty() ? url : "");
}

void UiWeb::tableWidget_WebScraper_OnDoubleClickWithoutSelection()
{
    // Add a new row if last one is not already empty or if table is empty
    if((this->ui->tableWidget_WebScraper->rowCount() == 0) || (!this->ui->tableWidget_WebScraper->item(this->ui->tableWidget_WebScraper->model()->rowCount() - 1,  0)->text().isEmpty() ))
    {
        int currentRow = this->ui->tableWidget_WebScraper->rowCount();

        this->ui->tableWidget_WebScraper->setRowCount(currentRow + 1);
        this->ui->tableWidget_WebScraper->setItem(currentRow, 0, new QTableWidgetItem(""));

        // Clear the other cols
        for( int i = 1; i < (this->ui->tableWidget_WebScraper->columnCount()); i++)
            this->ui->tableWidget_WebScraper->setItem(currentRow, i, new QTableWidgetItem(""));


        this->ui->tableWidget_WebScraper->setCurrentCell(currentRow,0);
        this->ui->tableWidget_WebScraper->setFocus();

        ui->tableWidget_WebScraper->edit(ui->tableWidget_WebScraper->currentIndex());

    }
}

void UiWeb::tableWidget_WebScraper_OnRowsCopy(const QModelIndexList& selectedRowsIndexesList)
{
    QString text;
    for (int i = 0; i < selectedRowsIndexesList.count(); i++)
    {
        text += this->WebScraper_getFullUrlFromTable(selectedRowsIndexesList.at(i).row());
        text += "\n";
    }
    QApplication::clipboard()->setText(text);
}

void UiWeb::tableWidget_WebScraper_OnTextPasted(const QString& text)
{
    auto urls = Utils_ExtractAllUrls(text);

    if( !urls.size() )
    {
        qDebug().noquote().nospace() << "Pasted " << text.length() << " but no URLs found. Have you included http(s) at the beginning?";
    }

    for(const QString &url_str: urls)
    {
        QUrl url(url_str);
        url.setQuery(url.query(QUrl::FullyDecoded), QUrl::DecodedMode);
        if (url.isValid())
        {
            //qDebug() << "Valid URL: " << url.scheme() << url.host() << url.path() << url.query() << url.fragment();
            const int currentRow = this->ui->tableWidget_WebScraper->rowCount();
            this->ui->tableWidget_WebScraper->setRowCount(currentRow + 1);
            this->ui->tableWidget_WebScraper->setItem(currentRow, 0, new QTableWidgetItem(url.scheme()));
            this->ui->tableWidget_WebScraper->setItem(currentRow, 1, new QTableWidgetItem(url.host()));
            // Set tld icon if any
            if( url.host().contains(".") )
            {
                QString tld =  url.host().split(".").last();
                QString resPath = ":/img/flags/" + tld + ".svg";
                if( QFile::exists(resPath) )
                {
                    this->ui->tableWidget_WebScraper->item(currentRow, 1)->setIcon(QIcon(resPath));
                }
            }
            this->ui->tableWidget_WebScraper->setItem(currentRow, 2, new QTableWidgetItem(url_str.split(url.host())[1]));
            this->ui->tableWidget_WebScraper->setItem(currentRow, 3, new QTableWidgetItem(""));
            this->ui->tableWidget_WebScraper->setItem(currentRow, 4, new QTableWidgetItem(""));
            this->ui->tableWidget_WebScraper->setItem(currentRow, 5, new QTableWidgetItem(""));
        }
        else
        {
            qDebug() << "Invalid URL detected: " << url_str;
        }
    }
}

void UiWeb::tableWidget_WebScraper_OnRowsInserted(const QModelIndex &parent, int first, int last)
{
    for( int i = first; i <= last; i++ )
    {
        this->WebScraperResponseHeaders[this->WebScraper_getFullUrlFromTable(i)] = "";
        this->WebScraperResponseData[this->WebScraper_getFullUrlFromTable(i)] = "";
    }

    // Update rows count
    this->ui->label_WebScraper_RecordsCount->setText("Records count: " + QString::number(this->ui->tableWidget_WebScraper->rowCount()));
}

void UiWeb::tableWidget_WebScraper_OnRowsAboutToBeDeleted(const QModelIndex &parent, int first, int last)
{
    for( int i = first; i <= last; i++ )
    {
        this->WebScraperResponseHeaders.remove(this->WebScraper_getFullUrlFromTable(i));
        this->WebScraperResponseData.remove(this->WebScraper_getFullUrlFromTable(i));
    }
}

void UiWeb::tableWidget_WebScraper_OnRowsDeleted(const QModelIndex &parent, int first, int last)
{
    // Update rows count
    this->ui->label_WebScraper_RecordsCount->setText("Records count: " + QString::number(this->ui->tableWidget_WebScraper->rowCount()));
}

void UiWeb::webScraper_OnRequestStarted(const QString &requestId, const QString &requestUrl)
{
    //dbgln << "[HTTP GET START] " << requestId << ". " << requestUrl;
    this->ui->tableWidget_WebScraper->item(requestId.toInt(), 5)->setIcon(QIcon(":/img/working.png"));
    this->ui->tableWidget_WebScraper->item(requestId.toInt(), 5)->setText("Working...");
}

void UiWeb::webScraper_OnRequestError(const QString &requestId, const QString &requestUrl, const HttpResponse &response)
{
    //dbgln << "[HTTP GET FAILED] [" << errorDescription << "] " << requestId << ". " << requestUrl;

    this->ui->tableWidget_WebScraper->item(requestId.toInt(), 5)->setText(response.AppErrorDetected?response.AppErrorDesc:response.NetworkErrorDescription);
    this->ui->tableWidget_WebScraper->item(requestId.toInt(), 5)->setIcon(QIcon(":/img/fail.png"));
    // Set host IP
    this->ui->tableWidget_WebScraper->item(requestId.toInt(), 3)->setText(response.HostIp);
    // Set IP organization
    this->ui->tableWidget_WebScraper->item(requestId.toInt(), 4)->setText( GeoIP::Instance()->IP2Org(response.HostIp.split(',')[0]) );
}

void UiWeb::webScraper_OnRequestFinished(const QString &requestId, const QString &requestUrl, const HttpResponse &response)
{
    //dbgln << "[HTTP GET SUCCEED] " << requestId << ". " << requestUrl << ": " << response.Code;
    if( response.Code == 200 )
    {
        this->ui->tableWidget_WebScraper->item(requestId.toInt(), 5)->setIcon(QIcon(":/img/success.png"));
    }
    else
    {
        this->ui->tableWidget_WebScraper->item(requestId.toInt(), 5)->setIcon(QIcon(":/img/warning.png"));
    }
    this->ui->tableWidget_WebScraper->item(requestId.toInt(), 5)->setText(QString::number(response.Code) + " - " + response.CodeDesc);

    // Set IP organization
    this->ui->tableWidget_WebScraper->item(requestId.toInt(), 4)->setText( GeoIP::Instance()->IP2Org(response.HostIp.split(',')[0]) );

    // Set host IP and show country flag of the host
    this->ui->tableWidget_WebScraper->item(requestId.toInt(), 3)->setText(response.HostIp);
    QString resPath = ":/img/flags/"+GeoIP::Instance()->IP2CountryISO(response.HostIp.split(',')[0]).toLower()+".svg";
    if( QFile::exists(resPath) )
    {
        this->ui->tableWidget_WebScraper->item(requestId.toInt(), 3)->setIcon(QIcon(resPath));
    }


    this->WebScraperResponseHeaders[WebScraper_getFullUrlFromTable(requestId.toInt())] = response.Headers;
    this->WebScraperResponseData[WebScraper_getFullUrlFromTable(requestId.toInt())] = response.Body;
}

void UiWeb::webScraper_OnAvailableWorkersChanged(int availableWorkers, int activeWorkers)
{
    this->ui->label_ActiveWorkers->setText("Active workers: " + QString::number(activeWorkers));
}

void UiWeb::on_pushButton_WebScraper_StopDownload_clicked()
{
    this->CancelRequests = true;
}

void UiWeb::on_pushButton_WebScraper_StartDownload_clicked()
{
    this->webScrapper_InitEngine();

    int rows = this->ui->tableWidget_WebScraper->model()->rowCount();

    // Set all statuses to PENDING and remove IPs
    for (int i = 0; i < rows; i++)
    {
        this->ui->tableWidget_WebScraper->item(i, 5)->setIcon(QIcon(":/img/pending.png"));
        this->ui->tableWidget_WebScraper->item(i, 5)->setText("Pending...");
        this->ui->tableWidget_WebScraper->item(i, 3)->setText("");
        this->ui->tableWidget_WebScraper->item(i, 3)->setIcon(QIcon());
        this->ui->tableWidget_WebScraper->item(i, 4)->setText("");
        this->ui->tableWidget_WebScraper->item(i, 4)->setIcon(QIcon());

    }

    this->CancelRequests = false;

    // Add record to queue to be executed by the threads in pool
    auto lam = [this, rows]()
    {
        int i = 0;
        while( i < rows )
        {
            QThread::msleep(5);
            if (this->CancelRequests)
                break;
            if (this->WebScrapperEngine->ThreadsPoolPtr()->AvailableThreads() <= 0)
                continue;
            this->WebScrapperEngine->EnqueueGetRequest(QString::number(i), this->WebScraper_getFullUrlFromTable(i));
            i++;
        }
    };

    // Start queing from a separate thread and feed as workers are available
    QFuture<void> future = QtConcurrent::run( lam);
}

void UiWeb::on_pushButton_WebScraping_Clear_clicked()
{
    this->CancelRequests = true;

    if( !this->WebScrapperEngine )
    {
        return;
    }

    if(this->WebScrapperEngine->ThreadsPoolPtr()->ActiveThreads() > 0 )
    {
        qDebug() << "Cannot clear while active threads: " << this->WebScrapperEngine->ThreadsPoolPtr()->ActiveThreads();
        return;
    }

    this->ui->tableWidget_WebScraper->model()->removeRows(0,  this->ui->tableWidget_WebScraper->rowCount());
    this->WebScraperResponseHeaders.clear();
    this->WebScraperResponseData.clear();
}

void UiWeb::on_tableWidget_WebScraper_customContextMenuRequested(const QPoint &pos)
{
    int row = ui->tableWidget_WebScraper->indexAt(pos).row();

    QMenu menu("contextMenu", this);
    QAction Item_ShowHeaders("Show headers", this);
    QAction Item_CopyResponse("Show response", this);
    QAction Item_Retest("Retest", this);
    QAction Item_WHOIS("WHOIS", this);

    if( row < 0 )
    {
        Item_ShowHeaders.setEnabled(false);
        Item_CopyResponse.setEnabled(false);
        Item_Retest.setEnabled(false);
    }
    else
    {
        QString rowUrl = this->WebScraper_getFullUrlFromTable(row);

        connect(&Item_ShowHeaders, &QAction::triggered, this, [rowUrl, this]()
        {
            QMessageBox msgBox;
            msgBox.setText("GET " + rowUrl + "\n");
            msgBox.setInformativeText(this->WebScraperResponseHeaders[rowUrl]);
            msgBox.setDefaultButton(QMessageBox::Ok);
            msgBox.setBaseSize(QSize(600, 120));
            msgBox.exec();
        });

        connect(&Item_CopyResponse, &QAction::triggered, this, [rowUrl, this]()
        {
            QString text = "GET " + rowUrl + "\n\n" + this->WebScraperResponseHeaders[rowUrl] + "\n\n" + this->WebScraperResponseData[rowUrl];

            QPlainTextEdit *editor = new QPlainTextEdit(text);
            editor->setWindowTitle("GET " + rowUrl);
            editor->setReadOnly(true);
            editor->setMinimumSize(QSize(800, 400));
            editor->show();
        });

        connect(&Item_Retest, &QAction::triggered, this, [this, row, rowUrl]()
        {
            this->webScrapper_InitEngine();
            this->WebScrapperEngine->EnqueueGetRequest(QString::number(row), rowUrl);
        });

        connect(&Item_WHOIS, &QAction::triggered, this, [this, row, rowUrl]()
        {
            QString domain = ui->tableWidget_WebScraper->model()->index(row, 1).data().toString();

            UiDomainWhois *whois = new UiDomainWhois(nullptr, domain);
            whois->setAttribute( Qt::WA_DeleteOnClose, true );
            whois->show();
            whois->TriggerWhois();
        });
    }

    menu.addAction(&Item_ShowHeaders);
    menu.addAction(&Item_CopyResponse);
    menu.addSeparator();
    menu.addAction(&Item_Retest);
    menu.addSeparator();
    menu.addAction(&Item_WHOIS);
    menu.exec(ui->tableWidget_WebScraper->viewport()->mapToGlobal(pos));
}

void UiWeb::on_pushButton_WebScraping_StretchCols_clicked()
{
    this->ui->tableWidget_WebScraper->resizeColumnsToContents();
    this->ui->tableWidget_WebScraper->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);

    //this->ui->tableWidget_WebScraper->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch);
}

void UiWeb::webScrapper_InitEngine()
{
    if( !this->WebScrapperEngine )
    {
        this->WebScrapperEngine = new WebScraper(25);
        connect(this->WebScrapperEngine, SIGNAL(OnRequestStarted(const QString &, const QString &)), this, SLOT(webScraper_OnRequestStarted(const QString &, const QString &)));
        connect(this->WebScrapperEngine, SIGNAL(OnRequestError(const QString &, const QString &, const HttpResponse &)), this, SLOT(webScraper_OnRequestError(const QString &, const QString &, const HttpResponse &)));
        connect(this->WebScrapperEngine, SIGNAL(OnRequestFinished(const QString &, const QString &, const HttpResponse &)), this, SLOT(webScraper_OnRequestFinished(const QString &, const QString &, const HttpResponse &)));
        connect(this->WebScrapperEngine, SIGNAL(AvailableWorkersChanged(int, int)), this, SLOT(webScraper_OnAvailableWorkersChanged(int, int)));
    }
}

