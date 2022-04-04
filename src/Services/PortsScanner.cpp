#include "PortsScanner.h"

PortsScanner::PortsScanner()
{

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
