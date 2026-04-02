#include "UiKeyExchange.h"
#include "ui_UiKeyExchange.h"

#include <QDebug>
#include <QRandomGenerator>
#include <eddsa.h>

#include <QCrypto/Hash.h>
#include <QUtils/QUtils.h>
#include <QWidgets/QWidgetsUtils.h>

UiKeyExchange::UiKeyExchange(QWidget *parent): QWidget(parent), ui(new Ui::UiKeyExchange)
{
    ui->setupUi(this);
}

UiKeyExchange::~UiKeyExchange()
{
    delete ui;
}