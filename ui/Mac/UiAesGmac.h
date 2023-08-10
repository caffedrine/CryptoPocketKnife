//
// Created by uib74520 on 2023-08-10.
//

#ifndef CRYPTOPOCKETKNIFE_UIAESGMAC_H
#define CRYPTOPOCKETKNIFE_UIAESGMAC_H

#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui {
class UiAesGmac;
}
QT_END_NAMESPACE

class UiAesGmac : public QMainWindow
{
Q_OBJECT

public:
    explicit UiAesGmac(QWidget *parent = nullptr);
    ~UiAesGmac() override;

private:
    Ui::UiAesGmac *ui;
};


#endif //CRYPTOPOCKETKNIFE_UIAESGMAC_H
