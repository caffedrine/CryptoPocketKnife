#ifndef _NETWORKUTILS_H_
#define _NETWORKUTILS_H_

#include <QString>
#include <QStringList>

namespace utils::network
{
    namespace ipv4
    {
        bool IsValidIP(QString ip);
        QStringList ExtractIpAddresses(QString input);
        QStringList ExtractIpPortProxies(QString input);
        quint32 Dotted2Long(QString ip);
        QString Dec2Dotted(quint32 ip);
    }

    namespace ipv6
    {
        bool IsValidIP(QString ip);
        QStringList ExtractIpAddresses(QString input);
        QStringList ExtractIpPortProxies(QString input);
    }
}

#endif // _NETWORKUTILS_H_