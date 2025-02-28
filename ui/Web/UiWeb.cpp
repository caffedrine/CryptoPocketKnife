#include <QWidgets/QAdvancedTableWidget/QAdvancedTableWidget.h>
#include <QGeoIP/GeoIP.h>
#include <QGeoIP/TldCountry.h>
#include <QUtils/QUtils.h>
#include <QWidgets/QWidgetsUtils.h>
#include <QUtils/QWebUtils.h>

#include "UiWeb.h"
#include "ui_UiWeb.h"
#include "utils/LambdaEventFilter.h"
#include "web/WebScraper.h"

UiWeb::UiWeb(QWidget *parent): QWidget(parent), ui(new Ui::UiWeb)
{
    ui->setupUi(this);
}

UiWeb::~UiWeb()
{
    delete ui;
}

