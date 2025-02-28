#include "UiDigitalSignatures.h"
#include "ui_UiDigitalSignatures.h"

#include <QRandomGenerator>
#include <eddsa.h>
#include <QUtils/QUtils.h>
#include <QWidgets/QWidgetsUtils.h>


UiDigitalSignatures::UiDigitalSignatures(QWidget *parent): QWidget(parent), ui(new Ui::UiDigitalSignatures)
{
    ui->setupUi(this);
}

UiDigitalSignatures::~UiDigitalSignatures()
{
    delete ui;
}

void UiDigitalSignatures::Status_EndWithError(QString err_msg)
{
    qCritical().nospace().noquote() << "ERROR: " + err_msg;
}

void UiDigitalSignatures::Status_EndWithSuccess(QString err_msg)
{
    qDebug().nospace().noquote() << "SUCCESS: " + err_msg;
}

void UiDigitalSignatures::Status_Clear()
{

}

/*   _____        _               _             _
    |  __ \      | |             (_)           (_)
    | |  | | __ _| |_ __ _    ___ _  __ _ _ __  _ _ __   __ _
    | |  | |/ _` | __/ _` |  / __| |/ _` | '_ \| | '_ \ / _` |
    | |__| | (_| | || (_| |  \__ \ | (_| | | | | | | | | (_| |
    |_____/ \__,_|\__\__,_|  |___/_|\__, |_| |_|_|_| |_|\__, |
                                     __/ |               __/ |
                                    |___/               |___/
*/
void UiDigitalSignatures::on_ed25519_pushButton_GenerateKeysPair_clicked()
{
    uint8_t public_key[ED25519_KEY_LEN];
    uint8_t private_key[ED25519_KEY_LEN];
    ssize_t len;


    // Generate a random private key if one is not already set
    if( (!Base::Utils::ByteArrays::RawHexStrToArr( this->ui->ed25529_textEdit_privateKey->text(), private_key, &len, (ssize_t)sizeof(private_key)) || (len != 32) ))
    {
        for(uint8_t & i : private_key)
        {
            i = (uint8_t) QRandomGenerator::global()->bounded(256);
        }
    }

    // Generate keys pair
    ed25519_genpub(public_key, private_key);

    // Write generated keys pair to the output
    ui->ed25529_textEdit_privateKey->setText( Base::Utils::ByteArrays::Uint8ArrToHexQStr(private_key, sizeof(private_key)) );
    ui->ed25529_textEdit_publicKey->setText( Base::Utils::ByteArrays::Uint8ArrToHexQStr(public_key, sizeof(public_key)));

    this->Status_EndWithSuccess("Public/Private keys pair generated");
}

void UiDigitalSignatures::on_ed25529_textEdit_privateKey_textChanged(const QString &arg1)
{
    uint8_t ReadBytes[128] = {0xFF};
    ssize_t ReadSize = 0;

    if( Base::Utils::ByteArrays::RawHexStrToArr(arg1, ReadBytes, &ReadSize, sizeof(ReadBytes)))
    {
        QString displayText = QString("Private key (" + QString::number((uint32_t)ReadSize) + " bytes)");
        ui->ed25519_label_PrivateKey->setText(displayText);
    }
    else
    {
        QString displayText = QString("Private key (0 bytes)");
        ui->ed25519_label_PrivateKey->setText(displayText);
    }
}

void UiDigitalSignatures::on_ed25529_textEdit_publicKey_textChanged(const QString &arg1)
{

}

void UiDigitalSignatures::on_ed25519_pushButton_CalculateSignature_clicked()
{
    uint8_t public_key[ED25519_KEY_LEN];
    uint8_t private_key[ED25519_KEY_LEN];
    uint8_t signature[ED25519_SIG_LEN];
    uint8_t message[10000];

    ssize_t message_len, public_key_len, private_key_len;

    // Read relevant data from ui
    if( !Base::Utils::ByteArrays::RawHexStrToArr(ui->ed25529_textEdit_publicKey->text(), public_key, &public_key_len, sizeof(public_key)) )
    {
        this->Status_EndWithError("Failed to read public key from UI");
        return;
    }
    if( !Base::Utils::ByteArrays::RawHexStrToArr(ui->ed25529_textEdit_privateKey->text(), private_key, &private_key_len, sizeof(private_key)) )
    {
        this->Status_EndWithError("Failed to read private key from UI");
        return;
    }
    if( ! Base::Utils::ByteArrays::RawHexStrToArr(ui->ed25529_textEdit_Message->toPlainText(), message, &message_len, sizeof(message)) )
    {
        this->Status_EndWithError("Failed to read message from UI");
        return;
    }

    /* create signature on the message with the key pair */
    ed25519_sign(signature, private_key, public_key, message, message_len);

    // Write signature to UI
    ui->ed25529_textEdit_Signature->setText( Base::Utils::ByteArrays::Uint8ArrToHexQStr(signature, sizeof(signature)));

    this->Status_EndWithSuccess("Signature generated");

}

void UiDigitalSignatures::on_ed25519_pushButton_VerifySignature_clicked()
{
    uint8_t public_key[32];
    uint8_t signature[64];
    uint8_t message[10000];
    ssize_t message_len, public_key_len, signature_len;

    // Read relevant data from ui
    if( !Base::Utils::ByteArrays::RawHexStrToArr(ui->ed25529_textEdit_publicKey->text(), public_key, &public_key_len, sizeof(public_key)) )
    {
        this->Status_EndWithError("Failed to read public key from UI");
        return;
    }
    if( !Base::Utils::ByteArrays::RawHexStrToArr(ui->ed25529_textEdit_Signature->text(), signature, &signature_len, sizeof(signature)) )
    {
        this->Status_EndWithError("Failed to read signature from UI");
        return;
    }
    if( ! Base::Utils::ByteArrays::RawHexStrToArr(ui->ed25529_textEdit_Message->toPlainText(), message, &message_len, sizeof(message)) )
    {
        this->Status_EndWithError("Failed to read message from UI");
        return;
    }

    /* verify the signature */
    if (ed25519_verify(signature, public_key, message, message_len))
    {
        Base::Utils::Widgets::MsgBoxPopup("Signature status", "Signature OK");
    }
    else
    {
        Base::Utils::Widgets::AlertPopup("Signature status","Signature NOT ok");
    }
}

void UiDigitalSignatures::on_pushButton_Signature_ED25519_Clear_clicked()
{
    this->ui->ed25529_textEdit_privateKey->clear();
    this->ui->ed25529_textEdit_publicKey->clear();
}