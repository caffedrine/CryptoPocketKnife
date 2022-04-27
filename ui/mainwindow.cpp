#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "GeoIP.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setAcceptDrops(false);
    ui->textEdit_certificates_Parse_ParsedCSR->setAcceptDrops(false);
    ui->textEdit_certificates_Parse_ParsedCertificate->setAcceptDrops(false);

    ui->textEdit_certificates_Parse_InputCertificate->setAcceptDrops(true);
    ui->textEdit_certificates_ParseCsr_InputCsr->setAcceptDrops(true);


    // Connect cert/csr dropping signals to slots
    QObject::connect(this->ui->textEdit_certificates_Parse_InputCertificate, SIGNAL( OnDraggedFile(QString) ),
            this, SLOT(OnCertFileDragged(QString)) );
    QObject::connect(this->ui->textEdit_certificates_ParseCsr_InputCsr, SIGNAL( OnDraggedFile(QString) ),
            this, SLOT(OnCsrFileDragged(QString)) );

    // Top menu slots connecting
    QObject::connect(this->ui->actionLogs, SIGNAL(triggered(bool)), this, SLOT(on_actionLogs_triggered(bool)), Qt::UniqueConnection);
    
    // Connect encoding/decoding boxes
    QObject::connect(this->ui->textEdit_EncodeDecode_General_Number, SIGNAL(textChanged()), this, SLOT(on_actionLogs_triggered(bool)), Qt::UniqueConnection);
    
    
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

void MainWindow::on_actionLogs_triggered(bool checked)
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


/*   _    _           _
    | |  | |         | |
    | |__| | __ _ ___| |__   ___  ___
    |  __  |/ _` / __| '_ \ / _ \/ __|
    | |  | | (_| \__ \ | | |  __/\__ \
    |_|  |_|\__,_|___/_| |_|\___||___/
*/
void MainWindow::on_textBrowser_SHA2_InputBytes_textChanged()
{
    QByteArray bytes = Utils_RawHexStrToQByteArr(this->ui->textBrowser_SHA2_InputBytes->toPlainText());
    if( bytes.length() <= 0 )
    {
        return;
    }

    // Calculate SHA2-256 hash
    QByteArray hash = Crypto::Hash::SHA2_256(bytes);
    this->ui->lineEdit_SHA2_256_OUTPUT->setText( Utils_QByteArrayToHexQStr(hash));

}

void MainWindow::on_textBrowser_SHA1_InputBytes_textChanged()
{
    QByteArray bytes = Utils_RawHexStrToQByteArr(this->ui->textBrowser_SHA1_InputBytes->toPlainText());
    if( bytes.length() <= 0 )
    {
        return;
    }

    // Calculate SHA1 hash
    QByteArray hash = Crypto::Hash::SHA1(bytes);
    this->ui->lineEdit_SHA1_Output->setText( Utils_QByteArrayToHexQStr(hash));
}

void MainWindow::on_textBrowser_MD5_InputBytes_textChanged()
{
    QByteArray bytes = Utils_RawHexStrToQByteArr(this->ui->textBrowser_MD5_InputBytes->toPlainText());
    if( bytes.length() <= 0 )
    {
        return;
    }

    // Calculate MD5 hash
    QByteArray hash = Crypto::Hash::MD5(bytes);
    this->ui->lineEdit_MD5_Output->setText( Utils_QByteArrayToHexQStr(hash));
}


/*    _____          _   _  __ _           _
     / ____|        | | (_)/ _(_)         | |
    | |     ___ _ __| |_ _| |_ _  ___ __ _| |_ ___  ___
    | |    / _ \ '__| __| |  _| |/ __/ _` | __/ _ \/ __|
    | |___|  __/ |  | |_| | | | | (_| (_| | ||  __/\__ \
     \_____\___|_|   \__|_|_| |_|\___\__,_|\__\___||___/
*/
QString MainWindow::ParseCertCsrInputStringToB64(QString input)
{
    // #0. Prepare folders workspace
    if( !QDir("tmp").exists() )
    {
        QDir().mkdir("tmp");
    }
    QFile("tmp/cert_pem").remove();
    QFile("tmp/csr_pem").remove();

    // #1. Read certificate from UI
    QString inputCert = input.replace("0x", "").replace(",", "").replace(" ", "").replace("\n", "");

    // Return if already in PEM format
    QString delimitator = "-----";
    if( inputCert.count(delimitator) == 4)
    {
        // Return it, certificate is already in PEM format (cut start and end tags)
        QString strRet = inputCert.split(delimitator)[2].split(delimitator)[0];
        return strRet;
    }

    // Convert to B64 in case of HEX format
    QByteArray bytes = inputCert.toLatin1();
    return QByteArray::fromHex(bytes).toBase64();
}

void MainWindow::ParseCert()
{
    // Clear message box
    this->Status_Clear();

    // Also clear output box
    ui->textEdit_certificates_Parse_ParsedCertificate->clear();

    // Assume RAW hex format
    QString inputContentB64 = this->ParseCertCsrInputStringToB64(ui->textEdit_certificates_Parse_InputCertificate->toPlainText());
    if( inputContentB64.isEmpty() )
    {
        this->Status_EndWithError("Failed to parse input certificate");
        return;
    }

    // Store as HEX bytes parsed certificate
    this->LastParsedCert = QByteArray::fromBase64(inputContentB64.toUtf8());

    // Add tags to PEM format and write it to a file so it can be parsed by OpenSSL
    inputContentB64 = "-----BEGIN CERTIFICATE-----\n" + inputContentB64 + "\n-----END CERTIFICATE-----";
    QFile file("tmp/cert_pem");
    if( file.open(QIODevice::ReadWrite | QIODevice::Text ) )
    {
        QTextStream stream(&file);
        stream << inputContentB64;
        file.waitForBytesWritten(1000);
        file.close();
    }
    else
    {
        this->Status_EndWithError("Failed to write to tmp/cert_hex");
        return;
    }
    ui->textEdit_certificates_Parse_ParsedCertificate->clear();

    // Use openssl to parse certificate
    QProcess process;
    process.setWorkingDirectory("tmp/");
    process.start("openssl.exe", QStringList() << "x509" << "-in" << "cert_pem" << "-text");
    process.waitForFinished(5000);
    QByteArray processOutput = process.readAllStandardOutput();
    processOutput += process.readAllStandardError();
    if( processOutput.length() > 0)
        ui->textEdit_certificates_Parse_ParsedCertificate->append(QString(processOutput));
}

//void MainWindow::ParseCert()
//{
//    // Clear message box
//    this->Status_Clear();

//    // Also clear output box
//    ui->textEdit_certificates_Parse_ParsedCertificate->clear();

//    // Assume RAW hex format
//    QString inputContentB64 = this->ParseCertCsrInputStringToB64(ui->textEdit_certificates_Parse_InputCertificate->toPlainText());
//    if( inputContentB64.isEmpty() )
//    {
//        this->Status_EndWithError("Failed to parse input certificate");
//        return;
//    }

//    // Store as HEX bytes parsed certificate
//    this->LastParsedCert = QByteArray::fromBase64(inputContentB64.toUtf8());

//    // Add tags to PEM format and write it to a file so it can be parsed by OpenSSL
//    inputContentB64 = "-----BEGIN CERTIFICATE-----\n" + inputContentB64 + "\n-----END CERTIFICATE-----";

//    QByteArray certDer = Utils_RawHexStrToQByteArr(ui->textEdit_certificates_Parse_InputCertificate->toPlainText());

//    QList<QSslCertificate> certs = QSslCertificate::fromPath("D:/temp/certs/backend.txt");

//    QSslCertificate cert(inputContentB64.toUtf8(), QSsl::Pem);

//    if( cert.isNull() )
//        ui->textEdit_certificates_Parse_ParsedCertificate->setText("Certificate provided cannot be parsed");
//    else
//        ui->textEdit_certificates_Parse_ParsedCertificate->setText(cert.toText());


//}

void MainWindow::ParseCSR()
{
    // Clear message box
    this->Status_Clear();

    // Also clear output box
    ui->textEdit_certificates_Parse_ParsedCSR->clear();

    // Assume RAW hex format
    QString inputContentB64 = this->ParseCertCsrInputStringToB64(ui->textEdit_certificates_ParseCsr_InputCsr->toPlainText());
    if( inputContentB64.isEmpty() )
    {
        this->Status_EndWithError("Failed to parse input csr");
        return;
    }

    // Store as HEX bytes parsed CSR
    this->LastParsedCSR = QByteArray::fromBase64(inputContentB64.toUtf8());

    // Add tags
    inputContentB64 = "-----BEGIN NEW CERTIFICATE REQUEST-----\n" + inputContentB64 + "\n-----END NEW CERTIFICATE REQUEST-----";
    QFile file("tmp/csr_pem");
    if( file.open(QIODevice::ReadWrite ) )
    {
        QTextStream stream(&file);
        stream << inputContentB64;
        file.waitForBytesWritten(1000);
        file.close();
    }
    else
    {
        this->Status_EndWithError("Failed to write to tmp/csr_hex");
        return;
    }
    ui->textEdit_certificates_Parse_ParsedCSR->clear();

    // Use openssl to parse certificate
    QProcess process;
    process.setWorkingDirectory("tmp/");
    process.start("openssl.exe", QStringList() << "req" << "-in" << "csr_pem" << "-text");
    process.waitForFinished(5000);
    QByteArray processOutput = process.readAllStandardOutput();
    processOutput += process.readAllStandardError();
    if( processOutput.length() > 0)
        ui->textEdit_certificates_Parse_ParsedCSR->append(QString(processOutput));
}

void MainWindow::on_textEdit_certificates_Parse_InputCertificate_textChanged()
{
    this->ParseCert();
}

void MainWindow::on_pushButton_certificates_Parse_ParseCertificate_clicked()
{
    this->ParseCert();
}

void MainWindow::on_pushButton_certificates_Parse_ParseCSR_clicked()
{
    this->ParseCSR();
}

void MainWindow::on_textEdit_certificates_ParseCsr_InputCsr_textChanged()
{
    // Clear message box
    this->Status_Clear();
    this->ParseCSR();
}

void MainWindow::on_pushButton_certificates_Parse_LoadCertificate_clicked()
{
    // Clear message box
    this->Status_Clear();

    QString fileName =  QFileDialog::getOpenFileName(this, tr("Load binary file"), "", "");

    this->ui->textEdit_certificates_Parse_InputCertificate->setText(ParseCertOrCsrFromFileToHexStr(fileName));
}

void MainWindow::on_pushButton_certificates_Parse_LoadCSR_clicked()
{
    // Clear message box
    this->Status_Clear();

    QString fileName =  QFileDialog::getOpenFileName(this, tr("Load binary file"), "", "");

    this->ui->textEdit_certificates_ParseCsr_InputCsr->setText(ParseCertOrCsrFromFileToHexStr(fileName));
}

void MainWindow::on_pushButton_certificates_Parse_CopyCertHEX_clicked()
{
    QString output = "";
    // Loop through each byte from array and append it to output

    if( this->LastParsedCert.size() > 0 )
    {
        output = "0x" + this->LastParsedCert.toHex(' ').replace(" ", " 0x");
    }

    QClipboard *clipboard = QGuiApplication::clipboard();
    clipboard->setText(output);
}

void MainWindow::on_pushButton_certificates_Parse_CopyCSRHEX_clicked()
{
    QString output = "";
    // Loop through each byte from array and append it to output

    if( this->LastParsedCSR.size() > 0 )
    {
        output = "0x" + this->LastParsedCSR.toHex(' ').replace(" ", " 0x");
    }

    QClipboard *clipboard = QGuiApplication::clipboard();
    clipboard->setText(output);
}

void MainWindow::on_pushButton_certificates_Parse_ExportCSR_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"),
                               "cert_sign_request.csr",
                               tr("Binary format (*.csr);;Privacy-Enhanced Mail Base64 (*.pem);;Distinguished Encoding Rules (*.der)"));

    if( fileName.isEmpty() )
        return;

    if( QFileInfo(fileName).suffix().toLower() == "pem")
    {
        QString output = "-----BEGIN CERTIFICATE REQUEST-----\n";
        output+= this->LastParsedCSR.toBase64();
        output+= "\n-----END CERTIFICATE REQUEST-----";

        // Write data to file
        QSaveFile file(fileName);
        file.open(QIODevice::WriteOnly);
        file.write(output.toUtf8());
        file.commit();
    }
    else
    {
        // Write data to file
        QSaveFile file(fileName);
        file.open(QIODevice::WriteOnly);
        file.write(this->LastParsedCSR);
        file.commit();
    }

    this->Status_EndWithSuccess("Certifiate singing request successfully exported!");
}

void MainWindow::on_pushButton_certificates_Parse_ExportCRT_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"),
                               "certificate.crt",
                               tr("Binary format (*.crt *.cer);;Privacy-Enhanced Mail Base64 (*.pem);;Distinguished Encoding Rules (*.der)"));

    if( fileName.isEmpty() )
        return;

    if( QFileInfo(fileName).suffix().toLower() == "pem")
    {
        QString output = "-----BEGIN CERTIFICATE-----\n";
        output+= this->LastParsedCert.toBase64();
        output+= "\n-----END CERTIFICATE-----";

        // Write data to file
        QSaveFile file(fileName);
        file.open(QIODevice::WriteOnly);
        file.write(output.toUtf8());
        // Calling commit() is mandatory, otherwise nothing will be written.
        file.commit();
    }
    else
    {
        // Write data to file
        QSaveFile file(fileName);
        file.open(QIODevice::WriteOnly);
        file.write(this->LastParsedCert);
        // Calling commit() is mandatory, otherwise nothing will be written.
        file.commit();
    }

    this->Status_EndWithSuccess("Certificate successfully exported!");
}

void MainWindow::OnCertFileDragged(QString fileName)
{
    this->ui->textEdit_certificates_Parse_InputCertificate->setText(ParseCertOrCsrFromFileToHexStr(fileName));
}

void MainWindow::OnCsrFileDragged(QString fileName)
{
    this->ui->textEdit_certificates_ParseCsr_InputCsr->setText(ParseCertOrCsrFromFileToHexStr(fileName));
}

/*   ______                     _ _
    |  ____|                   | (_)
    | |__   _ __   ___ ___   __| |_ _ __   __ _
    |  __| | '_ \ / __/ _ \ / _` | | '_ \ / _` |
    | |____| | | | (_| (_) | (_| | | | | | (_| |
    |______|_| |_|\___\___/ \__,_|_|_| |_|\__, |
                                           __/ |
                                          |___/
*/
void MainWindow::EncodeDecode_General_UpdateAllFieldsFromQByteArray(QByteArray bytes, const QString& exception)
{
    // Disable triggering "OnTextChange" event for the boxes that are being updated since this is a programatically triggered event.
    this->BypassOnChangeEventFlag = true;

    if( exception != "ascii" )
    {
        this->ui->textEdit_EncodeDecode_General_Ascii->setText(Utils_BytesToPrintableAsciiString(&bytes));
    }

    if( exception != "hex" )
    {
        this->ui->textEdit_EncodeDecode_General_HEX->setText(  bytes.toHex(' ') );
    }

    if( exception != "bin" )
    {
        this->ui->textEdit_EncodeDecode_General_BIN->setText( Utils_BytesToBinaryString(&bytes) );
    }

    if( exception != "dec" )
    {
        this->ui->textEdit_EncodeDecode_General_DEC->setText( Utils_BytesToDECString(&bytes) );
    }

    if( exception != "base64" )
    {
        this->ui->textEdit_EncodeDecode_General_Base64->setText(bytes.toBase64());
    }

    if( exception != "alnum" )
    {
        this->ui->textEdit_EncodeDecode_General_AlphanumericStrings->setText(Utils_BytesToAlphanumericString(&bytes));
    }
    
    if( exception != "number" )
    {
        this->ui->textEdit_EncodeDecode_General_Number->setText("test" );
    }

    if( exception != "raw" )
    {
        this->ui->textEdit_EncodeDecode_General_RawData->setText( QString(bytes) );
    }

    // Calculate hashes and CRC
    if( bytes.isEmpty() )
    {
        // clear if empty
        this->ui->encoding_lineEdit_MD5->clear();
        this->ui->encoding_lineEdit_SHA512->clear();
        this->ui->encoding_lineEdit_SHA3_512->clear();
        this->ui->encoding_lineEdit_KECCAK512->clear();
        this->ui->encoding_lineEdit_CRC16->clear();
        this->ui->encoding_lineEdit_CRC32->clear();
    }
    else
    {
        // Hashing
        this->ui->encoding_lineEdit_MD5->setText(QCryptographicHash::hash(bytes, QCryptographicHash::Md5).toHex());
        this->ui->encoding_lineEdit_SHA512->setText(QCryptographicHash::hash(bytes, QCryptographicHash::Sha512).toHex());
        this->ui->encoding_lineEdit_SHA3_512->setText(QCryptographicHash::hash(bytes, QCryptographicHash::Sha3_512).toHex());
        this->ui->encoding_lineEdit_KECCAK512->setText(QCryptographicHash::hash(bytes, QCryptographicHash::Keccak_512).toHex());

        // Calculate quick checksums
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
        this->ui->encoding_lineEdit_CRC16->setText(QString::number(qChecksum(bytes.data(), bytes.length(), Qt::ChecksumType::ChecksumIso3309), 16));
        this->ui->encoding_lineEdit_CRC32->setText(QString::number(qChecksum(bytes.data(), bytes.length(), Qt::ChecksumType::ChecksumItuV41), 16));
#pragma GCC diagnostic pop

        // Set cursor to initial positions for cursor. Show results from the beginning
        this->ui->encoding_lineEdit_MD5->setCursorPosition(0);
        this->ui->encoding_lineEdit_SHA512->setCursorPosition(0);
        this->ui->encoding_lineEdit_SHA3_512->setCursorPosition(0);
        this->ui->encoding_lineEdit_KECCAK512->setCursorPosition(0);
        this->ui->encoding_lineEdit_CRC16->setCursorPosition(0);
        this->ui->encoding_lineEdit_CRC32->setCursorPosition(0);
    }

    // Since the boxes were updated, enable event back. As any further change will be a user change.
    this->BypassOnChangeEventFlag = false;
}

void MainWindow::on_textEdit_EncodeDecode_General_Ascii_textChanged()
{
    // Skip updating the other boxes to prevent a infinite loop updates
    if(BypassOnChangeEventFlag)
        return;

    // Convert content to bytes array
    QByteArray bytes = this->ui->textEdit_EncodeDecode_General_Ascii->toPlainText().toUtf8();

    // Set only bytes hex, there all the other boxes will be converted
    this->EncodeDecode_General_UpdateAllFieldsFromQByteArray(bytes, "ascii");
}

void MainWindow::on_textEdit_EncodeDecode_General_HEX_textChanged()
{
    // Skip updating the other boxes to prevent a infinite loop updates
    if(BypassOnChangeEventFlag)
        return;

    // Convert content to bytes array
    QByteArray bytes = QByteArray::fromHex(this->ui->textEdit_EncodeDecode_General_HEX->toPlainText().toLatin1());

    // Set only bytes hex, there all the other boxes will be converted
    this->EncodeDecode_General_UpdateAllFieldsFromQByteArray(bytes, "hex");
}

void MainWindow::on_textEdit_EncodeDecode_General_BIN_textChanged()
{
    // Skip updating the other boxes to prevent a infinite loop updates
    if(BypassOnChangeEventFlag)
        return;

    // Read current string from the ui
    QString content = this->ui->textEdit_EncodeDecode_General_BIN->toPlainText().replace(" ", "");

    // Convert content to bytes array
    QByteArray bytes;
    if( !content.isEmpty() )
    {
        // Content needs to be 8bit aligned
        int misalign_bytes = content.length() % 8;
        if( content.length() < 8 )
        {
            misalign_bytes = 8 - misalign_bytes;
        }

        for( int i = 0; i < misalign_bytes; i++ )
        {
            content = "0" + content;
        }

        for(int i = 0; i < content.length(); i+= 8)
        {
            QString currBytesStr = "";
            for(int j = i; j < i+8; j++)
            {
                currBytesStr += content[j];
            }

            int parsed = currBytesStr.toInt(nullptr, 2);

            bytes.append( parsed );
        }
    }

    this->EncodeDecode_General_UpdateAllFieldsFromQByteArray(bytes, "bin");
}

void MainWindow::on_textEdit_EncodeDecode_General_Base64_textChanged()
{
    // Skip updating the other boxes to prevent a infinite loop updates
    if(BypassOnChangeEventFlag)
        return;

    // Convert content to bytes array
    QByteArray bytes = QByteArray::fromBase64(this->ui->textEdit_EncodeDecode_General_Base64->toPlainText().toUtf8());

    this->EncodeDecode_General_UpdateAllFieldsFromQByteArray(bytes, "base64");
}

void MainWindow::on_textEdit_EncodeDecode_General_AlphanumericStrings_textChanged()
{
    // Skip updating the other boxes to prevent a infinite loop updates
    if(BypassOnChangeEventFlag )
        return;

    // Convert content to bytes array
    QByteArray bytes = this->ui->textEdit_EncodeDecode_General_AlphanumericStrings->toPlainText().toUtf8();

    // Set only bytes hex, there all the other boxes will be converted
    this->EncodeDecode_General_UpdateAllFieldsFromQByteArray(bytes, "alnum");
}

void MainWindow::on_textEdit_EncodeDecode_General_DEC_textChanged()
{
    // Skip updating the other boxes to prevent a infinite loop updates
    if(BypassOnChangeEventFlag )
        return;

    // Convert content to bytes array
    QByteArray bytes;
    QStringList ints = this->ui->textEdit_EncodeDecode_General_DEC->toPlainText().trimmed().split(" ");
    for(int i = 0; i < ints.count(); i++)
    {
        bytes.append( QString(ints.at(i)).toInt(nullptr, 10) );
    }

    // Set only bytes hex, there all the other boxes will be converted
    this->EncodeDecode_General_UpdateAllFieldsFromQByteArray(bytes, "dec");
}

void MainWindow::on_textEdit_EncodeDecode_General_Number_textChanged()
{
    // Skip updating the other boxes to prevent a infinite loop updates
    if(BypassOnChangeEventFlag )
        return;
    
    // Convert content to bytes array
    QByteArray bytes;
    
    // Read only digits as string form UI
    QString number = "";
    for (const QChar c : this->ui->textEdit_EncodeDecode_General_Number->toPlainText())
    {
        if (c.isDigit())
            number.append(c);
    }
    
    //bytes.setNum();
    
    // Set only bytes hex, there all the other boxes will be converted
    this->EncodeDecode_General_UpdateAllFieldsFromQByteArray(bytes, "number");
    
    
    qDebug() << "update bignum";
    
}

void MainWindow::on_pushButton_EncodeDecode_General_ClearAll_clicked()
{
    // Set this flag to prevent boxes updating each other
    this->BypassOnChangeEventFlag = true;

    // Clear boxes
    this->ui->textEdit_EncodeDecode_General_HEX->clear();
    this->ui->textEdit_EncodeDecode_General_Base64->clear();
    this->ui->textEdit_EncodeDecode_General_Ascii->clear();
    this->ui->textEdit_EncodeDecode_General_BIN->clear();
    this->ui->textEdit_EncodeDecode_General_AlphanumericStrings->clear();
    this->ui->textEdit_EncodeDecode_General_RawData->clear();
    this->ui->textEdit_EncodeDecode_General_DEC->clear();

    // Set the flag back so the other boxes can update each other again
    this->BypassOnChangeEventFlag = false;
}

void MainWindow::on_pushButton_EncodeDecode_General_LoadBinary_clicked()
{
    QString fileName =  QFileDialog::getOpenFileName(this, tr("Load binary file"), "", "");

    // Open file and create reading stream
    QFile f(fileName);
    if (!f.open(QFile::ReadOnly))
            return;

    // Read file bytes
    QByteArray fileContent = f.readAll();

    // Read content into UI
    this->EncodeDecode_General_UpdateAllFieldsFromQByteArray(fileContent, "none");

    // Close file
    f.close();
}

void MainWindow::on_textEdit_EncodeDecode_UrlEncoded_textChanged()
{
    // Skip updating the other boxes to prevent a infinite loop updates
    if(BypassOnChangeEventFlag )
        return;

    this->BypassOnChangeEventFlag = true;
    this->ui->textEdit_EncodeDecode_UrlDecoded->setText( QUrl::toPercentEncoding(this->ui->textEdit_EncodeDecode_UrlEncoded->toPlainText()) );
    this->BypassOnChangeEventFlag = false;
}

void MainWindow::on_textEdit_EncodeDecode_UrlDecoded_textChanged()
{
    // Skip updating the other boxes to prevent a infinite loop updates
    if(BypassOnChangeEventFlag )
        return;

    this->BypassOnChangeEventFlag = true;
    this->ui->textEdit_EncodeDecode_UrlEncoded->setText( QUrl::fromPercentEncoding(this->ui->textEdit_EncodeDecode_UrlDecoded->toPlainText().toLatin1()) );
    this->BypassOnChangeEventFlag = false;
}

void MainWindow::on_textEdit_EncodeDecode_HtmlEncoded_textChanged()
{
    // Skip updating the other boxes to prevent a infinite loop updates
    if(BypassOnChangeEventFlag )
        return;

    this->BypassOnChangeEventFlag = true;
    QTextDocument doc;
    doc.setHtml(this->ui->textEdit_EncodeDecode_HtmlEncoded->toPlainText());
    this->ui->textEdit_EncodeDecode_HtmlDecoded->setText( doc.toPlainText() );
    this->BypassOnChangeEventFlag = false;
}

void MainWindow::on_textEdit_EncodeDecode_HtmlDecoded_textChanged()
{
    // Skip updating the other boxes to prevent a infinite loop updates
    if(BypassOnChangeEventFlag )
        return;

    this->BypassOnChangeEventFlag = true;

    QString tmp = this->ui->textEdit_EncodeDecode_HtmlDecoded->toPlainText().toHtmlEscaped();

    this->ui->textEdit_EncodeDecode_HtmlEncoded->setText( tmp );
    this->BypassOnChangeEventFlag = false;
}

/*
    __          __  _
    \ \        / / | |
     \ \  /\  / /__| |__
      \ \/  \/ / _ \ '_ \
       \  /\  /  __/ |_) |
        \/  \/ \___|_.__/
*/



/*
     _   _      _                      _
    | \ | |    | |                    | |
    |  \| | ___| |___      _____  _ __| | __
    | . ` |/ _ \ __\ \ /\ / / _ \| '__| |/ /
    | |\  |  __/ |_ \ V  V / (_) | |  |   <
    |_| \_|\___|\__| \_/\_/ \___/|_|  |_|\_\
*/


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

