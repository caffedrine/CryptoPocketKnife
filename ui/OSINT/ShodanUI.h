#ifndef CRYPTOPOCKETKNIFE_SHODANUI_H
#define CRYPTOPOCKETKNIFE_SHODANUI_H

#include <QWidget>
#include "UserSettings.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
    class ShodanUI;
}
QT_END_NAMESPACE

class ShodanUI : public QWidget
{
Q_OBJECT

public:
    explicit ShodanUI(QWidget *parent = nullptr);
    ~ShodanUI() override;

protected slots:
    void pushButton_shodanSettings_SaveKey_clicked();
    void pushButton_shodanSettings_TestApiKey_clicked();
    void pushButton_shodanSettings_GetSearchFilters_clicked();
    void pushButton_ManualQuery_GetResults_clicked();
    void pushButton_ManualQuery_Count_clicked();

private:
    Ui::ShodanUI *ui;
};


#endif //CRYPTOPOCKETKNIFE_SHODANUI_H
