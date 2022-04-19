#include "GeoIP.h"

#include <QLocale>

// Class instance init
GeoIP *GeoIP::instance = nullptr;

GeoIP::GeoIP()
{
}

GeoIP::~GeoIP()
{
    delete this->dbip;
    this->dbip = nullptr;

    delete this->maxmind;
    this->maxmind = nullptr;
}

GeoIP *GeoIP::Instance()
{
    if (GeoIP::instance == nullptr)
    {
        GeoIP::instance = new GeoIP();
    }
    return GeoIP::instance;
}

void GeoIP::DestroyInstance()
{
    delete GeoIP::instance;
    GeoIP::instance = nullptr;
}

QString GeoIP::IP2CountryISO(const QString &ip_address)
{
    if (this->dbip == nullptr)
    {
        this->dbip = new DbIP();
    }

    return this->dbip->IP2CountryISO(this->Cfg_DbIP.Get_IP2COUNTRY_DbPath(), ip_address);
}

QString GeoIP::IP2CountryName(const QString &ip_address)
{
    if (this->dbip == nullptr)
    {
        this->dbip = new DbIP();
    }

    return this->dbip->IP2CountryName(this->Cfg_DbIP.Get_IP2COUNTRY_DbPath(), ip_address);
}

QString GeoIP::IP2Asn(const QString &ip_address)
{
    if (this->dbip == nullptr)
    {
        this->dbip = new DbIP();
    }

    return this->dbip->IP2Asn(this->Cfg_DbIP.Get_IP2ASN_DbPath(), ip_address);
}

QString GeoIP::IP2Org(const QString &ip_address)
{
    if (this->dbip == nullptr)
    {
        this->dbip = new DbIP();
    }

    return this->dbip->IP2Org(this->Cfg_DbIP.Get_IP2ASN_DbPath(), ip_address);
}
