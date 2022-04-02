/*  
 *  File      : PortsScanProfiles.h
 *  Created on: 2022-04-02
 */

#ifndef CRYPTOPOCKETKNIFE_PORTSSCANPROFILES_H
#define CRYPTOPOCKETKNIFE_PORTSSCANPROFILES_H

#include <QWidget>
#include <QDialog>


QT_BEGIN_NAMESPACE
namespace Ui
{
    class PortsScanProfiles;
}
QT_END_NAMESPACE

class PortsScanProfiles: public QDialog
{
Q_OBJECT

public:
    explicit PortsScanProfiles(QWidget *parent = nullptr);

    ~PortsScanProfiles() override;

private:
    Ui::PortsScanProfiles *ui;
};


#endif //CRYPTOPOCKETKNIFE_PORTSSCANPROFILES_H
