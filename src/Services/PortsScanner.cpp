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

    // Read scan profile
    PortsScanProfileType scanProfile = PortsScanProfilesManager::instance().GetByName(scanProfileName);

    // Emit a notification when scan started
    emit this->OnRequestStarted(host);

    // Store current timestamp
    output.StartScanTimestamp = QDateTime::currentSecsSinceEpoch();

    // Check if host is up
    QStringList initialScan = this->RunNmapPingAndRDNSScan(host);
    output.HostIp = initialScan[0];
    output.HostRdns = initialScan[1];
    output.Availability = initialScan[2].toUpper();

    // Notify UI about the progress done
    emit this->OnProcessProgress(host, output);

    // Currently, is launched one nmap scan for each target within profile
    for(int i = 0; i < scanProfile.Targets.count(); i++)
    {
        // Build nMap command string
        QString scanRequestCommandString = BuildNmapScanCommand(host, scanProfile.Targets[i]);
        //qDebug() << "Exec " << scanRequestCommandString;
        // Launch nmap scan
        QString nmapOutputXml = this->RunNmapScan(scanRequestCommandString);
        output.TargetsOutputs.append(nmapOutputXml);

        // Notify UI about the progress done
        emit this->OnProcessProgress(host, output);
    }

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

QStringList PortsScanner::RunNmapPingAndRDNSScan(const QString &host)
{
    QStringList output(3);

    QString scanXmlnMap = this->RunNmapScan("nmap -sn " + host + " -oX -");
    QString parsingError;
    QDomDocument nmapXmlOutput;
    if( !nmapXmlOutput.setContent(scanXmlnMap, &parsingError))
    {
        qDebug() << "Invalid nmap XML result detected: " << parsingError;
        return output;
    }

    output[0] = nmapXmlOutput.documentElement().elementsByTagName("address").item(0).toElement().attribute("addr");
    output[1] = nmapXmlOutput.documentElement().elementsByTagName("hostname").item(0).toElement().attribute("name");
    output[2] = nmapXmlOutput.documentElement().elementsByTagName("status").item(0).toElement().attribute("state");

    return output;
}




