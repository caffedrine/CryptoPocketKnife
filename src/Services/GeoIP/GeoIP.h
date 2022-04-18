#ifndef _GEOIP_H_
#define _GEOIP_H_

#include "Cfg_GeoIP.h"

#include "DbIP/DbIP.h"
#include "Maxmind/Maxmind.h"

class GeoIP: protected Cfg_GeoIP
{
public:
    Q_DISABLE_COPY_MOVE(GeoIP)

    static GeoIP *Instance();
    static void DestroyInstance();
    static QString IsoCodeToCountryName(const QString &isoCode);

    QString IP2CountryISO(const QString &ip_address);
    QString IP2CountryName(const QString &ip_address);
    QString IP2Asn(const QString &ip_address);

protected:
    GeoIP();
    ~GeoIP();

private:
    static GeoIP *instance;

    // GeoIP Service providers instances
    class DbIP *dbip;
    class Maxmind *maxmind;
};


#endif // _GEOIP_H_