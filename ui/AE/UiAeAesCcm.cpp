#include "UiAeAesCcm.h"
#include "ui_UiAeAesCcm.h"

#include <QUtils/QUtils.h>
#include <QWidgets/QWidgetsUtils.h>

#include "AeAesCcm.h"

UiAeAesCcm::UiAeAesCcm(QWidget *parent): QMainWindow(parent), ui(new Ui::UiAeAesCcm)
{
    ui->setupUi(this);
}

UiAeAesCcm::~UiAeAesCcm()
{
    delete ui;
}


void UiAeAesCcm::on_textEdit_InputDataEncDec_textChanged()
{
    this->inputEncDecBytes = Base::Utils::ByteArrays::RawHexStrToQByteArr(this->ui->textEdit_InputDataEncDec->toPlainText());
    this->ui->label_InputEncDec->setText( QString("Input encrypt/decrypt data (%1 bytes)").arg(this->inputEncDecBytes.length()) );
}

void UiAeAesCcm::on_textEdit_InputDataAuth_textChanged()
{
    this->inputBytesAad = Base::Utils::ByteArrays::RawHexStrToQByteArr(this->ui->textEdit_InputDataAuth->toPlainText());
    this->ui->label_InputAuth->setText( QString("AAD - Authenticated data (%1 bytes)").arg(this->inputBytesAad.length()) );
}

void UiAeAesCcm::on_textEdit_OutputData_textChanged()
{
    this->outputBytes = Base::Utils::ByteArrays::RawHexStrToQByteArr(this->ui->textEdit_OutputData->toPlainText());
    this->ui->label_OutputData->setText( QString("Output (%1 bytes)").arg(this->outputBytes.length()) );
}

void UiAeAesCcm::on_lineEdit_Tag_textChanged()
{
    this->tag = Base::Utils::ByteArrays::RawHexStrToQByteArr(this->ui->lineEdit_Tag->text());
    this->ui->label_Mac->setText( QString("TAG (%1 bytes) - Only needed when decrypting").arg(this->tag.length()) );
}

void UiAeAesCcm::on_comboBox_TagSize_currentTextChanged(const QString& text)
{
    this->tagSize = text.toInt();
}

void UiAeAesCcm::on_lineEdit_Key_textChanged()
{
    this->key = Base::Utils::ByteArrays::RawHexStrToQByteArr(this->ui->lineEdit_Key->text());
    this->ui->label_Key->setText( QString("KEY (%1 bytes)").arg(this->key.length()) );
}

void UiAeAesCcm::on_lineEdit_Nonce_textChanged()
{
    this->nonce = Base::Utils::ByteArrays::RawHexStrToQByteArr(this->ui->lineEdit_Nonce->text());
    this->ui->label_Nonce->setText( QString("Nonce (%1 bytes)").arg(this->nonce.length()) );
}

bool UiAeAesCcm::CheckPreconditions()
{
    int aesVersion = this->ui->comboBox_Mode->currentIndex();

    // Validate key
    if( aesVersion == 0 )
    {
        if( this->key.length() != AE_AES_CCM_KEY_SIZE_128 )
        {
            Base::Utils::Widgets::AlertPopup("Invalid key length", "AES128-CCM Key length must be 16 bytes");
            return false;
        }
    }
    else
    {
        Base::Utils::Widgets::AlertPopup("Invalid AES algo", "Invalid algo");
        return false;
    }

    if(this->nonce.length() < AE_AES_CCM_NONCE_MIN_LEN || this->nonce.length() > AE_AES_CCM_NONCE_MAX_LEN )
    {
        Base::Utils::Widgets::AlertPopup("Invalid nonce length", QString("Nonce length needs to be %1-%2 bytes (see RFC 3610)").arg(QString::number(AE_AES_CCM_NONCE_MIN_LEN), QString::number(AE_AES_CCM_NONCE_MAX_LEN)));
        return false;
    }

    return true;
}

void UiAeAesCcm::on_pushButton_Encrypt_clicked()
{
    if( !this->CheckPreconditions() )
        return;

    uint16_t retVal;
    uint8_t outTag[this->tagSize];
    uint32_t outTagLen = this->tagSize;

    uint8_t encData[this->inputEncDecBytes.length()];
    uint32_t encDataLen = this->inputEncDecBytes.length();
    uint32_t encDataIdx = 0;

    AeAesCcmEncrypt enc;
    retVal = enc.Init((uint8_t *) this->key.toStdString().c_str(), this->key.length(),
                      (uint8_t *) this->nonce.toStdString().c_str(), this->nonce.length(),
                      this->inputBytesAad.length(), this->inputEncDecBytes.length(), this->tagSize);

    retVal |= enc.Update((uint8_t *) this->inputEncDecBytes.toStdString().c_str(), this->inputEncDecBytes.length(),
                         (uint8_t *) this->inputBytesAad.toStdString().c_str(), this->inputBytesAad.length(),
                         encData, &encDataLen);
    encDataIdx += encDataLen;
    encDataLen = this->inputEncDecBytes.length() - encDataIdx;
    retVal |= enc.Finish(&encData[encDataIdx], &encDataLen, outTag, &outTagLen);

    if( retVal == 0 )
    {
        this->ui->textEdit_OutputData->setText( QByteArray(reinterpret_cast<const char *>(encData), this->inputEncDecBytes.length()).toHex(' ') );
        this->ui->lineEdit_Tag->setText( QByteArray(reinterpret_cast<const char *>(outTag), outTagLen).toHex(' ') );
    }
    else
    {
        Base::Utils::Widgets::AlertPopup("Calculation failed", QString("Encryption failed with error code %1").arg(retVal));
    }
}

void UiAeAesCcm::on_pushButton_Decrypt_clicked()
{
    if( !this->CheckPreconditions() )
        return;

    uint16_t retVal;
    uint8_t decData[this->inputEncDecBytes.length()];
    uint32_t decDataLen = this->inputEncDecBytes.length();
    uint32_t decDataIdx = 0;


    AeAesCcmDecrypt dec;
    retVal = dec.Init((uint8_t *) this->key.toStdString().c_str(), this->key.length(),
                      (uint8_t *) this->nonce.toStdString().c_str(), this->nonce.length(),
                      this->inputBytesAad.length(), this->inputEncDecBytes.length(), this->tagSize);
    retVal |= dec.Update((uint8_t *) this->inputEncDecBytes.toStdString().c_str(), this->inputEncDecBytes.length(),
                         (uint8_t *) this->inputBytesAad.toStdString().c_str(), this->inputBytesAad.length(),
                         decData, &decDataLen);
    decDataIdx += decDataLen;
    decDataLen = this->inputEncDecBytes.length() - decDataIdx;
    retVal |= dec.Finish(&decData[decDataIdx], &decDataLen, (uint8_t *) this->tag.toStdString().c_str());

    if( retVal == 0 )
    {
        this->ui->textEdit_OutputData->setText( QByteArray(reinterpret_cast<const char *>(decData), this->inputEncDecBytes.length()).toHex(' ') );
    }
    else if(retVal == AE_AES_CCM_ERR_TAG_VERIFICATION)
    {
        Base::Utils::Widgets::AlertPopup("Auth failed", QString("Incorrect TAG"));
        this->ui->textEdit_OutputData->clear();
    }
    else
    {
        Base::Utils::Widgets::AlertPopup("Calculation failed", QString("Encryption failed with error code %1").arg(retVal));
        this->ui->textEdit_OutputData->clear();
    }
}
