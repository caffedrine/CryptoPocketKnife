#ifndef _DBIP_H_
#define _DBIP_H_

#include <QtCore/QString>
#include <QtCore/QDebug>

#include "MmdbReader.h"

class DbIP
{
public:
    static const int MAX_DB_SIZE = 64 * 1024 * 1024;
    DbIP();
    ~DbIP();

    QString IP2Country(const QString &CountryDbPath, const QString &ip_address);
    QString IP2Asn(const QString &AsnDbPath, const QString &ip_address);

protected:


private:
    MmdbReader *CountryDbReader = nullptr;
    MmdbReader *AsnDbReader = nullptr;

};

#endif // _DBIP_H_
