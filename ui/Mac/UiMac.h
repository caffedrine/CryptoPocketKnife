#ifndef CRYPTOPOCKETKNIFE_UIMAC_H
#define CRYPTOPOCKETKNIFE_UIMAC_H

#include <QMainWindow>
#include "ui/Mac/UiAesCmac.h"
#include "ui/Mac/UiAesGmac.h"
#include "ui/Mac/UiHmac.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class UiMac;
}
QT_END_NAMESPACE

class UiMac : public QMainWindow
{
    Q_OBJECT

public:
    explicit UiMac(QWidget *parent = nullptr);
    ~UiMac() override;

private:
    Ui::UiMac *ui;
};


#endif //CRYPTOPOCKETKNIFE_UIMAC_H
