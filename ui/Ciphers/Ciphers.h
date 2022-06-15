#ifndef CRYPTOPOCKETKNIFE_CIPHERS_H
#define CRYPTOPOCKETKNIFE_CIPHERS_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui
{
    class Ciphers;
}
QT_END_NAMESPACE

class Ciphers : public QWidget
{
Q_OBJECT

public:
    explicit Ciphers(QWidget *parent = nullptr);
    ~Ciphers() override;

private:
    Ui::Ciphers *ui;
};


#endif //CRYPTOPOCKETKNIFE_CIPHERS_H
