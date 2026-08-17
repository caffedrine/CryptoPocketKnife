#include <QGlobals/QAppInfo.h>
#include <QGlobals/QAppUtils.h>
#include <QLogger/QLogger.h>
#include <OpenSslLoader/OpenSslLoader.h>
#include <QApplication>
#include <QLibrary>
#include <memory>

#include "src/gendata/Config.h"
#include "ui/MainConsole.h"
#include "ui/MainWindow.h"

int main(int argc, char *argv[])
{
    // Early logger init that catches errors before logger is initialized
    Base::Logger::PreInit();

    // Initialize pre-application creation
    Base::PreAppCreationCallout();

#if QT_VERSION >= QT_VERSION_CHECK(5, 14, 0)
    if(!Base::IsConsoleApp(argc, argv))
    {
        QGuiApplication::setHighDpiScaleFactorRoundingPolicy(Qt::HighDpiScaleFactorRoundingPolicy::PassThrough);
    }
#endif

    // Create application. Ownership is scoped: ~QCoreApplication MUST run before main() returns,
    // otherwise the main thread's QThreadData is only released during static destruction, after
    std::unique_ptr<QCoreApplication> app( Base::IsConsoleApp(argc, argv)
                                           ? new QCoreApplication(argc, argv)
                                           : static_cast<QCoreApplication *>(new QApplication(argc, argv)) );

    // Load global project info to be used across all components
    QAppInfo::SetProjectInfo(PROJECT_NAME, PROJECT_DESC);
    QAppInfo::SetProjectVersion(PROJECT_VER_MAJOR, PROJECT_VER_MINOR, PROJECT_VER_PATCH );
    QAppInfo::SetCompanyInfo(PROJECT_APP_COMPANY, PROJECT_APP_WEBSITE);
    QAppInfo::SetAppInfo(PROJECT_APP_ID, PROJECT_APP_BACKEND_API_URL);

    // Initialize post-application creation settings - after project info was set
    Base::PostAppCreationCallout();

    // Initialize logger
    Base::Logger::Init();

    // Store return code here
    int returnCode;

    // Is GUI app?
    if (qobject_cast<QApplication *>(app.get()))
    {
        qDebug().nospace().noquote() << "Start application in GUI mode (use flag --nogui to launch in console mode)";
        (void)OpenSslLoader::LoadSsl(false);

        MainWindow w;
        w.show();
        returnCode = app->exec();
    }   // MainWindow destroyed here, while the application object is still alive
    else
    {
        (void)OpenSslLoader::LoadSsl(true);
        MainConsole c;
        returnCode = app->exec();
    }

    // Application cleanup
    app.reset();

    // Logger cleanup and flush
    Base::Logger::Shutdown();

    // Return application error code (if any)
    return returnCode;
}