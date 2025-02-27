#ifndef NETWORKTRAFFICRECORDER_MAINCONSOLE_H
#define NETWORKTRAFFICRECORDER_MAINCONSOLE_H

#include <QObject>
#include <QDebug>
#include <QCoreApplication>
#include <QCommandLineParser>


class MainConsole: public QObject
{
    Q_OBJECT
public:
    MainConsole();
    ~MainConsole();

private:
    void init();
    void exit(int retcode);
};


#endif //NETWORKTRAFFICRECORDER_MAINCONSOLE_H
