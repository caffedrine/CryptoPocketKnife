#include "UiKeyExchange.h"
#include "ui_UiKeyExchange.h"

UiKeyExchange::UiKeyExchange(QWidget *parent): QWidget(parent), ui(new Ui::UiKeyExchange)
{
    ui->setupUi(this);
}

UiKeyExchange::~UiKeyExchange()
{
    delete ui;
}
