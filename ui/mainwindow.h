#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDebug>
#include <QMainWindow>
#include <QRandomGenerator>
#include <QDir>
#include <QTextStream>
#include <QDateTime>
#include <QDesktopServices>
#include <QMessageBox>

#include "Logger.h"
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
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private slots:
    // Appl
    void on_actionSupport_triggered();
    void on_actionAbout_triggered();
    void on_actionExit_triggered();
    void on_actionLogs_triggered();

    // Signatrure calculus
    void on_ed25519_pushButton_GenerateKeysPair_clicked();
    void on_ed25529_textEdit_privateKey_textChanged(const QString &arg1);
    void on_ed25529_textEdit_publicKey_textChanged(const QString &arg1);
    void on_ed25519_pushButton_CalculateSignature_clicked();
    void on_ed25519_pushButton_VerifySignature_clicked();
    void on_pushButton_Signature_ED25519_Clear_clicked();

    // Key exchange
    void on_x25519_pushButton_GenerateEphemeralKeys_clicked();
    void on_x25519_pushButton_CalculateSharedSecret_clicked();
    void on_x25519_pushButton_Clear_clicked();
    void on_x25519_pushButton_CalcSymKeys_clicked();

    // Ciphers
    void on_ciphers_AES_pushButton_Encrypt_clicked();
    void on_ciphers_AES_pushButton_Decrypt_clicked();

    // Utils
    void on_pushButton_Utils_CurrentTimestamp_clicked();
    void on_pushButton_Utils_CurrentDateTime_clicked();
    void on_pushButton_TimestampToDatetime_clicked();
    void on_pushButton_dateTimeToTimestamp_clicked();

    private:
    Ui::MainWindow *ui;
    QMap<QString, QString> WebScraperResponseHeaders;
    QMap<QString, QString> WebScraperResponseData;

    void Status_EndWithError(QString err_msg);
    void Status_EndWithSuccess(QString err_msg);
    void Status_Clear();

};
#endif // MAINWINDOW_H
