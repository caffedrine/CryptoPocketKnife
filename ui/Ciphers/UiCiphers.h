#ifndef CRYPTOPOCKETKNIFE_UICIPHERS_H
#define CRYPTOPOCKETKNIFE_UICIPHERS_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui
{
    class UiCiphers;
}
QT_END_NAMESPACE

class UiCiphers : public QWidget
{
Q_OBJECT

public:
    explicit UiCiphers(QWidget *parent = nullptr);
    ~UiCiphers() override;
    void setCurrentIndex(int idx) {};

private:
    Ui::UiCiphers *ui;

private slots:
    void on_ciphers_AES_pushButton_Encrypt_clicked();
    void on_ciphers_AES_pushButton_Decrypt_clicked();
};


#endif //CRYPTOPOCKETKNIFE_UICIPHERS_H
