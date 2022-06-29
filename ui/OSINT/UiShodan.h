#ifndef CRYPTOPOCKETKNIFE_UISHODAN_H
#define CRYPTOPOCKETKNIFE_UISHODAN_H

#include <QWidget>
#include "UserSettings.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
    class UiShodan;
}
QT_END_NAMESPACE

class UiShodan : public QWidget
{
Q_OBJECT

public:
    explicit UiShodan(QWidget *parent = nullptr);
    ~UiShodan() override;

protected slots:
    void pushButton_shodanSettings_SaveKey_clicked();
    void pushButton_shodanSettings_TestApiKey_clicked();
    void pushButton_shodanSettings_GetSearchFilters_clicked();
    void pushButton_ManualQuery_GetResults_clicked();
    void pushButton_ManualQuery_Count_clicked();
    void on_pushButton_ManualQuery_CopyOutputData_clicked();

private:
    Ui::UiShodan *ui;
};


#endif //CRYPTOPOCKETKNIFE_UISHODAN_H
