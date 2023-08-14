#ifndef CRYPTOPOCKETKNIFE_UIAEAESCCM_H
#define CRYPTOPOCKETKNIFE_UIAEAESCCM_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class UiAeAesCcm;
}
QT_END_NAMESPACE

class UiAeAesCcm : public QMainWindow
{
Q_OBJECT

public:
    explicit UiAeAesCcm(QWidget *parent = nullptr);
    ~UiAeAesCcm() override;

public slots:
    void on_textEdit_InputDataEncDec_textChanged();
    void on_textEdit_InputDataAuth_textChanged();
    void on_textEdit_OutputData_textChanged();
    void on_lineEdit_Tag_textChanged();
    void on_comboBox_TagSize_currentTextChanged(const QString&);
    void on_lineEdit_Key_textChanged();
    void on_lineEdit_Nonce_textChanged();
    void on_pushButton_Encrypt_clicked();
    void on_pushButton_Decrypt_clicked();

private:
    Ui::UiAeAesCcm *ui;

    uint8_t tagSize = 10;
    QByteArray inputEncDecBytes, inputBytesAad, outputBytes, tag, key, nonce;

    bool CheckPreconditions();
};

#endif //CRYPTOPOCKETKNIFE_UIAEAESCCM_H
