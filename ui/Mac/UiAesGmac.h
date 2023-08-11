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

public slots:
    void on_textEdit_InputData_textChanged();
    void on_lineEdit_Mac_textChanged();
    void on_lineEdit_Key_textChanged();
    void on_lineEdit_IV_textChanged();
    void on_pushButton_CalcMac_clicked();
    void on_pushButton_VerifyMac_clicked();

private:
    Ui::UiAesGmac *ui;
    QByteArray inputBytes, mac, key, iv;

    bool CheckPreconditions();
};


#endif //CRYPTOPOCKETKNIFE_UIAESGMAC_H
