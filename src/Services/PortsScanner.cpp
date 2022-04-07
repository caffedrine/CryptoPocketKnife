#include "PortsScanner.h"

PortsScanner::PortsScanner(int max_threads_count)
{
    if( max_threads_count <= 1 || max_threads_count >= 500 )
    {
        qDebug() << "Max threads count out of range for port scanner";
        return;
    }

    this->ThreadsPoolPtr()->setMaxThreadCount(max_threads_count);
}

bool PortsScanner::EnqueueScan(const QString &host, const QString &scanProfileName)
{
    // Add record to queue to be executed by the threads in pool
    auto lam = [this, host, scanProfileName]()
    {
        emit(this->AvailableWorkersChanged(this->ThreadsPoolPtr()->AvailableThreads(), this->ThreadsPoolPtr()->ActiveThreads())); // substract current worker which will be disposed
        this->Task(host, scanProfileName);
        emit(this->AvailableWorkersChanged(this->ThreadsPoolPtr()->AvailableThreads(), this->ThreadsPoolPtr()->ActiveThreads()-1)); // substract current worker which will be disposed
    };

    if(!this->ThreadsPoolPtr()->tryStart(lam))
    {
        PortsScanResult response;
        response.AppErrorDetected = true;
        response.AppErrorDesc = "No threads available";

        emit this->OnRequestError(host, response);
        return false;
    }
    return true;
}

void PortsScanner::Task(const QString &host, const QString &scanProfileName)
{
    // Create output var
    PortsScanResult output;
    output.ScanProfile = scanProfileName;
    output.StartScanTimestamp = QDateTime::currentSecsSinceEpoch();

    // Emit a notification when scan started
    emit this->OnRequestStarted(host, output);

    // Check if host is up and if XML returned by nmap does not indicate any error
    if( this->RunNmapPingAndRDNSScan(host, &output) )
    {
        // Notify UI about the progress done
        emit this->OnProcessProgress(host, output);

        // Read scan profile
        PortsScanProfileType scanProfile = PortsScanProfilesManager::instance().GetByName(scanProfileName);

        // Currently, is launched one nmap scan for each target within profile
        for (PortsScanTargetType &target: scanProfile.Targets)
        {
            // Build nMap command string
            QString scanRequestCommandString = BuildNmapScanCommand(host, target);
            //qDebug() << "Exec " << scanRequestCommandString;
            // Launch nmap scan
            QString nmapOutputXml = this->RunNmapScan(scanRequestCommandString);

            // Check if nmap output is valid
            QString parsingError;
            QDomDocument xml;
            if( !xml.setContent(nmapOutputXml, &parsingError))
            {
                QString msg = "Invalid nMap XML: " + parsingError;
                qDebug() << msg;
                output.AppErrorDetected = true;
                output.AppErrorDesc = msg;
                output.TargetsOutputs.append(nmapOutputXml);
                break;
            }

            output.TargetsOutputs.append(xml.toString(4));

            // Update portslist scanned
            QDomNodeList ports = xml.documentElement().elementsByTagName("port");
            for( int j = 0; j < ports.count(); j++ )
            {
                QString port = ports.item(j).toElement().attribute("portid");
                QString protocol = ports.item(j).toElement().attribute("protocol");
                //QString service = ports.item(j).toElement().elementsByTagName("service").item(0).toElement().attribute("name");

                if( protocol.toLower() == "tcp")
                    output.OpenTcpPorts.append(port);
                else
                    output.OpenUdpPorts.append(port);
            }

            // Notify UI about the progress done
            emit this->OnProcessProgress(host, output);
        }
    }

    // Remove ports duplicates
    output.OpenTcpPorts.removeDuplicates();
    output.OpenUdpPorts.removeDuplicates();
    // Sort list
    Utils_NumericListSort(&output.OpenTcpPorts);
    Utils_NumericListSort(&output.OpenUdpPorts);

    // Calculate how many seconds all scan took
    output.ScanDurationSeconds = QDateTime::currentSecsSinceEpoch() - output.StartScanTimestamp;

    // Emit finishing signals
    if(output.NetworkErrorDetected || output.AppErrorDetected )
    {
        emit this->OnRequestError(host, output);
    }
    else
    {
        emit this->OnRequestFinished(host, output);
    }
}


QString PortsScanner::BuildNmapScanCommand(const QString &host, PortsScanTargetType &target)
{
    QString output = "nmap ";

    // Add TCP/UDP scan flags
    output += (target.TcpPorts.count() > 0)?"-sT ":"";
    output += (target.UdpPorts.count() > 0)?"-sU ":"";

    // Add flag to specify the ports
    output += ((target.TcpPorts.count() > 0) || (target.UdpPorts.count() > 0))?"-p":"";

    // Add tcp ports
    if(target.TcpPorts.count() > 0)
    {
        output += "T:" + target.GetTcpPortsString();
    }
    if(target.UdpPorts.count() > 0)
    {
        output += target.TcpPorts.count()>0?",":"";
        output += "U:";
        output += target.GetUdpPortsString();
    }

    // Append whitespace after ports, if any were specified
    output += ((target.TcpPorts.count() > 0) || (target.UdpPorts.count() > 0))?" ":"";

    if( !target.nMapArguments.isEmpty() )
    {
        output += target.nMapArguments + " ";
    }

    output += host + " " + "-oX -";

    return output;
}

QString PortsScanner::RunNmapScan(QString nMapCommand)
{
    // Use openssl to parse certificate
    QProcess process;
    process.startCommand(nMapCommand);
    process.waitForFinished(999999999);
    QByteArray processOutput = process.readAllStandardOutput();
    processOutput += process.readAllStandardError();
    return processOutput;
}

bool PortsScanner::RunNmapPingAndRDNSScan(const QString &host, PortsScanResult *output)
{
    QString scanXmlnMap = this->RunNmapScan("nmap -sn " + host + " -oX -");
    QString parsingError;
    QDomDocument nmapXmlOutput;
    if( !nmapXmlOutput.setContent(scanXmlnMap, &parsingError))
    {
        QString msg = "nMap XML error: " + parsingError;
        qDebug() << msg;
        output->AppErrorDetected = true;
        output->AppErrorDesc = msg;
        output->TargetsOutputs.append(nmapXmlOutput.toString(4));
        return false;
    }

    output->HostIp = nmapXmlOutput.documentElement().elementsByTagName("address").item(0).toElement().attribute("addr");
    output->HostRdns = nmapXmlOutput.documentElement().elementsByTagName("hostname").item(0).toElement().attribute("name");
    output->Availability = nmapXmlOutput.documentElement().elementsByTagName("status").item(0).toElement().attribute("state").toUpper();

    return true;
}




