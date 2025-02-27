#include "UiAeAesGcm.h"
#include "ui_UiAeAesGcm.h"

#include <QUtils/QUtils.h>
#include <QWidgets/QWidgetsUtils.h>

#include "AeAesGcm.h"

UiAeAesGcm::UiAeAesGcm(QWidget *parent): QMainWindow(parent), ui(new Ui::UiAeAesGcm)
{
    ui->setupUi(this);
}

UiAeAesGcm::~UiAeAesGcm()
{
    delete ui;
}

void UiAeAesGcm::on_textEdit_InputDataEncDec_textChanged()
{
    this->inputEncDecBytes = Base::Utils::ByteArrays::RawHexStrToQByteArr(this->ui->textEdit_InputDataEncDec->toPlainText());
    this->ui->label_InputEncDec->setText( QString("Input encrypt/decrypt data (%1 bytes)").arg(this->inputEncDecBytes.length()) );
}

void UiAeAesGcm::on_textEdit_InputDataAuth_textChanged()
{
    this->inputAuthBytes = Base::Utils::ByteArrays::RawHexStrToQByteArr(this->ui->textEdit_InputDataAuth->toPlainText());
    this->ui->label_InputAuth->setText( QString("Input authenticated data (%1 bytes)").arg(this->inputAuthBytes.length()) );
}

void UiAeAesGcm::on_textEdit_OutputData_textChanged()
{
    this->outputBytes = Base::Utils::ByteArrays::RawHexStrToQByteArr(this->ui->textEdit_OutputData->toPlainText());
    this->ui->label_OutputData->setText( QString("Output (%1 bytes)").arg(this->outputBytes.length()) );
}

void UiAeAesGcm::on_lineEdit_Mac_textChanged()
{
    this->mac = Base::Utils::ByteArrays::RawHexStrToQByteArr(this->ui->lineEdit_Mac->text());
    this->ui->label_Mac->setText( QString("TAG (%1 bytes) - Only needed when decrypting").arg(this->mac.length()) );
}

void UiAeAesGcm::on_lineEdit_Key_textChanged()
{
    this->key = Base::Utils::ByteArrays::RawHexStrToQByteArr(this->ui->lineEdit_Key->text());
    this->ui->label_Key->setText( QString("KEY (%1 bytes)").arg(this->key.length()) );
}

void UiAeAesGcm::on_lineEdit_IV_textChanged()
{
    this->iv = Base::Utils::ByteArrays::RawHexStrToQByteArr(this->ui->lineEdit_IV->text());
    this->ui->label_IV->setText( QString("IV (%1 bytes)").arg(this->iv.length()) );
}

bool UiAeAesGcm::CheckPreconditions()
{
    int aesVersion = this->ui->comboBox_Mode->currentIndex();

    // Validate key
    if( aesVersion == 0 )
    {
        if( this->key.length() != AE_AES_GCM_KEY_SIZE_128 )
        {
            Base::Utils::Widgets::AlertPopup("Invalid key length", "AES128-GCM Key length must be 16 bytes");
            return false;
        }
    }
    else if( aesVersion == 1 )
    {
        if( this->key.length() != AE_AES_GCM_KEY_SIZE_192 )
        {
            Base::Utils::Widgets::AlertPopup("Invalid key length", "AES192-GCM Key length must be 24 bytes");
            return false;
        }
    }
    else if(aesVersion == 2 )
    {
        if( this->key.length() != AE_AES_GCM_KEY_SIZE_256 )
        {
            Base::Utils::Widgets::AlertPopup("Invalid key length", "AES256-GCM Key length must be 32 bytes");
            return false;
        }
    }
    else
    {
        Base::Utils::Widgets::AlertPopup("Invalid AES algo", "Invalid algo");
        return false;
    }

    if( this->iv.length() == 0 )
    {
        Base::Utils::Widgets::AlertPopup("Invalid IV length", "IV length cannot be 0");
        return false;
    }

    return true;
}

void UiAeAesGcm::on_pushButton_Encrypt_clicked()
{
    if( !this->CheckPreconditions() )
        return;

    uint16_t retVal;
    uint8_t outTag[AE_AES_GCM_TAG_LENGTH];

    uint8_t encData[this->inputEncDecBytes.length()];
    uint32_t endDataLen = this->inputEncDecBytes.length();
    uint32_t encDataIdx = 0;

    AeAesGcmEncrypt enc;
    retVal = enc.Init((uint8_t *) this->key.toStdString().c_str(), this->key.length(),
                      (uint8_t *) this->iv.toStdString().c_str(), this->iv.length() );

    // additional data shall be added before data to be ciphered
    if( !this->inputAuthBytes.isEmpty() )
        retVal |= enc.AddAuthData((uint8_t *) this->inputAuthBytes.toStdString().c_str(), this->inputAuthBytes.length());

    retVal |= enc.AddEncData((uint8_t *) this->inputEncDecBytes.toStdString().c_str(), this->inputEncDecBytes.length(),
                             &encData[encDataIdx], &endDataLen);
    encDataIdx += endDataLen;
    endDataLen = this->inputEncDecBytes.length() - encDataIdx;
    retVal |= enc.Finish(&encData[encDataIdx], &endDataLen, outTag);

    if( retVal == 0 )
    {
        this->ui->textEdit_OutputData->setText( QByteArray(reinterpret_cast<const char *>(encData), this->inputEncDecBytes.length()).toHex(' ') );
        this->ui->lineEdit_Mac->setText( QByteArray(reinterpret_cast<const char *>(outTag), AE_AES_GCM_TAG_LENGTH).toHex(' ') );
    }
    else
    {
        Base::Utils::Widgets::AlertPopup("Calculation failed", QString("Encryption failed with error code %1").arg(retVal));
    }
}

void UiAeAesGcm::on_pushButton_Decrypt_clicked()
{
    if( !this->CheckPreconditions() )
        return;

    uint16_t retVal;
    uint8_t decData[this->inputEncDecBytes.length()];
    uint32_t decDataLen = this->inputEncDecBytes.length();
    uint32_t decDataIdx = 0;

    AeAesGcmDecrypt dec;
    retVal = dec.Init((uint8_t *) this->key.toStdString().c_str(), this->key.length(), (uint8_t *) this->iv.toStdString().c_str(), this->iv.length() );
    // additional data shall be added before data to be ciphered
    if( !this->inputAuthBytes.isEmpty() )
        retVal |= dec.AddAuthData((uint8_t *) this->inputAuthBytes.toStdString().c_str(), this->inputAuthBytes.length());
    retVal |= dec.AddDecData((uint8_t *) this->inputEncDecBytes.toStdString().c_str(), this->inputEncDecBytes.length(), &decData[decDataIdx], &decDataLen);
    decDataIdx += decDataLen;
    decDataLen = this->inputEncDecBytes.length() - decDataIdx;
    retVal |= dec.Finish(&decData[decDataIdx], &decDataLen, (uint8_t *) this->mac.toStdString().c_str());

    if( retVal == 0 )
    {
        this->ui->textEdit_OutputData->setText( QByteArray(reinterpret_cast<const char *>(decData), this->inputEncDecBytes.length()).toHex(' ') );
    }
    else if(retVal == AE_AES_GCM_ERR_TAG_VERIFICATION)
    {
        Base::Utils::Widgets::AlertPopup("Auth failed", QString("Incorrect TAG"));
    }
    else
    {
        Base::Utils::Widgets::AlertPopup("Calculation failed", QString("Encryption failed with error code %1").arg(retVal));
    }
}
