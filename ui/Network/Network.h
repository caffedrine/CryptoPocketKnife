/*  
 *  File      : Network.h
 *  Created on: 2022-04-01
 */

#ifndef CRYPTOPOCKETKNIFE_NETWORK_H
#define CRYPTOPOCKETKNIFE_NETWORK_H

#include <QWidget>


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

private:
    Ui::Network *ui;
};


#endif //CRYPTOPOCKETKNIFE_NETWORK_H
