#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QRandomGenerator>
#include <QDir>
#include <QProcess>
#include <QFileDialog>
#include <QTextStream>
#include <QDebug>
#include <QClipboard>

#include "utils.h"
#include <eddsa.h>
#include <aes.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_ed25519_pushButton_GenerateKeysPair_clicked();
    void on_ed25529_textEdit_privateKey_textChanged(const QString &arg1);
    void on_ed25529_textEdit_publicKey_textChanged(const QString &arg1);
    void on_ed25519_pushButton_CalculateSignature_clicked();
    void on_ed25519_pushButton_VerifySignature_clicked();

    void on_x25519_pushButton_GenerateEphemeralKeys_clicked();
    void on_x25519_pushButton_GenerateEphemeralKeys_2_clicked();
    void on_x25519_pushButton_Clear_clicked();
    void on_x25519_pushButton_CalcSymKeys_clicked();

    void on_ciphers_AES_pushButton_Encrypt_clicked();
    void on_ciphers_AES_pushButton_Decrypt_clicked();

    void on_textEdit_certificates_Parse_InputCertificate_textChanged();
    void on_pushButton_certificates_Parse_ParseCertificate_clicked();
    void on_pushButton_certificates_Parse_ParseCSR_clicked();
    void on_textEdit_certificates_ParseCsr_InputCsr_textChanged();
    void on_pushButton_certificates_Parse_LoadCertificate_clicked();
    void on_pushButton_certificates_Parse_LoadCSR_clicked();
    void on_pushButton_certificates_Parse_CopyCertHEX_clicked();
    void on_pushButton_certificates_Parse_CopyCSRHEX_clicked();

    void on_textEdit_EncodeDecode_General_Ascii_textChanged();
    void on_textEdit_EncodeDecode_General_HEX_textChanged();
    void on_textEdit_EncodeDecode_General_BIN_textChanged();
    void on_pushButton_EncodeDecode_General_ClearAll_clicked();
    void on_pushButton_EncodeDecode_General_LoadBinary_clicked();
    void on_textEdit_EncodeDecode_General_Base64_textChanged();



private:
    Ui::MainWindow *ui;
    bool BypassOnChangeEventFlag = false;

    QByteArray LastParsedCSR, LastParsedCert;

    void Status_EndWithError(QString err_msg);
    void Status_EndWithSuccess(QString err_msg);
    void Status_Clear();
    void ParseCert();
    void ParseCSR();
    QString ParseCertCsrInputStringToB64(QString);
};
#endif // MAINWINDOW_H
