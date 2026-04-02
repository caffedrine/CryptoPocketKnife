//
// Created by 616C6578 on 2026-04-02.
//

#ifndef CRYPTOPOCKETKNIFE_UISECP_H
#define CRYPTOPOCKETKNIFE_UISECP_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui
{
    class UiSecp;
}
QT_END_NAMESPACE

class UiSecp : public QWidget
{
Q_OBJECT

public:
    explicit UiSecp(QWidget *parent = nullptr);

    ~UiSecp() override;

private:
    Ui::UiSecp *ui;
    void Status_EndWithError(QString err_msg);
    void Status_EndWithSuccess(QString err_msg);
    void Status_Clear();

private slots:
    void on_pushButton_GenerateEphemeralKeys_clicked();
    void on_pushButton_CalculateSharedSecret_clicked();
    void on_pushButton_Clear_clicked();
};


#endif //CRYPTOPOCKETKNIFE_UISECP_H
