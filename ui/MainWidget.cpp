#include <QDesktopServices>
#include "MainWidget.h"
#include "ui_MainWidget.h"

#include "ui/KDF/UiKdf.h"
#include "ui/Utils/UiMathExpEval.h"
#include <QGeoIP/CountryFlags.h>

MainWidget::MainWidget(QStatusBar *statusBar, QWidget *parent): QWidget(parent), ui(new Ui::MainWidget), statusBar(statusBar)
{
    ui->setupUi(this);

    // Initialize MAC tab
    UiMac *mac = new UiMac(this);
    mac->setWindowFlags(Qt::Widget);
    this->ui->gridLayout_8->addWidget(mac);

    // Init authenticated encryption tab
    AuthenticatedEncryption *ae = new AuthenticatedEncryption(this);
    ae->setWindowFlags(Qt::Widget);
    this->ui->gridLayout_AuthEnc->addWidget(ae);

    // Init KDF window
    UiKdf *kdf = new UiKdf(this);
    kdf->setWindowFlags(Qt::Widget);
    this->ui->gridLayout_KDF->addWidget(kdf);

    // Init math exp evaluator
    UiMathExpEval *math = new UiMathExpEval(this);
    kdf->setWindowFlags(Qt::Widget);
    this->ui->gridLayout_MathExpEval->addWidget(math);

    qDebug() << BASE_COUNTRYFLAGS_CountryIcon("RO");
}

MainWidget::~MainWidget()
{
    delete ui;
}

void MainWidget::Status_EndWithError(QString err_msg)
{
    this->statusBar->setStyleSheet("QStatusBar{padding-left:8px;background:rgba(255,0,0,255);color:black;font-weight:bold;}");
    this->statusBar->showMessage("ERROR: " + err_msg);
}

void MainWidget::Status_EndWithSuccess(QString err_msg)
{
    this->statusBar->setStyleSheet("QStatusBar{padding-left:8px;background:rgba(20,165,58,1);color:black;font-weight:bold;}");
    this->statusBar->showMessage("SUCCESS: " + err_msg);
}

void MainWidget::Status_Clear()
{
    this->statusBar->setStyleSheet("");
    this->statusBar->showMessage("");
}

/*   _    _ _   _ _
    | |  | | | (_) |
    | |  | | |_ _| |___
    | |  | | __| | / __|
    | |__| | |_| | \__ \
     \____/ \__|_|_|___/
*/

void MainWidget::on_pushButton_Utils_CurrentTimestamp_clicked()
{
    this->ui->lineEdit_Utils_LinuxTimestamp->setText( QString::number( QDateTime::currentSecsSinceEpoch() ) );
}

void MainWidget::on_pushButton_Utils_CurrentDateTime_clicked()
{
    this->ui->lineEdit_Utils_DateTime->setText( QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss") );
}

void MainWidget::on_pushButton_TimestampToDatetime_clicked()
{
    this->ui->lineEdit_Utils_DateTime->setText(QDateTime::fromSecsSinceEpoch(this->ui->lineEdit_Utils_LinuxTimestamp->text().toInt()).toString("yyyy-MM-dd hh:mm:ss") );
}

void MainWidget::on_pushButton_dateTimeToTimestamp_clicked()
{
    this->ui->lineEdit_Utils_LinuxTimestamp->setText( QString::number( QDateTime::fromString(this->ui->lineEdit_Utils_DateTime->text(), "yyyy-MM-dd hh:mm:ss").toSecsSinceEpoch()));
}