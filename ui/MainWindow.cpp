#include <fmt/core.h>
#include <QGlobals/QAppInfo.h>
#include <QWidgets/QWidgetsUtils.h>
#include <QWidgetsThemes/ThemesManager.h>
#include <QWidgets/QTabWidgetExtended/QTabBarExtended.h>
#include <QWidgetAppElements/QBaseAppSettings.h>

#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "src/gendata/Config.h"
#include "UiTrace32.h"
#include "VectorStorageParser.h"

#include <QDesktopServices>
#include <QSizeGrip>

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // This for QVariant to perform default conversion to string to print dictionary
    QMetaType::registerConverter(&VectorStorageElement::toString);

    // Init needed modules - needed before the UI as the theme is loaded before
    this->InitUiLogger(this);
    Base::ThemesManager::Init(this);
    this->StartBgUpdateChecker(this);

    // Update default base settings to have workspace enabled by default
    Base::QBaseAppSettingsDefault defaultBaseSettings;
    defaultBaseSettings.IsWorkspaceSaveEnabled = true;
    defaultBaseSettings.IsWorkspaceRestoreEnabled = true;

    // Load the default base application settings (logs settings, settings location, etc)
    Base::QBaseAppSettings::InitBaseSettings(defaultBaseSettings);

    // Enable "ADD NEW" tab widget button
    this->ui->tabWidget->SetEnableAddNewButton(true);
    this->ui->tabWidget->RemoveAllTabs();
    this->ui->tabWidget->setTabsClosable(true);
    this->ui->tabWidget->SetPreventLastTabClosure(true);
    this->ui->tabWidget->setMovable(true);
    this->ui->tabWidget->SetEnableTabsRename(true);

    // Register a default context menu to manage the tabs
    QTabCtxMenuCustom *contextMenu = this->ui->tabWidget->GetDefaultTabsManagementContextMenu();
    this->ui->tabWidget->RegisterCustomContextMenuFunc([=](QContextMenuEvent *event, QTabWidgetExtended *widget, int tabIndex){
        // Notify custom menu about current tab
        contextMenu->tabIdx = tabIndex;

        // Execute the custom context menu
        QAction *selectedAction = contextMenu->exec(event->globalPos());
    });

    // Enable adding new tabs
    QObject::connect(this->ui->tabWidget, &QTabWidgetExtended::NewTabRequested, [=](){
        // main window central Widgets
        UiTrace32 *mainWidget = new UiTrace32(this);
        mainWidget->setWindowFlags(Qt::Widget);

        // Init settings manager
//        UiMathEvaluator::InitGlobalSettings({}, [=](QMathEvaluatorSettings mathEvalSettings)
//        {
//            // Propagate the settings changes to the instances onChange - these are only math eval settings, NOT the UI settings
//            mainWidget->UpdateSettings(mathEvalSettings);
//        });

        this->ui->tabWidget->addTab(mainWidget, "Tab " + QString::number(this->ui->tabWidget->count() + 1));
    });

    // Create an initial tab by default if no workspace was found or restoration not enabled
    if( !Base::QBaseAppSettings::IsWorkspaceRestoreEnabled() || !this->RestoreMainWindowState(this) )
    {
        this->ui->tabWidget->RequestNewTab();
        this->ui->tabWidget->setCurrentIndex(0);
    }

    // Add a debugging test button
    #ifdef QT_DEBUG
        QMenu *debugMenu = GetDefaultDebugMenuTools(this);
        this->ui->menubar->addMenu( debugMenu );
        debugMenu->addSeparator();

        // App specific action 1
        QAction *newAction = new QAction("Dummy button");
        QObject::connect(newAction, &QAction::triggered, [](){
            qDebug() << "Nothing happened...";
        });
        debugMenu->addAction(newAction);
    #endif
}

MainWindow::~MainWindow()
{
    // Preserve object state if option enabled
    if( Base::QBaseAppSettings::IsWorkspaceSaveEnabled() )
        this->SaveMainWindowState(this);

    delete ui;
}

void MainWindow::on_action_Exit_triggered()
{
    qApp->quit();
}

void MainWindow::on_action_Logs_triggered()
{
    this->TriggerLogsPopup(this);
}

void MainWindow::on_action_About_triggered()
{
    this->TriggerAboutPopup(this);
}

void MainWindow::on_action_Preferences_triggered()
{
    this->TriggerPreferencesPopup(this);
}

void MainWindow::on_action_StickToTheTop_triggered()
{
    Base::Utils::Widgets::window::SetStickToTop(this, this->ui->action_StickToTheTop->isChecked());
}

void MainWindow::on_action_NewTab_triggered()
{
    this->ui->tabWidget->RequestNewTab();
}
