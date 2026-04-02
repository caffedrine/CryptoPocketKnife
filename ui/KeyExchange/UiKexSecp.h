#ifndef CRYPTOPOCKETKNIFE_UIKEXSECP_H
#define CRYPTOPOCKETKNIFE_UIKEXSECP_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui
{
    class UiKexSecp;
}
QT_END_NAMESPACE

class UiKexSecp : public QWidget
{
Q_OBJECT

public:
    explicit UiKexSecp(QWidget *parent = nullptr);

    ~UiKexSecp() override;

private:
    Ui::UiKexSecp *ui;
    void Status_EndWithError(QString err_msg);
    void Status_EndWithSuccess(QString err_msg);
    void Status_Clear();

private slots:
    void on_pushButton_GenerateEphemeralKeys_clicked();
    void on_pushButton_CalculateSharedSecret_clicked();
    void on_pushButton_Clear_clicked();
};


#endif //CRYPTOPOCKETKNIFE_UIKEXSECP_H
