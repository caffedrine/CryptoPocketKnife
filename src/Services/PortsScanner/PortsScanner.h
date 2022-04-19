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
#include <QCoreApplication>
#include <QTextDocument>

#include "Cfg_PortsScanner.h"

#include "utils.h"
#include "ThreadsPool.h"
#include "PortsScanProfilesManager.h"
#include "nMapXmlParser.h"

namespace Services::PortsScanner
{

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
    QString PingOutput = "";
    quint64 StartScanTimestamp = 0;
    quint64 ScanDurationSeconds = 0;
    QString PingState = "";
    float PingLatencySeconds;
    QStringList OpenTcpPorts;
    QStringList OpenUdpPorts;
    QStringList DeviceType;
    QStringList DeviceName;

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
    void OnRequestStarted(const QString &host, const PortsScanResult &result);
    void OnRequestError(const QString &host, const PortsScanResult &result);
    void OnProcessProgress(const QString &host, const PortsScanResult &result);
    void OnRequestFinished(const QString &host, const PortsScanResult &result);
    void AvailableWorkersChanged(int availableWorkers, int activeWorkers);
private:
    void Task(const QString& host, const QString &scanProfileName);
    QString BuildNmapScanCommand(const QString &host, PortsScanTargetType &target);
    QString RunNmapScan(QString nMapCommand);
    bool RunNmapPingAndRDNSScan(const QString &host, PortsScanResult *output);
    bool TryParseNmapXML(QString xmlContent, nMapXmlParser *outputNmapXmlParser, PortsScanResult *output);
};

}

#endif // _PORTSSCANNER_H_