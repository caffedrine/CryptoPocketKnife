#include "UiAesCmac.h"
#include "ui_UiAesCmac.h"

#include "base/utils/utils.h"
#include "CmacAes.h"

UiAesCmac::UiAesCmac(QWidget *parent) : QMainWindow(parent), ui(new Ui::UiAesCmac)
{
    ui->setupUi(this);
}

UiAesCmac::~UiAesCmac()
{
    delete ui;
}

void UiAesCmac::on_textEdit_InputData_textChanged()
{
    this->inputBytes = Utils_RawHexStrToQByteArr(this->ui->textEdit_InputData->toPlainText());
    this->ui->label_Input->setText( QString("Input (%1 bytes)").arg(this->inputBytes.length()) );
}

void UiAesCmac::on_lineEdit_Mac_textChanged()
{
    this->mac = Utils_RawHexStrToQByteArr(this->ui->lineEdit_Mac->text());
    this->ui->label_Mac->setText( QString("MAC (%1 bytes)").arg(this->mac.length()) );
}

void UiAesCmac::on_lineEdit_Key_textChanged()
{
    this->key = Utils_RawHexStrToQByteArr(this->ui->lineEdit_Key->text());
    this->ui->label_Key->setText( QString("MAC (%1 bytes)").arg(this->key.length()) );
}


void UiAesCmac::on_pushButton_CalcMac_clicked()
{
    int aesVersion = this->ui->comboBox_Mode->currentIndex();
    if( !this->CheckPreconditions() )
        return;

    uint16_t retVal;
    uint8_t generatedMac[CMAC_AES_MAC_SIZE];

    CmacAes cmac;
    retVal = cmac.Init((uint8_t *) this->key.toStdString().c_str(), this->key.length());
    retVal |= cmac.Update((uint8_t *) this->inputBytes.toStdString().c_str(), this->inputBytes.length());
    retVal |= cmac.Finish(generatedMac);

    if( retVal == 0 )
    {
        this->ui->lineEdit_Mac->setText( QByteArray::fromRawData(reinterpret_cast<const char *>(generatedMac), CMAC_AES_MAC_SIZE).toHex(' ') );
    }
    else
    {
        Utils_Alert("Calculation failed", QString("MAC generation failed with error code %1").arg(retVal));
    }
}

void UiAesCmac::on_pushButton_VerifyMac_clicked()
{
    int aesVersion = this->ui->comboBox_Mode->currentIndex();
    if( !this->CheckPreconditions() )
        return;

    if( this->mac.length() != CMAC_AES_MAC_SIZE )
    {
        Utils_Alert("Invalid mac length", "AES-CMAC MAX length must be 16 bytes");
        return;
    }

    uint16_t retVal;
    CmacAes cmac;
    retVal = cmac.Init((uint8_t *) this->key.toStdString().c_str(), this->key.length());
    retVal |= cmac.Update((uint8_t *) this->inputBytes.toStdString().c_str(), this->inputBytes.length());
    retVal |= cmac.VerifyMac((uint8_t *) this->mac.toStdString().c_str());

    if( retVal == 0 )
    {
        Utils_MsgBox("MAC Result", "MAC is OK");
    }
    else if( retVal == CMAC_INCORRECT_MAC )
    {
        Utils_Alert("MAC Result", QString("MAC is NOT ok."));
    }
    else
    {
        Utils_Alert("Calculation failed", QString("MAC verification failed with error code %1").arg(retVal));
    }
}

bool UiAesCmac::CheckPreconditions()
{
    int aesVersion = this->ui->comboBox_Mode->currentIndex();

    // Validate key
    if( aesVersion == 0 )
    {
        if( this->key.length() != CMAC_AES128_KEY_SIZE )
        {
            Utils_Alert("Invalid key length", "AES128-CMAC Key length must be 16 bytes");
            return false;
        }
    }
    else if( aesVersion == 1 )
    {
        if( this->key.length() != CMAC_AES256_KEY_SIZE )
        {
            Utils_Alert("Invalid key length", "AES256-CMAC Key length must be 32 bytes");
            return false;
        }
    }
    else
    {
        Utils_Alert("Invalid aes algo", "Invalid algo");
        return false;
    }

    // Validate input
    if( this->inputBytes.length() < 16 || this->inputBytes.length() % CMAC_AES_BLOCK_SIZE != 0 )
    {
        Utils_Alert("Invalid payload length", QString("Payload needs to be greater than %1 and aligned with %1").arg(CMAC_AES_BLOCK_SIZE));
        return false;
    }

    return true;
}

