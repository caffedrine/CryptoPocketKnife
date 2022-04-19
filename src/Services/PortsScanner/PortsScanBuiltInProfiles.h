#ifndef _PORTSSCANBUILTINPROFILES_H_
#define _PORTSSCANBUILTINPROFILES_H_

#include "PortsScanProfileType.h"
#include "Singleton.h"

namespace Services::PortsScanner
{

class PortsScanBuiltInProfiles: public Singleton<PortsScanBuiltInProfiles>
{
public:
    QList<PortsScanProfileType> GetAllProfiles()
    {
        QList<PortsScanProfileType> profiles;
        profiles.append(this->GetProfile_PlainNmapFast());
        profiles.append(this->GetProfile_PlainNmap());
        profiles.append(this->GetProfile_PlainNmapFastAllPorts());
        profiles.append(this->GetProfile_WebServers());
        profiles.append(this->GetProfile_WebServersFingerprint());
        profiles.append(this->GetProfile_IcsEssentials());
        profiles.append(this->GetProfile_IcsProtocols());

        return profiles;
    };

private:
    PortsScanProfileType GetProfile_PlainNmapFast()
    {
        QString targets = "ANY,ANY,,,,,Scan default nMap ports FAST,";

        PortsScanProfileType profile;
        profile.BuiltInProfile = true;
        profile.ProfileName = "Plain nMap fast (default ports)";
        profile.Targets = this->ParseTargetsFromString(targets);
        return profile;
    }

    PortsScanProfileType GetProfile_PlainNmap()
    {
        QString targets = "ANY,ANY,,,,-sC -sV -O,Scan default nMap ports,";

        PortsScanProfileType profile;
        profile.BuiltInProfile = true;
        profile.ProfileName = "Plain nMap (default ports)";
        profile.Targets = this->ParseTargetsFromString(targets);
        return profile;
    }

    PortsScanProfileType GetProfile_PlainNmapFastAllPorts()
    {
        QString targets = "ANY,ANY,,,,-p-,Scan all ports FAST,";

        PortsScanProfileType profile;
        profile.BuiltInProfile = true;
        profile.ProfileName = "Plain nMap fast (all ports)";
        profile.Targets = this->ParseTargetsFromString(targets);
        return profile;
    }

    PortsScanProfileType GetProfile_WebServers()
    {
        QString targets = "WEB SERVER,,\"66,80,81,443,445,457,1080,1100,1241,1352,1433,1434,1521,1944,2301,3000,3128,3306,4000,4001,4002,4100,5000,5432,5800,5801,5802,6346,6347,7001,7002,8080,8443,8888,30821\",\"66,80,81,443,445,457,1080,1100,1241,1352,1433,1434,1521,1944,2301,3000,3128,3306,4000,4001,4002,4100,5000,5432,5800,5801,5802,6346,6347,7001,7002,8080,8443,8888,30821\",,-sC -sV,Scan for webservers,";

        PortsScanProfileType profile;
        profile.BuiltInProfile = true;
        profile.ProfileName = "Web Servers Detection";
        profile.Targets = this->ParseTargetsFromString(targets);
        return profile;
    }

    PortsScanProfileType GetProfile_WebServersFingerprint()
    {
        QString targets = "WEB SERVER,,\"66,80,81,443,445,457,1080,1100,1241,1352,1433,1434,1521,1944,2301,3000,3128,3306,4000,4001,4002,4100,5000,5432,5800,5801,5802,6346,6347,7001,7002,8080,8443,8888,30821\",\"66,80,81,443,445,457,1080,1100,1241,1352,1433,1434,1521,1944,2301,3000,3128,3306,4000,4001,4002,4100,5000,5432,5800,5801,5802,6346,6347,7001,7002,8080,8443,8888,30821\",,\"--script=http-*\",Scan and fingerprint webservers,";

        PortsScanProfileType profile;
        profile.BuiltInProfile = true;
        profile.ProfileName = "Web Servers Fingerprint";
        profile.Targets = this->ParseTargetsFromString(targets);
        return profile;
    }

    PortsScanProfileType GetProfile_IcsEssentials()
    {
        // https://ctf-wiki.mahaloz.re/ics/discover/
        static QString targets = QString(QByteArray::fromBase64("SUNTLE1vZGJ1cyBUQ1AsNTAyLCxwb3J0OjUwMiwiLVBuIC1zVCAtLXNjcmlwdD1iYW5uZXIsbW9kYnVzLWRpc2NvdmVyLG1vZGljb24taW5mbyAtLXNjcmlwdC1hcmdzPSdtb2RidXMtZGlzY292ZXIuYWdncmVzc2l2ZT10cnVlJyIsTW9kYnVzIFRDUCwKSUNTLENyaW1zb24gdjMsNzg5LCxwb3J0Ojc4OSBwcm9kdWN0OlwiUmVkIExpb24gQ29udHJvbHNcIiwiLVBuIC1zVCAtLXNjcmlwdD1iYW5uZXIsY3IzLWZpbmdlcnByaW50Lm5zZSIsUmVkIExpb24gQ3JpbXNvbiBWMyBQcm90b2NvbCwKSUNTLElFQyA2MDg3MC01LTEwNCw3ODksLHBvcnQ6Nzg5LCItUG4gLW4gLWQgLS1zY3JpcHQ9YmFubmVyLGllYy1pZGVudGlmeS5uc2UgLS1zY3JpcHQtYXJncz0naWVjLWlkZW50aWZ5LnRpbWVvdXQ9NTAwJyIsSVBDT01NIFByb3RvY29scywKSUNTLFNpZW1lbnMgUzcsMTAyLCxwb3J0OjEwMiwiLVBuIC1zVCAtLXNjcmlwdD1iYW5uZXIsczctaW5mby5uc2UsczcxMjAwLWVudW1lcmF0ZS1vbGQubnNlIixTaWVtZW5zIFM3IEZhbWlseSwKSUNTLEJBQ25ldC9JUCwsNDc4MDgscG9ydDo0NzgwOCwiLVBuIC1zVSAtLXNjcmlwdD1iYW5uZXIsQkFDbmV0LWRpc2NvdmVyLWVudW1lcmF0ZS5uc2UiLCJCQUNuZXQvSVAgcHJvdG9jb2wiLApJQ1MsRE5QMywyMDAwMCwyMDAwMCxwb3J0OjIwMDAwLCItUG4gLXNDIC1zViAtc1QgLXNVIC0tc2NyaXB0PWJhbm5lcixkbnAzLWVudW1lcmF0ZS5uc2UsZG5wMy1pbmZvLm5zZSIsRE5QMyBvbiBUQ1AvVURQIDIwMDAwLApJQ1MsRXRoZXJDQVQsLDM0OTgwLHBvcnQ6MzQ5ODAsIi1QbiAtc0MgLXNWIC1zVSAtLXNjcmlwdD1iYW5uZXIiLEV0aGVyQ0FUIFByb3RvY29sLApJQ1MsRXRoZXJuZXQvSVAsNDQ4MTgsMjIyMixwb3J0OjQ0ODE4LCItUG4gLXNDIC1zViAtc1QgLXNVIC0tc2NyaXB0PWJhbm5lcixlbmlwLWVudW1lcmF0ZSIsRXRoZXJuZXQvSVAsCklDUyxGTC1uZXQsLCI1NTAwMCw1NTAwMSw1NTAwMiw1NTAwMyIsInBvcnQ6NTUwMDAsNTUwMDEsNTUwMDIsNTUwMDMiLCItUG4gLXNDIC1zViAtc1UgLS1zY3JpcHQ9YmFubmVyIixGTC1uZXQsCklDUyxGaWVsZGJ1cywiMTA4OSwxMDkwLDEwOTEiLCIxMDg5LDEwOTAsMTA5MSIsInBvcnQ6MTA4OSwxMDkwLDEwOTEiLCItUG4gLXNDIC1zViAtc1QgLXNVIC0tc2NyaXB0PWJhbm5lciIsRm91bmRhdGlvbiBGaWVsZGJ1cyBIU0UsCklDUyxPUEMgVUEgU2VydmVyLDQ4NDAsLHBvcnQ6NDg0MCwiLVBuIC1zQyAtc1YgLS1zY3JpcHQ9YmFubmVyIixPUEMgVUEgRGlzY292ZXJ5IFNlcnZlciAtIDQ4NDAsCklDUyxQUk9GSU5FVCwiMzQ5NjIsMzQ5NjMsMzQ5NjQiLCIzNDk2MiwzNDk2MywzNDk2NCIsInBvcnQ6MzQ5NjIsMzQ5NjMsMzQ5NjQiLCItUG4gLXNDIC1zViAtc1QgLXNVIC0tc2NyaXB0PWJhbm5lciIsUFJPRklORVQsCklDUyxGSU5TLDk2MDAsOTYwMCxwb3J0Ojk2MDAsIi1QbiAtc0MgLXNWIC1zVCAtc1UgLS1zY3JpcHQ9YmFubmVyLG9tcm9udGNwLWluZm8ubnNlLG9tcm9udWRwLWluZm8ubnNlIixGSU5TIChGYWN0b3J5IEludGVyZmFjZSBOZXR3b3JrIFNlcnZpY2UpLApJQ1MsSEFSVC1JUCw1MDk0LDUwOTQscG9ydDo1MDk0LCItUG4gLXNDIC1zViAtc1QgLXNVIC0tc2NyaXB0PWJhbm5lcixoYXJ0aXAubnNlIixIQVJULUlQIChIaWdod2F5IEFkZHJlc3NhYmxlIFJlbW90ZSBUcmFuc2R1Y2VyIG92ZXIgSVApLApJQ1MsTUVMU0VDLVEsNTAwNyw1MDA2LCJwb3J0OjUwMDYsNTAwNyIsIi1QbiAtc0MgLXNWIC1zVCAtc1UgLS1zY3JpcHQ9YmFubmVyLG1lbHNlY3EtZGlzY292ZXIubnNlLG1lbHNlY3EtZGlzY292ZXIubnNlIixNRUxTRUMtUSAoTWl0c3ViaXNoaSBlbGVjdHJpYyksCklDUyxUcmlkaXVtIEZveCwiNDkxMSwxOTExIiwsInBvcnQ6MTkxMSw0OTExIiwiLVBuIC1zQyAtc1YgLS1zY3JpcHQ9YmFubmVyLGZveC1pbmZvLm5zZSIsVHJpZGl1bSBGb3ggUHJvdG9jb2wgYnkgTmlhZ2FyYSBBWCwKSUNTLFBDV09SWCwxOTYyLCxwb3J0OjE5NjIsIi1QbiAtc0MgLXNWIC0tc2NyaXB0PWJhbm5lcixwY3dvcngtaW5mbyIsUENXb3J4IGJ5IFBob2VuaXggQ29udGFjdCwKSUNTLFByb0Nvbk9zLDIwNTQ3LCwicG9ydDoyMDU0NyBQTEMiLCItUG4gLXNDIC1zViAtLXNjcmlwdD1iYW5uZXIscHJvY29ub3MtaW5mby5uc2UiLFByb0Nvbk9zLApJQ1MsQ29kZXN5cywiMTIwMCwyNDU1IiwsInBvcnQ6MjQ1NSBvcGVyYXRpbmcgc3lzdGVtIiwiLVBuIC1zQyAtc1YgLS1zY3JpcHQ9YmFubmVyLGNvZGVzeXMtdjItZGlzY292ZXIubnNlIixDb2Rlc3lzLApJQ1MsR0UtU1JUUCwiMTgyNDUsMTgyNDYiLCwicG9ydDoxODI0NSwxODI0NiBwcm9kdWN0OiJnZW5lcmFsIGVsZWN0cmljIiIsIi1QbiAtc0MgLXNWIC0tc2NyaXB0PWJhbm5lciIsU2VydmljZSBSZXF1ZXN0IFRyYW5zcG9ydCBQcm90b2NvbCAoR0UtU1JUUCks=="));

        PortsScanProfileType profile;
        profile.BuiltInProfile = true;
        profile.ProfileName = "ICS Essentials";
        profile.Targets = this->ParseTargetsFromString(targets);
        return profile;
    }

    PortsScanProfileType GetProfile_IcsProtocols()
    {
        QString targets = "";
        PortsScanProfileType profile;
        profile.BuiltInProfile = true;
        profile.ProfileName = "ICS Protocols";
        profile.Targets = this->GetProfile_IcsEssentials().Targets;
        profile.Targets.append(this->ParseTargetsFromString(targets));
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

}

#endif // _PORTSSCANBUILTINPROFILES_H_
