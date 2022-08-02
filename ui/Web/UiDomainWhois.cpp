#include "UiDomainWhois.h"
#include "ui_UiDomainWhois.h"

#include <QHostInfo>
#include "utils.h"

UiDomainWhois::UiDomainWhois(QWidget *parent, QString domain): QWidget(parent), ui(new Ui::UiDomainWhois)
{
    ui->setupUi(this);
    this->ui->lineEdit_DomainName->setText(domain);
}

UiDomainWhois::~UiDomainWhois()
{
    delete ui;
}

void UiDomainWhois::on_pushButton_Lookup_clicked()
{
    Utils_PushButtonStartLoading(this->ui->pushButton_Lookup);

    // Query domain info
    Services::Whois::DomainWhois whoisHandler;
    whoisHandler.GetDomainInfo(this->ui->lineEdit_DomainName->text().trimmed());

    if( !whoisHandler.WhoisServers.isEmpty() && !whoisHandler.ServersResponses.isEmpty())
    {
        this->ui->plainTextEdit_LookupResult->setPlainText(whoisHandler.WhoisServers.join(" -> "));
        this->ui->plainTextEdit_LookupResult->appendPlainText("---------------------------");
        this->ui->plainTextEdit_LookupResult->appendPlainText(whoisHandler.ServersResponses.last());
    }

    Utils_PushButtonEndLoading(this->ui->pushButton_Lookup);
}
