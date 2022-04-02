#ifndef _PORTSSCANNER_H_
#define _PORTSSCANNER_H_

#include <QObject>
#include <QThreadPool>
#include <QString>

#include "PortsScanProfilesManager.h"

/* */
class ScanResult
{
public:
    bool AppErrorDetected = false;
    QString AppErrorDesc = "";

    bool NetworkErrorDetected = false;
    QString NetworkErrorDescription = "";

    qint16 Code;
    QString CodeDesc;
    bool Redirected = false;
    QString Headers;
    QString Body;
    QString HostIp;
};

/* */
class PortsScanner: public QObject
{
Q_OBJECT
public:
    const int MAX_THREADS = 30;

    PortsScanner();
    ~PortsScanner();

    int AvailableWorkers();
    int ActiveWorkers();
    bool EnqueueScan(const QString &host, const QString &scanProfileName);
signals:
    void OnRequestStarted(const QString &host);
    void OnRequestError(const QString &host, ScanResult result);
    void OnRequestFinished(const QString &host, ScanResult result);
    void AvailableWorkersChanged(int availableWorkers, int activeWorkers);
private:
    QThreadPool *threadsPool = nullptr;
    void Task(const QString& host, const QString &scanProfileName);
};

#endif // _PORTSSCANNER_H_