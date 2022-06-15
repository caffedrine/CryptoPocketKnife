#include "DigitalSignatures.h"
#include "ui_DigitalSignatures.h"


DigitalSignatures::DigitalSignatures(QWidget *parent): QWidget(parent), ui(new Ui::DigitalSignatures)
{
    ui->setupUi(this);
}

DigitalSignatures::~DigitalSignatures()
{
    delete ui;
}
