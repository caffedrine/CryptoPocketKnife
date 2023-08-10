//
// Created by uib74520 on 2023-08-10.
//

// You may need to build the project (run Qt uic code generator) to get "ui_UiHmac.h" resolved

#include "UiHmac.h"
#include "ui_UiHmac.h"


UiHmac::UiHmac(QWidget *parent) :
        QMainWindow(parent), ui(new Ui::UiHmac)
{
    ui->setupUi(this);
}

UiHmac::~UiHmac()
{
    delete ui;
}
