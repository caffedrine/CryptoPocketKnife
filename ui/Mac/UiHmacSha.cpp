#include "UiHmacSha.h"
#include "ui_UiHmacSha.h"

#include <QUtils/QUtils.h>
#include <QWidgets/QWidgetsUtils.h>
#include "HmacSha1.h"
#include "HmacSha2.h"

UiHmacSha::UiHmacSha(QWidget *parent): QMainWindow(parent), ui(new Ui::UiHmacSha)
{
    ui->setupUi(this);
}

UiHmacSha::~UiHmacSha()
{
    delete ui;
}

void UiHmacSha::on_textEdit_InputData_textChanged()
{
    this->inputBytes = Base::Utils::ByteArrays::RawHexStrToQByteArr(this->ui->textEdit_InputData->toPlainText());
    this->ui->label_Input->setText( QString("Input (%1 bytes)").arg(this->inputBytes.length()) );
}

void UiHmacSha::on_lineEdit_Mac_textChanged()
{
    this->mac = Base::Utils::ByteArrays::RawHexStrToQByteArr(this->ui->lineEdit_Mac->text());
    this->ui->label_Mac->setText( QString("MAC (%1 bytes)").arg(this->mac.length()) );
}

void UiHmacSha::on_lineEdit_Key_textChanged()
{
    this->key = Base::Utils::ByteArrays::RawHexStrToQByteArr(this->ui->lineEdit_Key->text());
    this->ui->label_Key->setText( QString("Key (%1 bytes)").arg(this->key.length()) );
}


bool UiHmacSha::CheckPreconditions()
{
    int aesVersion = this->ui->comboBox_Mode->currentIndex();

    // Validate key
    if(this->key.length() == 0)
    {
        Base::Utils::Widgets::AlertPopup("Invalid key length", "Key length cannot be empty");
        return false;
    }

    return true;
}

void UiHmacSha::on_pushButton_CalcMac_clicked()
{
    if( !this->CheckPreconditions() )
        return;

    uint16_t retVal;


    if( this->ui->comboBox_Mode->currentIndex() == 0 )
    {
        uint8_t generatedMac[HMAC_SHA1_MAC_LENGTH];

        HmacSha1 hmac1;
        retVal = hmac1.Init((uint8_t *) this->key.toStdString().c_str(), this->key.length());
        retVal |= hmac1.Update((uint8_t *) this->inputBytes.toStdString().c_str(), this->inputBytes.length());
        retVal |= hmac1.Finish(generatedMac);
        if(retVal == 0)
            this->ui->lineEdit_Mac->setText(QByteArray::fromRawData(reinterpret_cast<const char *>(generatedMac), HMAC_SHA1_MAC_LENGTH).toHex(' '));
    }
    else if(ui->comboBox_Mode->currentIndex() == 1)
    {
        uint8_t generatedMac[HMAC_SHA2_256_MAC_LEN];

        HmacSha2 hmac2(HMAC_SHA2_256);
        retVal = hmac2.Init((uint8_t *) this->key.toStdString().c_str(), this->key.length());
        retVal |= hmac2.Update((uint8_t *) this->inputBytes.toStdString().c_str(), this->inputBytes.length());
        retVal |= hmac2.Finish(generatedMac);
        if(retVal == 0)
            this->ui->lineEdit_Mac->setText(QByteArray::fromRawData(reinterpret_cast<const char *>(generatedMac), HMAC_SHA2_256_MAC_LEN).toHex(' '));
    }
    else if(ui->comboBox_Mode->currentIndex() == 2)
    {
        uint8_t generatedMac[HMAC_SHA2_384_MAC_LEN];

        HmacSha2 hmac2(HMAC_SHA2_384);
        retVal = hmac2.Init((uint8_t *) this->key.toStdString().c_str(), this->key.length());
        retVal |= hmac2.Update((uint8_t *) this->inputBytes.toStdString().c_str(), this->inputBytes.length());
        retVal |= hmac2.Finish(generatedMac);
        if(retVal == 0)
            this->ui->lineEdit_Mac->setText(QByteArray::fromRawData(reinterpret_cast<const char *>(generatedMac), HMAC_SHA2_384_MAC_LEN).toHex(' '));
    }

    if( retVal != 0 )
    {
        Base::Utils::Widgets::AlertPopup("Calculation failed", QString("MAC generation failed with error code %1").arg(retVal));
    }

}

void UiHmacSha::on_pushButton_VerifyMac_clicked()
{
    if( !this->CheckPreconditions() )
        return;

}
