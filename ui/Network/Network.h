/*  
 *  File      : Network.h
 *  Created on: 2022-04-01
 */

#ifndef CRYPTOPOCKETKNIFE_NETWORK_H
#define CRYPTOPOCKETKNIFE_NETWORK_H

#include <QWidget>
#include <QAction>
#include <QMenu>
#include <QMessageBox>
#include <QPlainTextEdit>
#include <QtConcurrent>
#include <QFuture>

#include "PortsScanner.h"
#include "PortsScanProfiles.h"
#include "PortsScanProfilesManager.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
    class Network;
}
QT_END_NAMESPACE

class Network : public QWidget
{
Q_OBJECT

public:
    explicit Network(QWidget *parent = nullptr);
    ~Network() override;
    void setCurrentIndex(int idx) {};
public slots:
    void PortsScanner_tableWidget_OnRowsCopy(const QModelIndexList& selectedRows);
    void PortsScanner_tableWidget_OnTextPasted(const QString& text);
    void PortsScanner_tableWidget_OnRowsInserted(const QModelIndex &parent, int first, int last);
    void PortsScanner_tableWidget_OnRowsAboutToBeDeleted(const QModelIndex &parent, int first, int last);
    void PortsScanner_tableWidget_OnRowsDeleted(const QModelIndex &parent, int first, int last);
    void PortsScanner_tableWidget_customContextMenuRequested(const QPoint &pos);
    int PortsScanner_GetRowIndexByHost(const QString &host);
    void PortsScanner_ManageScanProfiles_pushButtonCLicked();
    void PortsScanner_StartScan_pushButtonClocked();
    void PortsScanner_StopScan_pushButtonClocked();
    void PortsScanner_StretchTable_pushButtonClocked();
    void PortsScanner_ClearTable_pushButtonClocked();
    void PortsScanner_OnRequestStarted(const QString &host);
    void PortsScanner_OnRequestError(const QString &host, PortsScanResult result);
    void PortsScanner_OnRequestFinished(const QString &host, PortsScanResult result);
    void PortsScanner_OnAvailableWorkersChanged(int availableWorkers, int activeWorkers);
private:
    Ui::Network *ui;

    PortsScanner *PortsScannerEngine = nullptr;
    bool CancelRequests = false;
    QMap<QString, QString> PortsScanResults;

    void PortsScanner_InitEngine();
};


#endif //CRYPTOPOCKETKNIFE_NETWORK_H