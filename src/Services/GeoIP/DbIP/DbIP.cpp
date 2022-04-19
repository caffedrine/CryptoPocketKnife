#include "DbIP.h"

#include <QDateTime>
#include <QDebug>
#include <QFile>
#include <QHostAddress>
#include <QVariant>

DbIP::DbIP()
{

}

DbIP::~DbIP()
{
    delete this->CountryDbReader;
    this->CountryDbReader = nullptr;

    delete this->AsnDbReader;
    this->AsnDbReader = nullptr;
}

QString DbIP::IP2Country(const QString &CountryDbPath, const QString &ip_address)
{
    QString error;
    if(this->CountryDbReader == nullptr )
    {
        this->CountryDbReader = MmdbReader::load(CountryDbPath, error);
        if(this->CountryDbReader == nullptr)
        {
            qDebug() << "Cannot load DB-IP ip2country database: "<< error;
            return "";
        }
    }

    QVariant lookupResultBlock = this->CountryDbReader->lookup(QHostAddress(ip_address));



    return this->CountryDbReader->lookup(QHostAddress(ip_address) );
}

QString DbIP::IP2Asn(const QString &AsnDbPath, const QString &ip_address)
{
    QString error;
    if(this->AsnDbReader == nullptr )
    {
        this->AsnDbReader = MmdbReader::load(AsnDbPath, error);
        if(this->AsnDbReader == nullptr)
        {
            qDebug() << "Cannot load DB-IP ip2asn database: "<< error;
            return "";
        }
    }

    QVariant lookupResultBlock = this->AsnDbReader->lookup(QHostAddress(ip_address));

    //return this->AsnDbReader->lookup(QHostAddress(ip_address) );
}
