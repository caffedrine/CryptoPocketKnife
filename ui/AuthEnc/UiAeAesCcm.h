//
// Created by uib74520 on 2023-08-13.
//

#ifndef CRYPTOPOCKETKNIFE_UIAEAESCCM_H
#define CRYPTOPOCKETKNIFE_UIAEAESCCM_H

#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui {
class UiAeAesCcm;
}
QT_END_NAMESPACE

class UiAeAesCcm : public QMainWindow
{
Q_OBJECT

public:
    explicit UiAeAesCcm(QWidget *parent = nullptr);
    ~UiAeAesCcm() override;

private:
    Ui::UiAeAesCcm *ui;
};


#endif //CRYPTOPOCKETKNIFE_UIAEAESCCM_H
