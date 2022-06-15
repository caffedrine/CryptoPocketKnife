#include "Ciphers.h"
#include "ui_Ciphers.h"


Ciphers::Ciphers(QWidget *parent) :
        QWidget(parent), ui(new Ui::Ciphers)
{
    ui->setupUi(this);
}

Ciphers::~Ciphers()
{
    delete ui;
}
