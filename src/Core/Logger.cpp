#include "Logger.h"
#include <iostream>
#include <QCoreApplication>

spdlog::logger *logger;

void outputMessage(QtMsgType type,const QMessageLogContext &context,const QString &msg)
{
#ifdef QT_DEBUG
    QString ctx_str = "[" + QString(context.file) + ":" + QString::number(context.line) + "] ";
#else
    QString ctx_str = "";
#endif
    switch (type)
    {
        case QtDebugMsg:
            logger->debug( QString(ctx_str + msg).toStdString());
            break;
        case QtWarningMsg:
            logger->warn( QString(ctx_str + msg).toStdString());
            break;
        case QtCriticalMsg:
            logger->critical( QString(ctx_str + msg).toStdString());
            break;
        case QtFatalMsg:
            logger->error( QString(ctx_str + msg).toStdString());
            break;
        default:
            logger->info( QString(ctx_str + msg).toStdString());
    }
}

void setup_logger()
{
    try
    {
        std::string pattern = "[%Y-%m-%d %H:%M:%S.%e] [thread %t] [%^%l%$] %v";

        spdlog::set_pattern(pattern);
        auto stdout_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
        auto rotating_sink = std::make_shared<spdlog::sinks::rotating_file_sink_mt>(QCoreApplication::applicationDirPath().toStdString() + "/logs.log", 1024 * 1024 * 20, 10);

        logger = new spdlog::logger("main", {stdout_sink, rotating_sink});
        logger->set_level(spdlog::level::trace);
        logger->set_pattern(pattern);
    }
    catch( const spdlog::spdlog_ex &ex )
    {
        std::cout << "Logger initialization failed: " << ex.what() << std::endl;
    }

    // Bind Qt logging functions to spdlog
    qInstallMessageHandler(outputMessage);
}