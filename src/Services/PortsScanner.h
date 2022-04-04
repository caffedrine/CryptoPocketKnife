#ifndef _PORTSSCANNER_H_
#define _PORTSSCANNER_H_

#include <QObject>
#include <QThreadPool>
#include <QString>
#include <QDebug>

#include "utils.h"
#include "ThreadsPool.h"
#include "PortsScanProfilesManager.h"

/* */
class PostsScanRequestNMAP
{
public:
    QString host;
    QList<quint16> TcpPorts;
    QList<quint16> UdpPorts;
    QMap<QString, QMap<QString, QList<quint16>>> nMapScripts;
};

/* */
class PortsScanResult
{
public:
    bool AppErrorDetected = false;
    QString AppErrorDesc = "";

    bool NetworkErrorDetected = false;
    QString NetworkErrorDescription = "";

    QString nMapCommand;
    QString ScanProfile;
    QString Timestamp;
    QString Availability;
    QMap<quint16, QString> OpenTcpPorts;
    QMap<quint16, QString> OpenUdpPorts;
    QList<quint16> ScannedTcpPorts;
    QList<quint16> ScannedUdpPorts;
    QString DeviceType;
    QString VendorName;
    QString DeviceName;
    QString HostIp;
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
    void StartNmapScan(const PostsScanRequestNMAP &request);
};

#endif // _PORTSSCANNER_H_