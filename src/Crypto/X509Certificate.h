#ifndef CRYPTOPOCKETKNIFE_X509CERTIFICATE_H
#define CRYPTOPOCKETKNIFE_X509CERTIFICATE_H

#include <QString>
#include <QByteArray>

namespace Core { namespace Crypto { namespace x509 {
    QString GetCertHumanReadableFormat(const QByteArray &certBytes);

}}} //  namespaces


#endif //CRYPTOPOCKETKNIFE_X509CERTIFICATE_H
