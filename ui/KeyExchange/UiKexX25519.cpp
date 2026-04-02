#include "UiKexX25519.h"
#include "ui_UiKexX25519.h"
#include <QDebug>
#include <QRandomGenerator>
#include <eddsa.h>

#include <QCrypto/Hash.h>
#include <QUtils/QUtils.h>
#include <QWidgets/QWidgetsUtils.h>

UiKexX25519::UiKexX25519(QWidget *parent) :
        QWidget(parent), ui(new Ui::UiKexX25519)
{
    ui->setupUi(this);
}

UiKexX25519::~UiKexX25519()
{
    delete ui;
}

void UiKexX25519::Status_EndWithError(QString err_msg)
{
    qCritical().nospace().noquote() << "ERROR: " + err_msg;
}

void UiKexX25519::Status_EndWithSuccess(QString err_msg)
{
    qDebug().nospace().noquote() << "SUCCESS: " + err_msg;
}

void UiKexX25519::Status_Clear()
{

}

void UiKexX25519::on_pushButton_Clear_clicked()
{
    ui->textEdit_ownCalcKey->setText("");
    ui->textEdit_otherCalcKey->setText("");
    ui->textEdit_ownPrivateKey->setText("");
    ui->textEdit_ownPublicKey->setText("");
    ui->textEdit_otherPrivateKey->setText("");
    ui->textEdit_otherPublicKey->setText("");
}

void UiKexX25519::on_pushButton_GenerateEphemeralKeys_clicked()
{
    uint8_t own_public_key[X25519_KEY_LEN], other_public_key[X25519_KEY_LEN];
    uint8_t own_private_key[X25519_KEY_LEN], other_private_key[X25519_KEY_LEN];

    // Read or generate own private key
    QByteArray tmpArr = Base::Utils::ByteArrays::RawHexStrToQByteArr(this->ui->textEdit_ownPrivateKey->text());
    if( tmpArr.size() != 32 )
    {
        for( size_t i = 0; i < sizeof(own_private_key); i++ )
            own_private_key[i] = (uint8_t)QRandomGenerator::global()->bounded(256);
    }
    else
    {
        memcpy(own_private_key, (uint8_t *)tmpArr.data(), sizeof(own_private_key));
    }

    // Read or generate other private key
    tmpArr = Base::Utils::ByteArrays::RawHexStrToQByteArr(this->ui->textEdit_otherPrivateKey->text());
    if( tmpArr.size() != 32 )
    {
        for( size_t i = 0; i < sizeof(other_private_key); i++ )
            other_private_key[i] = (uint8_t)QRandomGenerator::global()->bounded(256);
    }
    else
    {
        memcpy(other_private_key, (uint8_t *)tmpArr.data(), sizeof(other_private_key));
    }

    // Calculate public keys
    x25519_base(own_public_key, own_private_key);
    x25519_base(other_public_key, other_private_key);


    // Send calculated keys to UI
    ui->textEdit_ownPrivateKey->setText( Base::Utils::ByteArrays::Uint8ArrToHexQStr(own_private_key, sizeof(own_private_key)));
    ui->textEdit_ownPublicKey->setText( Base::Utils::ByteArrays::Uint8ArrToHexQStr(own_public_key, sizeof(own_public_key)));
    ui->textEdit_otherPrivateKey->setText( Base::Utils::ByteArrays::Uint8ArrToHexQStr(other_private_key, sizeof(other_private_key)));
    ui->textEdit_otherPublicKey->setText( Base::Utils::ByteArrays::Uint8ArrToHexQStr(other_public_key, sizeof(other_public_key)));
}

void UiKexX25519::on_pushButton_CalculateSharedSecret_clicked()
{
    uint8_t own_shared_secret[X25519_KEY_LEN], other_shared_secret[X25519_KEY_LEN];
    uint8_t own_public_key[X25519_KEY_LEN], other_public_key[X25519_KEY_LEN];
    uint8_t own_private_key[X25519_KEY_LEN], other_private_key[X25519_KEY_LEN];
    ssize_t own_public_key_len, own_private_key_len, other_public_key_len, other_private_key_len;

    // Read keys from UI
    if( !Base::Utils::ByteArrays::RawHexStrToArr(ui->textEdit_ownPrivateKey->text(), own_private_key, &own_private_key_len, sizeof(own_private_key)) )
    {
        this->Status_EndWithError("Failed to read data from UI");
        return;
    }
    if( !Base::Utils::ByteArrays::RawHexStrToArr(ui->textEdit_ownPublicKey->text(), own_public_key, &own_public_key_len, sizeof(own_public_key)) )
    {
        this->Status_EndWithError("Failed to read data from UI");
        return;
    }
    if( ! Base::Utils::ByteArrays::RawHexStrToArr(ui->textEdit_otherPrivateKey->text(), other_private_key, &other_private_key_len, sizeof(other_private_key)) )
    {
        this->Status_EndWithError("Failed to read data from UI");
        return;
    }
    if( ! Base::Utils::ByteArrays::RawHexStrToArr(ui->textEdit_otherPublicKey->text(), other_public_key, &other_public_key_len, sizeof(other_public_key)) )
    {
        this->Status_EndWithError("Failed to read data from UI");
        return;
    }

    // Try to obtain the same shared secret by only using public keys
    x25519(own_shared_secret, own_private_key, other_public_key);
    x25519(other_shared_secret, other_private_key, own_public_key);

    // Send again to the UI the input that was used (properly formatted)
    ui->textEdit_ownPrivateKey->setText( Base::Utils::ByteArrays::Uint8ArrToHexQStr(own_private_key, sizeof(own_private_key)));
    ui->textEdit_ownPublicKey->setText( Base::Utils::ByteArrays::Uint8ArrToHexQStr(own_public_key, sizeof(own_public_key)));
    ui->textEdit_otherPrivateKey->setText( Base::Utils::ByteArrays::Uint8ArrToHexQStr(other_private_key, sizeof(other_private_key)));
    ui->textEdit_otherPublicKey->setText( Base::Utils::ByteArrays::Uint8ArrToHexQStr(other_public_key, sizeof(other_public_key)));

    // Send calculated keys to UI
    ui->textEdit_ownCalcKey->setText( Base::Utils::ByteArrays::Uint8ArrToHexQStr(own_shared_secret, sizeof(own_shared_secret)));
    ui->textEdit_otherCalcKey->setText( Base::Utils::ByteArrays::Uint8ArrToHexQStr(other_shared_secret, sizeof(other_shared_secret)));
}