#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QRandomGenerator>
#include <QDir>
#include <QProcess>
#include <QFileDialog>
#include <QSaveFile>
#include <QTextStream>
#include <QDebug>
#include <QClipboard>
#include <QMimeData>
#include <QDropEvent>
#include <QDragEnterEvent>
#include <QCryptographicHash>
#include <QDateTime>
#include <QDesktopServices>
#include <QMessageBox>
#include <QDebug>
#include <QtGlobal>
#include <QMap>

#define dbgln qDebug().noquote().nospace()

#include "AdvancedTableWidget.h"
#include "AdvancedTextEdit.h"
#include "WebScraper.h"
#include "utils.h"
#include <eddsa.h>
#include <aes.h>
#include <Hash.h>

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
    // Appl
    void on_actionSupport_triggered();
    void on_actionAbout_triggered();
    void on_actionExit_triggered();

    // Signatrure calculus
    void on_ed25519_pushButton_GenerateKeysPair_clicked();
    void on_ed25529_textEdit_privateKey_textChanged(const QString &arg1);
    void on_ed25529_textEdit_publicKey_textChanged(const QString &arg1);
    void on_ed25519_pushButton_CalculateSignature_clicked();
    void on_ed25519_pushButton_VerifySignature_clicked();

    // Key exchange
    void on_x25519_pushButton_GenerateEphemeralKeys_clicked();
    void on_x25519_pushButton_CalculateSharedSecret_clicked();
    void on_x25519_pushButton_Clear_clicked();
    void on_x25519_pushButton_CalcSymKeys_clicked();

    // Ciphers
    void on_ciphers_AES_pushButton_Encrypt_clicked();
    void on_ciphers_AES_pushButton_Decrypt_clicked();

    // Certificates
    void on_textEdit_certificates_Parse_InputCertificate_textChanged();
    void on_pushButton_certificates_Parse_ParseCertificate_clicked();
    void on_pushButton_certificates_Parse_ParseCSR_clicked();
    void on_textEdit_certificates_ParseCsr_InputCsr_textChanged();
    void on_pushButton_certificates_Parse_LoadCertificate_clicked();
    void on_pushButton_certificates_Parse_LoadCSR_clicked();
    void on_pushButton_certificates_Parse_CopyCertHEX_clicked();
    void on_pushButton_certificates_Parse_CopyCSRHEX_clicked();
    void on_pushButton_certificates_Parse_ExportCSR_clicked();
    void on_pushButton_certificates_Parse_ExportCRT_clicked();
    void OnCertFileDragged(QString filename);
    void OnCsrFileDragged(QString filename);

    // Encoding/decoding
    void EncodeDecode_General_UpdateAllFieldsFromQByteArray(QByteArray bytes, QString exception);
    void on_textEdit_EncodeDecode_General_Ascii_textChanged();
    void on_textEdit_EncodeDecode_General_HEX_textChanged();
    void on_textEdit_EncodeDecode_General_BIN_textChanged();
    void on_textEdit_EncodeDecode_General_DEC_textChanged();
    void on_pushButton_EncodeDecode_General_ClearAll_clicked();
    void on_pushButton_EncodeDecode_General_LoadBinary_clicked();
    void on_textEdit_EncodeDecode_General_Base64_textChanged();
    void on_textEdit_EncodeDecode_General_AlphanumericStrings_textChanged();
    void on_textEdit_EncodeDecode_UrlEncoded_textChanged();
    void on_textEdit_EncodeDecode_UrlDecoded_textChanged();
    void on_textEdit_EncodeDecode_HtmlEncoded_textChanged();
    void on_textEdit_EncodeDecode_HtmlDecoded_textChanged();

    // Hashing
    void on_textBrowser_SHA2_InputBytes_textChanged();
    void on_textBrowser_SHA1_InputBytes_textChanged();
    void on_textBrowser_MD5_InputBytes_textChanged();

    // Web
    QString WebScraper_getFullUrlFromTable(int row);
    void tableWidget_WebScraper_OnRowsCopy(QModelIndexList selectedRows);
    void tableWidget_WebScraper_OnTextPasted(QString text);
    void tableWidget_WebScraper_OnRowsInserted(const QModelIndex &parent, int first, int last);
    void tableWidget_WebScraper_OnRowsAboutToBeDeleted(const QModelIndex &parent, int first, int last);
    void on_tableWidget_WebScraper_customContextMenuRequested(const QPoint &pos);
    void on_pushButton_WebScraping_Clear_clicked();
    void on_pushButton_WebScraper_StopDownload_clicked();
    void on_pushButton_WebScraper_StartDownload_clicked();
    void webScraper_OnRequestError(QString requestId, QString requestUrl, HttpResponse response);
    void webScraper_OnRequestStarted(QString requestId, QString requestUrl);
    void webScraper_OnRequestFinished(QString requestId, QString requestUrl, HttpResponse response);

    // Networking

    // Utils
    void on_pushButton_Utils_CurrentTimestamp_clicked();
    void on_pushButton_Utils_CurrentDateTime_clicked();
    void on_pushButton_TimestampToDatetime_clicked();
    void on_pushButton_dateTimeToTimestamp_clicked();


    private:
    Ui::MainWindow *ui;
    bool BypassOnChangeEventFlag = false;
    QByteArray LastParsedCSR, LastParsedCert;
    QMap<QString, QString> WebScraperResponseHeaders;
    QMap<QString, QString> WebScraperResponseData;

    void Status_EndWithError(QString err_msg);
    void Status_EndWithSuccess(QString err_msg);
    void Status_Clear();
    void ParseCert();
    void ParseCSR();
    QString ParseCertCsrInputStringToB64(QString);
};
#endif // MAINWINDOW_H
