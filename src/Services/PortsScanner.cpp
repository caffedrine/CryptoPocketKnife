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

    // Currently, is launched one nmap scan for each target within profile
    for(int i = 0; i < scanProfile.Targets.count(); i++)
    {
        // Build nMap command string
        QString scanRequestCommandString = BuildNmapScanCommand(host, scanProfile.Targets[i]);
        qDebug() << "Exec " << scanRequestCommandString;
        // Launch nmap scan
        QString nmapOutputXml = this->RunNmapScan(scanRequestCommandString);
        output.TargetsOutputs.append(nmapOutputXml);
    }

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
    if(target.TcpPorts.count() > 0)
    {
        output += "-sT ";
        output += "-pT:" + target.GetTcpPortsString() + " ";
    }
    if(target.UdpPorts.count() > 0)
    {
        output += target.TcpPorts.count()>0?",":"";
        output += target.GetUdpPortsString() + " ";
        output += "-sU ";
    }

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


