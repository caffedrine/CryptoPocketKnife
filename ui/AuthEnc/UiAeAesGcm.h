#ifndef CRYPTOPOCKETKNIFE_UIAEAESGCM_H
#define CRYPTOPOCKETKNIFE_UIAEAESGCM_H

#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui {
class UiAeAesGcm;
}
QT_END_NAMESPACE

class UiAeAesGcm : public QMainWindow
{
Q_OBJECT

public:
    explicit UiAeAesGcm(QWidget *parent = nullptr);
    ~UiAeAesGcm() override;

public slots:
    void on_textEdit_InputData_textChanged();
    void on_textEdit_OutputData_textChanged();
    void on_lineEdit_Mac_textChanged();
    void on_lineEdit_Key_textChanged();
    void on_lineEdit_IV_textChanged();
    void on_pushButton_Encrypt_clicked();
    void on_pushButton_Decrypt_clicked();

private:
    Ui::UiAeAesGcm *ui;

    QByteArray inputBytes, outputBytes, mac, key, iv;

    bool CheckPreconditions();
};


#endif //CRYPTOPOCKETKNIFE_UIAEAESGCM_H
