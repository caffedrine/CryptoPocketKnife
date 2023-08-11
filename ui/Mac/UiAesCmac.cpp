#include "UiAesCmac.h"
#include "ui_UiAesCmac.h"


UiAesCmac::UiAesCmac(QWidget *parent) : QMainWindow(parent), ui(new Ui::UiAesCmac)
{
    ui->setupUi(this);
}

UiAesCmac::~UiAesCmac()
{
    delete ui;
}
