#include "Compiler.h"
#include "ui/mainwindow.h"
#include <QApplication>

#ifdef _WIN32
    #include <Windows.h>
#endif
#include "Logger.h"

#include <QListView>
#include <QListViewModel.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    // Show debug info when app is executed from console
//    #ifdef _WIN32
//        /// https://stackoverflow.com/questions/3360548/console-output-in-a-qt-gui-app
//        if (AttachConsole(ATTACH_PARENT_PROCESS))
//        {
//            freopen("CONOUT$", "w", stdout);
//            freopen("CONOUT$", "w", stderr);
//        }
//    #endif

    setup_logger();
    logger->info("App started...");
    w.show();
    return a.exec();

//    QListView view;
//    view.setEditTriggers(QAbstractItemView::AllEditTriggers);
//
//    QModelIndex index = view.currentIndex();
//    view.edit(index);
//
//    QStringList lines; lines << "aaa" << "bbb";
//    QListViewModel model(lines);
//    view.setModel(&model);
//
//    view.show();
//
//    QEventLoop waitLoop;
//    QObject::connect( &view, &QListView::destroyed, [&waitLoop](){
//        waitLoop.exec();
//    });
//    return waitLoop.exec();
}
