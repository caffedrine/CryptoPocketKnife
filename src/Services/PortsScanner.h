#ifndef _PORTSSCANNER_H_
#define _PORTSSCANNER_H_

#include <QObject>
#include <QThreadPool>
#include <QString>
#include <QDebug>
#include <QProcess>
#include <QDateTime>
#include <QDomElement>
#include <QDomDocument>
#include <QDomText>

#include "Logger.h"
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


    QString ScanProfile = "";

    QString HostRdns = "";
    QString HostIp = "";
    quint64 StartScanTimestamp = 0;
    quint64 ScanDurationSeconds = 0;
    QString Availability = "";

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
    //void OnRequestPreStart(const QString &host_address, const QString &rdns );
    void OnRequestStarted(const QString &host);
    void OnRequestError(const QString &host, PortsScanResult result);
    void OnProcessProgress(const QString &host, PortsScanResult result);
    void OnRequestFinished(const QString &host, PortsScanResult result);
    void AvailableWorkersChanged(int availableWorkers, int activeWorkers);
private:
    void Task(const QString& host, const QString &scanProfileName);
    QString BuildNmapScanCommand(const QString &host, PortsScanTargetType &target);
    QString RunNmapScan(QString nMapCommand);
    QStringList RunNmapPingAndRDNSScan(const QString &host);


};

#endif // _PORTSSCANNER_H_