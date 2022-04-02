#ifndef _PORTSSCANBUILTINPROFILES_H_
#define _PORTSSCANBUILTINPROFILES_H_

#include "PortsScanProfileType.h"
#include "Singleton.h"

class PortsScanBuiltInProfiles: public Singleton<PortsScanBuiltInProfiles>
{
public:
    QList<PortsScanProfileType> GetProfiles()
    {
        QList<PortsScanProfileType> profiles;

        return profiles;
    };

private:
    PortsScanProfileType GetProfile_IcsEssentials()
    {
        QString targets = "ICS;PLC;;502;;port:502;nmap_script;Modbus over TCP IP on port 502\n"
                          "ICS;PLC;;502;;port:102;nmap_Script;Siemens S7 (S7 Communication)\n"
                          "PLC;Niagara;Tridium;1911,4911;1911,4911;port:1911,4911 product:Niagara;nmap script;The Fox protocol, developed as part of the Niagara framework from Tridium";

        PortsScanProfileType profile;
//
//        for( const QString &target: targets.split("\n") )
//        {
//
//        }

    }

};

#endif // _PORTSSCANBUILTINPROFILES_H_
