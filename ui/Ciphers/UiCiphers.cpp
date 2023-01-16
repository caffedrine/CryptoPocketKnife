#include "UiCiphers.h"
#include "ui_UiCiphers.h"

#include "base/utils/utils.h"

UiCiphers::UiCiphers(QWidget *parent): QWidget(parent), ui(new Ui::UiCiphers)
{
    ui->setupUi(this);
}

UiCiphers::~UiCiphers()
{
    delete ui;
}