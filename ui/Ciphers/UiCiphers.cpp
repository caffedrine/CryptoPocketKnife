#include "UiCiphers.h"
#include "ui_UiCiphers.h"

#include <QUtils/QUtils.h>
#include <QWidgets/QWidgetsUtils.h>

UiCiphers::UiCiphers(QWidget *parent): QWidget(parent), ui(new Ui::UiCiphers)
{
    ui->setupUi(this);
}

UiCiphers::~UiCiphers()
{
    delete ui;
}