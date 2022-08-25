#ifndef CRYPTOPOCKETKNIFE_UIENCODING_H
#define CRYPTOPOCKETKNIFE_UIENCODING_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui
{
    class UiEncoding;
}
QT_END_NAMESPACE

class UiEncoding: public QWidget
{
    const bool ENC_DEBUGGING = true;

Q_OBJECT
public:
    explicit UiEncoding(QWidget *parent = nullptr);
    ~UiEncoding() override;
    void setCurrentIndex(int idx) {};

private:
    Ui::UiEncoding *ui;
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
    void OnRawDataFileDragged(QString filename);

    void on_textEdit_EncodeDecode_UrlEncoded_textChanged();
    void on_textEdit_EncodeDecode_UrlDecoded_textChanged();
    void on_textEdit_EncodeDecode_HtmlEncoded_textChanged();
    void on_textEdit_EncodeDecode_HtmlDecoded_textChanged();
};


#endif //CRYPTOPOCKETKNIFE_UIENCODING_H
