// https://www.ietf.org/rfc/rfc3912.txt
// https://datatracker.ietf.org/doc/html/rfc2167

#ifndef _SERVICES_DOMAINWHOIS_H_
#define _SERVICES_DOMAINWHOIS_H_

#include <QString>
#include <QStringList>

namespace Services { namespace Whois
{
    class DomainWhois
    {
    public:
        QStringList WhoisServers;
        QStringList ServersResponses;

        QString GetDomainInfo(QString domain_name);
        const bool ShowDebugMessages = true;

    private:
        QString DownloadWhoisInfo(const QString &whoisServer, const QString &domainName);
        QString ParseWhoisReponseAndGetForwardWhois(const QString &whoisServer, const QString &whoisReponse);

    };

}}; // Namespaces

#endif // _SERVICES_DOMAINWHOIS_H_
