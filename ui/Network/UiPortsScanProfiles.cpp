#include "UiPortsScanProfiles.h"
#include "ui_UiPortsScanProfiles.h"

UiPortsScanProfiles::UiPortsScanProfiles(QWidget *parent): QDialogExtended(parent), ui(new Ui::UiPortsScanProfiles)
{
    ui->setupUi(this);

    QList<PortsScanProfileType> allProfiles = PortsScanProfilesManager::instance().GetAll();
    for(const PortsScanProfileType &profile: allProfiles)
    {
        ui->listWidget_AvailableProfiles->addItem(profile.ProfileName);
    }
}

UiPortsScanProfiles::~UiPortsScanProfiles()
{
    delete ui;
}

void UiPortsScanProfiles::onSelectedItemChanged_AvailableProfiles()
{
    this->ui->tableWidget_ProfileTargets->model()->removeRows(0,  this->ui->tableWidget_ProfileTargets->rowCount());

    QString currentProfileName = ui->listWidget_AvailableProfiles->currentItem()->text();

    for( PortsScanTargetType target: PortsScanProfilesManager::instance().GetByName(currentProfileName).Targets )
    {
        const int currentRow = this->ui->tableWidget_ProfileTargets->rowCount();
        this->ui->tableWidget_ProfileTargets->setRowCount(currentRow + 1);

        int i = 0;
        this->ui->tableWidget_ProfileTargets->setItem(currentRow, i++, new QTableWidgetItem(target.TargetType));
        this->ui->tableWidget_ProfileTargets->setItem(currentRow, i++, new QTableWidgetItem(target.TargetName));
        this->ui->tableWidget_ProfileTargets->setItem(currentRow, i++, new QTableWidgetItem(target.GetTcpPortsString()));
        this->ui->tableWidget_ProfileTargets->setItem(currentRow, i++, new QTableWidgetItem(target.GetUdpPortsString()));
        this->ui->tableWidget_ProfileTargets->setItem(currentRow, i++, new QTableWidgetItem(target.ShodanDorks.join(',')));
        this->ui->tableWidget_ProfileTargets->setItem(currentRow, i++, new QTableWidgetItem(target.nMapArguments));
        this->ui->tableWidget_ProfileTargets->setItem(currentRow, i++, new QTableWidgetItem(target.Description));
        this->ui->tableWidget_ProfileTargets->setItem(currentRow, i++, new QTableWidgetItem(target.GitSrc));
    }
}

void UiPortsScanProfiles::setCurrentIndex(int index)
{
    this->ui->listWidget_AvailableProfiles->setCurrentRow(index);
    onSelectedItemChanged_AvailableProfiles();
}

