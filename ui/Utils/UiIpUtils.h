#ifndef CRYPTOPOCKETKNIFE_UIIPUTILS_H
#define CRYPTOPOCKETKNIFE_UIIPUTILS_H

#include <QWidget>
#include <base/utils/NetworkUtils.h>
#include <base/utils/RegexUtils.h>

QT_BEGIN_NAMESPACE
namespace Ui
{
    class UiIpUtils;
}
QT_END_NAMESPACE

class UiIpUtils : public QWidget
{
Q_OBJECT

public:
    explicit UiIpUtils(QWidget *parent = nullptr);
    ~UiIpUtils() override;

private:
    Ui::UiIpUtils *ui;

private slots:
    void on_pushButton_ExtractIP_clicked();
    void on_pushButton_ExtractIpPort_clicked();
    void on_pushButton_ExtractIPv6_clicked();
    void on_pushButton_ExtractIPv6Port_clicked();
    void on_pushButton_Decimal2Dotted_clicked();
    void on_pushButton_Dotted2Decimal_clicked();
    void on_pushButton_Output_Clear_clicked();
    void on_pushButton_OrderList_clicked();
};


#endif //CRYPTOPOCKETKNIFE_UIIPUTILS_H
