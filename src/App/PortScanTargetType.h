#ifndef _PORTSCANTARGETTYPE_H_
#define _PORTSCANTARGETTYPE_H_

#include <QString>
#include <QList>
#include <QMap>
#include <QStringList>

class DeviceTypes
{
public:
    const QString ICS = "ICS";
    const QString WEB = "WEB";
};

class PortsScanTargetType
{
public:
    QString DeviceType;
    QString DeviceName;
    QString VendorName;
    QList<quint16> TcpPorts;
    QList<quint16> UdpPorts;
    QStringList ShodanDorks;
    QList<QMap<quint16, QString>> NmapScripts;
    QString Description;

    bool ParseTargetFromString(QString input)
    {
        // 8 separators needs to be present
        QStringList elements = input.split(";");
        if( elements.count() != 8 )
        {
            return false;
        }

        // Parse category, device and vendor info
        this->DeviceType = elements[0];
        this->DeviceName = elements[1];
        this->VendorName = elements[2];

        // Parse TCP ports
        this->TcpPorts = this->ParsePorts(elements[3]);

        // Parse UDP ports
        this->TcpPorts = this->ParsePorts(elements[4]);

        // Parse shodan dorks
        this->ShodanDorks = this->ParseShodanDorks(elements[5]);

        // Parse nmap scripts to be used during scan
        this->NmapScripts = this->ParseNmapScripts(elements[6]);

        // Parse description
        this->Description = elements[7];
    }

    QString Serialize()
    {
        return "";
    }

    QString ToString()
    {
        return "Device type: " + this->DeviceType
        + ", Device name: " + this->DeviceName
        + ", Vendor name: " + this->VendorName

        + ", Description: " + this->Description
        ;
    }

private:
    QList<quint16> ParsePorts(QString input)
    {
        QList<quint16> output;

        QStringList ports = input.split(",");
        if( ports.count() > 0 )
        {
            for(const QString &port: ports)
            {
                if( this->IsValidPort(port) )
                {
                    output.append(port.toInt());
                }
            }
        }
        else if( !input.isEmpty() )
        {
            if( this->IsValidPort(input) )
            {
                output.append(input.toInt());
            }
        }

        return output;
    }

    bool IsValidPort(QString input)
    {
        bool isNum = false;
        int value = input.toInt(&isNum);
        if( isNum && value >= 1 && value <= 65535 )
            return true;
        return false;
    }

    QStringList ParseShodanDorks(QString input)
    {
        QStringList output;

        QStringList dorks = input.split(",");
        if(dorks.count() > 0 )
        {
            for( const QString &dork: dorks )
            {
                if( !dork.isEmpty() )
                {
                    output.append(dork);
                }
            }
        }
        else if( !input.isEmpty() )
        {
            output.append(input);
        }

        return output;
    }

    QList<QMap<quint16, QString>> ParseNmapScripts(QString input)
    {
        QList<QMap<quint16, QString>> output;

        return output;
    }
};

#endif // _PORTSCANTARGETTYPE_H_