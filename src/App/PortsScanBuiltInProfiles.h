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
        QString targets = "ANY,ANY,,,,-sC -sV -O,Scan default nMap ports,";

        PortsScanProfileType profile;
        profile.BuiltInProfile = true;
        profile.ProfileName = "Plain nMap (default ports)";
        profile.Targets = this->ParseTargetsFromString(targets);
        return profile;
    }

    PortsScanProfileType GetProfile_PlainNmapFast()
    {
        QString targets = "ANY,ANY,,,,,Scan default nMap ports faster,";

        PortsScanProfileType profile;
        profile.BuiltInProfile = true;
        profile.ProfileName = "Plain nMap fast (default ports)";
        profile.Targets = this->ParseTargetsFromString(targets);
        return profile;
    }

    PortsScanProfileType GetProfile_PlainNmapFastAllPorts()
    {
        QString targets = "ANY,ANY,,,,-p-,Scan default nMap ports faster,";

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
        static QString targets = QString(QByteArray::fromBase64("SUNTLE1vZGJ1cyBUQ1AsNTAyLCxwb3J0OjUwMiwiLVBuIC1zVCAtLXNjcmlwdD1tb2RidXMtZGlzY292ZXIsbW9kaWNvbi1pbmZvIixNb2RidXMgVENQLApJQ1MsQ3JpbXNvbiB2Myw3ODksLHBvcnQ6Nzg5IHByb2R1Y3Q6XCJSZWQgTGlvbiBDb250cm9sc1wiLC1QbiAtc1QgLS1zY3JpcHQ9Y3IzLWZpbmdlcnByaW50Lm5zZSxSZWQgTGlvbiBDcmltc29uIFYzIFByb3RvY29sLApJQ1MsSUVDIDYwODcwLTUtMTA0LDc4OSwscG9ydDo3ODksIi1QbiAtbiAtZCAtLXNjcmlwdD1pZWMtaWRlbnRpZnkubnNlIC0tc2NyaXB0LWFyZ3M9J2llYy1pZGVudGlmeS50aW1lb3V0PTUwMCciLElQQ09NTSBQcm90b2NvbHMsCklDUyxTaWVtZW5zIFM3LDEwMiwscG9ydDoxMDIsIi1QbiAtc1QgLS1zY3JpcHQ9czctaW5mby5uc2UsczcxMjAwLWVudW1lcmF0ZS1vbGQubnNlIixTaWVtZW5zIFM3IEZhbWlseSwKSUNTLEJBQ25ldC9JUCwsNDc4MDgscG9ydDo0NzgwOCwiLVBuIC1zVSAtLXNjcmlwdD1CQUNuZXQtZGlzY292ZXItZW51bWVyYXRlLm5zZSIsIkJBQ25ldC9JUCBwcm90b2NvbCIsCklDUyxETlAzLDIwMDAwLDIwMDAwLHBvcnQ6MjAwMDAsIi1zVCAtLXNjcmlwdD1kbnAzLWVudW1lcmF0ZS5uc2UsZG5wMy1pbmZvLm5zZSIsRE5QMyBvbiBUQ1AvVURQIDIwMDAwLApJQ1MsRXRoZXJDQVQsLDM0OTgwLHBvcnQ6MzQ5ODAsLVBuIC1zQyAtc1YsRXRoZXJDQVQgUHJvdG9jb2wsCklDUyxFdGhlcm5ldC9JUCw0NDgxOCwyMjIyLHBvcnQ6NDQ4MTgsLVBuIC1zQyAtc1YgLS1zY3JpcHQ9ZW5pcC1lbnVtZXJhdGUsRXRoZXJuZXQvSVAsCklDUyxGTC1uZXQsLCI1NTAwMCw1NTAwMSw1NTAwMiw1NTAwMyIsInBvcnQ6NTUwMDAsNTUwMDEsNTUwMDIsNTUwMDMiLC1QbiAtc0MgLXNWLEZMLW5ldCwKSUNTLEZvdW5kYXRpb24gRmllbGRidXMgSFNFLCIxMDg5LDEwOTAsMTA5MSIsIjEwODksMTA5MCwxMDkxIiwicG9ydDoxMDg5LDEwOTAsMTA5MSIsLVBuIC1zQyAtc1YsRm91bmRhdGlvbiBGaWVsZGJ1cyBIU0UsCklDUyxPUEMgVUEgRGlzY292ZXJ5IFNlcnZlciw0ODQwLCxwb3J0OjQ4NDAsLVBuIC1zQyAtc1YsT1BDIFVBIERpc2NvdmVyeSBTZXJ2ZXIgLSA0ODQwLApJQ1MsUFJPRklORVQsIjM0OTYyLDM0OTYzLDM0OTY0IiwiMzQ5NjIsMzQ5NjMsMzQ5NjQiLCJwb3J0OjM0OTYyLDM0OTYzLDM0OTY0IiwtUG4gLXNDIC1zVixQUk9GSU5FVCwKSUNTLEZJTlMsOTYwMCw5NjAwLHBvcnQ6OTYwMCwiLVBuIC1zQyAtc1YgLS1zY3JpcHQgb3Jtb250Y3AtaW5mby5uc2Usb3Jtb251ZHAtaW5mby5uc2UiLEZJTlMgKEZhY3RvcnkgSW50ZXJmYWNlIE5ldHdvcmsgU2VydmljZSksCklDUyxIQVJULUlQLDUwOTQsNTA5NCxwb3J0OjUwOTQsLVBuIC1zQyAtc1YgLS1zY3JpcHQ9aGFydGlwLm5zZSxIQVJULUlQIChIaWdod2F5IEFkZHJlc3NhYmxlIFJlbW90ZSBUcmFuc2R1Y2VyIG92ZXIgSVApLApJQ1MsTUVMU0VDLVEsNTAwNyw1MDA2LCJwb3J0OjUwMDYsNTAwNyIsIi1QbiAtc0MgLXNWIC1zVCAtc1UgLS1zY3JpcHQ9bWVsc2VjcS1kaXNjb3Zlci5uc2UsbWVsc2VjcS1kaXNjb3Zlci5uc2UiLE1FTFNFQy1RIChNaXRzdWJpc2hpIGVsZWN0cmljKSwKSUNTLFRyaWRpdW0gRm94LCI0OTExLDE5MTEiLCwicG9ydDoxOTExLDQ5MTEiLCItUG4gLXNDIC1zViAtLXNjcmlwdD1mb3gtaW5mby5uc2UiLFRyaWRpdW0gRm94IFByb3RvY29sIGJ5IE5pYWdhcmEgQVgsCklDUyxQQ1dPUlgsMTk2MiwscG9ydDoxOTYyLC1QbiAtc0MgLXNWIC0tc2NyaXB0PXBjd29yeC1pbmZvLFBDV29yeCBieSBQaG9lbml4IENvbnRhY3QsCklDUyxQcm9Db25PcywyMDU0NywsInBvcnQ6MjA1NDcgUExDIiwtUG4gLXNDIC1zViAtLXNjcmlwdD1wcm9jb25vcy1pbmZvLm5zZSxQcm9Db25PcywKSUNTLENvZGVzeXMsIjEyMDAsMjQ1NSIsLCJwb3J0OjI0NTUgb3BlcmF0aW5nIHN5c3RlbSIsIi1QbiAtc0MgLXNWIC0tc2NyaXB0PWNvZGVzeXMtdjItZGlzY292ZXIubnNlIixDb2Rlc3lzLApJQ1MsR0UtU1JUUCwiMTgyNDUsMTgyNDYiLCwicG9ydDoxODI0NSwxODI0NiBwcm9kdWN0OiJnZW5lcmFsIGVsZWN0cmljIiIsIi1QbiAtc0MgLXNWIixTZXJ2aWNlIFJlcXVlc3QgVHJhbnNwb3J0IFByb3RvY29sIChHRS1TUlRQKSw="));

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
