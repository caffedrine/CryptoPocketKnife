#ifndef CRYPTOPOCKETKNIFE_UIKEYEXCHANGE_H
#define CRYPTOPOCKETKNIFE_UIKEYEXCHANGE_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui
{
    class UiKeyExchange;
}
QT_END_NAMESPACE

class UiKeyExchange : public QWidget
{
Q_OBJECT

public:
    explicit UiKeyExchange(QWidget *parent = nullptr);
    ~UiKeyExchange() override;
    void setCurrentIndex(int idx) {};

private:
    Ui::UiKeyExchange *ui;

    void Status_EndWithError(QString err_msg);
    void Status_EndWithSuccess(QString err_msg);
    void Status_Clear();

private slots:
    void on_x25519_pushButton_GenerateEphemeralKeys_clicked();
    void on_x25519_pushButton_CalculateSharedSecret_clicked();
    void on_x25519_pushButton_Clear_clicked();
    void on_x25519_pushButton_CalcSymKeys_clicked();

};


#endif //CRYPTOPOCKETKNIFE_UIKEYEXCHANGE_H
