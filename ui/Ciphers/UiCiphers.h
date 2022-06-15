#ifndef CRYPTOPOCKETKNIFE_UICIPHERS_H
#define CRYPTOPOCKETKNIFE_UICIPHERS_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui
{
    class UiCiphers;
}
QT_END_NAMESPACE

class UiCiphers : public QWidget
{
Q_OBJECT

public:
    explicit UiCiphers(QWidget *parent = nullptr);
    ~UiCiphers() override;

private:
    Ui::UiCiphers *ui;
};


#endif //CRYPTOPOCKETKNIFE_UICIPHERS_H
