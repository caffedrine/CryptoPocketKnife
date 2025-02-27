#ifndef _ASN1EDITOR_MAINWINDOW_H_
#define _ASN1EDITOR_MAINWINDOW_H_

#define DEBUG_MENU_TOOLS    1

#include <QMainWindow>
#include <QPlainTextEdit>
#include <QTimer>
#include <QWidgetAppElements/QAppMainWindowExtension.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow, protected QAppMainWindowExtension
{
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private:
    Ui::MainWindow *ui;

private slots:
    void on_action_NewTab_triggered();
    void on_action_Exit_triggered();
    void on_action_Logs_triggered();
    void on_action_About_triggered();
    void on_action_Preferences_triggered();
    void on_action_StickToTheTop_triggered();
};

#endif // _ASN1EDITOR_MAINWINDOW_H_
