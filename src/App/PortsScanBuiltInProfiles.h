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
        profiles.append(this->GetProfile_WebServers());
        profiles.append(this->GetProfile_WebServersFingerprint());
        profiles.append(this->GetProfile_IcsEssentials());
        profiles.append(this->GetProfile_IcsProtocols());

        return profiles;
    };

private:
    PortsScanProfileType GetProfile_PlainNmap()
    {
        QString targets = "ANY;ANY;;;;-sC -sV -O;Scan default nMap ports";

        PortsScanProfileType profile;
        profile.BuiltInProfile = true;
        profile.ProfileName = "Plain nMap (default ports)";
        profile.Targets = this->ParseTargetsFromString(targets);
        return profile;
    }

    PortsScanProfileType GetProfile_PlainNmapFast()
    {
        QString targets = "ANY;ANY;;;;;Scan default nMap ports faster";

        PortsScanProfileType profile;
        profile.BuiltInProfile = true;
        profile.ProfileName = "Plain nMap fast (default ports)";
        profile.Targets = this->ParseTargetsFromString(targets);
        return profile;
    }

    PortsScanProfileType GetProfile_PlainNmapFastAllPorts()
    {
        QString targets = "ANY;ANY;;;;-p-;Scan default nMap ports faster";

        PortsScanProfileType profile;
        profile.BuiltInProfile = true;
        profile.ProfileName = "Plain nMap fast (all ports)";
        profile.Targets = this->ParseTargetsFromString(targets);
        return profile;
    }

    PortsScanProfileType GetProfile_WebServers()
    {
        QString targets = "WEB SERVER;;66,80,81,443,445,457,1080,1100,1241,1352,1433,1434,1521,1944,2301,3000,3128,3306,4000,4001,4002,4100,5000,5432,5800,5801,5802,6346,6347,7001,7002,8080,8443,8888,30821;66,80,81,443,445,457,1080,1100,1241,1352,1433,1434,1521,1944,2301,3000,3128,3306,4000,4001,4002,4100,5000,5432,5800,5801,5802,6346,6347,7001,7002,8080,8443,8888,30821;;;Scan for webservers";

        PortsScanProfileType profile;
        profile.BuiltInProfile = true;
        profile.ProfileName = "Web Servers Detection";
        profile.Targets = this->ParseTargetsFromString(targets);
        return profile;
    }

    PortsScanProfileType GetProfile_WebServersFingerprint()
    {
        QString targets = "WEB SERVER;;66,80,81,443,445,457,1080,1100,1241,1352,1433,1434,1521,1944,2301,3000,3128,3306,4000,4001,4002,4100,5000,5432,5800,5801,5802,6346,6347,7001,7002,8080,8443,8888,30821;66,80,81,443,445,457,1080,1100,1241,1352,1433,1434,1521,1944,2301,3000,3128,3306,4000,4001,4002,4100,5000,5432,5800,5801,5802,6346,6347,7001,7002,8080,8443,8888,30821;;--script=http-*;Scan and fingerprint webservers";

        PortsScanProfileType profile;
        profile.BuiltInProfile = true;
        profile.ProfileName = "Web Servers Fingerprint";
        profile.Targets = this->ParseTargetsFromString(targets);
        return profile;
    }

    PortsScanProfileType GetProfile_IcsEssentials()
    {
        // https://ctf-wiki.mahaloz.re/ics/discover/
        QString targets =
                "ICS;Modbus TCP;502;;port:502;-sT -Pn --script=modbus-discover,modicon-info;Modbus TCP\n"
                "ICS;Crimson v3;789;;port:789 product:\"Red Lion Controls\";-sT -Pn --script=cr3-fingerprint.nse;Red Lion Crimson V3 Protocol\n"
                "ICS;Siemens S7;102;;port:102;-Pn -sT --script=s7-info.nse,s71200-enumerate-old.nse;Siemens S7 Family\n"
                "ICS;IEC 60870-5-104;789;;port:789;-Pn -n -d --script=iec-identify.nse --script-args='iec-identify.timeout=500';IPCOMM Protocols\n"


//                "Protocol;BACnet/IP;;47808;port:47808;-Pn -sC -sV;BACnet/IP - 47808\n"
//                "Protocol;DNP3;20000;20000;port:20000;-Pn -sC -sV;DNP3 - 20000\n"
//                "Protocol;EtherCAT;;34980;port:34980;-Pn -sC -sV;EtherCAT - 34980\n"
//                "Protocol;Ethernet/IP;44818;2222;port:44818;-Pn -sC -sV;Ethernet/IP\n"
//                "Protocol;FL-net;;55000,55001,55002,55003;port:55000,55001,55002,55003;-Pn -sC -sV;FL-net\n"
//                "Protocol;Foundation Fieldbus HSE;1089,1090,1091;1089,1090,1091;port:1089,1090,1091;-Pn -sC -sV;Foundation Fieldbus HSE\n"
//                "Protocol;Modbus TCP;502;;port:502;-Pn -sC -sV;Modbus TCP\n"
//                "Protocol;OPC UA Discovery Server;4840;;port:4840;-Pn -sC -sV;OPC UA Discovery Server - 4840\n"
//                "Protocol;PROFINET;34962,34963,34964;34962,34963,34964;port:34962,34963,34964;-Pn -sC -sV;PROFINET\n"
//                "Protocol;ROC PLus;4000;;port:4000;-Pn -sC -sV;ROC PLus - 4000\n"
//                "Protocol;FINS;9600;9600;port:9600;-Pn -sC -sV;FINS (Factory Interface Network Service)\n"
//                "Protocol;HART-IP;5094;5094;port:5094;-Pn -sC -sV;HART-IP (Highway Addressable Remote Transducer over IP)\n"
//                "Protocol;Unknown;5006;5007;port:5006,5007;-Pn -sC -sV;MELSEC-Q (Mitsubishi electric)\n"
//                "Protocol;Tridium Fox;4911,1911;;port:1911,4911;-Pn -sC -sV;Tridium Fox Protocol by Niagara AX\n"
//                "Protocol;PCWORX;1962;;port:1962;-Pn -sC -sV;PCWorx by Phoenix Contact\n"

        ;
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
