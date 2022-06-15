#include "UiOSINT.h"
#include "ui_UiOSINT.h"


UiOSINT::UiOSINT(QWidget *parent) :
        QWidget(parent), ui(new Ui::UiOSINT)
{
    ui->setupUi(this);
}

UiOSINT::~UiOSINT()
{
    delete ui;
}
