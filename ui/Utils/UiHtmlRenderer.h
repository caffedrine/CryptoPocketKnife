#ifndef CRYPTOPOCKETKNIFE_UIHTMLRENDERER_H
#define CRYPTOPOCKETKNIFE_UIHTMLRENDERER_H

#include <QWidget>
#include "base/data_structures/DomModel.h"

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
    explicit UiHtmlRenderer(QWidget *parent = nullptr, QString html_content = "");
    ~UiHtmlRenderer() override;

protected slots:
    void on_plainTextEdit_textChanged();

private:
    Ui::UiHtmlRenderer *ui;
    DomModel *model = nullptr;
};


#endif //CRYPTOPOCKETKNIFE_UIHTMLRENDERER_H
