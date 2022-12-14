#include "UiAesCipher.h"
#include "ui_UiAesCipher.h"

#include "qaesencryption.h"
#include "utils.h"

UiAesCipher::UiAesCipher(QWidget *parent): QWidget(parent), ui(new Ui::UiAesCipher)
{
    ui->setupUi(this);

    this->ui->label_Input->setText( "Input (" + QString::number( Utils_RawHexStrToQByteArr(this->ui->textEdit_Input->toPlainText()).length() ) + " bytes)" );
    this->ui->label_Output->setText( "Output (" + QString::number(Utils_RawHexStrToQByteArr(this->ui->textEdit_Output->toPlainText()).length()) + " bytes)" );
    this->ui->label_Key->setText( "AES KEY (" + QString::number(Utils_RawHexStrToQByteArr(this->ui->lineEdit_Key->text()).length()) + " bytes)" );
    this->ui->label_IV->setText( "AES IV (" + QString::number(Utils_RawHexStrToQByteArr(this->ui->lineEdit_IV->text()).length()) + " bytes)" );

}

UiAesCipher::~UiAesCipher()
{
    delete ui;
}

void UiAesCipher::on_pushButton_Encrypt_clicked()
{
    QByteArray aesKey = Utils_RawHexStrToQByteArr(this->ui->lineEdit_Key->text());
    QByteArray aesIV = Utils_RawHexStrToQByteArr(this->ui->lineEdit_IV->text());
    int SelectedLevel = this->GetCurrentLevel();
    int SelectedMode = this->GetCurrentMode();
    int SelectedPadding = this->GetCurrentPadding();

    if( (this->AesKeySizes[SelectedLevel] != aesKey.length() * 8) || ( aesIV.length() < 1 ) )
    {
        Utils_Alert("Wrong AES configuration", "Selected mode require the KEY to have " + QString::number(this->AesKeySizes[SelectedLevel]) + " bits, and IV should have at least 8 bits");
        return;
    }

    this->ui->textEdit_Output->setText(QAESEncryption::Crypt((QAESEncryption::Aes) SelectedLevel, (QAESEncryption::Mode) SelectedMode, Utils_RawHexStrToQByteArr(this->ui->textEdit_Input->toPlainText()), aesKey, aesIV, (QAESEncryption::Padding) SelectedPadding).toHex(' '));
}

void UiAesCipher::on_pushButton_Decrypt_clicked()
{
    QByteArray aesKey = Utils_RawHexStrToQByteArr(this->ui->lineEdit_Key->text());
    QByteArray aesIV = Utils_RawHexStrToQByteArr(this->ui->lineEdit_IV->text());
    int SelectedLevel = this->GetCurrentLevel();
    int SelectedMode = this->GetCurrentMode();
    int SelectedPadding = this->GetCurrentPadding();

    if( (this->AesKeySizes[SelectedLevel] != aesKey.length() * 8) || ( aesIV.length() != 16 ) )
    {
        Utils_Alert("Wrong AES configuration", "Selected mode require the KEY to have " + QString::number(this->AesKeySizes[SelectedLevel]) + " bits, and IV should always have 128 bit");
        return;
    }

    this->ui->textEdit_Input->setText(QAESEncryption::Decrypt( (QAESEncryption::Aes)SelectedLevel, (QAESEncryption::Mode)SelectedMode, Utils_RawHexStrToQByteArr(this->ui->textEdit_Output->toPlainText()), aesKey, aesIV, (QAESEncryption::Padding)SelectedPadding).toHex(' '));
}

int UiAesCipher::GetCurrentLevel()
{
    return this->ui->comboBox_AesSize->currentIndex();
}

int UiAesCipher::GetCurrentMode()
{
    return this->ui->comboBox_AesMode->currentIndex();
}

int UiAesCipher::GetCurrentPadding()
{
    return this->ui->comboBox_AesPadding->currentIndex();
}

void UiAesCipher::on_textEdit_Input_textChanged()
{
    this->ui->label_Input->setText( "Input (" + QString::number( Utils_RawHexStrToQByteArr(this->ui->textEdit_Input->toPlainText()).length() ) + " bytes)" );
}

void UiAesCipher::on_textEdit_Output_textChanged()
{
    this->ui->label_Output->setText( "Output (" + QString::number(Utils_RawHexStrToQByteArr(this->ui->textEdit_Output->toPlainText()).length()) + " bytes)" );
}

void UiAesCipher::on_lineEdit_Key_textChanged()
{
    this->ui->label_Key->setText( "AES KEY (" + QString::number(Utils_RawHexStrToQByteArr(this->ui->lineEdit_Key->text()).length()) + " bytes)" );
}

void UiAesCipher::on_lineEdit_IV_textChanged()
{
    this->ui->label_IV->setText( "AES IV (" + QString::number(Utils_RawHexStrToQByteArr(this->ui->lineEdit_IV->text()).length()) + " bytes)" );
}

