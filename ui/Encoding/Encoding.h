#ifndef CRYPTOPOCKETKNIFE_ENCODING_H
#define CRYPTOPOCKETKNIFE_ENCODING_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui
{
    class Encoding;
}
QT_END_NAMESPACE

class Encoding: public QWidget
{
Q_OBJECT

public:
    explicit Encoding(QWidget *parent = nullptr);
    ~Encoding() override;
    void setCurrentIndex(int idx) {};

private:
    Ui::Encoding *ui;
    bool BypassOnChangeEventFlag = false;


private slots:
    // Encoding/decoding
    void EncodeDecode_General_UpdateAllFieldsFromQByteArray(QByteArray bytes, const QString& exception);
    void on_textEdit_EncodeDecode_General_Ascii_textChanged();
    void on_textEdit_EncodeDecode_General_HEX_textChanged();
    void on_textEdit_EncodeDecode_General_BIN_textChanged();
    void on_textEdit_EncodeDecode_General_DEC_textChanged();
    void on_textEdit_EncodeDecode_General_Number_textChanged();
    void on_pushButton_EncodeDecode_General_ClearAll_clicked();
    void on_pushButton_EncodeDecode_General_LoadBinary_clicked();
    void on_textEdit_EncodeDecode_General_Base64_textChanged();
    void on_textEdit_EncodeDecode_General_AlphanumericStrings_textChanged();
    void on_textEdit_EncodeDecode_UrlEncoded_textChanged();
    void on_textEdit_EncodeDecode_UrlDecoded_textChanged();
    void on_textEdit_EncodeDecode_HtmlEncoded_textChanged();
    void on_textEdit_EncodeDecode_HtmlDecoded_textChanged();
};


#endif //CRYPTOPOCKETKNIFE_ENCODING_H
