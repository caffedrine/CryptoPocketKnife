/*  
 *  File      : PortsScanProfiles.h
 *  Created on: 2022-04-02
 */

#ifndef CRYPTOPOCKETKNIFE_PORTSSCANPROFILES_H
#define CRYPTOPOCKETKNIFE_PORTSSCANPROFILES_H

#include <QWidget>
#include <QListWidgetItem>

#include "QDialogExtended.h"
#include "PortsScanProfilesManager.h"

using namespace Services::PortsScanner;

QT_BEGIN_NAMESPACE
namespace Ui
{
    class PortsScanProfiles;
}
QT_END_NAMESPACE

class PortsScanProfiles: public QDialogExtended
{
Q_OBJECT

public:
    explicit PortsScanProfiles(QWidget *parent = nullptr);
    ~PortsScanProfiles();
    void setCurrentIndex(int index);

public slots:
    void onSelectedItemChanged_AvailableProfiles();

private:
    Ui::PortsScanProfiles *ui;
};


#endif //CRYPTOPOCKETKNIFE_PORTSSCANPROFILES_H
