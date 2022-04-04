#ifndef _PORTSSCANBUILTINPROFILES_H_
#define _PORTSSCANBUILTINPROFILES_H_

#include "PortsScanProfileType.h"
#include "Singleton.h"

class PortsScanBuiltInProfiles: public Singleton<PortsScanBuiltInProfiles>
{
public:
    QList<PortsScanProfileType> GetAllProfiles()
    {
        QList<PortsScanProfileType> profiles;
        profiles.append(this->GetProfile_PlainNmap());
        profiles.append(this->GetProfile_PlainNmapFast());
        profiles.append(this->GetProfile_PlainNmapFastAllPorts());
        profiles.append(this->GetProfile_IcsEssentials());
        profiles.append(this->GetProfile_IcsProtocols());

        return profiles;
    };

private:
    PortsScanProfileType GetProfile_PlainNmap()
    {
        QString targets = "ANY;ANY;ANY;;;;-sC -sV -O;Scan default nMap ports";

        PortsScanProfileType profile;
        profile.BuiltInProfile = true;
        profile.ProfileName = "Plain nMap (default ports)";
        profile.Targets = this->ParseTargetsFromString(targets);
        return profile;
    }

    PortsScanProfileType GetProfile_PlainNmapFast()
    {
        QString targets = "ANY;ANY;ANY;;;;;Scan default nMap ports faster";

        PortsScanProfileType profile;
        profile.BuiltInProfile = true;
        profile.ProfileName = "Plain nMap fast (default ports)";
        profile.Targets = this->ParseTargetsFromString(targets);
        return profile;
    }

    PortsScanProfileType GetProfile_PlainNmapFastAllPorts()
    {
        QString targets = "ANY;ANY;ANY;;;;-p-;Scan default nMap ports faster";

        PortsScanProfileType profile;
        profile.BuiltInProfile = true;
        profile.ProfileName = "Plain nMap fast (all ports)";
        profile.Targets = this->ParseTargetsFromString(targets);
        return profile;
    }

    PortsScanProfileType GetProfile_IcsEssentials()
    {
        QString targets = "ICS;PLC;;502;;port:502;nmap_script;Modbus over TCP IP on port 502\n"
                          "ICS;PLC;;502;;port:102;nmap_Script;Siemens S7 (S7 Communication)\n"
                          "PLC;Niagara;Tridium;1911,4911;1911,4911;port:1911,4911 product:Niagara;nmap script;The Fox protocol, developed as part of the Niagara framework from Tridium";

        PortsScanProfileType profile;
        profile.BuiltInProfile = true;
        profile.ProfileName = "ICS Essentials";
        profile.Targets = this->ParseTargetsFromString(targets);
        return profile;
    }

    PortsScanProfileType GetProfile_IcsProtocols()
    {
        QString targets = "Protocol;BACnet/IP;;;47808;port:47808;nmap_script;BACnet/IP - 47808\n"
                          "Protocol;DNP3;;20000;20000;port:20000;nmap_script;DNP3 - 20000\n"
                          "Protocol;EtherCAT;;;34980;port:34980;nmap_script;EtherCAT - 34980\n"
                          "Protocol;Ethernet/IP;;44818;2222;port:44818;nmap_script;Ethernet/IP\n";
        PortsScanProfileType profile;
        profile.BuiltInProfile = true;
        profile.ProfileName = "ICS Protocols";
        profile.Targets = this->ParseTargetsFromString(targets);
        return profile;
    }

    QList<PortsScanTargetType> ParseTargetsFromString(const QString &input)
    {
        QList<PortsScanTargetType> output;
        for( const QString &target_str: input.split("\n") )
        {
            PortsScanTargetType target;
            if( target.ParseTargetFromString(target_str) )
            {
                output.append(target);
            }
        }
        return output;
    }

};

#endif // _PORTSSCANBUILTINPROFILES_H_
