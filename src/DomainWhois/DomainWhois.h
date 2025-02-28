// https://www.ietf.org/rfc/rfc3912.txt
// https://datatracker.ietf.org/doc/html/rfc2167

#ifndef _SERVICES_DOMAINWHOIS_H_
#define _SERVICES_DOMAINWHOIS_H_

#include <QString>
#include <QStringList>

#if !defined(DLL_DECL_SPEC)
#define DLL_DECL_SPEC
#endif

namespace Services { namespace Whois
{
    class DLL_DECL_SPEC DomainWhois
    {
    public:
        const bool SHOW_DEBUG_MESSAGES = true;

        QStringList WhoisServers;
        QStringList ServersResponses;

        QString GetDomainInfo(QString domain_name);

    private:
        QString DownloadWhoisInfo(const QString &whoisServer, const QString &domainName);
        QString ParseWhoisReponseAndGetForwardWhois(const QString &whoisServer, const QString &whoisReponse);

    };

}}; // Namespaces

#endif // _SERVICES_DOMAINWHOIS_H_
