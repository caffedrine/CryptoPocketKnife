#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/res/img/logo.png"));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_ed25519_pushButton_GenerateKeysPair_clicked()
{
    uint8_t public_key[ED25519_KEY_LEN];
    uint8_t private_key[ED25519_KEY_LEN];

    // Generate a random private key
    for( uint32_t i = 0; i < sizeof(private_key); i++ )
        private_key[i] = (uint8_t)QRandomGenerator::global()->bounded(256);

    // Generate keys pair
    ed25519_genpub(public_key, private_key);

    // Write generated keys pair to the output
    ui->ed25529_textEdit_privateKey->setText( Utils_Uint8ArrToHexQStr(private_key, sizeof(private_key)) );
    ui->ed25529_textEdit_publicKey->setText( Utils_Uint8ArrToHexQStr(public_key, sizeof(public_key)));

    this->Status_EndWithSuccess("Public/Private keys pair generated");
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
    ui->statusbar->showMessage("");
}

void MainWindow::on_ed25529_textEdit_privateKey_textChanged(const QString &arg1)
{
    uint8_t ReadBytes[1024] = {0xFF};
    ssize_t ReadSize = 0;

    if( Utils_RawHexStrToArr(ui->ed25529_textEdit_privateKey->text(), ReadBytes, &ReadSize, sizeof(ReadBytes)))
    {
        static const QString displayText = QString("Private key (" + QString::number(ReadSize) + " bytes)");
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

void MainWindow::on_x25519_pushButton_GenerateEphemeralKeys_clicked()
{
    uint8_t own_shared_secret[X25519_KEY_LEN], other_shared_secret[X25519_KEY_LEN];
    uint8_t own_public_key[X25519_KEY_LEN], other_public_key[X25519_KEY_LEN];
    uint8_t own_private_key[X25519_KEY_LEN], other_private_key[X25519_KEY_LEN];

    // Generate random private keys
    for( int i = 0; i < sizeof(X25519_KEY_LEN); i++ )
    {
        own_private_key[i] = (uint8_t)QRandomGenerator::global()->bounded(256);
        other_private_key[i] = (uint8_t)QRandomGenerator::global()->bounded(256);
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


void MainWindow::on_x25519_pushButton_GenerateEphemeralKeys_2_clicked()
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

    // Send calculated keys to UI
    ui->x25529_textEdit_ownSharedSecret->setText( Utils_Uint8ArrToHexQStr(own_shared_secret, sizeof(own_shared_secret)));
    ui->x25529_textEdit_otherSharedSecret->setText( Utils_Uint8ArrToHexQStr(other_shared_secret, sizeof(other_shared_secret)));
}


void MainWindow::on_x25519_pushButton_Clear_clicked()
{
    ui->x25529_textEdit_ownSharedSecret->setText("");
    ui->x25529_textEdit_otherSharedSecret->setText("");
    ui->x25529_textEdit_ownPrivateKey->setText("");
    ui->x25529_textEdit_ownPublicKey->setText("");
    ui->x25529_textEdit_otherPrivateKey->setText("");
    ui->x25529_textEdit_otherPublicKey->setText("");
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
        return inputCert.split(delimitator)[2];
    }

    // Convert to B64 in case of HEX format
    QByteArray bytes = inputCert.toLatin1();
    return QByteArray::fromHex(bytes).toBase64();
}

void MainWindow::ParseCert()
{
    // Assume RAW hex format
    QString inputContentB64 = this->ParseCertCsrInputStringToB64(ui->textEdit_certificates_Parse_InputCertificate->toPlainText());
    if( inputContentB64.isEmpty() )
    {
        this->Status_EndWithError("Failed to parse input certificate");
        return;
    }

    // Add tags
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

void MainWindow::ParseCSR()
{
    // Assume RAW hex format
    QString inputContentB64 = this->ParseCertCsrInputStringToB64(ui->textEdit_certificates_ParseCsr_InputCsr->toPlainText());
    if( inputContentB64.isEmpty() )
    {
        this->Status_EndWithError("Failed to parse input csr");
        return;
    }

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
    this->ParseCSR();
}

void MainWindow::on_textEdit_EncodeDecode_General_Ascii_textChanged()
{
    // Skip updating the other boxes to prevent a infinite loop updates
    if( this->BypassOnChangeEventFlag )
        return;
}

void MainWindow::on_textEdit_EncodeDecode_General_HEX_textChanged()
{
    // Skip updating the other boxes to prevent a infinite loop updates
    if( this->BypassOnChangeEventFlag )
        return;

    // Read current string from the ui
    QString hexContent =  this->ui->textEdit_EncodeDecode_General_HEX->toPlainText();

    // Convert content to bytes array
    QByteArray bytes = QByteArray::fromHex(hexContent.toLatin1());

    // Set this flag to prevent boxes updating each other
    this->BypassOnChangeEventFlag = true;

    // Clear boxes
    this->ui->textEdit_EncodeDecode_General_BIN->setText( QString(bytes) );
    this->ui->textEdit_EncodeDecode_General_Base64->setText(bytes.toBase64());
    this->ui->textEdit_EncodeDecode_General_Ascii->setText(Utils_BytesToPrintableString(&bytes));

    // Set the flag back so the other boxes can update each other again
    this->BypassOnChangeEventFlag = false;
}

void MainWindow::on_textEdit_EncodeDecode_General_BIN_textChanged()
{
    // Skip updating the other boxes to prevent a infinite loop updates
    if( this->BypassOnChangeEventFlag )
        return;
}

void MainWindow::on_textEdit_EncodeDecode_General_Base64_textChanged()
{
    // Skip updating the other boxes to prevent a infinite loop updates
    if( this->BypassOnChangeEventFlag )
        return;
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

    // Convert bytes to RAW hex and send them to UI
    QString fileContentHex = fileContent.toHex(' ');

    // Read content into UI
    this->ui->textEdit_EncodeDecode_General_HEX->setText(fileContentHex);

    // Close file
    f.close();
}


