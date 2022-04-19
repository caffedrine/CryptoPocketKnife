#ifndef _CFG_GEOIP_H_
#define _CFG_GEOIP_H_

#include <QtCore/QString>
#include <QtCore/QCoreApplication>

class GeoIPProviders
{
public:
    inline static const QString DbIP = "DB-IP";
    inline static const QString Maxmind = "MaxMind";
};

class Cfg_GeoIP
{
    public:
    QString CurrentProvider = GeoIPProviders::DbIP;

    class Cfg_DbIP
    {
        public:
        static QString Get_IP2ASN_DbPath()
        {
            return QCoreApplication::applicationDirPath() + "/data/GeoIP/DbIP/ip2asn.mmdb";
        }


        static QString Get_IP2COUNTRY_DbPath()
        {
            return QCoreApplication::applicationDirPath() + "/data/GeoIP/DbIP/ip2country.mmdb";
        }
    };

    class Cfg_Maxmind
    {
        public:
        static QString Get_IP2ISP_DbPath()
        {
            return QCoreApplication::applicationDirPath() + "/data/GeoIP/Maxmind/ip2isp.dat";
        }

        static QString Get_IP2ORG_DbPath()
        {
            return QCoreApplication::applicationDirPath() + "/data/GeoIP/Maxmind/ip2org.dat";
        }
    };

    static Cfg_DbIP Cfg_DbIP;
    static Cfg_Maxmind Cfg_Maxmind;

};

#endif // _CFG_GEOIP_H_
