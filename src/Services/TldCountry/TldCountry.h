#ifndef CRYPTOPOCKETKNIFE_TLDCOUNTRY_H
#define CRYPTOPOCKETKNIFE_TLDCOUNTRY_H

#include <QMap>

namespace Services::TldCountry
{
    QString GetCountryByTLD(QString tld);
    QString GetTldByCountry(QString country_tld);
}

#endif //CRYPTOPOCKETKNIFE_TLDCOUNTRY_H
