#include "MainConsole.h"
#include <QEventLoop>
#include <QThread>

#include <QUtils/QUtils.h>
#include <fmt/core.h>

#include "src/gendata/Config.h"

MainConsole::MainConsole()
{
    this->init();
}

MainConsole::~MainConsole()
{
    qInfo().nospace().noquote() << "Execution terminated";
}

void MainConsole::exit(int retcode)
{
    QCoreApplication::exit(retcode);
    QCoreApplication::processEvents();
    std::exit(retcode);
}

void MainConsole::init()
{
    QCommandLineParser parser;
    parser.setApplicationDescription(PROJECT_DESC);
    parser.addVersionOption();

    // Option help
    QCommandLineOption helpOption({"?", "h", "help"}, QCoreApplication::translate("main", "Displays help on commandline options.  "));
    parser.addOption(helpOption);

    // Option nogui
    QCommandLineOption noguiOption({"c", "console", "nogui"}, QCoreApplication::translate("main", "Load application in console mode"));
    parser.addOption(noguiOption);

    QCommandLineOption expOption({"e", "exp"}, QCoreApplication::translate("main", "Math expression to be evaluated"));
    parser.addOption(noguiOption);

    // Show sample output
    QCommandLineOption optionSample("sample", QCoreApplication::translate("main", "Show sample output"));
    parser.addOption(optionSample);

    // Process the actual command line arguments given by the user
    parser.process(*QCoreApplication::instance());

    // Show help menu if requested and then exit
    if( parser.isSet(helpOption) )
    {
        parser.showHelp();
        this->exit(0);
        return;
    }

    if( parser.isSet(expOption) )
    {
        // Evaluate the math from string
//        QMathEvaluatorResult result = QMathEvaluator::EvaluateInput(parser.value(expOption));
//
//        // and provide the result to the output
//        fmt::print("{}", result.GetHumanReadable().toStdString());
        std::fflush(stdout);
        this->exit(0);
        return;
    }

    qCritical().noquote().nospace() << "No options provided, check help menu";
    parser.showHelp();
}