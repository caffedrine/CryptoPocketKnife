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
//    QObject::connect(this->ui->tableWidget_PortsScanner, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(PortsScanner_tableWidget_customContextMenuRequested(QPoint)));
    QObject::connect(this->ui->tableWidget_PortsScanner, SIGNAL( OnRowsCopy(QModelIndexList) ), this, SLOT(PortsScanner_tableWidget_OnRowsCopy(QModelIndexList)) );
    QObject::connect(this->ui->tableWidget_PortsScanner, SIGNAL( OnTextPasted(QString) ), this, SLOT(PortsScanner_tableWidget_OnTextPasted(QString)) );
    QObject::connect(this->ui->tableWidget_PortsScanner->model(), SIGNAL( rowsInserted(const QModelIndex &, int, int) ), this, SLOT(PortsScanner_tableWidget_OnRowsInserted(const QModelIndex &, int, int)) );
    QObject::connect(this->ui->tableWidget_PortsScanner->model(), SIGNAL( rowsAboutToBeRemoved(const QModelIndex &, int, int) ), this, SLOT(PortsScanner_tableWidget_OnRowsAboutToBeDeleted(const QModelIndex &, int, int)) );
    QObject::connect(this->ui->tableWidget_PortsScanner->model(), SIGNAL( rowsRemoved(const QModelIndex &, int, int) ), this, SLOT(PortsScanner_tableWidget_OnRowsDeleted(const QModelIndex &, int, int)) );
}

Network::~Network()
{
    delete ui;
}

void Network::PortsScanner_ManageScanProfiles_pushButtonCLicked()
{
    PortsScanProfiles scanProfilesUi(nullptr);
    scanProfilesUi.exec();
}

void Network::PortsScanner_StartScan_pushButtonClocked()
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

void Network::PortsScanner_StopScan_pushButtonClocked()
{
    this->CancelRequests = true;
}

void Network::PortsScanner_StretchTable_pushButtonClocked()
{
    this->ui->tableWidget_PortsScanner->resizeColumnsToContents();
    this->ui->tableWidget_PortsScanner->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);

}

void Network::PortsScanner_ClearTable_pushButtonClocked()
{
    this->CancelRequests = true;

    if( !this->PortsScannerEngine )
    {
        return;
    }

    if(this->PortsScannerEngine->ThreadsPoolPtr()->ActiveThreads() > 0 )
    {
        qDebug() << "Cannot clear while active threads: " << this->PortsScannerEngine->ThreadsPoolPtr()->ActiveThreads();
        return;
    }

    this->ui->tableWidget_PortsScanner->model()->removeRows(0,  this->ui->tableWidget_PortsScanner->rowCount());
    this->PortsScanResults.clear();
}

void Network::PortsScanner_InitEngine()
{
    if( !this->PortsScannerEngine )
    {
        this->PortsScannerEngine = new PortsScanner(25);
        connect(this->PortsScannerEngine, SIGNAL(OnRequestStarted(const QString &, const QString &)), this, SLOT(PortsScanner_OnRequestStarted(const QString &)));
        connect(this->PortsScannerEngine, SIGNAL(OnRequestError(const QString &, const QString &, const HttpResponse &)), this, SLOT(PortsScanner_OnRequestError(const QString &, const PortsScanResult &)));
        connect(this->PortsScannerEngine, SIGNAL(OnRequestFinished(const QString &, const QString &, const HttpResponse &)), this, SLOT(PortsScanner_OnRequestFinished(const QString &, const PortsScanResult &)));
        connect(this->PortsScannerEngine, SIGNAL(AvailableWorkersChanged(int, int)), this, SLOT(PortsScanner_OnAvailableWorkersChanged(int, int)));
    }
}

void Network::PortsScanner_OnRequestStarted(const QString &host)
{
    int hostIndex = this->PortsScanner_GetRowIndexByHost(host);
    this->PortsScanResults[host] = "";
    this->ui->tableWidget_PortsScanner->item(hostIndex, this->ui->tableWidget_PortsScanner->columnCount() - 1)->setIcon(QIcon(":/img/working.png"));
    this->ui->tableWidget_PortsScanner->item(hostIndex, this->ui->tableWidget_PortsScanner->columnCount() - 1)->setText("Working...");
}

void Network::PortsScanner_OnRequestError(const QString &host, PortsScanResult result)
{
    int hostIndex = this->PortsScanner_GetRowIndexByHost(host);
    this->ui->tableWidget_PortsScanner->item(hostIndex, this->ui->tableWidget_PortsScanner->columnCount() - 1)->setText(result.AppErrorDetected?result.AppErrorDesc:result.NetworkErrorDescription);
    this->ui->tableWidget_PortsScanner->item(hostIndex, this->ui->tableWidget_PortsScanner->columnCount() - 1)->setIcon(QIcon(":/img/fail.png"));
}

void Network::PortsScanner_OnRequestFinished(const QString &host, PortsScanResult result)
{
    int hostIndex = this->PortsScanner_GetRowIndexByHost(host);

    this->ui->tableWidget_PortsScanner->item(hostIndex, this->ui->tableWidget_PortsScanner->columnCount() - 1)->setText("Succeed");
    this->ui->tableWidget_PortsScanner->item(hostIndex, this->ui->tableWidget_PortsScanner->columnCount() - 1)->setIcon(QIcon(":/img/success.png"));
}

void Network::PortsScanner_OnAvailableWorkersChanged(int availableWorkers, int activeWorkers)
{
    this->ui->label_PortsScanner_ActiveWorkers->setText("Active workers: " + QString::number(activeWorkers));
}

int Network::PortsScanner_GetRowIndexByHost(const QString &host)
{
    int rows = this->ui->tableWidget_PortsScanner->model()->rowCount();

    // Set all statuses to PENDING and remove IPs
    for (int i = 0; i < rows; i++)
    {
        if( this->ui->tableWidget_PortsScanner->item(i, 0)->text() == host )
            return i;
    }
    return -1;
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
    for( int i = first; i <= last; i++ )
    {
        this->PortsScanResults[this->ui->tableWidget_PortsScanner->item(i, 0)->text()] = "";
    }

    // Update rows count
    this->ui->label_PortScanner_RecordsCount->setText("Records count: " + QString::number(this->ui->tableWidget_PortsScanner->rowCount()));
}

void Network::PortsScanner_tableWidget_OnTextPasted(const QString &text)
{
    QStringList hosts = Utils_ExtractAllHosts(text);

    foreach(const QString &host, hosts)
        {
            const int currentRow = this->ui->tableWidget_PortsScanner->rowCount();

            this->ui->tableWidget_PortsScanner->setRowCount(currentRow + 1);
//            this->ui->tableWidget_PortsScanner->setItem(currentRow, 0, new QTableWidgetItem(host));

//            // Clear the other cols
//            for( int i = 1; i < (this->ui->tableWidget_PortsScanner->columnCount()); i++)
//                this->ui->tableWidget_PortsScanner->setItem(currentRow, i, new QTableWidgetItem(""));
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
    QString host = this->ui->tableWidget_PortsScanner->item(row, 0)->text();

    QMenu menu("contextMenu", this);
    QAction ShowResult("Show result", this);
    QAction Item_Retest("Retest", this);

    if( !this->PortsScanResults.contains(host) )
    {
        ShowResult.setEnabled(false);
    }


    menu.addAction(&ShowResult);
    menu.addSeparator();
    menu.addAction(&Item_Retest);

    connect(&ShowResult, &QAction::triggered, this, [&host, this]() {
        QString text = "Scan results for " + host + "\n\n" + this->PortsScanResults[host];

        QPlainTextEdit *editor = new QPlainTextEdit(text);
        editor->setWindowTitle("Scan results for " + host);
        editor->setBaseSize(QSize(600, 120));
        editor->show();
    });

    connect(&Item_Retest, &QAction::triggered, this, [this, row, &host]() {
        this->PortsScanner_InitEngine();
        this->PortsScanResults[host] = "";
        for( int i = 1; i < this->ui->tableWidget_PortsScanner->columnCount() - 1; i++ )
            this->ui->tableWidget_PortsScanner->item(row, i)->setText("");
        this->PortsScannerEngine->EnqueueScan(host, this->ui->comboBox_ScanProfiles->currentText());
    });

    menu.exec(ui->tableWidget_PortsScanner->viewport()->mapToGlobal(pos));
}



