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
        QString targets = "ANY,ANY,,,,-p-,Scan scan all ports FAST,";

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
        static QString targets = QString(QByteArray::fromBase64("SUNTLE1vZGJ1cyBUQ1AsNTAyLCxwb3J0OjUwMiwiLVBuIC1zVCAtLXNjcmlwdD1iYW5uZXIsbW9kYnVzLWRpc2NvdmVyLG1vZGljb24taW5mbyAtLXNjcmlwdC1hcmdzPSdtb2RidXMtZGlzY292ZXIuYWdncmVzc2l2ZT10cnVlJyIsTW9kYnVzIFRDUCwKSUNTLENyaW1zb24gdjMsNzg5LCxwb3J0Ojc4OSBwcm9kdWN0OlwiUmVkIExpb24gQ29udHJvbHNcIiwiLVBuIC1zVCAtLXNjcmlwdD1iYW5uZXIsY3IzLWZpbmdlcnByaW50Lm5zZSIsUmVkIExpb24gQ3JpbXNvbiBWMyBQcm90b2NvbCwKSUNTLElFQyA2MDg3MC01LTEwNCw3ODksLHBvcnQ6Nzg5LCItUG4gLW4gLWQgLS1zY3JpcHQ9YmFubmVyLGllYy1pZGVudGlmeS5uc2UgLS1zY3JpcHQtYXJncz0naWVjLWlkZW50aWZ5LnRpbWVvdXQ9NTAwJyIsSVBDT01NIFByb3RvY29scywKSUNTLFNpZW1lbnMgUzcsMTAyLCxwb3J0OjEwMiwiLVBuIC1zVCAtLXNjcmlwdD1iYW5uZXIsczctaW5mby5uc2UsczcxMjAwLWVudW1lcmF0ZS1vbGQubnNlIixTaWVtZW5zIFM3IEZhbWlseSwKSUNTLEJBQ25ldC9JUCwsNDc4MDgscG9ydDo0NzgwOCwiLVBuIC1zVSAtLXNjcmlwdD1iYW5uZXIsQkFDbmV0LWRpc2NvdmVyLWVudW1lcmF0ZS5uc2UiLCJCQUNuZXQvSVAgcHJvdG9jb2wiLApJQ1MsRE5QMywyMDAwMCwyMDAwMCxwb3J0OjIwMDAwLCItUG4gLXNDIC1zViAtc1QgLXNVIC0tc2NyaXB0PWJhbm5lcixkbnAzLWVudW1lcmF0ZS5uc2UsZG5wMy1pbmZvLm5zZSIsRE5QMyBvbiBUQ1AvVURQIDIwMDAwLApJQ1MsRXRoZXJDQVQsLDM0OTgwLHBvcnQ6MzQ5ODAsIi1QbiAtc0MgLXNWIC1zVSAtLXNjcmlwdD1iYW5uZXIiLEV0aGVyQ0FUIFByb3RvY29sLApJQ1MsRXRoZXJuZXQvSVAsNDQ4MTgsMjIyMixwb3J0OjQ0ODE4LCItUG4gLXNDIC1zViAtc1QgLXNVIC0tc2NyaXB0PWJhbm5lcixlbmlwLWVudW1lcmF0ZSIsRXRoZXJuZXQvSVAsCklDUyxGTC1uZXQsLCI1NTAwMCw1NTAwMSw1NTAwMiw1NTAwMyIsInBvcnQ6NTUwMDAsNTUwMDEsNTUwMDIsNTUwMDMiLCItUG4gLXNDIC1zViAtc1UgLS1zY3JpcHQ9YmFubmVyIixGTC1uZXQsCklDUyxGb3VuZGF0aW9uIEZpZWxkYnVzIEhTRSwiMTA4OSwxMDkwLDEwOTEiLCIxMDg5LDEwOTAsMTA5MSIsInBvcnQ6MTA4OSwxMDkwLDEwOTEiLCItUG4gLXNDIC1zViAtc1QgLXNVIC0tc2NyaXB0PWJhbm5lciIsRm91bmRhdGlvbiBGaWVsZGJ1cyBIU0UsCklDUyxPUEMgVUEgRGlzY292ZXJ5IFNlcnZlciw0ODQwLCxwb3J0OjQ4NDAsIi1QbiAtc0MgLXNWIC0tc2NyaXB0PWJhbm5lciIsT1BDIFVBIERpc2NvdmVyeSBTZXJ2ZXIgLSA0ODQwLApJQ1MsUFJPRklORVQsIjM0OTYyLDM0OTYzLDM0OTY0IiwiMzQ5NjIsMzQ5NjMsMzQ5NjQiLCJwb3J0OjM0OTYyLDM0OTYzLDM0OTY0IiwiLVBuIC1zQyAtc1YgLXNUIC1zVSAtLXNjcmlwdD1iYW5uZXIiLFBST0ZJTkVULApJQ1MsRklOUyw5NjAwLDk2MDAscG9ydDo5NjAwLCItUG4gLXNDIC1zViAtc1QgLXNVIC0tc2NyaXB0PWJhbm5lcixvbXJvbnRjcC1pbmZvLm5zZSxvbXJvbnVkcC1pbmZvLm5zZSIsRklOUyAoRmFjdG9yeSBJbnRlcmZhY2UgTmV0d29yayBTZXJ2aWNlKSwKSUNTLEhBUlQtSVAsNTA5NCw1MDk0LHBvcnQ6NTA5NCwiLVBuIC1zQyAtc1YgLXNUIC1zVSAtLXNjcmlwdD1iYW5uZXIsaGFydGlwLm5zZSIsSEFSVC1JUCAoSGlnaHdheSBBZGRyZXNzYWJsZSBSZW1vdGUgVHJhbnNkdWNlciBvdmVyIElQKSwKSUNTLE1FTFNFQy1RLDUwMDcsNTAwNiwicG9ydDo1MDA2LDUwMDciLCItUG4gLXNDIC1zViAtc1QgLXNVIC0tc2NyaXB0PWJhbm5lcixtZWxzZWNxLWRpc2NvdmVyLm5zZSxtZWxzZWNxLWRpc2NvdmVyLm5zZSIsTUVMU0VDLVEgKE1pdHN1YmlzaGkgZWxlY3RyaWMpLApJQ1MsVHJpZGl1bSBGb3gsIjQ5MTEsMTkxMSIsLCJwb3J0OjE5MTEsNDkxMSIsIi1QbiAtc0MgLXNWIC0tc2NyaXB0PWJhbm5lcixmb3gtaW5mby5uc2UiLFRyaWRpdW0gRm94IFByb3RvY29sIGJ5IE5pYWdhcmEgQVgsCklDUyxQQ1dPUlgsMTk2MiwscG9ydDoxOTYyLCItUG4gLXNDIC1zViAtLXNjcmlwdD1iYW5uZXIscGN3b3J4LWluZm8iLFBDV29yeCBieSBQaG9lbml4IENvbnRhY3QsCklDUyxQcm9Db25PcywyMDU0NywsInBvcnQ6MjA1NDcgUExDIiwiLVBuIC1zQyAtc1YgLS1zY3JpcHQ9YmFubmVyLHByb2Nvbm9zLWluZm8ubnNlIixQcm9Db25PcywKSUNTLENvZGVzeXMsIjEyMDAsMjQ1NSIsLCJwb3J0OjI0NTUgb3BlcmF0aW5nIHN5c3RlbSIsIi1QbiAtc0MgLXNWIC0tc2NyaXB0PWJhbm5lcixjb2Rlc3lzLXYyLWRpc2NvdmVyLm5zZSIsQ29kZXN5cywKSUNTLEdFLVNSVFAsIjE4MjQ1LDE4MjQ2IiwsInBvcnQ6MTgyNDUsMTgyNDYgcHJvZHVjdDoiZ2VuZXJhbCBlbGVjdHJpYyIiLCItUG4gLXNDIC1zViAtLXNjcmlwdD1iYW5uZXIiLFNlcnZpY2UgUmVxdWVzdCBUcmFuc3BvcnQgUHJvdG9jb2wgKEdFLVNSVFApLA=="));

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

#endif // _PORTSSCANBUILTINPROFILES_H_
