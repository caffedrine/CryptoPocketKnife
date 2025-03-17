#include "UiDsaSECP.h"
#include "ui_UiDsaSECP.h"
#include <QUtils/QUtils.h>
#include <QWidgets/QWidgetsUtils.h>
#include <CryptoPrimitives/DsaSecp.h>
#include <QCrypto/Rng.h>
UiDsaSECP::UiDsaSECP(QWidget *parent): QWidget(parent), ui(new Ui::UiDsaSECP)
{
    ui->setupUi(this);

    this->on_comboBox_AlgoName_currentTextChanged();
    this->ui->comboBox_AlgoName->setCurrentIndex(4); // secp521r1 vby default
}

UiDsaSECP::~UiDsaSECP()
{
    delete ui;
}

void UiDsaSECP::on_comboBox_AlgoName_currentTextChanged()
{
    // Secp keys sizes
    static QList secpKeysInfo = {
            // secp r1 sizes
            UiDsaSecp_CurrAlgo("secp160r1 (P-160)", 21, 20, Base::CryptoPrimitives::secp160r1),
            UiDsaSecp_CurrAlgo("secp224r1 (P-224)", 28, 56, Base::CryptoPrimitives::secp224r1),
            UiDsaSecp_CurrAlgo("secp256r1 (P-256)", 32, 64, Base::CryptoPrimitives::secp256r1),
            UiDsaSecp_CurrAlgo("secp384r1 (P-384)", 48, 96, Base::CryptoPrimitives::secp384r1),
            UiDsaSecp_CurrAlgo("secp521r1 (P-521)", 66, 132, Base::CryptoPrimitives::secp521r1),

            // secp K1 sizes
            UiDsaSecp_CurrAlgo("secp192k1", 24, 48, Base::CryptoPrimitives::secp192k1),
            UiDsaSecp_CurrAlgo("secp224k1", 28, 56, Base::CryptoPrimitives::secp224k1),
            UiDsaSecp_CurrAlgo("secp256k1", 32, 64, Base::CryptoPrimitives::secp256k1)
    };

    // find the match in combobox and populate output strings
    bool found = false;
    for(auto it = secpKeysInfo.begin(); it != secpKeysInfo.end(); ++it)
    {
        if( this->ui->comboBox_AlgoName->currentText().toLower().contains(it->name.toLower()) )
        {
            this->currAlgo = *it;
            found = true;
            break;
        }
    }

    // Algo not found?
    if( !found )
    {
        this->currAlgo.name = "";
        this->currAlgo.pubKeySizeBytes = 0;
        this->currAlgo.privKeySizeBytes = 0;
        this->currAlgo.algoId = -1;
    }

    // Update the ui
    this->on_textEdit_privateKey_textChanged( this->ui->textEdit_privateKey->text() );
    this->on_textEdit_publicKey_textChanged( this->ui->textEdit_publicKey->text() );
}

void UiDsaSECP::on_textEdit_privateKey_textChanged(const QString &arg1)
{
    QByteArray currBytes = Base::Utils::ByteArrays::RawHexStrToQByteArr(this->ui->textEdit_privateKey->text());
    QString currSize = QString::number(currBytes.length());
    QString targetSize = QString::number(this->currAlgo.privKeySizeBytes);
    this->ui->label_PrivateKey->setText( QString("Private key (%1/%2 bytes)").arg(currSize, targetSize) );
}

void UiDsaSECP::on_textEdit_publicKey_textChanged(const QString &arg1)
{
    QByteArray currBytes = Base::Utils::ByteArrays::RawHexStrToQByteArr(this->ui->textEdit_publicKey->text());
    QString currSize = QString::number(currBytes.length());
    QString targetSize = QString::number(this->currAlgo.pubKeySizeBytes);
    this->ui->label_PublicKey->setText( QString("Public key (%1/%2 bytes)").arg(currSize, targetSize) );
}

void UiDsaSECP::on_pushButton_GenerateKeysPair_clicked()
{
    QByteArray currBytes = Base::Utils::ByteArrays::RawHexStrToQByteArr(this->ui->textEdit_privateKey->text());

    if( !currBytes.isEmpty() && currBytes.length() != this->currAlgo.privKeySizeBytes)
    {
        Base::Utils::Widgets::AlertPopup("Invalid input",
              QString("Invalid private key length: got %1 bytes, expected %2").arg(currBytes.length()).arg(this->currAlgo.privKeySizeBytes) );
        return;
    }

    // Generate a new key if input is empty
    if( currBytes.isEmpty() )
    {
        currBytes = Base::Crypto::Rng::GetRandomBytes(this->currAlgo.privKeySizeBytes);
        currBytes[0] = 0x00; // all keys starting with 0x00 will be valid? don't know why.
        this->ui->textEdit_privateKey->setText(currBytes.toHex(' '));
    }

    // Calculate the public key
    Base::CryptoPrimitives::DsaSecp secpHandler( (Base::CryptoPrimitives::dsa_secp_curve_t )currAlgo.algoId);
    QByteArray publicKey = Base::Utils::ByteArrays::StdVectorToQByteArray(secpHandler.CalcPubKey( Base::Utils::ByteArrays::QByteArrayToStdVector(currBytes) ));

    // Send it to the ui
    this->ui->textEdit_publicKey->setText(publicKey.toHex(' '));
}

void UiDsaSECP::on_pushButton_Keys_Clear_clicked()
{
    this->ui->textEdit_privateKey->clear();
    this->ui->textEdit_publicKey->clear();
}

void UiDsaSECP::on_pushButton_CalculateSignature_clicked()
{

}

void UiDsaSECP::on_pushButton_VerifySignature_clicked()
{

}
