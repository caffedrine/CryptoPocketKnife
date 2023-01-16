/*  
 *  File      : PortsScanProfiles.h
 *  Created on: 2022-04-02
 */

#ifndef CRYPTOPOCKETKNIFE_UIPORTSSCANPROFILES_H
#define CRYPTOPOCKETKNIFE_UIPORTSSCANPROFILES_H

#include <QWidget>
#include <QListWidgetItem>

#include "base/extensions/QDialogExtended.h"
#include "base/services/PortsScanner/PortsScanProfilesManager.h"

using namespace Services::PortsScanner;

QT_BEGIN_NAMESPACE
namespace Ui
{
    class UiPortsScanProfiles;
}
QT_END_NAMESPACE

class UiPortsScanProfiles: public QDialogExtended
{
Q_OBJECT

public:
    explicit UiPortsScanProfiles(QWidget *parent = nullptr);
    ~UiPortsScanProfiles();
    void setCurrentIndex(int index);

public slots:
    void onSelectedItemChanged_AvailableProfiles();

private:
    Ui::UiPortsScanProfiles *ui;
};


#endif //CRYPTOPOCKETKNIFE_UIPORTSSCANPROFILES_H
