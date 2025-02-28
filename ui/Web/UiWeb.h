#ifndef CRYPTOPOCKETKNIFE_UIWEB_H
#define CRYPTOPOCKETKNIFE_UIWEB_H

#include <QWidget>
#include <QAction>
#include <QMenu>
#include <QMessageBox>
#include <QPlainTextEdit>
#include <QtConcurrent>
#include <QFuture>
#include <QWidgets/QTabWidgetExtended/QTabWidgetExtended.h>

QT_BEGIN_NAMESPACE
namespace Ui
{
    class UiWeb;
}
QT_END_NAMESPACE

class UiWeb: public QWidget
{
Q_OBJECT

public:
    explicit UiWeb(QWidget *parent = nullptr);
    ~UiWeb() override;
    void setCurrentIndex(int index) {};

private slots:


private:
    Ui::UiWeb *ui;

    QTabWidgetExtended *dynamicTabs;
};


#endif //CRYPTOPOCKETKNIFE_UIWEB_H
