#include "IpUtils.h"
#include "ui_IpUtils.h"
#include <QHostAddress>
#include <QAbstractSocket>
#include <QRegularExpressionMatchIterator>

IpUtils::IpUtils(QWidget *parent): QWidget(parent), ui(new Ui::IpUtils)
{
    ui->setupUi(this);
}

IpUtils::~IpUtils()
{
    delete ui;
}

void IpUtils::on_pushButton_ExtractIP_clicked()
{
    this->ui->plainTextEdit_Output->clear();

    /* Extract IPv4 addresses from given string */
    QStringList ips = this->ExtractIPv4Addresses(this->ui->plainTextEdit_Input->toPlainText());

    foreach (QString ip, ips)
    {
        this->ui->plainTextEdit_Output->appendPlainText(ip);
    }
}

void IpUtils::on_pushButton_ExtractIpPort_clicked()
{
    this->ui->plainTextEdit_Output->clear();

    /* Proxy pattern */
    QString regexPattern = "([0-9]{1,3}\\.[0-9]{1,3}\\.[0-9]{1,3}\\.[0-9]{1,3})(:|[\\s]+)([0-9]{1,5})";

    /* Fetch proxies from string */
    QStringList proxies = this->GetRegexMatches(regexPattern, this->ui->plainTextEdit_Input->toPlainText().replace(" ", "\n"));

    foreach (QString proxy, proxies)
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
    QStringList ips = this->GetRegexMatches(pattern, this->ui->plainTextEdit_Input->toPlainText());

    foreach (QString ip, ips)
    {
        ui->plainTextEdit_Output->appendPlainText(this->IPv4Dec2Dotted( ip.toULongLong() ));
    }
}

void IpUtils::on_pushButton_Dotted2Decimal_clicked()
{
    this->ui->plainTextEdit_Output->clear();

    /* Extract IPv4 addresses from given string */
    QStringList ips = this->ExtractIPv4Addresses(this->ui->plainTextEdit_Input->toPlainText());

    foreach (QString ip, ips)
    {
        ui->plainTextEdit_Output->appendPlainText(QString::number(this->IPv4Dotted2Long(ip)));
    }
}

void IpUtils::on_pushButton_Output_Clear_clicked()
{
    this->ui->plainTextEdit_Output->clear();
}

bool IpUtils::IsValidIPv4(QString ip)
{
    QHostAddress address(ip);
    if(QAbstractSocket::IPv4Protocol == address.protocol())
    {
        return true;
    }
    else if(QAbstractSocket::IPv6Protocol == address.protocol())
    {
        /* IP given is v6 */
        return false;
    }
    else
    {
        return false;
    }
}

QStringList IpUtils::ExtractIPv4Addresses(QString str)
{
    /* Regex to match ip address */
    QString pattern = ("[0-9]{1,3}\\.[0-9]{1,3}\\.[0-9]{1,3}\\.[0-9]{1,3}");

    return this->GetRegexMatches(pattern, str);
}

QStringList IpUtils::GetRegexMatches(QString regexPattern, QString str)
{
    QStringList list;

    /* Regex to match ip address */
    QRegularExpression validator(regexPattern);

    /* Get matches */
    QRegularExpressionMatchIterator lineMatches = validator.globalMatch(str);

    /* Fill list with matches*/
    while(lineMatches.hasNext())
    {
        QRegularExpressionMatch match = lineMatches.next();
        if(match.hasMatch())
        {
            list.append(match.captured(0));
        }
    }

    return list;
}

quint32 IpUtils::IPv4Dotted2Long(QString ip)
{
    QHostAddress address(ip);
    return address.toIPv4Address();
}

QString IpUtils::IPv4Dec2Dotted(quint32 ip)
{
    QHostAddress address(ip);
    return address.toString();
}


