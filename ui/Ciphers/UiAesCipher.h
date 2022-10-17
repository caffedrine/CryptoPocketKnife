#ifndef CRYPTOPOCKETKNIFE_UIAESCIPHER_H
#define CRYPTOPOCKETKNIFE_UIAESCIPHER_H

#include <QWidget>
#include <QMap>

#include "qaesencryption.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class UiAesCipher;
}
QT_END_NAMESPACE

class UiAesCipher : public QWidget
{
Q_OBJECT

public:
    explicit UiAesCipher(QWidget *parent = nullptr);
    ~UiAesCipher() override;

private slots:
    void on_pushButton_Encrypt_clicked();
    void on_pushButton_Decrypt_clicked();
    void on_textEdit_Input_textChanged();
    void on_textEdit_Output_textChanged();
    void on_lineEdit_Key_textChanged();
    void on_lineEdit_IV_textChanged();

private:
    Ui::UiAesCipher *ui;

    int GetCurrentLevel();
    int GetCurrentMode();
    int GetCurrentPadding();

    QMap<int, int> AesKeySizes = {{((int)QAESEncryption::AES_128), 128},  {((int)QAESEncryption::AES_192), 192}, {(int)QAESEncryption::AES_256, 256}};
};


#endif //CRYPTOPOCKETKNIFE_UIAESCIPHER_H
