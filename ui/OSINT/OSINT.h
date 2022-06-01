#ifndef CRYPTOPOCKETKNIFE_OSINT_H
#define CRYPTOPOCKETKNIFE_OSINT_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui
{
    class OSINT;
}
QT_END_NAMESPACE

class OSINT : public QWidget
{
Q_OBJECT

public:
    explicit OSINT(QWidget *parent = nullptr);
    ~OSINT() override;
    void setCurrentIndex(int index) {};

private:
    Ui::OSINT *ui;
};


#endif //CRYPTOPOCKETKNIFE_OSINT_H
