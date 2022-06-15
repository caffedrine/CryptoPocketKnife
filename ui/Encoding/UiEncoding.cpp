#include <QTextDocument>
#include <QFileDialog>
#include "UiEncoding.h"
#include "ui_UiEncoding.h"
#include "utils.h"
#include "BigInt.h"


UiEncoding::UiEncoding(QWidget *parent): QWidget(parent), ui(new Ui::UiEncoding)
{
    ui->setupUi(this);

    // Connect encoding/decoding boxes
    QObject::connect(this->ui->textEdit_EncodeDecode_General_Number, SIGNAL(textChanged()), this, SLOT(on_textEdit_EncodeDecode_General_Number_textChanged()), Qt::UniqueConnection);

}

UiEncoding::~UiEncoding()
{
    delete ui;
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
void UiEncoding::EncodeDecode_General_UpdateAllFieldsFromQByteArray(QByteArray bytes, const QString& exception)
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

//    if( exception != "number" )
//    {
//        BigInt n = BigInt().from_hex(bytes.toHex().toStdString());
//        this->ui->textEdit_EncodeDecode_General_Number->setText(QString::fromStdString(n.to_string()));
//    }

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

void UiEncoding::on_textEdit_EncodeDecode_General_Ascii_textChanged()
{
    // Skip updating the other boxes to prevent a infinite loop updates
    if(BypassOnChangeEventFlag)
        return;

    // Convert content to bytes array
    QByteArray bytes = this->ui->textEdit_EncodeDecode_General_Ascii->toPlainText().toUtf8();

    // Set only bytes hex, there all the other boxes will be converted
    this->EncodeDecode_General_UpdateAllFieldsFromQByteArray(bytes, "ascii");
}

void UiEncoding::on_textEdit_EncodeDecode_General_HEX_textChanged()
{
    // Skip updating the other boxes to prevent a infinite loop updates
    if(BypassOnChangeEventFlag)
        return;

    // Convert content to bytes array
    QByteArray bytes = QByteArray::fromHex(this->ui->textEdit_EncodeDecode_General_HEX->toPlainText().toLatin1());

    // Set only bytes hex, there all the other boxes will be converted
    this->EncodeDecode_General_UpdateAllFieldsFromQByteArray(bytes, "hex");
}

void UiEncoding::on_textEdit_EncodeDecode_General_BIN_textChanged()
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

void UiEncoding::on_textEdit_EncodeDecode_General_Base64_textChanged()
{
    // Skip updating the other boxes to prevent a infinite loop updates
    if(BypassOnChangeEventFlag)
        return;

    // Convert content to bytes array
    QByteArray bytes = QByteArray::fromBase64(this->ui->textEdit_EncodeDecode_General_Base64->toPlainText().toUtf8());

    this->EncodeDecode_General_UpdateAllFieldsFromQByteArray(bytes, "base64");
}

void UiEncoding::on_textEdit_EncodeDecode_General_AlphanumericStrings_textChanged()
{
    // Skip updating the other boxes to prevent a infinite loop updates
    if(BypassOnChangeEventFlag )
        return;

    // Convert content to bytes array
    QByteArray bytes = this->ui->textEdit_EncodeDecode_General_AlphanumericStrings->toPlainText().toUtf8();

    // Set only bytes hex, there all the other boxes will be converted
    this->EncodeDecode_General_UpdateAllFieldsFromQByteArray(bytes, "alnum");
}

void UiEncoding::on_textEdit_EncodeDecode_General_DEC_textChanged()
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

void UiEncoding::on_textEdit_EncodeDecode_General_Number_textChanged()
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

    if( number.isEmpty() )
        return;

    BigInt n(number.toStdString());
    bytes = Utils_RawHexStrToQByteArr( QString::fromStdString(n.to_hex_str()) );

    // Set only bytes hex, there all the other boxes will be converted
    this->EncodeDecode_General_UpdateAllFieldsFromQByteArray(bytes, "number");
}

void UiEncoding::on_pushButton_EncodeDecode_General_ClearAll_clicked()
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

void UiEncoding::on_pushButton_EncodeDecode_General_LoadBinary_clicked()
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

void UiEncoding::on_textEdit_EncodeDecode_UrlEncoded_textChanged()
{
    // Skip updating the other boxes to prevent a infinite loop updates
    if(BypassOnChangeEventFlag )
        return;

    this->BypassOnChangeEventFlag = true;
    this->ui->textEdit_EncodeDecode_UrlDecoded->setText( QUrl::toPercentEncoding(this->ui->textEdit_EncodeDecode_UrlEncoded->toPlainText()) );
    this->BypassOnChangeEventFlag = false;
}

void UiEncoding::on_textEdit_EncodeDecode_UrlDecoded_textChanged()
{
    // Skip updating the other boxes to prevent a infinite loop updates
    if(BypassOnChangeEventFlag )
        return;

    this->BypassOnChangeEventFlag = true;
    this->ui->textEdit_EncodeDecode_UrlEncoded->setText( QUrl::fromPercentEncoding(this->ui->textEdit_EncodeDecode_UrlDecoded->toPlainText().toLatin1()) );
    this->BypassOnChangeEventFlag = false;
}

void UiEncoding::on_textEdit_EncodeDecode_HtmlEncoded_textChanged()
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

void UiEncoding::on_textEdit_EncodeDecode_HtmlDecoded_textChanged()
{
    // Skip updating the other boxes to prevent a infinite loop updates
    if(BypassOnChangeEventFlag )
        return;

    this->BypassOnChangeEventFlag = true;

    QString tmp = this->ui->textEdit_EncodeDecode_HtmlDecoded->toPlainText().toHtmlEscaped();

    this->ui->textEdit_EncodeDecode_HtmlEncoded->setText( tmp );
    this->BypassOnChangeEventFlag = false;
}