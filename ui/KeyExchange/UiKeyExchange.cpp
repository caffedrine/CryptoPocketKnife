#include "UiKeyExchange.h"
#include "ui_UiKeyExchange.h"

#include <QDebug>
#include <QRandomGenerator>
#include <eddsa.h>
#include "base/crypto/Hash.h"
#include <QUtils/QUtils.h>
#include <QWidgets/QWidgetsUtils.h>

UiKeyExchange::UiKeyExchange(QWidget *parent): QWidget(parent), ui(new Ui::UiKeyExchange)
{
    ui->setupUi(this);
}

UiKeyExchange::~UiKeyExchange()
{
    delete ui;
}

void UiKeyExchange::Status_EndWithError(QString err_msg)
{
    qCritical().nospace().noquote() << "ERROR: " + err_msg;
}

void UiKeyExchange::Status_EndWithSuccess(QString err_msg)
{
    qDebug().nospace().noquote() << "SUCCESS: " + err_msg;
}

void UiKeyExchange::Status_Clear()
{

}

/*   _  __                          _
    | |/ /                         | |
    | ' / ___ _   _    _____  _____| |__   __ _ _ __   __ _  ___
    |  < / _ \ | | |  / _ \ \/ / __| '_ \ / _` | '_ \ / _` |/ _ \
    | . \  __/ |_| | |  __/>  < (__| | | | (_| | | | | (_| |  __/
    |_|\_\___|\__, |  \___/_/\_\___|_| |_|\__,_|_| |_|\__, |\___|
               __/ |                                   __/ |
              |___/                                   |___/
*/
void UiKeyExchange::on_x25519_pushButton_Clear_clicked()
{
    ui->x25529_textEdit_ownSharedSecret->setText("");
    ui->x25529_textEdit_otherSharedSecret->setText("");
    ui->x25529_textEdit_ownPrivateKey->setText("");
    ui->x25529_textEdit_ownPublicKey->setText("");
    ui->x25529_textEdit_otherPrivateKey->setText("");
    ui->x25529_textEdit_otherPublicKey->setText("");
}

void UiKeyExchange::on_x25519_pushButton_GenerateEphemeralKeys_clicked()
{
    uint8_t own_public_key[X25519_KEY_LEN], other_public_key[X25519_KEY_LEN];
    uint8_t own_private_key[X25519_KEY_LEN], other_private_key[X25519_KEY_LEN];

    // Read or generate own private key
    QByteArray tmpArr = Base::Utils::ByteArrays::RawHexStrToQByteArr(this->ui->x25529_textEdit_ownPrivateKey->text());
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
    tmpArr = Base::Utils::ByteArrays::RawHexStrToQByteArr(this->ui->x25529_textEdit_otherPrivateKey->text());
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
    ui->x25529_textEdit_ownPrivateKey->setText( Utils_Uint8ArrToHexQStr(own_private_key, sizeof(own_private_key)));
    ui->x25529_textEdit_ownPublicKey->setText( Utils_Uint8ArrToHexQStr(own_public_key, sizeof(own_public_key)));
    ui->x25529_textEdit_otherPrivateKey->setText( Utils_Uint8ArrToHexQStr(other_private_key, sizeof(other_private_key)));
    ui->x25529_textEdit_otherPublicKey->setText( Utils_Uint8ArrToHexQStr(other_public_key, sizeof(other_public_key)));
}

void UiKeyExchange::on_x25519_pushButton_CalculateSharedSecret_clicked()
{
    uint8_t own_shared_secret[X25519_KEY_LEN], other_shared_secret[X25519_KEY_LEN];
    uint8_t own_public_key[X25519_KEY_LEN], other_public_key[X25519_KEY_LEN];
    uint8_t own_private_key[X25519_KEY_LEN], other_private_key[X25519_KEY_LEN];
    ssize_t own_public_key_len, own_private_key_len, other_public_key_len, other_private_key_len;

    // Read keys from UI
    if( !Utils_RawHexStrToArr(ui->x25529_textEdit_ownPrivateKey->text(), own_private_key, &own_private_key_len, sizeof(own_private_key)) )
    {
        this->Status_EndWithError("Failed to read data from UI");
        return;
    }
    if( !Utils_RawHexStrToArr(ui->x25529_textEdit_ownPublicKey->text(), own_public_key, &own_public_key_len, sizeof(own_public_key)) )
    {
        this->Status_EndWithError("Failed to read data from UI");
        return;
    }
    if( ! Utils_RawHexStrToArr(ui->x25529_textEdit_otherPrivateKey->text(), other_private_key, &other_private_key_len, sizeof(other_private_key)) )
    {
        this->Status_EndWithError("Failed to read data from UI");
        return;
    }
    if( ! Utils_RawHexStrToArr(ui->x25529_textEdit_otherPublicKey->text(), other_public_key, &other_public_key_len, sizeof(other_public_key)) )
    {
        this->Status_EndWithError("Failed to read data from UI");
        return;
    }

    // Try to obtain the same shared secret by only using public keys
    x25519(own_shared_secret, own_private_key, other_public_key);
    x25519(other_shared_secret, other_private_key, own_public_key);

    // Send again to the UI the input that was used (properly formatted)
    ui->x25529_textEdit_ownPrivateKey->setText( Utils_Uint8ArrToHexQStr(own_private_key, sizeof(own_private_key)));
    ui->x25529_textEdit_ownPublicKey->setText( Utils_Uint8ArrToHexQStr(own_public_key, sizeof(own_public_key)));
    ui->x25529_textEdit_otherPrivateKey->setText( Utils_Uint8ArrToHexQStr(other_private_key, sizeof(other_private_key)));
    ui->x25529_textEdit_otherPublicKey->setText( Utils_Uint8ArrToHexQStr(other_public_key, sizeof(other_public_key)));

    // Send calculated keys to UI
    ui->x25529_textEdit_ownSharedSecret->setText( Utils_Uint8ArrToHexQStr(own_shared_secret, sizeof(own_shared_secret)));
    ui->x25529_textEdit_otherSharedSecret->setText( Utils_Uint8ArrToHexQStr(other_shared_secret, sizeof(other_shared_secret)));
}

void UiKeyExchange::on_x25519_pushButton_CalcSymKeys_clicked()
{
    ssize_t ownSharedSecret_len, otherSharedSecret_len, nonce_len;
    uint8_t ownSharedSecret[32] = {0}, otherSharedSecret[32] = {0};
    uint8_t ownSymKey[16] = {0}, otherSymKey[16] = {0};
    uint8_t ownAesIv[16] = {0}, otherAesIv[16] = {0};
    uint8_t nonce[32] = {0};
    uint8_t hashMaterial[sizeof(ownSharedSecret) + sizeof(nonce)] = {0}, hashResult[64] = {0};

    if( !Utils_RawHexStrToArr(ui->x25529_textEdit_ownSharedSecret->text(), ownSharedSecret, &ownSharedSecret_len, sizeof(ownSharedSecret)) )
    {
        this->Status_EndWithError("Failed to read data from UI");
        return;
    }
    if( !Utils_RawHexStrToArr(ui->x25529_textEdit_otherSharedSecret->text(), otherSharedSecret, &otherSharedSecret_len, sizeof(otherSharedSecret)) )
    {
        this->Status_EndWithError("Failed to read data from UI");
        return;
    }
    if( !Utils_RawHexStrToArr(ui->x25529_textEdit_nonce->text(), nonce, &nonce_len, sizeof(nonce)) )
    {
        this->Status_EndWithError("Failed to read data from UI");
        return;
    }

    //Sym key is calculated using the following formula: hash = sha512(nonce + shared_secret); key = 16 msb of hash result, IV = 16 lsb of hash result
    // concat nonce + shared secret

    /// Calc OWN sym keys
    memcpy(hashMaterial, nonce, sizeof (nonce));
    memcpy(&hashMaterial[sizeof(nonce)], ownSharedSecret, sizeof(ownSharedSecret));
    // Calculate hash
     (hashMaterial, sizeof(hashMaterial), hashResult);
    // Extract key and IV from calculated hash
    memcpy(ownSymKey, hashResult, 16u);
    memcpy(ownAesIv, &hashResult[sizeof (hashResult) - 16u], 16u);

    /// Calc OTHEr sym keys
    memcpy(hashMaterial, nonce, sizeof (nonce));
    memcpy(&hashMaterial[sizeof(nonce)], otherSharedSecret, sizeof(otherSharedSecret));
    // Calculate hash
    QByteArray hashResultTmp = base::Crypto::Hash::SHA2_512(QByteArray(reinterpret_cast<const char *>(hashMaterial), sizeof(hashMaterial)));
    memcpy(hashResult, hashResultTmp.data(), hashResultTmp.size());
    // Extract key and IV from calculated hash
    memcpy(otherSymKey, hashResult, 16u);
    memcpy(otherAesIv, &hashResult[sizeof (hashResult) - 16u], 16u);

    // Send data to ui
    ui->x25529_textEdit_ownAesKey->setText(Utils_Uint8ArrToHexQStr(ownSymKey, sizeof(ownSymKey)));
    ui->x25529_textEdit_ownAesIv->setText(Utils_Uint8ArrToHexQStr(ownAesIv, sizeof(ownAesIv)));
    ui->x25529_textEdit_otherAesKey->setText(Utils_Uint8ArrToHexQStr(otherSymKey, sizeof(otherSymKey)));
    ui->x25529_textEdit_otherAesIv->setText(Utils_Uint8ArrToHexQStr(otherAesIv, sizeof(otherAesIv)));

}