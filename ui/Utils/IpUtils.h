#ifndef CRYPTOPOCKETKNIFE_IPUTILS_H
#define CRYPTOPOCKETKNIFE_IPUTILS_H

#include <QWidget>
#include <NetworkUtils.h>
#include <RegexUtils.h>

QT_BEGIN_NAMESPACE
namespace Ui
{
    class IpUtils;
}
QT_END_NAMESPACE

class IpUtils : public QWidget
{
Q_OBJECT

public:
    explicit IpUtils(QWidget *parent = nullptr);
    ~IpUtils() override;

private:
    Ui::IpUtils *ui;

private slots:
    void on_pushButton_ExtractIP_clicked();
    void on_pushButton_ExtractIpPort_clicked();
    void on_pushButton_ExtractIPv6_clicked();
    void on_pushButton_ExtractIPv6Port_clicked();
    void on_pushButton_Decimal2Dotted_clicked();
    void on_pushButton_Dotted2Decimal_clicked();
    void on_pushButton_Output_Clear_clicked();
};


#endif //CRYPTOPOCKETKNIFE_IPUTILS_H