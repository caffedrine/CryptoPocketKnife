#include "UiKdf.h"
#include "ui_UiKdf.h"


UiKdf::UiKdf(QWidget *parent) :
        QMainWindow(parent), ui(new Ui::UiKdf)
{
    ui->setupUi(this);
}

UiKdf::~UiKdf()
{
    delete ui;
}
