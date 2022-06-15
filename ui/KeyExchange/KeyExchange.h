#ifndef CRYPTOPOCKETKNIFE_KEYEXCHANGE_H
#define CRYPTOPOCKETKNIFE_KEYEXCHANGE_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui
{
    class KeyExchange;
}
QT_END_NAMESPACE

class KeyExchange : public QWidget
{
Q_OBJECT

public:
    explicit KeyExchange(QWidget *parent = nullptr);
    ~KeyExchange() override;

private:
    Ui::KeyExchange *ui;
};


#endif //CRYPTOPOCKETKNIFE_KEYEXCHANGE_H
