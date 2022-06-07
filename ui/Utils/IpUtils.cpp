#include "IpUtils.h"
#include "ui_IpUtils.h"

IpUtils::IpUtils(QWidget *parent): QWidget(parent), ui(new Ui::IpUtils)
{
    ui->setupUi(this);

    // Connect signals from UI
    connect(this->ui->pushButton_Decimal2Dotted, SIGNAL(clicked()), this, SLOT(on_pushButton_Decimal2Dotted_clicked()));
    connect(this->ui->pushButton_Dotted2Decimal, SIGNAL(clicked()), this, SLOT(on_pushButton_Dotted2Decimal_clicked()));
    connect(this->ui->pushButton_ExtractIP, SIGNAL(clicked()), this, SLOT(on_pushButton_ExtractIP_clicked()));
    connect(this->ui->pushButton_ExtractIpPort, SIGNAL(clicked()), this, SLOT(on_pushButton_ExtractIpPort_clicked()));
    connect(this->ui->pushButton_ExtractIPv6, SIGNAL(clicked()), this, SLOT(on_pushButton_ExtractIPv6_clicked()));
    connect(this->ui->pushButton_ExtractIPv6Port, SIGNAL(clicked()), this, SLOT(on_pushButton_ExtractIPv6Port_clicked()));
    connect(this->ui->pushButton_OrderList, SIGNAL(clicked()), this, SLOT(on_pushButton_OrderList_clicked()));
}

IpUtils::~IpUtils()
{
    delete ui;
}

void IpUtils::on_pushButton_ExtractIP_clicked()
{
    this->ui->plainTextEdit_Output->clear();

    /* Extract IPv4 addresses from given string */
    QStringList ips = utils::network::ipv4::ExtractIpAddresses(this->ui->plainTextEdit_Input->toPlainText());

    for (QString ip: ips)
    {
        this->ui->plainTextEdit_Output->appendPlainText(ip);
    }
}

void IpUtils::on_pushButton_ExtractIpPort_clicked()
{
    this->ui->plainTextEdit_Output->clear();

    /* Extract IPv4 addresses from given string */
    QStringList proxies = utils::network::ipv4::ExtractIpPortProxies(this->ui->plainTextEdit_Input->toPlainText());

    for (QString proxy: proxies)
    {
        ui->plainTextEdit_Output->appendPlainText( proxy );
    }
}

void IpUtils::on_pushButton_ExtractIPv6_clicked()
{
    this->ui->plainTextEdit_Output->clear();

    /* Extract IPv4 addresses from given string */
    QStringList ips = utils::network::ipv6::ExtractIpAddresses(this->ui->plainTextEdit_Input->toPlainText());

    for (QString ip: ips)
    {
        this->ui->plainTextEdit_Output->appendPlainText(ip);
    }
}
void IpUtils::on_pushButton_ExtractIPv6Port_clicked()
{
    this->ui->plainTextEdit_Output->clear();

    /* Extract IPv4 addresses from given string */
    QStringList proxies = utils::network::ipv6::ExtractIpPortProxies(this->ui->plainTextEdit_Input->toPlainText());

    for (QString proxy: proxies)
    {
        ui->plainTextEdit_Output->appendPlainText( proxy );
    }
}


void IpUtils::on_pushButton_Decimal2Dotted_clicked()
{
    this->ui->plainTextEdit_Output->clear();

    /* Decimal IP address regex validator */
    QString pattern = "[0-9]{8,12}";

    /* Extract IPv4 addresses from given string */
    QStringList ips = utils::regex::GetAllMatches(pattern, this->ui->plainTextEdit_Input->toPlainText());

    for (QString ip: ips)
    {
        ui->plainTextEdit_Output->appendPlainText(utils::network::ipv4::Dec2Dotted( ip.toULongLong() ));
    }
}

void IpUtils::on_pushButton_Dotted2Decimal_clicked()
{
    this->ui->plainTextEdit_Output->clear();

    /* Extract IPv4 addresses from given string */
    QStringList ips = utils::network::ipv4::ExtractIpAddresses(this->ui->plainTextEdit_Input->toPlainText());

    for (QString ip: ips)
    {
        ui->plainTextEdit_Output->appendPlainText(QString::number(utils::network::ipv4::Dotted2Long(ip)));
    }
}

void IpUtils::on_pushButton_Output_Clear_clicked()
{
    this->ui->plainTextEdit_Output->clear();
}

void IpUtils::on_pushButton_OrderList_clicked()
{

}

