//
// Created by uib74520 on 2023-08-10.
//

#ifndef CRYPTOPOCKETKNIFE_UIAESCMAC_H
#define CRYPTOPOCKETKNIFE_UIAESCMAC_H

#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui {
class UiAesCmac;
}
QT_END_NAMESPACE

class UiAesCmac : public QMainWindow
{
Q_OBJECT

public:
    explicit UiAesCmac(QWidget *parent = nullptr);
    ~UiAesCmac() override;

private:
    Ui::UiAesCmac *ui;
};


#endif //CRYPTOPOCKETKNIFE_UIAESCMAC_H
