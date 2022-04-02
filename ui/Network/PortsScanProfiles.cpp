#include "PortsScanProfiles.h"
#include "ui_PortsScanProfiles.h"


PortsScanProfiles::PortsScanProfiles(QWidget *parent) : QDialog(parent), ui(new Ui::PortsScanProfiles)
{
    ui->setupUi(this);
}

PortsScanProfiles::~PortsScanProfiles()
{
    delete ui;
}

