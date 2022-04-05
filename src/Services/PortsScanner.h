#ifndef _PORTSSCANNER_H_
#define _PORTSSCANNER_H_

#include <QObject>
#include <QThreadPool>
#include <QString>
#include <QDebug>
#include <QProcess>

#include "utils.h"
#include "ThreadsPool.h"
#include "PortsScanProfilesManager.h"

/* */
class PostsScanResultTarget
{
public:
    int TargetIndexWithinProfile;
    QString nMapOutput;
};

/* */
class PortsScanResult
{
public:
    bool AppErrorDetected = false;
    QString AppErrorDesc = "";

    bool NetworkErrorDetected = false;
    QString NetworkErrorDescription = "";


    QString ScanProfile;

    QString hostName;
    QString HostIp;
    QString Timestamp;
    QString Availability;
    QStringList TargetsOutputs;
};

/* */
class PortsScanner: public QObject, public ThreadsPool
{
Q_OBJECT
public:
    PortsScanner(int max_threads_count);
    ~PortsScanner() = default;

    bool EnqueueScan(const QString &host, const QString &scanProfileName);

signals:
    void OnRequestStarted(const QString &host);
    void OnRequestError(const QString &host, PortsScanResult result);
    void OnRequestFinished(const QString &host, PortsScanResult result);
    void AvailableWorkersChanged(int availableWorkers, int activeWorkers);
private:
    void Task(const QString& host, const QString &scanProfileName);
    QString BuildNmapScanCommand(const QString &host, PortsScanTargetType &target);
    QString RunNmapScan(QString nMapCommand);


};

#endif // _PORTSSCANNER_H_