#ifndef CRYPTOPOCKETKNIFE_UIDIGITALSIGNATURES_H
#define CRYPTOPOCKETKNIFE_UIDIGITALSIGNATURES_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui
{
    class UiDigitalSignatures;
}
QT_END_NAMESPACE

class UiDigitalSignatures : public QWidget
{
Q_OBJECT

public:
    explicit UiDigitalSignatures(QWidget *parent = nullptr);
    ~UiDigitalSignatures() override;
    void setCurrentIndex(int idx) {};

private:
    Ui::UiDigitalSignatures *ui;

    void Status_EndWithError(QString err_msg);
    void Status_EndWithSuccess(QString err_msg);
    void Status_Clear();

private slots:
    void on_ed25519_pushButton_GenerateKeysPair_clicked();
    void on_ed25529_textEdit_privateKey_textChanged(const QString &arg1);
    void on_ed25529_textEdit_publicKey_textChanged(const QString &arg1);
    void on_ed25519_pushButton_CalculateSignature_clicked();
    void on_ed25519_pushButton_VerifySignature_clicked();
    void on_pushButton_Signature_ED25519_Clear_clicked();
};


#endif //CRYPTOPOCKETKNIFE_UIDIGITALSIGNATURES_H
