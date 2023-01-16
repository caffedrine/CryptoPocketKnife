#ifndef CRYPTOPOCKETKNIFE_UIWEB_H
#define CRYPTOPOCKETKNIFE_UIWEB_H

#include <QWidget>
#include <QAction>
#include <QMenu>
#include <QMessageBox>
#include <QPlainTextEdit>
#include <QtConcurrent>
#include <QFuture>

#include "UiHttpWebRequests.h"
#include "base/services/TldCountry/TldCountry.h"
#include "base/services/GeoIP/GeoIP.h"
#include "base/services/Web/WebScraper.h"
#include "base/utils/utils.h"
#include "base/utils/WebUtils.h"
#include "base/utils/LambdaEventFilter.h"
#include "base/extensions/AdvancedTableWidget.h"

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

    UiHttpWebRequests *webRequestsMainwindow;

};


#endif //CRYPTOPOCKETKNIFE_UIWEB_H
