#include "Network.h"
#include "ui_Network.h"


Network::Network(QWidget *parent): QWidget(parent), ui(new Ui::Network)
{
    ui->setupUi(this);
}

Network::~Network()
{
    delete ui;
}

