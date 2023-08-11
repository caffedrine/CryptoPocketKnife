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

public slots:
    void on_textEdit_InputData_textChanged();
    void on_lineEdit_Mac_textChanged();
    void on_lineEdit_Key_textChanged();
    void on_pushButton_CalcMac_clicked();
    void on_pushButton_VerifyMac_clicked();
private:
    Ui::UiAesCmac *ui;
    QByteArray inputBytes;
    QByteArray mac, key;

    bool CheckPreconditions();
};


#endif //CRYPTOPOCKETKNIFE_UIAESCMAC_H
