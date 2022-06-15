#ifndef CRYPTOPOCKETKNIFE_UIKEYEXCHANGE_H
#define CRYPTOPOCKETKNIFE_UIKEYEXCHANGE_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui
{
    class UiKeyExchange;
}
QT_END_NAMESPACE

class UiKeyExchange : public QWidget
{
Q_OBJECT

public:
    explicit UiKeyExchange(QWidget *parent = nullptr);
    ~UiKeyExchange() override;

private:
    Ui::UiKeyExchange *ui;
};


#endif //CRYPTOPOCKETKNIFE_UIKEYEXCHANGE_H
