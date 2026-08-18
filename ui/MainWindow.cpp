#include <fmt/core.h>
#include <QGlobals/QAppInfo.h>
#include <QWidgets/QWidgetsUtils.h>
#include <QWidgetsThemes/ThemesManager.h>
#include <QWidgets/QTabWidgetExtended/QTabBarExtended.h>
#include <QWidgetAppElements/QBaseAppSettings.h>

#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "MainWidget.h"
#include "src/gendata/Config.h"
#include "UserSettings.h"

#include <QDesktopServices>
#include <QSizeGrip>
#include <QStyle>

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), QAppMainWindowExtension(this), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Initialize user settings
    UserSettings::Init();

    // Init needed modules - needed before the UI as the theme is loaded before
    this->InitUiLogger();
    Base::ThemesManager::Init(this);
    this->StartBgUpdateChecker();

    // Update default base settings to have workspace enabled by default
    Base::QBaseAppSettingsDefault defaultBaseSettings;
    defaultBaseSettings.EnableWorkspaces = false;
    defaultBaseSettings.IsWorkspaceSaveEnabled = false;
    defaultBaseSettings.IsWorkspaceRestoreEnabled = false;

    // Load the default base application settings (logs settings, settings location, etc)
    Base::QBaseAppSettings::InitBaseSettings(defaultBaseSettings);

    // Init tab wiget
    this->InitTabWidget();

    // Init workspace
    this->InitWorkspace();

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
//    if( Base::QBaseAppSettings::IsWorkspaceSaveEnabled() )
//        this->SaveMainWindowState(this);

    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    if (!this->WorkspaceSaved && !this->ExitWithoutWsSave)
    {
        this->SaveMainWindow();
        this->WorkspaceSaved = true;
    }
    QMainWindow::closeEvent(event);
}


void MainWindow::SaveMainWindow()
{
//    QJsonObject mainWindowSetts;
//    mainWindowSetts.insert("pythonScriptPath",  Base::Utils::Path::Normalize(this->ui->lineEdit_pythonScript->text()));
//    mainWindowSetts.insert("curr_root_section", currentConfigName);
    this->SaveMainWindowState(this/*, mainWindowSetts*/);
}

bool MainWindow::RestoreMainWindow()
{
    QJsonObject mainWindowSetts;
    if ( !this->RestoreMainWindowState(this, &mainWindowSetts) )
    {
        return false;
    }

    return true;
}

void MainWindow::InitTabWidget()
{
    // Init tab widget options
    this->ui->tabWidget->RemoveAllTabs();
    this->ui->tabWidget->SetEnableAddNewButton(true);
    this->ui->tabWidget->setTabsClosable(true);
    this->ui->tabWidget->SetPreventLastTabClosure(true);
    this->ui->tabWidget->setMovable(true);
    this->ui->tabWidget->SetEnableTabsRename(true);
    this->ui->tabWidget->SetEnableDetachableTabs(true);
    // Tabs only have bottom margins. add one on top since this is first widget from top
    this->ui->gridLayout->layout()->setContentsMargins(0, 1, 0, 0);

    // Get default context menu options for closing the tabs (right, left, this, etc)
    QTabCtxMenuCustom *contextMenu = this->ui->tabWidget->GetDefaultTabsManagementContextMenu();
    this->ui->tabWidget->RegisterCustomContextMenuFunc([=](QContextMenuEvent *event, QTabWidgetExtended *widget, int tabIndex){
        // Notify custom menu about current tab
        contextMenu->tabIdx = tabIndex;
        // Execute the custom context menu
        QAction *selectedAction = contextMenu->exec(event->globalPos());
    });

    // The one place that knows how to construct a page of a given type
    this->ui->tabWidget->RegisterTabFactory([=](const QString &tabType) -> QPair<QWidget*, QVariant>
    {
        // main window central Widgets
        MainWidget *mathWidget = new MainWidget(this->ui->statusBar, this->ui->tabWidget->tabBar());
        mathWidget->setWindowFlags(Qt::Widget);

        return {mathWidget, QVariant()};
    });
}

void MainWindow::InitWorkspace()
{
    // Create an initial tab by default if no workspace was found or restoration not enabled
    if( !Base::QBaseAppSettings::WorkspacesEnabled->GetVal().toBool() || !Base::QBaseAppSettings::IsWorkspaceRestoreEnabled->GetVal().toBool() || !this->RestoreMainWindow() )
    {
        this->ui->tabWidget->CreateNewTab();    // Create one default tab in case there is nothing to restore
        this->ui->tabWidget->setCurrentIndex(0);
    }

    // Add workspaces toolbar item and handling for workspace changes
    this->InitWorkspacesMenu(this->ui->menubar, 2, [this](QString newWs)-> bool
    // Workspace about to change callback
    {
        bool confirmSave;
        if ( !Base::Utils::Widgets::ShowConfirmationDialog("Save current workspace?", "Do you want to save the current workspace before switching?", QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel, QMessageBox::Yes, &confirmSave) )
        {
            // action aborted/window closed
            return false;
        }

        // Accepted workspace change. Check if current ws shall be saved
        if (confirmSave)
        {
            this->SaveMainWindow(); // Save current workspace before switching
        }
        return true;
    },
    // Workspace changed callback
    [this](QString newWs)
    {
        // Restore main window
        this->RestoreMainWindow();

    });
}

void MainWindow::on_action_Exit_triggered()
{
    this->close();
}

void MainWindow::on_action_Logs_triggered()
{
    this->TriggerLogsPopup();
}

void MainWindow::on_action_About_triggered()
{
    this->TriggerAboutPopup();
}

void MainWindow::on_action_CheckForUpdates_triggered()
{
    this->TriggerUpdaterPopup();
}

void MainWindow::on_action_BugReport_triggered()
{
    this->TriggerBugReport();
}

void MainWindow::on_action_FeatureRequest_triggered()
{
    this->TriggerFeatureRequest();
}

void MainWindow::on_action_Preferences_triggered()
{
    this->TriggerPreferencesPopup();
}

void MainWindow::on_action_StickToTheTop_triggered()
{
    Base::Utils::Widgets::window::SetStickToTop(this, this->ui->action_StickToTheTop->isChecked());
}

void MainWindow::on_action_NewTab_triggered()
{
    this->ui->tabWidget->CreateNewTab();
}
