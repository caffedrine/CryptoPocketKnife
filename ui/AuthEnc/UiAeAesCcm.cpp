//
// Created by uib74520 on 2023-08-13.
//

// You may need to build the project (run Qt uic code generator) to get "ui_UiAeAesCcm.h" resolved

#include "UiAeAesCcm.h"
#include "ui_UiAeAesCcm.h"


UiAeAesCcm::UiAeAesCcm(QWidget *parent) :
        QMainWindow(parent), ui(new Ui::UiAeAesCcm)
{
    ui->setupUi(this);
}

UiAeAesCcm::~UiAeAesCcm()
{
    delete ui;
}
