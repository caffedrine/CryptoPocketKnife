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

    // Read scan profile
    PortsScanProfileType scanProfile = PortsScanProfilesManager::instance().GetByName(scanProfileName);

    // Build nMap scan request
    PostsScanRequestNMAP scanRequest = this->BuildNmapScanRequest(scanProfile);

    // Build nMap command string
    QString scanRequestCommandString = BuildNmapScanCommand(scanRequest);

    qDebug() << scanRequestCommandString;
    qDebug() << scanRequestCommandString;

    return;

    // Emit a notification when scan started
    emit this->OnRequestStarted(host);

    // Run nMap
    PortsScanResult output = this->RunNmapScan(scanRequestCommandString);

    if( !output.OpenTcpPorts.empty() || !output.OpenUdpPorts.empty())
    {
        output.DeviceType = scanProfile.DeviceCategoryIfProfileMatch;
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

PostsScanRequestNMAP PortsScanner::BuildNmapScanRequest(const PortsScanProfileType &profile)
{
    return PostsScanRequestNMAP();
}

QString PortsScanner::BuildNmapScanCommand(const PostsScanRequestNMAP &request)
{
    return QString();
}

PortsScanResult PortsScanner::RunNmapScan(QString nMapCommand)
{
    return PortsScanResult();
}


