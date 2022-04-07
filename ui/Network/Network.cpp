#include "Network.h"
#include "ui_Network.h"

Network::Network(QWidget *parent): QWidget(parent), ui(new Ui::Network)
{
    ui->setupUi(this);

    QList<PortsScanProfileType> allProfiles = PortsScanProfilesManager::instance().GetAll();
    for(const PortsScanProfileType &profile: allProfiles)
    {
        ui->comboBox_ScanProfiles->addItem(profile.ProfileName);
    }

    this->ui->tableWidget_PortsScanner->setContextMenuPolicy(Qt::CustomContextMenu);
    QObject::connect(this->ui->tableWidget_PortsScanner, SIGNAL( OnRowsCopy(QModelIndexList) ), this, SLOT(PortsScanner_tableWidget_OnRowsCopy(QModelIndexList)) );
    QObject::connect(this->ui->tableWidget_PortsScanner, SIGNAL( OnTextPasted(QString) ), this, SLOT(PortsScanner_tableWidget_OnTextPasted(QString)) );
    QObject::connect(this->ui->tableWidget_PortsScanner->model(), SIGNAL( rowsInserted(QModelIndex,int,int) ), this, SLOT(PortsScanner_tableWidget_OnRowsInserted(QModelIndex,int,int)) );
    QObject::connect(this->ui->tableWidget_PortsScanner->model(), SIGNAL( rowsAboutToBeRemoved(QModelIndex,int,int) ), this, SLOT(PortsScanner_tableWidget_OnRowsAboutToBeDeleted(QModelIndex,int,int)) );
    QObject::connect(this->ui->tableWidget_PortsScanner->model(), SIGNAL( rowsRemoved(QModelIndex,int,int) ), this, SLOT(PortsScanner_tableWidget_OnRowsDeleted(QModelIndex,int,int)) );
    QObject::connect(this->ui->tableWidget_PortsScanner, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(PortsScanner_tableWidget_customContextMenuRequested(QPoint)));
    QObject::connect(this->ui->tableWidget_PortsScanner, SIGNAL(OnDoubleClickWithoutSelection()), this, SLOT(PortsScanner_tableWidget_OnDoubleClickWithoutSelection()));

    QObject::connect(this->ui->pushButton_ManageProfiles, SIGNAL(clicked()), this, SLOT(PortsScanner_ManageScanProfiles_pushButtonCLicked()));
    QObject::connect(this->ui->pushButton_PortsScanner_Start, SIGNAL(clicked()), this, SLOT(PortsScanner_StartScan_pushButtonClicked()));
    QObject::connect(this->ui->pushButton_PortsScanner_Stop, SIGNAL(clicked()), this, SLOT(PortsScanner_StopScan_pushButtonClicked()));
    QObject::connect(this->ui->pushButton_PortsScanner_StretchCols, SIGNAL(clicked()), this, SLOT(PortsScanner_StretchTable_pushButtonClicked()));
    QObject::connect(this->ui->pushButton_PortsScanner_Clear, SIGNAL(clicked()), this, SLOT(PortsScanner_ClearTable_pushButtonClicked()));
    QObject::connect(this->ui->pushButton_PortsScanner_Export, SIGNAL(clicked()), this, SLOT(PortsScanner_ExportTable_pushButtonClicked()));

}

Network::~Network()
{
    delete ui;
}

void Network::PortsScanner_ManageScanProfiles_pushButtonCLicked()
{
    PortsScanProfiles scanProfilesUi(nullptr);
    scanProfilesUi.setCurrentIndex(this->ui->comboBox_ScanProfiles->currentIndex());
    scanProfilesUi.exec();
}

void Network::PortsScanner_StartScan_pushButtonClicked()
{
    this->PortsScanner_InitEngine();

    int rows = this->ui->tableWidget_PortsScanner->model()->rowCount();

    // Clear all columns except for host
    for (int i = 0; i < rows; i++)
    {
        for(  int j = 1; j < this->ui->tableWidget_PortsScanner->columnCount() - 1; j++)
        {
            this->ui->tableWidget_PortsScanner->item(i, j)->setText("");
        }
    }

    // Set all statuses to PENDING
    for (int i = 0; i < rows; i++)
    {
        this->ui->tableWidget_PortsScanner->item(i, this->ui->tableWidget_PortsScanner->columnCount() - 1)->setIcon(QIcon(":/img/pending.png"));
        this->ui->tableWidget_PortsScanner->item(i, this->ui->tableWidget_PortsScanner->columnCount() - 1)->setText("Pending...");
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
            if (this->PortsScannerEngine->ThreadsPoolPtr()->AvailableThreads() <= 0)
                continue;
            this->PortsScannerEngine->EnqueueScan(this->ui->tableWidget_PortsScanner->item(i, 0)->text(), this->ui->comboBox_ScanProfiles->currentText());
            i++;
        }
    };

    // Start queing from a separate thread and feed as workers are available
    QFuture<void> future = QtConcurrent::run( lam);
}

void Network::PortsScanner_StopScan_pushButtonClicked()
{
    this->CancelRequests = true;
}

void Network::PortsScanner_StretchTable_pushButtonClicked()
{
    this->ui->tableWidget_PortsScanner->resizeColumnsToContents();
    this->ui->tableWidget_PortsScanner->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);

}

void Network::PortsScanner_ClearTable_pushButtonClicked()
{
    this->CancelRequests = true;

    if(this->PortsScannerEngine && this->PortsScannerEngine->ThreadsPoolPtr()->ActiveThreads() > 0 )
    {
        qDebug() << "Cannot clear while active threads: " << this->PortsScannerEngine->ThreadsPoolPtr()->ActiveThreads();
        return;
    }

    this->ui->tableWidget_PortsScanner->model()->removeRows(0,  this->ui->tableWidget_PortsScanner->rowCount());
    this->PortsScanResults.clear();
}

void Network::PortsScanner_ExportTable_pushButtonClicked()
{
    dbgln << "Export to be done...";
}

void Network::PortsScanner_InitEngine()
{
    if( !this->PortsScannerEngine )
    {
        this->PortsScannerEngine = new PortsScanner(25);
        connect(this->PortsScannerEngine, SIGNAL(OnRequestStarted(QString,PortsScanResult)), this, SLOT(PortsScanner_OnRequestStarted(QString,PortsScanResult)));
        connect(this->PortsScannerEngine, SIGNAL(OnRequestError(QString,PortsScanResult)), this, SLOT(PortsScanner_OnRequestError(QString,PortsScanResult)));
        connect(this->PortsScannerEngine, SIGNAL(OnRequestFinished(QString,PortsScanResult)), this, SLOT(PortsScanner_OnRequestFinished(QString,PortsScanResult)));
        connect(this->PortsScannerEngine, SIGNAL(OnProcessProgress(QString,PortsScanResult)), this, SLOT(PortsScanner_OnProcessProgress(QString,PortsScanResult)));
        connect(this->PortsScannerEngine, SIGNAL(AvailableWorkersChanged(int,int)), this, SLOT(PortsScanner_OnAvailableWorkersChanged(int,int)));
    }
}

void Network::PortsScanner_OnRequestStarted(const QString &host, const PortsScanResult &result)
{
    int hostIndex = this->PortsScanner_GetRowIndexByHost(host);
    this->PortsScanResults[host] = result;
    this->ui->tableWidget_PortsScanner->item(hostIndex, this->ui->tableWidget_PortsScanner->columnCount() - 1)->setIcon(QIcon(":/img/working.png"));
    this->ui->tableWidget_PortsScanner->item(hostIndex, this->ui->tableWidget_PortsScanner->columnCount() - 1)->setText("Working...");
}

void Network::PortsScanner_OnRequestError(const QString &host, const PortsScanResult &result)
{
    int hostIndex = this->PortsScanner_GetRowIndexByHost(host);
    this->PortsScanResults[host] = result;
    this->ui->tableWidget_PortsScanner->item(hostIndex, this->ui->tableWidget_PortsScanner->columnCount() - 1)->setText(result.AppErrorDetected?result.AppErrorDesc:result.NetworkErrorDescription);
    this->ui->tableWidget_PortsScanner->item(hostIndex, this->ui->tableWidget_PortsScanner->columnCount() - 1)->setIcon(QIcon(":/img/fail.png"));
}

void Network::PortsScanner_OnProcessProgress(const QString &host, const PortsScanResult &result)
{
    int hostIndex = this->PortsScanner_GetRowIndexByHost(host);
    this->PortsScanResults[host] = result;
    this->PortsScanner_ShowScanResults(hostIndex, host, true);
}

void Network::PortsScanner_OnRequestFinished(const QString &host, const PortsScanResult &result)
{
    int hostIndex = this->PortsScanner_GetRowIndexByHost(host);
    this->PortsScanResults[host] = result;

    if(result.AppErrorDetected || result.NetworkErrorDetected)
    {
        this->ui->tableWidget_PortsScanner->item(hostIndex, this->ui->tableWidget_PortsScanner->columnCount() - 1)->setText("ERR: " + (result.AppErrorDetected?result.AppErrorDesc:result.NetworkErrorDescription));
        this->ui->tableWidget_PortsScanner->item(hostIndex, this->ui->tableWidget_PortsScanner->columnCount() - 1)->setIcon(QIcon(":/img/fail.png"));
    }
    else
    {
        this->ui->tableWidget_PortsScanner->item(hostIndex, this->ui->tableWidget_PortsScanner->columnCount() - 1)->setText("Succeed");
        this->ui->tableWidget_PortsScanner->item(hostIndex, this->ui->tableWidget_PortsScanner->columnCount() - 1)->setIcon(QIcon(":/img/success.png"));
    }

    this->PortsScanner_ShowScanResults(hostIndex, host, false);
}

void Network::PortsScanner_OnAvailableWorkersChanged(int availableWorkers, int activeWorkers)
{
    this->ui->label_PortsScanner_ActiveWorkers->setText("Active workers: " + QString::number(activeWorkers));
}

int  Network::PortsScanner_GetRowIndexByHost(const QString &host)
{
    int rows = this->ui->tableWidget_PortsScanner->model()->rowCount();

    for (int i = 0; i < rows; i++)
    {
        if (this->ui->tableWidget_PortsScanner->item(i, 0)->text() == host)
            return i;
    }
    return -1;
}

void Network::PortsScanner_tableWidget_OnDoubleClickWithoutSelection()
{
    // Add a new row if last one is not already empty or if table is empty
    if((this->ui->tableWidget_PortsScanner->rowCount() == 0) || (!this->ui->tableWidget_PortsScanner->item(this->ui->tableWidget_PortsScanner->model()->rowCount() - 1,  0)->text().isEmpty() ))
    {
        int currentRow = this->ui->tableWidget_PortsScanner->rowCount();

        this->ui->tableWidget_PortsScanner->setRowCount(currentRow + 1);
        this->ui->tableWidget_PortsScanner->setItem(currentRow, 0, new QTableWidgetItem(""));

        // Clear the other cols
        for( int i = 1; i < (this->ui->tableWidget_PortsScanner->columnCount()); i++)
            this->ui->tableWidget_PortsScanner->setItem(currentRow, i, new QTableWidgetItem(""));


        this->ui->tableWidget_PortsScanner->setCurrentCell(currentRow,0);
        this->ui->tableWidget_PortsScanner->setFocus();

        ui->tableWidget_PortsScanner->edit(ui->tableWidget_PortsScanner->currentIndex());

    }
}

void Network::PortsScanner_tableWidget_OnRowsAboutToBeDeleted(const QModelIndex &parent, int first, int last)
{
    for( int i = first; i <= last; i++ )
    {
        this->PortsScanResults.remove(this->ui->tableWidget_PortsScanner->item(i, 0)->text());
    }
}

void Network::PortsScanner_tableWidget_OnRowsDeleted(const QModelIndex &parent, int first, int last)
{
    this->ui->label_PortScanner_RecordsCount->setText("Records count: " + QString::number(this->ui->tableWidget_PortsScanner->rowCount()));
}

void Network::PortsScanner_tableWidget_OnRowsInserted(const QModelIndex &parent, int first, int last)
{
    // Update rows count
    this->ui->label_PortScanner_RecordsCount->setText("Records count: " + QString::number(this->ui->tableWidget_PortsScanner->rowCount()));
}

void Network::PortsScanner_tableWidget_OnTextPasted(const QString &text)
{
    QStringList hosts = Utils_ExtractAllHosts(text);

    foreach(const QString &host, hosts)
        {
            int currentRow = this->ui->tableWidget_PortsScanner->rowCount();

            this->ui->tableWidget_PortsScanner->setRowCount(currentRow + 1);
            this->ui->tableWidget_PortsScanner->setItem(currentRow, 0, new QTableWidgetItem(host));

            // Clear the other cols
            for( int i = 1; i < (this->ui->tableWidget_PortsScanner->columnCount()); i++)
                this->ui->tableWidget_PortsScanner->setItem(currentRow, i, new QTableWidgetItem(""));
        }
}

void Network::PortsScanner_tableWidget_OnRowsCopy(const QModelIndexList &selectedRows)
{
    QString text;
    for (int i = 0; i < selectedRows.count(); i++)
    {
        for( int j = 0; j < this->ui->tableWidget_PortsScanner->columnCount(); j++)
            text += this->ui->tableWidget_PortsScanner->item(i, 0)->text() + ";";

        if( !text.isEmpty() )
        {
            text.chop(1);
        }

        text += "\n";
    }
    QApplication::clipboard()->setText(text);
}

void Network::PortsScanner_tableWidget_customContextMenuRequested(const QPoint &pos)
{
    int row = ui->tableWidget_PortsScanner->indexAt(pos).row();

    QMenu menu("contextMenu", this);
    QAction Item_ViewReport("View report", this);
    QAction Item_ShowResult("Show raw result", this);
    QAction Item_Retest("Retest", this);

    if( row < 0 )
    {
        Item_ViewReport.setEnabled(false);
        Item_ShowResult.setEnabled(false);
        Item_Retest.setEnabled(false);
    }
    else
    {
        QString host = this->ui->tableWidget_PortsScanner->item(row, 0)->text();
        connect(&Item_ViewReport, &QAction::triggered, this, [host, this]()
        {
            qDebug() << "Trigger report viewer!";
        });


        connect(&Item_ShowResult, &QAction::triggered, this, [host, this]()
        {
            QString text = this->PortsScanResults[host].TargetsOutputs.join("\n\n-----\n\n");

            QPlainTextEdit *editor = new QPlainTextEdit(text);
            editor->setWindowTitle("Scan results for " + host + ", profile " + this->PortsScanResults[host].ScanProfile);
            editor->setBaseSize(QSize(600, 120));
            editor->show();
        });

        connect(&Item_Retest, &QAction::triggered, this, [this, row, host]()
        {
            this->PortsScanner_InitEngine();
            for (int i = 1; i < this->ui->tableWidget_PortsScanner->columnCount() - 1; i++)
                this->ui->tableWidget_PortsScanner->item(row, i)->setText("");
            this->PortsScannerEngine->EnqueueScan(host, this->ui->comboBox_ScanProfiles->currentText());
        });
    }

    menu.addAction(&Item_ViewReport);
    menu.addAction(&Item_ShowResult);
    menu.addSeparator();
    menu.addAction(&Item_Retest);
    menu.exec(ui->tableWidget_PortsScanner->viewport()->mapToGlobal(pos));
}

void Network::PortsScanner_ShowScanResults(int tableHostIndex, const QString &host, bool ScanInProgress)
{
    // Start filling data into table
    int i = 1;
    this->ui->tableWidget_PortsScanner->item(tableHostIndex, i++)->setText(this->PortsScanResults[host].HostIp);
    this->ui->tableWidget_PortsScanner->item(tableHostIndex, i++)->setText(this->PortsScanResults[host].HostRdns);
    this->ui->tableWidget_PortsScanner->item(tableHostIndex, i++)->setText(QDateTime::fromSecsSinceEpoch(this->PortsScanResults[host].StartScanTimestamp).toString("yyyy-MM-dd hh:mm:ss"));
    this->ui->tableWidget_PortsScanner->item(tableHostIndex, i++)->setText(!ScanInProgress?QTime(0,0,0,0).addSecs(this->PortsScanResults[host].ScanDurationSeconds).toString("hh:mm:ss"):"");
    this->ui->tableWidget_PortsScanner->item(tableHostIndex, i++)->setText(this->PortsScanResults[host].Availability);
    this->ui->tableWidget_PortsScanner->item(tableHostIndex, i++)->setText(this->PortsScanResults[host].OpenTcpPorts.join(","));
    this->ui->tableWidget_PortsScanner->item(tableHostIndex, i++)->setText(this->PortsScanResults[host].OpenUdpPorts.join(","));
}





