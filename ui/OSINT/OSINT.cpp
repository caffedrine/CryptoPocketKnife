#include "OSINT.h"
#include "ui_OSINT.h"


OSINT::OSINT(QWidget *parent) :
        QWidget(parent), ui(new Ui::OSINT)
{
    ui->setupUi(this);
}

OSINT::~OSINT()
{
    delete ui;
}
