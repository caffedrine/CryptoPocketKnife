#include "UiDigitalSignatures.h"
#include "ui_UiDigitalSignatures.h"


UiDigitalSignatures::UiDigitalSignatures(QWidget *parent): QWidget(parent), ui(new Ui::UiDigitalSignatures)
{
    ui->setupUi(this);
}

UiDigitalSignatures::~UiDigitalSignatures()
{
    delete ui;
}
