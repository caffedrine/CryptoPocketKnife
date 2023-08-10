//
// Created by uib74520 on 2023-08-10.
//

#ifndef CRYPTOPOCKETKNIFE_UIHMAC_H
#define CRYPTOPOCKETKNIFE_UIHMAC_H

#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui {
class UiHmac;
}
QT_END_NAMESPACE

class UiHmac : public QMainWindow
{
Q_OBJECT

public:
    explicit UiHmac(QWidget *parent = nullptr);
    ~UiHmac() override;

private:
    Ui::UiHmac *ui;
};


#endif //CRYPTOPOCKETKNIFE_UIHMAC_H
