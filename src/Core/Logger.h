#ifndef _LOGGER_H_
#define _LOGGER_H_

#include <spdlog/spdlog.h>
#include "spdlog/cfg/env.h"  // support for loading levels from the environment variable
#include "spdlog/fmt/ostr.h" // support for user defined types

#include <spdlog/sinks/base_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/rotating_file_sink.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/fmt/bin_to_hex.h>


/* Logger instance - multi-threaded */
extern spdlog::logger *logger;

void setup_logger();

#endif // _LOGGER_H_