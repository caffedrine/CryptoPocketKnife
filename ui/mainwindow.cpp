#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "GeoIP.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Top menu slots connecting
    QObject::connect(this->ui->actionLogs, SIGNAL(triggered()), this, SLOT(on_actionLogs_triggered()), Qt::UniqueConnection);
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
    loggerContentGui->setWindowTitle("Application logs");
    loggerContentGui->setReadOnly(true);
    loggerContentGui->setMinimumSize(QSize(800, 400));
    loggerContentGui->showNormal();
}


/*   _____        _               _             _
    |  __ \      | |             (_)           (_)
    | |  | | __ _| |_ __ _    ___ _  __ _ _ __  _ _ __   __ _
    | |  | |/ _` | __/ _` |  / __| |/ _` | '_ \| | '_ \ / _` |
    | |__| | (_| | || (_| |  \__ \ | (_| | | | | | | | | (_| |
    |_____/ \__,_|\__\__,_|  |___/_|\__, |_| |_|_|_| |_|\__, |
                                     __/ |               __/ |
                                    |___/               |___/
*/
void MainWindow::on_ed25519_pushButton_GenerateKeysPair_clicked()
{
    uint8_t public_key[ED25519_KEY_LEN];
    uint8_t private_key[ED25519_KEY_LEN];
    ssize_t len;


    // Generate a random private key if one is not already set
    if( (!Utils_RawHexStrToArr( this->ui->ed25529_textEdit_privateKey->text(), private_key, &len, (ssize_t)sizeof(private_key)) || (len != 32) ))
    {
        for(uint8_t & i : private_key)
        {
            i = (uint8_t) QRandomGenerator::global()->bounded(256);
        }
    }

    // Generate keys pair
    ed25519_genpub(public_key, private_key);

    // Write generated keys pair to the output
    ui->ed25529_textEdit_privateKey->setText( Utils_Uint8ArrToHexQStr(private_key, sizeof(private_key)) );
    ui->ed25529_textEdit_publicKey->setText( Utils_Uint8ArrToHexQStr(public_key, sizeof(public_key)));

    this->Status_EndWithSuccess("Public/Private keys pair generated");
}

void MainWindow::on_ed25529_textEdit_privateKey_textChanged(const QString &arg1)
{
    uint8_t ReadBytes[128] = {0xFF};
    ssize_t ReadSize = 0;

    if( Utils_RawHexStrToArr(arg1, ReadBytes, &ReadSize, sizeof(ReadBytes)))
    {
        QString displayText = QString("Private key (" + QString::number((uint32_t)ReadSize) + " bytes)");
        ui->ed25519_label_PrivateKey->setText(displayText);
    }
    else
    {
        QString displayText = QString("Private key (0 bytes)");
        ui->ed25519_label_PrivateKey->setText(displayText);
    }
}

void MainWindow::on_ed25529_textEdit_publicKey_textChanged(const QString &arg1)
{

}

void MainWindow::on_ed25519_pushButton_CalculateSignature_clicked()
{
    uint8_t public_key[ED25519_KEY_LEN];
    uint8_t private_key[ED25519_KEY_LEN];
    uint8_t signature[ED25519_SIG_LEN];
    uint8_t message[10000];

    ssize_t message_len, public_key_len, private_key_len;

    // Read relevant data from ui
    if( !Utils_RawHexStrToArr(ui->ed25529_textEdit_publicKey->text(), public_key, &public_key_len, sizeof(public_key)) )
    {
        this->Status_EndWithError("Failed to read public key from UI");
        return;
    }
    if( !Utils_RawHexStrToArr(ui->ed25529_textEdit_privateKey->text(), private_key, &private_key_len, sizeof(private_key)) )
    {
        this->Status_EndWithError("Failed to read private key from UI");
        return;
    }
    if( ! Utils_RawHexStrToArr(ui->ed25529_textEdit_Message->toPlainText(), message, &message_len, sizeof(message)) )
    {
        this->Status_EndWithError("Failed to read message from UI");
        return;
    }

    /* create signature on the message with the key pair */
    ed25519_sign(signature, private_key, public_key, message, message_len);

    // Write signature to UI
    ui->ed25529_textEdit_Signature->setText( Utils_Uint8ArrToHexQStr(signature, sizeof(signature)));

    this->Status_EndWithSuccess("Signature generated");

}

void MainWindow::on_ed25519_pushButton_VerifySignature_clicked()
{
    uint8_t public_key[32];
    uint8_t signature[64];
    uint8_t message[10000];
    ssize_t message_len, public_key_len, signature_len;

    // Read relevant data from ui
    if( !Utils_RawHexStrToArr(ui->ed25529_textEdit_publicKey->text(), public_key, &public_key_len, sizeof(public_key)) )
    {
        this->Status_EndWithError("Failed to read public key from UI");
        return;
    }
    if( !Utils_RawHexStrToArr(ui->ed25529_textEdit_Signature->text(), signature, &signature_len, sizeof(signature)) )
    {
        this->Status_EndWithError("Failed to read signature from UI");
        return;
    }
    if( ! Utils_RawHexStrToArr(ui->ed25529_textEdit_Message->toPlainText(), message, &message_len, sizeof(message)) )
    {
        this->Status_EndWithError("Failed to read message from UI");
        return;
    }

    /* verify the signature */
    if (ed25519_verify(signature, public_key, message, message_len))
    {
        this->Status_EndWithSuccess("Signature OK");
    }
    else
    {
        this->Status_EndWithError("Signature NOT ok");
    }
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

void MainWindow::on_pushButton_Signature_ED25519_Clear_clicked()
{
    this->ui->ed25529_textEdit_privateKey->clear();
    this->ui->ed25529_textEdit_publicKey->clear();
}

