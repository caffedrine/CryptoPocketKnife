#ifndef CRYPTOPOCKETKNIFE_UIHTMLRENDERER_H
#define CRYPTOPOCKETKNIFE_UIHTMLRENDERER_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui
{
    class UiHtmlRenderer;
}
QT_END_NAMESPACE

class UiHtmlRenderer : public QWidget
{
Q_OBJECT

public:
    explicit UiHtmlRenderer(QWidget *parent = nullptr);
    ~UiHtmlRenderer() override;

private:
    Ui::UiHtmlRenderer *ui;
};


#endif //CRYPTOPOCKETKNIFE_UIHTMLRENDERER_H
