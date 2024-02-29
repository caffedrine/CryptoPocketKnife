#ifndef _BASE_QWIDGETS_MATHEXPEVALWIDGET_H_
#define _BASE_QWIDGETS_MATHEXPEVALWIDGET_H_

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class MathExpEvalWidget;
}
QT_END_NAMESPACE

class MathExpEvalWidget : public QWidget
{
Q_OBJECT

public:
    explicit MathExpEvalWidget(QWidget *parent = nullptr);
    ~MathExpEvalWidget() override;

private:
    Ui::MathExpEvalWidget *ui;
};


#endif //_BASE_QWIDGETS_MATHEXPEVALWIDGET_H_
