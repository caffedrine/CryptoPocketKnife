#ifndef CRYPTOPOCKETKNIFE_UIHMACSHA_H
#define CRYPTOPOCKETKNIFE_UIHMACSHA_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class UiHmacSha;
}
QT_END_NAMESPACE

class UiHmacSha : public QMainWindow
{
Q_OBJECT

public:
    explicit UiHmacSha(QWidget *parent = nullptr);
    ~UiHmacSha() override;

public slots:
    void on_textEdit_InputData_textChanged();
    void on_lineEdit_Mac_textChanged();
    void on_lineEdit_Key_textChanged();
    void on_pushButton_CalcMac_clicked();
    void on_pushButton_VerifyMac_clicked();

private:
    Ui::UiHmacSha *ui;
    QByteArray inputBytes;
    QByteArray mac, key;

    bool CheckPreconditions();
};


#endif //CRYPTOPOCKETKNIFE_UIHMACSHA_H
