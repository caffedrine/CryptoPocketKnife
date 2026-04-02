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

/* BRAINPOOL */

//void UiDigitalSignatures::on_brainpool_comboBox_currentTextChanged()
//{
//    QString privateKeySize, publicKeySize;
//
//    static QMap<QString, QPair<int, int>> brainpoolKeysSizes = {
//            {"brainpoolP160r1", {20, 40}},
//            {"brainpoolP192r1", {24, 48}},
//            {"brainpoolP224r1", {28, 56}},
//            {"brainpoolP256r1", {32, 64}},
//            {"brainpoolP320r1", {40, 80}},
//            {"brainpoolP384r1", {48, 96}},
//            {"brainpoolP512r1", {64, 128}}
//    };
//
//    for(auto it = brainpoolKeysSizes.begin(); it != brainpoolKeysSizes.end(); ++it)
//    {
//        if( this->ui->brainpool_comboBox->currentText().toLower().contains(it.key().toLower()) )
//        {
//            privateKeySize = QString::number(it.value().first);
//            publicKeySize = QString::number(it.value().second);
//            break;
//        }
//    }
//
//    this->ui->brainpool_label_PrivateKey->setText("Private key ("+privateKeySize+" bytes)");
//    this->ui->brainpool_label_PublicKey->setText("Public key ("+publicKeySize+" bytes)");
//}
