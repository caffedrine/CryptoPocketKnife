#ifndef CRYPTOPOCKETKNIFE_UIDSAED25519_H
#define CRYPTOPOCKETKNIFE_UIDSAED25519_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui
{
    class UiDsaEd25519;
}
QT_END_NAMESPACE

class UiDsaEd25519 : public QWidget {
Q_OBJECT

public:
    explicit UiDsaEd25519(QWidget *parent = nullptr);

    ~UiDsaEd25519() override;

private:
    Ui::UiDsaEd25519 *ui;

    void Status_EndWithError(QString err_msg);
    void Status_EndWithSuccess(QString err_msg);
    void Status_Clear();

private slots:
    void on_pushButton_GenerateKeysPair_clicked();
    void on_pushButton_CalculateSignature_clicked();
    void on_pushButton_VerifySignature_clicked();
    void on_pushButton_Clear_clicked();
    void on_textEdit_privateKey_textChanged(const QString &arg1);
    void on_textEdit_publicKey_textChanged(const QString &arg1);
};


#endif //CRYPTOPOCKETKNIFE_UIDSAED25519_H
