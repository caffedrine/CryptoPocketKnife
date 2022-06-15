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

/*   _  __                          _
    | |/ /                         | |
    | ' / ___ _   _    _____  _____| |__   __ _ _ __   __ _  ___
    |  < / _ \ | | |  / _ \ \/ / __| '_ \ / _` | '_ \ / _` |/ _ \
    | . \  __/ |_| | |  __/>  < (__| | | | (_| | | | | (_| |  __/
    |_|\_\___|\__, |  \___/_/\_\___|_| |_|\__,_|_| |_|\__, |\___|
               __/ |                                   __/ |
              |___/                                   |___/
*/
void MainWindow::on_x25519_pushButton_Clear_clicked()
{
    ui->x25529_textEdit_ownSharedSecret->setText("");
    ui->x25529_textEdit_otherSharedSecret->setText("");
    ui->x25529_textEdit_ownPrivateKey->setText("");
    ui->x25529_textEdit_ownPublicKey->setText("");
    ui->x25529_textEdit_otherPrivateKey->setText("");
    ui->x25529_textEdit_otherPublicKey->setText("");
}

void MainWindow::on_x25519_pushButton_GenerateEphemeralKeys_clicked()
{
    uint8_t own_public_key[X25519_KEY_LEN], other_public_key[X25519_KEY_LEN];
    uint8_t own_private_key[X25519_KEY_LEN], other_private_key[X25519_KEY_LEN];

    // Read or generate own private key
    QByteArray tmpArr = Utils_RawHexStrToQByteArr(this->ui->x25529_textEdit_ownPrivateKey->text());
    if( tmpArr.count() != 32 )
    {
        for( size_t i = 0; i < sizeof(own_private_key); i++ )
            own_private_key[i] = (uint8_t)QRandomGenerator::global()->bounded(256);
    }
    else
    {
        memcpy(own_private_key, (uint8_t *)tmpArr.data(), sizeof(own_private_key));
    }

    // Read or generate other private key
    tmpArr = Utils_RawHexStrToQByteArr(this->ui->x25529_textEdit_otherPrivateKey->text());
    if( tmpArr.count() != 32 )
    {
        for( size_t i = 0; i < sizeof(other_private_key); i++ )
            other_private_key[i] = (uint8_t)QRandomGenerator::global()->bounded(256);
    }
    else
    {
        memcpy(other_private_key, (uint8_t *)tmpArr.data(), sizeof(other_private_key));
    }

    // Calculate public keys
    x25519_base(own_public_key, own_private_key);
    x25519_base(other_public_key, other_private_key);


    // Send calculated keys to UI
    ui->x25529_textEdit_ownPrivateKey->setText( Utils_Uint8ArrToHexQStr(own_private_key, sizeof(own_private_key)));
    ui->x25529_textEdit_ownPublicKey->setText( Utils_Uint8ArrToHexQStr(own_public_key, sizeof(own_public_key)));
    ui->x25529_textEdit_otherPrivateKey->setText( Utils_Uint8ArrToHexQStr(other_private_key, sizeof(other_private_key)));
    ui->x25529_textEdit_otherPublicKey->setText( Utils_Uint8ArrToHexQStr(other_public_key, sizeof(other_public_key)));
}

void MainWindow::on_x25519_pushButton_CalculateSharedSecret_clicked()
{
    uint8_t own_shared_secret[X25519_KEY_LEN], other_shared_secret[X25519_KEY_LEN];
    uint8_t own_public_key[X25519_KEY_LEN], other_public_key[X25519_KEY_LEN];
    uint8_t own_private_key[X25519_KEY_LEN], other_private_key[X25519_KEY_LEN];
    ssize_t own_public_key_len, own_private_key_len, other_public_key_len, other_private_key_len;

    // Read keys from UI
    if( !Utils_RawHexStrToArr(ui->x25529_textEdit_ownPrivateKey->text(), own_private_key, &own_private_key_len, sizeof(own_private_key)) )
    {
        this->Status_EndWithError("Failed to read data from UI");
        return;
    }
    if( !Utils_RawHexStrToArr(ui->x25529_textEdit_ownPublicKey->text(), own_public_key, &own_public_key_len, sizeof(own_public_key)) )
    {
        this->Status_EndWithError("Failed to read data from UI");
        return;
    }
    if( ! Utils_RawHexStrToArr(ui->x25529_textEdit_otherPrivateKey->text(), other_private_key, &other_private_key_len, sizeof(other_private_key)) )
    {
        this->Status_EndWithError("Failed to read data from UI");
        return;
    }
    if( ! Utils_RawHexStrToArr(ui->x25529_textEdit_otherPublicKey->text(), other_public_key, &other_public_key_len, sizeof(other_public_key)) )
    {
        this->Status_EndWithError("Failed to read data from UI");
        return;
    }

    // Try to obtain the same shared secret by only using public keys
    x25519(own_shared_secret, own_private_key, other_public_key);
    x25519(other_shared_secret, other_private_key, own_public_key);

    // Send again to the UI the input that was used (properly formatted)
    ui->x25529_textEdit_ownPrivateKey->setText( Utils_Uint8ArrToHexQStr(own_private_key, sizeof(own_private_key)));
    ui->x25529_textEdit_ownPublicKey->setText( Utils_Uint8ArrToHexQStr(own_public_key, sizeof(own_public_key)));
    ui->x25529_textEdit_otherPrivateKey->setText( Utils_Uint8ArrToHexQStr(other_private_key, sizeof(other_private_key)));
    ui->x25529_textEdit_otherPublicKey->setText( Utils_Uint8ArrToHexQStr(other_public_key, sizeof(other_public_key)));

    // Send calculated keys to UI
    ui->x25529_textEdit_ownSharedSecret->setText( Utils_Uint8ArrToHexQStr(own_shared_secret, sizeof(own_shared_secret)));
    ui->x25529_textEdit_otherSharedSecret->setText( Utils_Uint8ArrToHexQStr(other_shared_secret, sizeof(other_shared_secret)));
}

void MainWindow::on_x25519_pushButton_CalcSymKeys_clicked()
{
    ssize_t ownSharedSecret_len, otherSharedSecret_len, nonce_len;
    uint8_t ownSharedSecret[32] = {0}, otherSharedSecret[32] = {0};
    uint8_t ownSymKey[16] = {0}, otherSymKey[16] = {0};
    uint8_t ownAesIv[16] = {0}, otherAesIv[16] = {0};
    uint8_t nonce[32] = {0};
    uint8_t hashMaterial[sizeof(ownSharedSecret) + sizeof(nonce)] = {0}, hashResult[64] = {0};

    if( !Utils_RawHexStrToArr(ui->x25529_textEdit_ownSharedSecret->text(), ownSharedSecret, &ownSharedSecret_len, sizeof(ownSharedSecret)) )
    {
        this->Status_EndWithError("Failed to read data from UI");
        return;
    }
    if( !Utils_RawHexStrToArr(ui->x25529_textEdit_otherSharedSecret->text(), otherSharedSecret, &otherSharedSecret_len, sizeof(otherSharedSecret)) )
    {
        this->Status_EndWithError("Failed to read data from UI");
        return;
    }
    if( !Utils_RawHexStrToArr(ui->x25529_textEdit_nonce->text(), nonce, &nonce_len, sizeof(nonce)) )
    {
        this->Status_EndWithError("Failed to read data from UI");
        return;
    }

    //Sym key is calculated using the following formula: hash = sha512(nonce + shared_secret); key = 16 msb of hash result, IV = 16 lsb of hash result
    // concat nonce + shared secret

    /// Calc OWN sym keys
    memcpy(hashMaterial, nonce, sizeof (nonce));
    memcpy(&hashMaterial[sizeof(nonce)], ownSharedSecret, sizeof(ownSharedSecret));
    // Calculate hash
    Utils_Sha512(hashMaterial, sizeof(hashMaterial), hashResult);
    // Extract key and IV from calculated hash
    memcpy(ownSymKey, hashResult, 16u);
    memcpy(ownAesIv, &hashResult[sizeof (hashResult) - 16u], 16u);

    /// Calc OTHEr sym keys
    memcpy(hashMaterial, nonce, sizeof (nonce));
    memcpy(&hashMaterial[sizeof(nonce)], otherSharedSecret, sizeof(otherSharedSecret));
    // Calculate hash
    Utils_Sha512(hashMaterial, sizeof(hashMaterial), hashResult);
    // Extract key and IV from calculated hash
    memcpy(otherSymKey, hashResult, 16u);
    memcpy(otherAesIv, &hashResult[sizeof (hashResult) - 16u], 16u);

    // Send data to ui
    ui->x25529_textEdit_ownAesKey->setText(Utils_Uint8ArrToHexQStr(ownSymKey, sizeof(ownSymKey)));
    ui->x25529_textEdit_ownAesIv->setText(Utils_Uint8ArrToHexQStr(ownAesIv, sizeof(ownAesIv)));
    ui->x25529_textEdit_otherAesKey->setText(Utils_Uint8ArrToHexQStr(otherSymKey, sizeof(otherSymKey)));
    ui->x25529_textEdit_otherAesIv->setText(Utils_Uint8ArrToHexQStr(otherAesIv, sizeof(otherAesIv)));

}


/*    _____ _       _
     / ____(_)     | |
    | |     _ _ __ | |__   ___ _ __ ___
    | |    | | '_ \| '_ \ / _ \ '__/ __|
    | |____| | |_) | | | |  __/ |  \__ \
     \_____|_| .__/|_| |_|\___|_|  |___/
             | |
             |_|
*/
void MainWindow::on_ciphers_AES_pushButton_Encrypt_clicked()
{
    ssize_t aerKeyIn_len, aesIvIn_len, aesInput_len, aesOutput_len = 0;
    uint8_t aerKeyIn[1024], aesIvIn[1024];
    uint8_t aesInput[8192], aesOutput[8192];

    // Read data from ui
    Utils_RawHexStrToArr(ui->ciphers_AES_textEdit_AesKey->text(), aerKeyIn, &aerKeyIn_len, sizeof(aerKeyIn));
    Utils_RawHexStrToArr(ui->ciphers_AES_textEdit_AesIV->text(), aesIvIn, &aesIvIn_len, sizeof(aesIvIn));
    Utils_RawHexStrToArr(ui->ciphers_AES_textEdit_AesInput->toPlainText(), aesInput, &aesInput_len, sizeof(aesInput));

    // Encrypt given input
    struct AES_ctx ctx;
    AES_init_ctx_iv(&ctx, aerKeyIn, aesIvIn);
    AES_CBC_encrypt_buffer(&ctx, aesInput, aesInput_len);
    // Copy to output
    memcpy(aesOutput, aesInput, aesInput_len);
    aesOutput_len = aesInput_len;

    // Write output to ui
    ui->ciphers_AES_textEdit_AesOutput->setText(Utils_Uint8ArrToHexQStr(aesOutput, aesOutput_len));
}

void MainWindow::on_ciphers_AES_pushButton_Decrypt_clicked()
{
    ssize_t aerKeyIn_len, aesIvIn_len, aesInput_len, aesOutput_len;
    uint8_t aerKeyIn[1024], aesIvIn[1024];
    uint8_t aesInput[8192], aesOutput[8192];

    // Read data from ui
    Utils_RawHexStrToArr(ui->ciphers_AES_textEdit_AesKey->text(), aerKeyIn, &aerKeyIn_len, sizeof(aerKeyIn));
    Utils_RawHexStrToArr(ui->ciphers_AES_textEdit_AesIV->text(), aesIvIn, &aesIvIn_len, sizeof(aesIvIn));
    Utils_RawHexStrToArr(ui->ciphers_AES_textEdit_AesInput->toPlainText(), aesInput, &aesInput_len, sizeof(aesInput));

    // Decrypt given input
    struct AES_ctx ctx;
    AES_init_ctx_iv(&ctx, aerKeyIn, aesIvIn);
    AES_CBC_decrypt_buffer(&ctx, aesInput, aesInput_len);
    // Copy to output
    memcpy(aesOutput, aesInput, aesInput_len);
    aesOutput_len = aesInput_len;

    // Write output to ui
    ui->ciphers_AES_textEdit_AesOutput->setText(Utils_Uint8ArrToHexQStr(aesOutput, aesOutput_len));
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

