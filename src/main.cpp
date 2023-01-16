#include "ui/mainwindow.h"
#include <QApplication>
#include <base/utils/Logger.h>

#ifdef _WIN32
    #include <Windows.h>
#endif

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

//    // Show debug info when app is executed from console
//    #ifdef _WIN32
//        /// https://stackoverflow.com/questions/3360548/console-output-in-a-qt-gui-app
//        if (AttachConsole(ATTACH_PARENT_PROCESS))
//        {
//            freopen("CONOUT$", "w", stdout);
//            freopen("CONOUT$", "w", stderr);
//        }
//    #endif

    base::setup_logger(false);
    base::logger->info("App started...");
    w.show();
    return a.exec();
}
