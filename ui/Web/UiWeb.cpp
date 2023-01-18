#include "UiWeb.h"
#include "ui_UiWeb.h"

UiWeb::UiWeb(QWidget *parent): QWidget(parent), ui(new Ui::UiWeb)
{
    ui->setupUi(this);

    // Create dynamic tabs and append
    this->dynamicTabs = new QTabWidgetExtended(this);
    // Enable adding new tabs
    QObject::connect(this->dynamicTabs, &QTabWidgetExtended::NewTabRequested, [this](){
        UiHttpWebRequests * webRequestsMainwindow = new UiHttpWebRequests(this->dynamicTabs);
        webRequestsMainwindow->setWindowFlags(Qt::Widget);
        this->dynamicTabs->addTab(webRequestsMainwindow, "Tab " + QString::number(this->dynamicTabs->count()));
    });
    // Enable tabs removal
    QObject::connect(this->dynamicTabs, &QTabWidget::tabCloseRequested, [this](int index){
        QWidget *tabContent = this->dynamicTabs->widget(index);
        if( this->dynamicTabs->count() > 1 )
            this->dynamicTabs->removeTab(index);
        delete tabContent;
    });

    // Create an initial tab
    UiHttpWebRequests * webRequestsMainwindow = new UiHttpWebRequests(this->dynamicTabs);
    webRequestsMainwindow->setWindowFlags(Qt::Widget);
    this->dynamicTabs->addTab(webRequestsMainwindow, "Tab 0");
    this->dynamicTabs->setCurrentIndex(0);

    this->ui->gridLayout_HttpWebRequests->addWidget(this->dynamicTabs);
}

UiWeb::~UiWeb()
{
    delete ui;
}

