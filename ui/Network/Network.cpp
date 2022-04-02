#include "Network.h"
#include "ui_Network.h"


Network::Network(QWidget *parent): QWidget(parent), ui(new Ui::Network)
{
    ui->setupUi(this);

    QList<PortsScanProfileType> allProfiles = PortsScanProfilesManager::instance().GetAll();
    for(const PortsScanProfileType &profile: allProfiles)
    {
        ui->comboBox_ScanProfiles->addItem(profile.ProfileName);
    }

}

Network::~Network()
{
    delete ui;
}

void Network::onButtonClicked_ManageScanProfiles()
{
    PortsScanProfiles scanProfilesUi(nullptr);
    scanProfilesUi.exec();
}

