#ifndef CRYPTOPOCKETKNIFE_UIXMLTREE_H
#define CRYPTOPOCKETKNIFE_UIXMLTREE_H

#include <QWidget>
#include "DomModel.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
    class UiXmlTree;
}
QT_END_NAMESPACE

class UiXmlTree : public QWidget
{
Q_OBJECT

public:
    explicit UiXmlTree(QWidget *parent = nullptr, QString dom_data = "");
    ~UiXmlTree() override;

protected slots:
    void on_plainTextEdit_textChanged();

private:
    Ui::UiXmlTree *ui;
    DomModel *model = nullptr;
};


#endif //CRYPTOPOCKETKNIFE_UIXMLTREE_H
