//
// Created by uib74520 on 2023-08-10.
//

// You may need to build the project (run Qt uic code generator) to get "ui_UiAesGmac.h" resolved

#include "UiAesGmac.h"
#include "ui_UiAesGmac.h"


UiAesGmac::UiAesGmac(QWidget *parent) :
        QMainWindow(parent), ui(new Ui::UiAesGmac)
{
    ui->setupUi(this);
}

UiAesGmac::~UiAesGmac()
{
    delete ui;
}
