#include "UiMac.h"
#include "ui_UiMac.h"

UiMac::UiMac(QWidget *parent) :
        QMainWindow(parent), ui(new Ui::UiMac)
{
    ui->setupUi(this);

    // Initialize MAC tab
    UiAesCmac *aesCmac = new UiAesCmac(this);
    aesCmac->setWindowFlags(Qt::Widget);
    this->ui->gridLayout_AesCmac->addWidget(aesCmac);

    // Initialize MAC tab
    UiAesGmac *aesGmac = new UiAesGmac(this);
    aesGmac->setWindowFlags(Qt::Widget);
    this->ui->gridLayout_AesGmac->addWidget(aesGmac);

    // Initialize MAC tab
    UiHmacSha *hmac = new UiHmacSha(this);
    hmac->setWindowFlags(Qt::Widget);
    this->ui->gridLayout_Hmac->addWidget(hmac);
}

UiMac::~UiMac()
{
    delete ui;
}
