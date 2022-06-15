#ifndef CRYPTOPOCKETKNIFE_UIHASHES_H
#define CRYPTOPOCKETKNIFE_UIHASHES_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui
{
    class UiHashes;
}
QT_END_NAMESPACE

class UiHashes : public QWidget
{
Q_OBJECT

public:
    explicit UiHashes(QWidget *parent = nullptr);
    ~UiHashes() override;
    void setCurrentIndex(int idx) {};

private:
    Ui::UiHashes *ui;

private slots:
    void on_textBrowser_SHA2_InputBytes_textChanged();
    void on_textBrowser_SHA1_InputBytes_textChanged();
    void on_textBrowser_MD5_InputBytes_textChanged();
    void on_textBrowser_SHA3_InputBytes_textChanged();
    void on_textBrowser_BLAKE2_InputBytes_textChanged();
    void on_textBrowser_KECCAK_InputBytes_textChanged();
};


#endif //CRYPTOPOCKETKNIFE_UIHASHES_H
