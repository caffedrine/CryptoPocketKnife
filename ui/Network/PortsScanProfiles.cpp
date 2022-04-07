#include "PortsScanProfiles.h"
#include "ui_PortsScanProfiles.h"

PortsScanProfiles::PortsScanProfiles(QWidget *parent): QDialog(parent), ui(new Ui::PortsScanProfiles)
{
    ui->setupUi(this);

    QList<PortsScanProfileType> allProfiles = PortsScanProfilesManager::instance().GetAll();
    for(const PortsScanProfileType &profile: allProfiles)
    {
        ui->listWidget_AvailableProfiles->addItem(profile.ProfileName);
    }
}

PortsScanProfiles::~PortsScanProfiles()
{
    delete ui;
}

void PortsScanProfiles::onSelectedItemChanged_AvailableProfiles()
{
    this->ui->tableWidget_ProfileTargets->model()->removeRows(0,  this->ui->tableWidget_ProfileTargets->rowCount());

    QString currentProfileName = ui->listWidget_AvailableProfiles->currentItem()->text();

    for( PortsScanTargetType target: PortsScanProfilesManager::instance().GetByName(currentProfileName).Targets )
    {
        const int currentRow = this->ui->tableWidget_ProfileTargets->rowCount();
        this->ui->tableWidget_ProfileTargets->setRowCount(currentRow + 1);
        this->ui->tableWidget_ProfileTargets->setItem(currentRow, 0, new QTableWidgetItem(target.TargetType));
        this->ui->tableWidget_ProfileTargets->setItem(currentRow, 1, new QTableWidgetItem(target.TargetName));
        this->ui->tableWidget_ProfileTargets->setItem(currentRow, 2, new QTableWidgetItem(target.VendorName));
        this->ui->tableWidget_ProfileTargets->setItem(currentRow, 3, new QTableWidgetItem(target.GetTcpPortsString()));
        this->ui->tableWidget_ProfileTargets->setItem(currentRow, 4, new QTableWidgetItem(target.GetUdpPortsString()));
        this->ui->tableWidget_ProfileTargets->setItem(currentRow, 5, new QTableWidgetItem(target.ShodanDorks.join(',')));
        this->ui->tableWidget_ProfileTargets->setItem(currentRow, 6, new QTableWidgetItem(target.nMapArguments));
        this->ui->tableWidget_ProfileTargets->setItem(currentRow, 7, new QTableWidgetItem(target.Description));
    }
}

void PortsScanProfiles::setCurrentIndex(int index)
{
    this->ui->listWidget_AvailableProfiles->setCurrentRow(index);
    onSelectedItemChanged_AvailableProfiles();
}

