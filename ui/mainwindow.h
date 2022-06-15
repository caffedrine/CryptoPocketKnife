#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDebug>
#include <QMainWindow>
#include <QDateTime>
#include <QMessageBox>
#include <QDesktopServices>

#include "Logger.h"
#include "utils.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private slots:
    // Appl
    void on_actionSupport_triggered();
    void on_actionAbout_triggered();
    void on_actionExit_triggered();
    void on_actionLogs_triggered();

    // Utils
    void on_pushButton_Utils_CurrentTimestamp_clicked();
    void on_pushButton_Utils_CurrentDateTime_clicked();
    void on_pushButton_TimestampToDatetime_clicked();
    void on_pushButton_dateTimeToTimestamp_clicked();

    private:
    Ui::MainWindow *ui;
    QMap<QString, QString> WebScraperResponseHeaders;
    QMap<QString, QString> WebScraperResponseData;

    void Status_EndWithError(QString err_msg);
    void Status_EndWithSuccess(QString err_msg);
    void Status_Clear();

};
#endif // MAINWINDOW_H
