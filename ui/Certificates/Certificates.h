//
// Created by uib74520 on 2022-06-14.
//

#ifndef CRYPTOPOCKETKNIFE_CERTIFICATES_H
#define CRYPTOPOCKETKNIFE_CERTIFICATES_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui
{
    class Certificates;
}
QT_END_NAMESPACE

class Certificates : public QWidget
{
Q_OBJECT

public:
    explicit Certificates(QWidget *parent = nullptr);
    ~Certificates() override;
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
    Ui::Certificates *ui;
    QByteArray LastParsedCSR, LastParsedCert;

    void ParseCert();
    void ParseCSR();
    QString ParseCertCsrInputStringToB64(QString);

    void Status_EndWithError(QString err_msg);
    void Status_EndWithSuccess(QString err_msg);
    void Status_Clear();
};


#endif //CRYPTOPOCKETKNIFE_CERTIFICATES_H
