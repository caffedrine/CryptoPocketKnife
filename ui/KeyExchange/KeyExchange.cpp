#include "KeyExchange.h"
#include "ui_KeyExchange.h"


KeyExchange::KeyExchange(QWidget *parent) :
        QWidget(parent), ui(new Ui::KeyExchange)
{
    ui->setupUi(this);
}

KeyExchange::~KeyExchange()
{
    delete ui;
}
