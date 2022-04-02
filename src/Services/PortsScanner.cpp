#include "PortsScanner.h"

PortsScanner::PortsScanner()
{
    this->threadsPool = new QThreadPool(this);
    this->threadsPool->setMaxThreadCount(PortsScanner::MAX_THREADS);
}

PortsScanner::~PortsScanner()
{
    delete this->threadsPool;
}

int PortsScanner::AvailableWorkers()
{
    if( !this->threadsPool )
        return PortsScanner::MAX_THREADS;

    return (this->threadsPool->maxThreadCount() - this->threadsPool->activeThreadCount());
}

int PortsScanner::ActiveWorkers()
{
    if( !this->threadsPool )
        return 0;

    return this->threadsPool->activeThreadCount();
}

bool PortsScanner::EnqueueScan(const QString &host, const QString &scanProfileName)
{
    // Add record to queue to be executed by the threads in pool
    auto lam = [this, host, scanProfileName]()
    {
        emit(this->AvailableWorkersChanged(this->AvailableWorkers(), this->ActiveWorkers())); // substract current worker which will be disposed
        this->Task(host, scanProfileName);
        emit(this->AvailableWorkersChanged(this->AvailableWorkers(), this->ActiveWorkers()-1)); // substract current worker which will be disposed
    };


    if(!this->threadsPool->tryStart(lam))
    {
        ScanResult response;
        response.AppErrorDetected = true;
        response.AppErrorDesc = "No threads available";

        emit this->OnRequestError(host, response);
        return false;
    }
    return true;
}

void PortsScanner::Task(const QString &host, const QString &scanProfileName)
{
    emit this->OnRequestStarted(host);
    ScanResult result;//implement here

    if(result.NetworkErrorDetected || result.AppErrorDetected )
    {
        emit this->OnRequestError(host, result);
    }
    else
    {
        emit this->OnRequestFinished(host, result);
    }
}
