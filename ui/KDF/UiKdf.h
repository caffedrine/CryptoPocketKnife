#ifndef CRYPTOPOCKETKNIFE_UIKDF_H
#define CRYPTOPOCKETKNIFE_UIKDF_H

#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui {
class UiKdf;
}
QT_END_NAMESPACE

class UiKdf : public QMainWindow
{
Q_OBJECT

public:
    explicit UiKdf(QWidget *parent = nullptr);
    ~UiKdf() override;

private:
    Ui::UiKdf *ui;
};


#endif //CRYPTOPOCKETKNIFE_UIKDF_H
