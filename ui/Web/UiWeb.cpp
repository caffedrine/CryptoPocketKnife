#include "UiWeb.h"
#include "ui_UiWeb.h"

UiWeb::UiWeb(QWidget *parent): QWidget(parent), ui(new Ui::UiWeb)
{
    ui->setupUi(this);

    webRequestsMainwindow = new UiHttpWebRequests(this);
    webRequestsMainwindow->setWindowFlags(Qt::Widget);
    this->ui->gridLayout_HttpWebRequests->addWidget(webRequestsMainwindow);
}

UiWeb::~UiWeb()
{
    delete ui;
}

