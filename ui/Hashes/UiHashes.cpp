#include "UiHashes.h"
#include "ui_UiHashes.h"

#include "base/utils/utils.h"
#include "base/crypto/Hash.h"

UiHashes::UiHashes(QWidget *parent): QWidget(parent), ui(new Ui::UiHashes)
{
    ui->setupUi(this);
}

UiHashes::~UiHashes()
{
    delete ui;
}

/*   _    _           _
    | |  | |         | |
    | |__| | __ _ ___| |__   ___  ___
    |  __  |/ _` / __| '_ \ / _ \/ __|
    | |  | | (_| \__ \ | | |  __/\__ \
    |_|  |_|\__,_|___/_| |_|\___||___/
*/
void UiHashes::on_textBrowser_SHA2_InputBytes_textChanged()
{
    QByteArray bytes = Utils_RawHexStrToQByteArr(this->ui->textBrowser_SHA2_InputBytes->toPlainText());
    if( bytes.length() <= 0 )
    {
        return;
    }

    // Calculate SHA2 224 hash
    this->ui->lineEdit_SHA2_224_OUTPUT->setText( Utils_QByteArrayToHexQStr(Crypto::Hash::SHA2_224(bytes)));

    // Calculate SHA2 256 hash
    this->ui->lineEdit_SHA2_256_OUTPUT->setText( Utils_QByteArrayToHexQStr(Crypto::Hash::SHA2_256(bytes)));

    // Calculate SHA2 384 hash
    this->ui->lineEdit_SHA2_384_Output->setText( Utils_QByteArrayToHexQStr(Crypto::Hash::SHA2_384(bytes)));

    // Calculate SHA2 512 hash
    this->ui->lineEdit_SHA2_512_OUTPUT->setText( Utils_QByteArrayToHexQStr(Crypto::Hash::SHA2_512(bytes)));

    // Calculate SHA2 512/224 hash
    this->ui->lineEdit_SHA2_512_224_Output->setText( Utils_QByteArrayToHexQStr(Crypto::Hash::SHA2_512_224(bytes)));

    // Calculate SHA2 512/256 hash
    this->ui->lineEdit_SHA2_512_256_Output->setText( Utils_QByteArrayToHexQStr(Crypto::Hash::SHA2_512_256(bytes)));
}

void UiHashes::on_textBrowser_SHA1_InputBytes_textChanged()
{
    QByteArray bytes = Utils_RawHexStrToQByteArr(this->ui->textBrowser_SHA1_InputBytes->toPlainText());
    if( bytes.length() <= 0 )
    {
        return;
    }

    // Calculate SHA1 hash
    QByteArray hash = Crypto::Hash::SHA1(bytes);
    this->ui->lineEdit_SHA1_Output->setText( Utils_QByteArrayToHexQStr(hash));
}

void UiHashes::on_textBrowser_MD5_InputBytes_textChanged()
{
    QByteArray bytes = Utils_RawHexStrToQByteArr(this->ui->textBrowser_MD5_InputBytes->toPlainText());
    if( bytes.length() <= 0 )
    {
        return;
    }

    // Calculate MD5 hash
    QByteArray hash = Crypto::Hash::MD5(bytes);
    this->ui->lineEdit_MD5_Output->setText( Utils_QByteArrayToHexQStr(hash));
}

void UiHashes::on_textBrowser_SHA3_InputBytes_textChanged()
{
    QByteArray bytes = Utils_RawHexStrToQByteArr(this->ui->textBrowser_SHA3_InputBytes->toPlainText());
    if( bytes.length() <= 0 )
    {
        return;
    }

    this->ui->lineEdit_SHA3_224_OUTPUT->setText( Utils_QByteArrayToHexQStr(Crypto::Hash::SHA3_224(bytes)));
    this->ui->lineEdit_SHA3_256_OUTPUT->setText( Utils_QByteArrayToHexQStr(Crypto::Hash::SHA3_256(bytes)));
    this->ui->lineEdit_SHA3_384_Output->setText( Utils_QByteArrayToHexQStr(Crypto::Hash::SHA3_384(bytes)));
    this->ui->lineEdit_SHA3_512_OUTPUT->setText( Utils_QByteArrayToHexQStr(Crypto::Hash::SHA3_512(bytes)));

}

void UiHashes::on_textBrowser_BLAKE2_InputBytes_textChanged()
{
    QByteArray bytes = Utils_RawHexStrToQByteArr(this->ui->textBrowser_BLAKE2_InputBytes->toPlainText());
    if( bytes.length() <= 0 )
    {
        return;
    }

    this->ui->lineEdit_BLAKE2B_160_OUTPUT->setText( Utils_QByteArrayToHexQStr(Crypto::Hash::BLAKE2B_160(bytes)));
    this->ui->lineEdit_BLAKE2B_256_OUTPUT_3->setText( Utils_QByteArrayToHexQStr(Crypto::Hash::BLAKE2B_256(bytes)));
    this->ui->lineEdit_BLAKE2B_384_OUTPUT->setText( Utils_QByteArrayToHexQStr(Crypto::Hash::BLAKE2B_384(bytes)));
    this->ui->lineEdit_BLAKE2B_512_OUTPUT->setText( Utils_QByteArrayToHexQStr(Crypto::Hash::BLAKE2B_512(bytes)));

    this->ui->lineEdit_BLAKE2S_128_OUTPUT->setText( Utils_QByteArrayToHexQStr(Crypto::Hash::BLAKE2S_128(bytes)));
    this->ui->lineEdit_BLAKE2S_160_OUTPUT->setText( Utils_QByteArrayToHexQStr(Crypto::Hash::BLAKE2S_160(bytes)));
    this->ui->lineEdit_BLAKE2S_224_OUTPUT->setText( Utils_QByteArrayToHexQStr(Crypto::Hash::BLAKE2S_224(bytes)));
    this->ui->lineEdit_BLAKE2S_256_OUTPUT->setText( Utils_QByteArrayToHexQStr(Crypto::Hash::BLAKE2S_256(bytes)));
}

void UiHashes::on_textBrowser_KECCAK_InputBytes_textChanged()
{
    QByteArray bytes = Utils_RawHexStrToQByteArr(this->ui->textBrowser_KECCAK_InputBytes->toPlainText());
    if( bytes.length() <= 0 )
    {
        return;
    }

    this->ui->lineEdit_KECCAK_224_OUTPUT->setText( Utils_QByteArrayToHexQStr(Crypto::Hash::KECCAK_224(bytes)));
    this->ui->lineEdit_KECCAK_256_OUTPUT->setText( Utils_QByteArrayToHexQStr(Crypto::Hash::KECCAK_256(bytes)));
    this->ui->lineEdit_KECCAK_384_Output->setText( Utils_QByteArrayToHexQStr(Crypto::Hash::KECCAK_384(bytes)));
    this->ui->lineEdit_KECCAK_512_OUTPUT->setText( Utils_QByteArrayToHexQStr(Crypto::Hash::KECCAK_512(bytes)));
}
