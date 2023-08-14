#include "AuthenticatedEncryption.h"
#include "ui_AuthenticatedEncryption.h"

#include "ui/AE/UiAeAesCcm.h"
#include "ui/AE/UiAeAesGcm.h"

AuthenticatedEncryption::AuthenticatedEncryption(QWidget *parent): QMainWindow(parent), ui(new Ui::AuthenticatedEncryption)
{
    ui->setupUi(this);

    // Initialize CCM tab
    UiAeAesCcm *aesCcm = new UiAeAesCcm(this);
    aesCcm->setWindowFlags(Qt::Widget);
    this->ui->gridLayout_AesCcm->addWidget(aesCcm);

    // Initialize GCM tab
    UiAeAesGcm *aesGcm = new UiAeAesGcm(this);
    aesGcm->setWindowFlags(Qt::Widget);
    this->ui->gridLayout_AesGcm->addWidget(aesGcm);
}

AuthenticatedEncryption::~AuthenticatedEncryption()
{
    delete ui;
}
