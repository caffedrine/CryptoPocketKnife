#ifndef CRYPTOPOCKETKNIFE_UIMATHEXPEVAL_H
#define CRYPTOPOCKETKNIFE_UIMATHEXPEVAL_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui {
class UiMathExpEval;
}
QT_END_NAMESPACE

class UiMathExpEval : public QWidget
{
Q_OBJECT

public:
    explicit UiMathExpEval(QWidget *parent = nullptr);
    ~UiMathExpEval() override;
protected slots:
    void on_pushButton_NewWindow_clicked();

private:
    Ui::UiMathExpEval *ui;
};


#endif //CRYPTOPOCKETKNIFE_UIMATHEXPEVAL_H
