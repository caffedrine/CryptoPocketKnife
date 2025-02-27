#ifndef CRYPTOPOCKETKNIFE_UINETWORK_H
#define CRYPTOPOCKETKNIFE_UINETWORK_H

#include <QWidget>
#include <QAction>
#include <QMenu>
#include <QMessageBox>
#include <QPlainTextEdit>
#include <QtConcurrent>
#include <QFuture>
#include <QDomElement>
#include <QDomDocument>
#include <QDomText>
#include <QFileDialog>

#include <QUtils/QUtils.h>
#include <QWidgets/QWidgetsUtils.h>
#include "base/services/GeoIP/GeoIP.h"
#include "base/services/PortsScanner/PortsScanner.h"
#include "base/services/PortsScanner/PortsScanProfilesManager.h"

#include "UiPortsScanProfiles.h"

using namespace Services::GeoIP;

QT_BEGIN_NAMESPACE
namespace Ui
{
    class UiNetwork;
}
QT_END_NAMESPACE

class UiNetwork : public QWidget
{
Q_OBJECT

public:
    explicit UiNetwork(QWidget *parent = nullptr);
    ~UiNetwork() override;
    void setCurrentIndex(int idx) {};
public slots:
    void PortsScanner_tableWidget_OnDoubleClickWithoutSelection();
    void PortsScanner_tableWidget_OnRowsCopy(const QModelIndexList& selectedRows);
    void PortsScanner_tableWidget_OnTextPasted(const QString& text);
    void PortsScanner_tableWidget_OnRowsInserted(const QModelIndex &parent, int first, int last);
    void PortsScanner_tableWidget_OnRowsAboutToBeDeleted(const QModelIndex &parent, int first, int last);
    void PortsScanner_tableWidget_OnRowsDeleted(const QModelIndex &parent, int first, int last);
    void PortsScanner_tableWidget_customContextMenuRequested(const QPoint &pos);
    int PortsScanner_GetRowIndexByHost(const QString &host);
    void PortsScanner_ManageScanProfiles_pushButtonCLicked();
    void PortsScanner_StartScan_pushButtonClicked();
    void PortsScanner_StopScan_pushButtonClicked();
    void PortsScanner_ScanSettings_pushButtonClicked();
    void PortsScanner_StretchTable_pushButtonClicked();
    void PortsScanner_ClearTable_pushButtonClicked();
    void PortsScanner_ExportTableCSV_pushButtonClicked();
    void PortsScanner_ExportTableHTML_pushButtonClicked();
    void PortsScanner_OnRequestStarted(QString host, PortsScanResult result);
    void PortsScanner_OnRequestError(QString host, PortsScanResult result);
    void PortsScanner_OnProcessProgress(QString host, PortsScanResult result);
    void PortsScanner_OnRequestFinished(QString host, PortsScanResult result);
    void PortsScanner_OnAvailableWorkersChanged(int availableWorkers, int activeWorkers);
    void PortsScanner_ShowScanResults(int tableHostIndex, const QString &host, bool ScanInProgress);

private:
    Ui::UiNetwork *ui;

    PortsScanner *PortsScannerEngine = nullptr;
    QAtomicInt CancelRequests = false;
    QMap<QString, PortsScanResult> PortsScanResults; // QMap[host] = { Map[profile]=QList[targets] }

    void PortsScanner_InitEngine();
};


#endif //CRYPTOPOCKETKNIFE_UINETWORK_H
