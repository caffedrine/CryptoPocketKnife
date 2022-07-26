#ifndef _GEOIP_H_
#define _GEOIP_H_

#include <QMutex>

#include "Cfg_GeoIP.h"

#include "DbIP/DbIP.h"
#include "Maxmind/Maxmind.h"

namespace Services { namespace GeoIP
{

class GeoIP
{
public:
    Q_DISABLE_COPY(GeoIP)

    static GeoIP *Instance();
    static void DestroyInstance();

    QString IP2CountryISO(const QString &ip_address);
    QString IP2CountryName(const QString &ip_address);
    QString IP2Asn(const QString &ip_address);
    QString IP2Org(const QString &ip_address);

protected:
    GeoIP();
    ~GeoIP();

private:
    QMutex mMutex;
    static GeoIP *instance;

    // GeoIP Service providers instances
    class DbIP *dbip = nullptr;
    class Maxmind *maxmind = nullptr;
};

}} // Namespaces

#endif // _GEOIP_H_
