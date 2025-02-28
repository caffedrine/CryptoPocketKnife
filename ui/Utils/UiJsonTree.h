#ifndef CRYPTOPOCKETKNIFE_UIJSONTREE_H
#define CRYPTOPOCKETKNIFE_UIJSONTREE_H

#include <QWidget>
#include <QJsonModel/QJsonModel.h>

QT_BEGIN_NAMESPACE
namespace Ui
{
    class UiJsonTree;
}
QT_END_NAMESPACE

class UiJsonTree : public QWidget
{
Q_OBJECT

public:
    explicit UiJsonTree(QWidget *parent = nullptr, QString RawJson = "");
    ~UiJsonTree() override;

protected slots:
    void on_plainTextEdit_textChanged();

private:
    Ui::UiJsonTree *ui;
    QJsonModel *model = nullptr;
};


#endif //CRYPTOPOCKETKNIFE_UIJSONTREE_H
