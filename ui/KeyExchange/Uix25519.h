//
// Created by 616C6578 on 2026-04-02.
//

#ifndef CRYPTOPOCKETKNIFE_UIX25519_H
#define CRYPTOPOCKETKNIFE_UIX25519_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui
{
    class Uix25519;
}
QT_END_NAMESPACE

class Uix25519 : public QWidget
{
Q_OBJECT

public:
    explicit Uix25519(QWidget *parent = nullptr);
    ~Uix25519() override;

private:
    Ui::Uix25519 *ui;

    void Status_EndWithError(QString err_msg);
    void Status_EndWithSuccess(QString err_msg);
    void Status_Clear();

private slots:
    void on_pushButton_GenerateEphemeralKeys_clicked();
    void on_pushButton_CalculateSharedSecret_clicked();
    void on_pushButton_Clear_clicked();
};


#endif //CRYPTOPOCKETKNIFE_UIX25519_H
