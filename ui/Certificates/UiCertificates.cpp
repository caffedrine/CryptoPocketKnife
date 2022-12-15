#include <QProcess>
#include <QFile>
#include <QFileDialog>
#include <QSaveFile>
#include <QClipboard>
#include <QDebug>
#include "UiCertificates.h"
#include "ui_UiCertificates.h"
#include "utils.h"

UiCertificates::UiCertificates(QWidget *parent): QWidget(parent), ui(new Ui::UiCertificates)
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
}

UiCertificates::~UiCertificates()
{
    delete ui;
}

void UiCertificates::Status_EndWithError(QString err_msg)
{
    qCritical().nospace().noquote() << "ERROR: " + err_msg;
}

void UiCertificates::Status_EndWithSuccess(QString err_msg)
{
    qDebug().nospace().noquote() << "SUCCESS: " + err_msg;
}

void UiCertificates::Status_Clear()
{

}

/*    _____          _   _  __ _           _
     / ____|        | | (_)/ _(_)         | |
    | |     ___ _ __| |_ _| |_ _  ___ __ _| |_ ___  ___
    | |    / _ \ '__| __| |  _| |/ __/ _` | __/ _ \/ __|
    | |___|  __/ |  | |_| | | | | (_| (_| | ||  __/\__ \
     \_____\___|_|   \__|_|_| |_|\___\__,_|\__\___||___/
*/
QString UiCertificates::ParseCertCsrInputStringToB64(QString input)
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

void UiCertificates::ParseCert()
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

    if( this->ui->checkBox_CertOpensslOutput->isChecked() )
    {
        // Add tags to PEM format and write it to a file so it can be parsed by OpenSSL
        inputContentB64 = "-----BEGIN CERTIFICATE-----\n" + inputContentB64 + "\n-----END CERTIFICATE-----";
        QFile file("tmp/cert_pem");
        if(file.open(QIODevice::ReadWrite | QIODevice::Text))
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
    }

    ui->textEdit_certificates_Parse_ParsedCertificate->clear();
    ui->textEdit_certificates_Parse_ParsedCertificate->append(Core::Crypto::x509::GetCertHumanReadableFormat(this->LastParsedCert) + "\n");

    if( this->ui->checkBox_CertOpensslOutput->isChecked() )
    {
        // Use openssl to parse certificate
        QProcess process;
        process.setWorkingDirectory("tmp/");
        process.start("openssl", QString("x509 -in cert_pem -text").split(" "));
        process.waitForFinished(5000);
        QByteArray processOutput = process.readAllStandardOutput();
        processOutput += process.readAllStandardError();
        if(processOutput.length() > 0)
            ui->textEdit_certificates_Parse_ParsedCertificate->append("OpenSSL output: $ openssl x509 -in cert_pem -text\n" + QString(processOutput));
    }
}

//void Certificates::ParseCert()
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

void UiCertificates::ParseCSR()
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
    if( this->ui->checkBox_CsrOpenSslOutput->isChecked() )
    {
        inputContentB64 = "-----BEGIN NEW CERTIFICATE REQUEST-----\n" + inputContentB64 + "\n-----END NEW CERTIFICATE REQUEST-----";
        QFile file("tmp/csr_pem");
        if(file.open(QIODevice::ReadWrite))
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
    }
    ui->textEdit_certificates_Parse_ParsedCSR->clear();

    if( this->ui->checkBox_CsrOpenSslOutput->isChecked() )
    {
        // Use openssl to parse certificate
        QProcess process;
        process.setWorkingDirectory("tmp/");
        process.start("openssl", QString("req -in csr_pem -text").split(" "));
        process.waitForFinished(5000);
        QByteArray processOutput = process.readAllStandardOutput();
        processOutput += process.readAllStandardError();
        if(processOutput.length() > 0)
            ui->textEdit_certificates_Parse_ParsedCSR->append("OpenSSL output: $ openssl req -in csr_pem -text\n" + QString(processOutput));
    }
}

void UiCertificates::on_textEdit_certificates_Parse_InputCertificate_textChanged()
{
    this->ParseCert();
}

void UiCertificates::on_pushButton_certificates_Parse_ParseCertificate_clicked()
{
    this->ParseCert();
}

void UiCertificates::on_pushButton_certificates_Parse_ParseCSR_clicked()
{
    this->ParseCSR();
}

void UiCertificates::on_textEdit_certificates_ParseCsr_InputCsr_textChanged()
{
    // Clear message box
    this->Status_Clear();
    this->ParseCSR();
}

void UiCertificates::on_pushButton_certificates_Parse_LoadCertificate_clicked()
{
    // Clear message box
    this->Status_Clear();

    QString fileName =  QFileDialog::getOpenFileName(this, tr("Load binary file"), "", "");

    this->ui->textEdit_certificates_Parse_InputCertificate->setText(ParseCertOrCsrFromFileToHexStr(fileName));
}

void UiCertificates::on_pushButton_certificates_Parse_LoadCSR_clicked()
{
    // Clear message box
    this->Status_Clear();

    QString fileName =  QFileDialog::getOpenFileName(this, tr("Load binary file"), "", "");

    this->ui->textEdit_certificates_ParseCsr_InputCsr->setText(ParseCertOrCsrFromFileToHexStr(fileName));
}

void UiCertificates::on_pushButton_certificates_Parse_CopyCertHEX_clicked()
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

void UiCertificates::on_pushButton_certificates_Parse_CopyCSRHEX_clicked()
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

void UiCertificates::on_pushButton_certificates_Parse_ExportCSR_clicked()
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

void UiCertificates::on_pushButton_certificates_Parse_ExportCRT_clicked()
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

void UiCertificates::OnCertFileDragged(QString fileName)
{
    this->ui->textEdit_certificates_Parse_InputCertificate->setText(ParseCertOrCsrFromFileToHexStr(fileName));
}

void UiCertificates::OnCsrFileDragged(QString fileName)
{
    this->ui->textEdit_certificates_ParseCsr_InputCsr->setText(ParseCertOrCsrFromFileToHexStr(fileName));
}
