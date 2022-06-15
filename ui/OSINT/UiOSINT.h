#ifndef CRYPTOPOCKETKNIFE_UIOSINT_H
#define CRYPTOPOCKETKNIFE_UIOSINT_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui
{
    class UiOSINT;
}
QT_END_NAMESPACE

class UiOSINT : public QWidget
{
Q_OBJECT

public:
    explicit UiOSINT(QWidget *parent = nullptr);
    ~UiOSINT() override;
    void setCurrentIndex(int index) {};

private:
    Ui::UiOSINT *ui;
};


#endif //CRYPTOPOCKETKNIFE_UIOSINT_H
