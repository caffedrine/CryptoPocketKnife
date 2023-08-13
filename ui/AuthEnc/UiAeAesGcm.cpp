#include "UiAeAesGcm.h"
#include "ui_UiAeAesGcm.h"

#include "base/utils/utils.h"
#include "AeAesGcm.h"

UiAeAesGcm::UiAeAesGcm(QWidget *parent): QMainWindow(parent), ui(new Ui::UiAeAesGcm)
{
    ui->setupUi(this);
}

UiAeAesGcm::~UiAeAesGcm()
{
    delete ui;
}

void UiAeAesGcm::on_textEdit_InputData_textChanged()
{
    this->inputBytes = Utils_RawHexStrToQByteArr(this->ui->textEdit_InputData->toPlainText());
    this->ui->label_Input->setText( QString("Input (%1 bytes)").arg(this->inputBytes.length()) );
}

void UiAeAesGcm::on_textEdit_OutputData_textChanged()
{
    this->outputBytes = Utils_RawHexStrToQByteArr(this->ui->textEdit_OutputData->toPlainText());
    this->ui->label_OutputData->setText( QString("Output (%1 bytes)").arg(this->outputBytes.length()) );
}

void UiAeAesGcm::on_lineEdit_Mac_textChanged()
{
    this->mac = Utils_RawHexStrToQByteArr(this->ui->lineEdit_Mac->text());
    this->ui->label_Mac->setText( QString("TAG (%1 bytes) - Only needed when decrypting").arg(this->mac.length()) );
}

void UiAeAesGcm::on_lineEdit_Key_textChanged()
{
    this->key = Utils_RawHexStrToQByteArr(this->ui->lineEdit_Key->text());
    this->ui->label_Key->setText( QString("KEY (%1 bytes)").arg(this->key.length()) );
}

void UiAeAesGcm::on_lineEdit_IV_textChanged()
{
    this->iv = Utils_RawHexStrToQByteArr(this->ui->lineEdit_IV->text());
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
            Utils_Alert("Invalid key length", "AES128-GCM Key length must be 16 bytes");
            return false;
        }
    }
    else if( aesVersion == 1 )
    {
        if( this->key.length() != AE_AES_GCM_KEY_SIZE_192 )
        {
            Utils_Alert("Invalid key length", "AES192-GCM Key length must be 24 bytes");
            return false;
        }
    }
    else if(aesVersion == 2 )
    {
        if( this->key.length() != AE_AES_GCM_KEY_SIZE_256 )
        {
            Utils_Alert("Invalid key length", "AES256-GCM Key length must be 32 bytes");
            return false;
        }
    }
    else
    {
        Utils_Alert("Invalid AES algo", "Invalid algo");
        return false;
    }

    if( this->iv.length() == 0 )
    {
        Utils_Alert("Invalid IV length", "IV length cannot be 0");
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
    uint8_t encData[this->inputBytes.length()];
    uint32_t encDataIdx = 0;
    uint32_t tmpOutLen = this->inputBytes.length();

    AeAesGcmEncrypt enc;
    retVal = enc.Init((uint8_t *) this->key.toStdString().c_str(), this->key.length(), (uint8_t *) this->iv.toStdString().c_str(), this->iv.length() );
    retVal |= enc.AddEncData((uint8_t *) this->inputBytes.toStdString().c_str(), this->inputBytes.length(), &encData[encDataIdx], &tmpOutLen);
    encDataIdx += tmpOutLen;
    tmpOutLen = this->inputBytes.length() - encDataIdx;
    retVal |= enc.Finish(&encData[encDataIdx], &tmpOutLen, outTag);

    if( retVal == 0 )
    {
        this->ui->textEdit_OutputData->setText( QByteArray(reinterpret_cast<const char *>(encData), this->inputBytes.length()).toHex(' ') );
        this->ui->lineEdit_Mac->setText( QByteArray(reinterpret_cast<const char *>(outTag), AE_AES_GCM_TAG_LENGTH).toHex(' ') );
    }
    else
    {
        Utils_Alert("Calculation failed", QString("Encryption failed with error code %1").arg(retVal));
    }
}

void UiAeAesGcm::on_pushButton_Decrypt_clicked()
{
    if( !this->CheckPreconditions() )
        return;
}
