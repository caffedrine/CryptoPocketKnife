#include <QDesktopServices>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Top menu slots connecting
    QObject::connect(this->ui->actionLogs, SIGNAL(triggered()), this, SLOT(on_actionLogs_triggered()), Qt::UniqueConnection);

    // Initialize MAC tab
    UiMac *mac = new UiMac(this);
    mac->setWindowFlags(Qt::Widget);
    this->ui->gridLayout_8->addWidget(mac);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Status_EndWithError(QString err_msg)
{
    ui->statusbar->setStyleSheet("QStatusBar{padding-left:8px;background:rgba(255,0,0,255);color:black;font-weight:bold;}");
    ui->statusbar->showMessage("ERROR: " + err_msg);
}

void MainWindow::Status_EndWithSuccess(QString err_msg)
{
    ui->statusbar->setStyleSheet("QStatusBar{padding-left:8px;background:rgba(20,165,58,1);color:black;font-weight:bold;}");
    ui->statusbar->showMessage("SUCCESS: " + err_msg);
}

void MainWindow::Status_Clear()
{
    ui->statusbar->setStyleSheet("");
    ui->statusbar->showMessage("");
}

void MainWindow::on_actionExit_triggered()
{
    qApp->quit();
}

void MainWindow::on_actionSupport_triggered()
{
    QDesktopServices::openUrl(QUrl("https://cryptopocketknife.com"));
}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::information(this, tr("About"), tr("Cryptographic tool to make life of a security engineer easier.\n\nPlease see https://cryptopocketknife.com for more info."), QMessageBox::Ok |  QMessageBox::Ok);
}

void MainWindow::on_actionLogs_triggered()
{
    base::loggerContentGui->setWindowTitle("Application logs");
    base::loggerContentGui->setReadOnly(true);
    base::loggerContentGui->setMinimumSize(QSize(800, 400));
    base::loggerContentGui->showNormal();
}

/*   _    _ _   _ _
    | |  | | | (_) |
    | |  | | |_ _| |___
    | |  | | __| | / __|
    | |__| | |_| | \__ \
     \____/ \__|_|_|___/
*/

void MainWindow::on_pushButton_Utils_CurrentTimestamp_clicked()
{
    this->ui->lineEdit_Utils_LinuxTimestamp->setText( QString::number( QDateTime::currentSecsSinceEpoch() ) );
}

void MainWindow::on_pushButton_Utils_CurrentDateTime_clicked()
{
    this->ui->lineEdit_Utils_DateTime->setText( QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss") );
}

void MainWindow::on_pushButton_TimestampToDatetime_clicked()
{
    this->ui->lineEdit_Utils_DateTime->setText(QDateTime::fromSecsSinceEpoch(this->ui->lineEdit_Utils_LinuxTimestamp->text().toInt()).toString("yyyy-MM-dd hh:mm:ss") );
}

void MainWindow::on_pushButton_dateTimeToTimestamp_clicked()
{
    this->ui->lineEdit_Utils_LinuxTimestamp->setText( QString::number( QDateTime::fromString(this->ui->lineEdit_Utils_DateTime->text(), "yyyy-MM-dd hh:mm:ss").toSecsSinceEpoch()));
}
