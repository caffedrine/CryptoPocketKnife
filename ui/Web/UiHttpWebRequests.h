#ifndef CRYPTOPOCKETKNIFE_UIHTTPWEBREQUESTS_H
#define CRYPTOPOCKETKNIFE_UIHTTPWEBREQUESTS_H

#include <QWidget>
#include "HttpWebRequest.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
    class UiHttpWebRequests;
}
QT_END_NAMESPACE

class UiHttpWebRequests : public QWidget
{
Q_OBJECT

public:
    explicit UiHttpWebRequests(QWidget *parent = nullptr);
    ~UiHttpWebRequests() override;

protected slots:
    void on_pushButton_Composer_Submit_clicked();

private:
    Ui::UiHttpWebRequests *ui;
    QList<QPair<QString, QStringList>> ResponsesHistory;
};


#endif //CRYPTOPOCKETKNIFE_UIHTTPWEBREQUESTS_H
