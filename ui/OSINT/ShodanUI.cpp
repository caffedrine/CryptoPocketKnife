#include "ShodanUI.h"
#include "ui_ShodanUI.h"

#include <QMessageBox>
#include "Shodan.h"
#include "Utils.h"

ShodanUI::ShodanUI(QWidget *parent): QWidget(parent), ui(new Ui::ShodanUI)
{
    ui->setupUi(this);
    QObject::connect(this->ui->pushButton_shodanSettings_SaveKey, SIGNAL(clicked()), this, SLOT(pushButton_shodanSettings_SaveKey_clicked()));
    QObject::connect(this->ui->pushButton_shodanSettings_TestApiKey, SIGNAL(clicked()), this, SLOT(pushButton_shodanSettings_TestApiKey_clicked()));
    QObject::connect(this->ui->pushButton_shodanSettings_GetSearchFilters, SIGNAL(clicked()), this, SLOT(pushButton_shodanSettings_GetSearchFilters_clicked()));

    QObject::connect(this->ui->pushButton_ManualQuery_GetResults, SIGNAL(clicked()), this, SLOT(pushButton_ManualQuery_GetResults_clicked()));
    QObject::connect(this->ui->pushButton_ManualQuery_Count, SIGNAL(clicked()), this, SLOT(pushButton_ManualQuery_Count_clicked()));


    this->ui->lineEdit_shodanSettings_ApiKey->setText( UserSettings->Get_OSINT_ShodanApiKey() );
}

ShodanUI::~ShodanUI()
{
    delete ui;
}

void ShodanUI::pushButton_shodanSettings_SaveKey_clicked()
{
    UserSettings->Set_OSINT_ShodanApiKey( this->ui->lineEdit_shodanSettings_ApiKey->text() );
}

void ShodanUI::pushButton_shodanSettings_TestApiKey_clicked()
{
    Utils_PushButtonStartLoading( this->ui->pushButton_shodanSettings_TestApiKey );

    Shodan shodan( UserSettings->Get_OSINT_ShodanApiKey() );
    Utils_MsgBox("Shodan reply", shodan.GetAccountInfo());

    Utils_PushButtonEndLoading( this->ui->pushButton_shodanSettings_TestApiKey );

}

void ShodanUI::pushButton_shodanSettings_GetSearchFilters_clicked()
{
    Utils_PushButtonStartLoading( this->ui->pushButton_shodanSettings_GetSearchFilters );

    Shodan shodan( UserSettings->Get_OSINT_ShodanApiKey() );
    Utils_RichTextBoxPopup("Shodan reply", shodan.GetSearchFilters());

    Utils_PushButtonEndLoading( this->ui->pushButton_shodanSettings_GetSearchFilters );
}

void ShodanUI::pushButton_ManualQuery_GetResults_clicked()
{

}

void ShodanUI::pushButton_ManualQuery_Count_clicked()
{
    Utils_PushButtonStartLoading( this->ui->pushButton_ManualQuery_Count );

    Shodan shodan( UserSettings->Get_OSINT_ShodanApiKey() );
    QString total = shodan.GetCountByQuery(this->ui->lineEdit_ManualQuery_Query->text());
    this->ui->lineEdit_ManualQuery_Count->setText(total);

    Utils_PushButtonEndLoading( this->ui->pushButton_ManualQuery_Count );
}
