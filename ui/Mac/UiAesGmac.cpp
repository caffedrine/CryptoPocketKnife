#include "UiAesGmac.h"
#include "ui_UiAesGmac.h"

#include <QUtils/QUtils.h>
#include <QWidgets/QWidgetsUtils.h>
#include "GmacAes.h"

UiAesGmac::UiAesGmac(QWidget *parent): QMainWindow(parent), ui(new Ui::UiAesGmac)
{
    ui->setupUi(this);
}

UiAesGmac::~UiAesGmac()
{
    delete ui;
}

void UiAesGmac::on_textEdit_InputData_textChanged()
{
    this->inputBytes = Base::Utils::ByteArrays::RawHexStrToQByteArr(this->ui->textEdit_InputData->toPlainText());
    this->ui->label_Input->setText( QString("Input (%1 bytes)").arg(this->inputBytes.length()) );
}

void UiAesGmac::on_lineEdit_Mac_textChanged()
{
    this->mac = Base::Utils::ByteArrays::RawHexStrToQByteArr(this->ui->lineEdit_Mac->text());
    this->ui->label_Mac->setText( QString("MAC (%1 bytes)").arg(this->mac.length()) );
}

void UiAesGmac::on_lineEdit_Key_textChanged()
{
    this->key = Base::Utils::ByteArrays::RawHexStrToQByteArr(this->ui->lineEdit_Key->text());
    this->ui->label_Key->setText( QString("KEY (%1 bytes)").arg(this->key.length()) );
}

void UiAesGmac::on_lineEdit_IV_textChanged()
{
    this->iv = Base::Utils::ByteArrays::RawHexStrToQByteArr(this->ui->lineEdit_IV->text());
    this->ui->label_IV->setText( QString("IV (%1 bytes)").arg(this->iv.length()) );
}

void UiAesGmac::on_pushButton_CalcMac_clicked()
{
    if( !this->CheckPreconditions() )
        return;

    uint16_t retVal;
    uint8_t generatedMac[GMAC_AES_MAC_TAG_LENGTH];

    GmacAes gmac;
    retVal = gmac.Init((uint8_t *) this->key.toStdString().c_str(), this->key.length(), (uint8_t *) this->iv.toStdString().c_str(), this->iv.length());
    retVal |= gmac.Update((uint8_t *) this->inputBytes.toStdString().c_str(), this->inputBytes.length());
    retVal |= gmac.Finish(generatedMac);

    if( retVal == 0 )
    {
        this->ui->lineEdit_Mac->setText( QByteArray::fromRawData(reinterpret_cast<const char *>(generatedMac), GMAC_AES_MAC_TAG_LENGTH).toHex(' ') );
    }
    else
    {
        Base::Utils::Widgets::AlertPopup("Calculation failed", QString("MAC generation failed with error code %1").arg(retVal));
    }
}

void UiAesGmac::on_pushButton_VerifyMac_clicked()
{
    int aesVersion = this->ui->comboBox_Mode->currentIndex();
    if( !this->CheckPreconditions() )
        return;

    if( this->mac.length() != GMAC_AES_MAC_TAG_LENGTH )
    {
        Base::Utils::Widgets::AlertPopup("Invalid MAC length", "AES-GMAC tag length must be 16 bytes");
        return;
    }

    uint32_t  retVal = 0;
    GmacAes gmac;
    retVal = gmac.Init((uint8_t *) this->key.toStdString().c_str(), this->key.length(), (uint8_t *) this->iv.toStdString().c_str(), this->iv.length());
    retVal |= gmac.Update((uint8_t *) this->inputBytes.toStdString().c_str(), this->inputBytes.length());
    retVal |= gmac.VerifyMac((uint8_t *) this->mac.toStdString().c_str());

    if( retVal == 0 )
    {
        Base::Utils::Widgets::MsgBoxPopup("MAC Result", "MAC is OK");
    }
    else if( retVal == GMAC_AES_TAG_INCORRECT )
    {
        Base::Utils::Widgets::AlertPopup("MAC Result", QString("MAC is NOT ok."));
    }
    else
    {
        Base::Utils::Widgets::AlertPopup("Calculation failed", QString("MAC verification failed with error code %1").arg(retVal));
    }
}

bool UiAesGmac::CheckPreconditions()
{
    int aesVersion = this->ui->comboBox_Mode->currentIndex();

    // Validate key
    if( aesVersion == 0 )
    {
        if( this->key.length() != GMAC_AES_GCM_KEY_SIZE_128 )
        {
            Base::Utils::Widgets::AlertPopup("Invalid key length", "AES128-GMAC Key length must be 16 bytes");
            return false;
        }
    }
    else if( aesVersion == 1 )
    {
        if( this->key.length() != GMAC_AES_GCM_KEY_SIZE_192 )
        {
            Base::Utils::Widgets::AlertPopup("Invalid key length", "AES256-GMAC Key length must be 24 bytes");
            return false;
        }
    }
    else if( aesVersion == 2 )
    {
        if( this->key.length() != GMAC_AES_GCM_KEY_SIZE_256 )
        {
            Base::Utils::Widgets::AlertPopup("Invalid key length", "AES256-GMAC Key length must be 32 bytes");
            return false;
        }
    }
    else
    {
        Base::Utils::Widgets::AlertPopup("Invalid aes algo", "Invalid algo");
        return false;
    }

    // Validate IV
    if( iv.length() < 12 || iv.length() > 16 )
    {
        Base::Utils::Widgets::AlertPopup("Invalid IV length", "IV length must be from 12 to 16 bytes");
        return false;
    }

    return true;
}
