/*  
 *  File      : PortsScanProfiles.h
 *  Created on: 2022-04-02
 */

// You may need to build the project (run Qt uic code generator) to get "ui_PortsScanProfiles.h" resolved

#include "PortsScanProfiles.h"
#include "ui_PortsScanProfiles.h"


PortsScanProfiles::PortsScanProfiles(QWidget *parent) :
        QWidget(parent), ui(new Ui::PortsScanProfiles)
{
    ui->setupUi(this);
}

PortsScanProfiles::~PortsScanProfiles()
{
    delete ui;
}

