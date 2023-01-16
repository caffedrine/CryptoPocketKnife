#include "UiDomainWhois.h"
#include "ui_UiDomainWhois.h"

#include <QHostInfo>
#include "base/utils/utils.h"
#include "base/utils/WebUtils.h"

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
    whoisHandler.GetDomainInfo(utils::web::GetDomainNameFromUrl(this->ui->lineEdit_DomainName->text().trimmed()));

    if( !whoisHandler.WhoisServers.isEmpty() && !whoisHandler.ServersResponses.isEmpty())
    {
        this->ui->plainTextEdit_LookupResult->setPlainText(whoisHandler.WhoisServers.join(" -> "));
        this->ui->plainTextEdit_LookupResult->appendPlainText("---------------------------");
        this->ui->plainTextEdit_LookupResult->appendPlainText(whoisHandler.ServersResponses.last().trimmed());
    }

    Utils_PushButtonEndLoading(this->ui->pushButton_Lookup);
}
