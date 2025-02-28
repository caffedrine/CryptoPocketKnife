#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QStatusBar>

#include "ui/Mac/UiMac.h"
#include "ui/AE/AuthenticatedEncryption.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWidget; }
QT_END_NAMESPACE

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainWidget(QStatusBar *statusBar, QWidget *parent = nullptr);
    ~MainWidget() override;

private slots:
    // Utils
    void on_pushButton_Utils_CurrentTimestamp_clicked();
    void on_pushButton_Utils_CurrentDateTime_clicked();
    void on_pushButton_TimestampToDatetime_clicked();
    void on_pushButton_dateTimeToTimestamp_clicked();

    private:
    Ui::MainWidget *ui;
    QMap<QString, QString> WebScraperResponseHeaders;
    QMap<QString, QString> WebScraperResponseData;

    void Status_EndWithError(QString err_msg);
    void Status_EndWithSuccess(QString err_msg);
    void Status_Clear();

private:
    QStatusBar *statusBar = nullptr;

};
#endif // MAINWIDGET_H