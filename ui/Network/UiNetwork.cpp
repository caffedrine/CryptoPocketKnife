#include "UiNetwork.h"
#include "ui_UiNetwork.h"

UiNetwork::UiNetwork(QWidget *parent): QWidget(parent), ui(new Ui::UiNetwork)
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
    QObject::connect(this->ui->pushButton_PortsScanner_ScanSettings, SIGNAL(clicked()), this, SLOT(PortsScanner_ScanSettings_pushButtonClicked()));
    QObject::connect(this->ui->pushButton_PortsScanner_StretchCols, SIGNAL(clicked()), this, SLOT(PortsScanner_StretchTable_pushButtonClicked()));
    QObject::connect(this->ui->pushButton_PortsScanner_Clear, SIGNAL(clicked()), this, SLOT(PortsScanner_ClearTable_pushButtonClicked()));
    QObject::connect(this->ui->pushButton_PortsScanner_ExportCSV, SIGNAL(clicked()), this, SLOT(PortsScanner_ExportTableCSV_pushButtonClicked()));
    QObject::connect(this->ui->pushButton_PortsScanner_ExportHTML, SIGNAL(clicked()), this, SLOT(PortsScanner_ExportTableHTML_pushButtonClicked()));

    ui->tableWidget_PortsScanner->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

UiNetwork::~UiNetwork()
{
    GeoIP::DestroyInstance();
    delete ui;
}

void UiNetwork::PortsScanner_ManageScanProfiles_pushButtonCLicked()
{
    UiPortsScanProfiles scanProfilesUi(nullptr);
    scanProfilesUi.setCurrentIndex(this->ui->comboBox_ScanProfiles->currentIndex());
    scanProfilesUi.exec();
}

void UiNetwork::PortsScanner_StartScan_pushButtonClicked()
{
    this->PortsScanner_InitEngine();

    // Read table rows
    int rows = this->ui->tableWidget_PortsScanner->model()->rowCount();

    // Table empty?
    if( rows == 0 )
    {
        Utils_Alert("Cannot start scanner", "No targets provided");
        return;
    }

    // Check if already running
    if( this->PortsScannerEngine->ThreadsPoolPtr()->ActiveThreads() > 0 )
    {
        Utils_Alert("Cannot start scanner", "Scanner already running");
        return;
    }

    Utils_PushButtonStartLoading(this->ui->pushButton_PortsScanner_Start);
    this->ui->pushButton_PortsScanner_Start->setText("Start 0/" + QString::number(rows));

    // Clear all columns except for host
    for (int i = 0; i < rows; i++)
    {
        for(  int j = 1; j < this->ui->tableWidget_PortsScanner->columnCount() - 1; j++)
        {
            this->ui->tableWidget_PortsScanner->item(i, j)->setText("");
            this->ui->tableWidget_PortsScanner->item(i, j)->setIcon(QIcon());
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
            if(this->PortsScannerEngine->IsScanRunning(this->ui->tableWidget_PortsScanner->item(i, 0)->text()))
                continue;
            this->PortsScannerEngine->EnqueueScan(this->ui->tableWidget_PortsScanner->item(i, 0)->text(), this->ui->comboBox_ScanProfiles->currentText());
            i++;

        }
    };

    // Start queuing from a separate thread and feed as workers are available
    QFuture<void> future = QtConcurrent::run( lam);
}

void UiNetwork::PortsScanner_StopScan_pushButtonClicked()
{
    // Check if already running
    if( (this->PortsScannerEngine == nullptr) || this->PortsScannerEngine->ThreadsPoolPtr()->ActiveThreads() == 0 )
    {
        Utils_Alert("Cannot stop scanner", "Already stopped!");
        return;
    }

    this->CancelRequests = true;
    this->PortsScannerEngine->RequestAllJobsStop();

    Utils_PushButtonEndLoading(this->ui->pushButton_PortsScanner_Start);
    Utils_PushButtonStartLoading(this->ui->pushButton_PortsScanner_Stop);
}

void UiNetwork::PortsScanner_ScanSettings_pushButtonClicked()
{
    qDebug() << "Scan settigns!";
}

void UiNetwork::PortsScanner_StretchTable_pushButtonClicked()
{
    this->ui->tableWidget_PortsScanner->resizeColumnsToContents();
    this->ui->tableWidget_PortsScanner->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);

}

void UiNetwork::PortsScanner_ClearTable_pushButtonClicked()
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

void UiNetwork::PortsScanner_InitEngine()
{
    if( !this->PortsScannerEngine )
    {
        this->PortsScannerEngine = new PortsScanner(50);
        connect(this->PortsScannerEngine, SIGNAL(OnRequestStarted(QString,PortsScanResult)), this, SLOT(PortsScanner_OnRequestStarted(QString,PortsScanResult)));
        connect(this->PortsScannerEngine, SIGNAL(OnRequestError(QString,PortsScanResult)), this, SLOT(PortsScanner_OnRequestError(QString,PortsScanResult)));
        connect(this->PortsScannerEngine, SIGNAL(OnRequestFinished(QString,PortsScanResult)), this, SLOT(PortsScanner_OnRequestFinished(QString,PortsScanResult)));
        connect(this->PortsScannerEngine, SIGNAL(OnProcessProgress(QString,PortsScanResult)), this, SLOT(PortsScanner_OnProcessProgress(QString,PortsScanResult)));
        connect(this->PortsScannerEngine, SIGNAL(AvailableWorkersChanged(int,int)), this, SLOT(PortsScanner_OnAvailableWorkersChanged(int,int)));
    }
}

void UiNetwork::PortsScanner_OnRequestStarted(const QString &host, const PortsScanResult &result)
{
    int hostIndex = this->PortsScanner_GetRowIndexByHost(host);
    this->PortsScanResults[host] = result;
    this->ui->tableWidget_PortsScanner->item(hostIndex, this->ui->tableWidget_PortsScanner->columnCount() - 1)->setIcon(QIcon(":/img/working.png"));
    this->ui->tableWidget_PortsScanner->item(hostIndex, this->ui->tableWidget_PortsScanner->columnCount() - 1)->setText("Working...");
}

void UiNetwork::PortsScanner_OnRequestError(const QString &host, const PortsScanResult &result)
{
    int hostIndex = this->PortsScanner_GetRowIndexByHost(host);
    this->PortsScanResults[host] = result;
    this->ui->tableWidget_PortsScanner->item(hostIndex, this->ui->tableWidget_PortsScanner->columnCount() - 1)->setText(result.AppErrorDetected?result.AppErrorDesc:result.NetworkErrorDescription);
    this->ui->tableWidget_PortsScanner->item(hostIndex, this->ui->tableWidget_PortsScanner->columnCount() - 1)->setIcon(QIcon(":/img/fail.png"));

    this->ui->tableWidget_PortsScanner->item(hostIndex, 1)->setText(this->PortsScanResults[host].HostIp);
    this->ui->tableWidget_PortsScanner->item(hostIndex, 2)->setText(this->PortsScanResults[host].HostRdns);
    this->ui->tableWidget_PortsScanner->item(hostIndex, 3)->setText(QDateTime::fromSecsSinceEpoch(this->PortsScanResults[host].StartScanTimestamp).toString("yyyy-MM-dd hh:mm:ss"));
    this->ui->tableWidget_PortsScanner->item(hostIndex, 4)->setText(QTime(0,0,0,0).addSecs(this->PortsScanResults[host].ScanDurationSeconds).toString("hh:mm:ss"));
}

void UiNetwork::PortsScanner_OnProcessProgress(const QString &host, const PortsScanResult &result)
{
    int hostIndex = this->PortsScanner_GetRowIndexByHost(host);
    this->PortsScanResults[host] = result;
    this->PortsScanner_ShowScanResults(hostIndex, host, true);

    // Update country flag on IP if nto already done
    if( !result.HostIp.isEmpty() && this->ui->tableWidget_PortsScanner->item(hostIndex, 1)->icon().isNull())
    {
        QString resPath = ":/img/flags/" + GeoIP::Instance()->IP2CountryISO(result.HostIp).toLower() + ".svg";
        if( QFile::exists(resPath) )
        {
            this->ui->tableWidget_PortsScanner->item(hostIndex, 1)->setIcon(QIcon(resPath));
        }
    }
}

void UiNetwork::PortsScanner_OnRequestFinished(const QString &host, const PortsScanResult &result)
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

    //this->ui->pushButton_PortsScanner_Start->setText("Start " + QString::number(this->PortsScanResults.count()) + "/" + QString::number(rows));
}

void UiNetwork::PortsScanner_ShowScanResults(int tableHostIndex, const QString &host, bool ScanInProgress)
{
    QStringList tcpPorts = this->PortsScanResults[host].OpenTcpPorts;
    tcpPorts.removeDuplicates();
    Utils_NumericListSort(&tcpPorts);


    QStringList udpPorts = this->PortsScanResults[host].OpenUdpPorts;
    udpPorts.removeDuplicates();
    Utils_NumericListSort(&udpPorts);

    // Start filling data into table
    int i = 1;
    this->ui->tableWidget_PortsScanner->item(tableHostIndex, i++)->setText(this->PortsScanResults[host].HostIp);
    this->ui->tableWidget_PortsScanner->item(tableHostIndex, i++)->setText(this->PortsScanResults[host].HostRdns);
    this->ui->tableWidget_PortsScanner->item(tableHostIndex, i++)->setText(QDateTime::fromSecsSinceEpoch(this->PortsScanResults[host].StartScanTimestamp).toString("yyyy-MM-dd hh:mm:ss"));
    this->ui->tableWidget_PortsScanner->item(tableHostIndex, i++)->setText(!ScanInProgress?QTime(0,0,0,0).addSecs(this->PortsScanResults[host].ScanDurationSeconds).toString("hh:mm:ss"):"");
    this->ui->tableWidget_PortsScanner->item(tableHostIndex, i++)->setText(this->PortsScanResults[host].PingState + (this->PortsScanResults[host].PingState == "UP" ? " (" + Utils_FloatWithDigitsPrecision(this->PortsScanResults[host].PingLatencySeconds, 2) + "s)" : ""));
    this->ui->tableWidget_PortsScanner->item(tableHostIndex, i++)->setText(tcpPorts.join(","));
    this->ui->tableWidget_PortsScanner->item(tableHostIndex, i++)->setText(udpPorts.join(","));
}

void UiNetwork::PortsScanner_OnAvailableWorkersChanged(int availableWorkers, int activeWorkers)
{
    this->ui->label_PortsScanner_ActiveWorkers->setText("Active workers: " + QString::number(activeWorkers));

    // Destroy IP lookup database instance to reduce RAM usage
    if( activeWorkers == 0 )
    {
        GeoIP::DestroyInstance();
    }

    if( activeWorkers == 0 )
    {
        Utils_PushButtonEndLoading(this->ui->pushButton_PortsScanner_Start);
        Utils_PushButtonEndLoading(this->ui->pushButton_PortsScanner_Stop);
    }
}

int  UiNetwork::PortsScanner_GetRowIndexByHost(const QString &host)
{
    int rows = this->ui->tableWidget_PortsScanner->model()->rowCount();

    for (int i = 0; i < rows; i++)
    {
        if (this->ui->tableWidget_PortsScanner->item(i, 0)->text() == host)
            return i;
    }
    return -1;
}

void UiNetwork::PortsScanner_tableWidget_OnDoubleClickWithoutSelection()
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

void UiNetwork::PortsScanner_tableWidget_OnRowsAboutToBeDeleted(const QModelIndex &parent, int first, int last)
{
    for( int i = first; i <= last; i++ )
    {
        this->PortsScanResults.remove(this->ui->tableWidget_PortsScanner->item(i, 0)->text());
    }
}

void UiNetwork::PortsScanner_tableWidget_OnRowsDeleted(const QModelIndex &parent, int first, int last)
{
    this->ui->label_PortScanner_RecordsCount->setText("Records count: " + QString::number(this->ui->tableWidget_PortsScanner->rowCount()));
}

void UiNetwork::PortsScanner_tableWidget_OnRowsInserted(const QModelIndex &parent, int first, int last)
{
    // Update rows count
    this->ui->label_PortScanner_RecordsCount->setText("Records count: " + QString::number(this->ui->tableWidget_PortsScanner->rowCount()));
}

void UiNetwork::PortsScanner_tableWidget_OnTextPasted(const QString &text)
{
    QStringList hosts = Utils_ExtractAllHosts(text);
    hosts.removeDuplicates();

    for(const QString &host: hosts)
    {
        if(host.isEmpty())
            continue;

        int currentRow = this->ui->tableWidget_PortsScanner->rowCount();

        this->ui->tableWidget_PortsScanner->setRowCount(currentRow + 1);
        this->ui->tableWidget_PortsScanner->setItem(currentRow, 0, new QTableWidgetItem(host));

        // Clear the other cols
        for(int i = 1; i < (this->ui->tableWidget_PortsScanner->columnCount()); i++)
            this->ui->tableWidget_PortsScanner->setItem(currentRow, i, new QTableWidgetItem(""));
    }
}

void UiNetwork::PortsScanner_tableWidget_OnRowsCopy(const QModelIndexList &selectedRows)
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

void UiNetwork::PortsScanner_tableWidget_customContextMenuRequested(const QPoint &pos)
{
    int row = ui->tableWidget_PortsScanner->indexAt(pos).row();

    QMenu menu("contextMenu", this);
    QAction Item_ViewReport("View report", this);
    QAction Item_ShowPingResult("Show ping result", this);
    QAction Item_ShowResult("Show raw scan results", this);
    QAction Item_Retest("Retest", this);

    if( row < 0 )
    {
        Item_ViewReport.setEnabled(false);
        Item_ShowPingResult.setEnabled(false);
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

        connect(&Item_ShowPingResult, &QAction::triggered, this, [host, this]()
        {
            QString text = this->PortsScanResults[host].PingOutput;

            QPlainTextEdit *editor = new QPlainTextEdit(text);
            editor->setWindowTitle("Ping scan result for " + host);
            editor->setBaseSize(QSize(800, 400));
            editor->show();
        });

        connect(&Item_ShowResult, &QAction::triggered, this, [host, this]()
        {
            QString text = this->PortsScanResults[host].TargetsOutputs.join("\n\n-----\n\n");

            QPlainTextEdit *editor = new QPlainTextEdit(text);
            editor->setWindowTitle("Scan results for " + host + ", profile " + this->PortsScanResults[host].ScanProfile);
            editor->setReadOnly(true);
            editor->setMinimumSize(QSize(800, 400));
            editor->show();
        });

        connect(&Item_Retest, &QAction::triggered, this, [this, row, host]()
        {
            this->PortsScanner_InitEngine();
            Utils_PushButtonStartLoading(this->ui->pushButton_PortsScanner_Start);
            for (int i = 1; i < this->ui->tableWidget_PortsScanner->columnCount() - 1; i++)
            {
                this->ui->tableWidget_PortsScanner->item(row, i)->setText("");
                this->ui->tableWidget_PortsScanner->item(row, i)->setIcon(QIcon());
            }

            if( this->PortsScannerEngine->IsScanRunning(host) )
            {
                Utils_Alert("Cannot start scan", "Selected host is already being scanned");
            }
            else
            {
                this->PortsScannerEngine->EnqueueScan(host, this->ui->comboBox_ScanProfiles->currentText());
            }
        });
    }

    menu.addAction(&Item_ViewReport);
    menu.addAction(&Item_ShowPingResult);
    menu.addAction(&Item_ShowResult);
    menu.addSeparator();
    menu.addAction(&Item_Retest);
    menu.exec(ui->tableWidget_PortsScanner->viewport()->mapToGlobal(pos));
}

void UiNetwork::PortsScanner_ExportTableHTML_pushButtonClicked()
{
    qDebug() << "Export HTML...";
}

void UiNetwork::PortsScanner_ExportTableCSV_pushButtonClicked()
{
    // Select location to save
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save results to file"),
                                                    "scan_results_" + QDateTime::currentDateTime().toString("yyyy-MM-dd_hh-mm-ss") + ".csv",
                                                    tr("Text format (*.txt);;Comma-separated Values (*.csv)"));
    if( fileName.isEmpty() )
        return;

    this->ui->tableWidget_PortsScanner->ExportAsCSV(fileName);
}





