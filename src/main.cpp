#include <QApplication>
#include <csignal>
#include <DummyTriggerRebuild.h>
#include <QGlobals/QAppInfo.h>
#include <QLogger/QLogger.h>
#include <OpenSslLoader/OpenSslLoader.h>

#ifdef _WIN32
    #include <Windows.h>
#endif

#include "src/gendata/Config.h"
#include "ui/MainConsole.h"
#include "ui/MainWindow.h"

QCoreApplication* createApplication(int &argc, char *argv[])
{
    for (int i = 1; i < argc; ++i) {
        if (!qstrcmp(argv[i], "-c") || !qstrcmp(argv[i], "--nogui") || !qstrcmp(argv[i], "--console") ||
                !qstrcmp(argv[i], "-?") || !qstrcmp(argv[i], "-h") || !qstrcmp(argv[i], "--help") || !qstrcmp(argv[i], "--version") )
            return new QCoreApplication(argc, argv);
    }
    return new QApplication(argc, argv);
}

// Example appl: https://platform.pkisolutions.com/shop/asn1-editor/

int main(int argc, char *argv[])
{
    QScopedPointer<QCoreApplication> app(createApplication(argc, argv));

    // Enable loading of libraries from the same folder as the executable
    QCoreApplication::addLibraryPath(QCoreApplication::applicationDirPath());

    QAppInfo::SetProjectInfo(PROJECT_NAME, PROJECT_DESC, PROJECT_VER);
    QAppInfo::SetCompanyInfo(PROJECT_APP_COMPANY, PROJECT_APP_WEBSITE);
    QAppInfo::SetAppInfo(PROJECT_APP_ID, PROJECT_APP_BACKEND_API_URL);

    // Set application info based on the config file
    QCoreApplication::setApplicationName(QAppInfo::ProjectName()->GetVal().toString());
    QCoreApplication::setApplicationVersion(QAppInfo::ProjectVer()->GetVal().toString());
    QCoreApplication::setOrganizationName(QAppInfo::CompanyName()->GetVal().toString());
    QCoreApplication::setOrganizationDomain(QAppInfo::CompanyWebsite()->GetVal().toString());

    // Show debug info when app is executed from console
    #ifdef _WIN32
        // https://stackoverflow.com/questions/3360548/console-output-in-a-qt-gui-app
        if (AttachConsole(ATTACH_PARENT_PROCESS))
        {
            freopen("CONOUT$", "w", stdout);
            freopen("CONOUT$", "w", stderr);
            freopen("CONIN$", "r", stdin);
        }
    #endif

    // Handle killing signals
    signal(SIGTERM, [](int sig) { qApp->exit(sig); });
    signal(SIGABRT, [](int sig) { qApp->exit(sig); });
    signal(SIGINT, [](int sig) { qApp->exit(sig); });

    // Init logger AFTER the app info was set
    Base::Logger::Init();

    if (qobject_cast<QApplication *>(app.data()))
    {
        qInfo().nospace().noquote() << "Start application in GUI mode (use flag --nogui to launch in console mode)";
        OpenSslLoader::LoadSsl(false);

        MainWindow w;
        w.show();
        return app->exec();
    }
    else
    {
        OpenSslLoader::LoadSsl(true);
        MainConsole c;
        return app->exec();
    }
}
