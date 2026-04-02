//
// Created by 616C6578 on 2026-04-02.
//

#ifndef CRYPTOPOCKETKNIFE_UIKEXX25519_H
#define CRYPTOPOCKETKNIFE_UIKEXX25519_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui
{
    class UiKexX25519;
}
QT_END_NAMESPACE

class UiKexX25519 : public QWidget
{
Q_OBJECT

public:
    explicit UiKexX25519(QWidget *parent = nullptr);
    ~UiKexX25519() override;

private:
    Ui::UiKexX25519 *ui;

    void Status_EndWithError(QString err_msg);
    void Status_EndWithSuccess(QString err_msg);
    void Status_Clear();

private slots:
    void on_pushButton_GenerateEphemeralKeys_clicked();
    void on_pushButton_CalculateSharedSecret_clicked();
    void on_pushButton_Clear_clicked();
};


#endif //CRYPTOPOCKETKNIFE_UIKEXX25519_H
