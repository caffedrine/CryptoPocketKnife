//
// Created by uib74520 on 2022-06-14.
//

#ifndef CRYPTOPOCKETKNIFE_UICERTIFICATES_H
#define CRYPTOPOCKETKNIFE_UICERTIFICATES_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui
{
    class UiCertificates;
}
QT_END_NAMESPACE

class UiCertificates : public QWidget
{
Q_OBJECT

public:
    explicit UiCertificates(QWidget *parent = nullptr);
    ~UiCertificates() override;
    void setCurrentIndex(int index) {};

private slots:
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

private:
    Ui::UiCertificates *ui;
    QByteArray LastParsedCSR, LastParsedCert;

    void ParseCert();
    void ParseCSR();
    QString ParseCertCsrInputStringToB64(QString);

    void Status_EndWithError(QString err_msg);
    void Status_EndWithSuccess(QString err_msg);
    void Status_Clear();
};


#endif //CRYPTOPOCKETKNIFE_UICERTIFICATES_H
