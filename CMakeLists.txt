cmake_minimum_required(VERSION 3.16)

set(PROJECT_NAME CryptoPocketKnife)
project(${PROJECT_NAME} DESCRIPTION "Crypto Pocket Knife" VERSION 1.0.0 LANGUAGES CXX C)
set(PROJECT_APP_COMPANY "SparkyByte")
set(PROJECT_APP_WEBSITE "www.sparkybyte.com")
set(PROJECT_APP_ID "cryptopocketknife")
set(PROJECT_APP_BACKEND_API_URL "https://sparkybyte.com/api/v1")

# Put all the artifacts on a single place so they can be easily copied when application is deployed
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/output_lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/output_bin")
SET(CMAKE_EXTRA_OUTPUT_DIRECTORY   "${CMAKE_BINARY_DIR}/output_extra" CACHE INTERNAL "CMAKE_EXTRA_OUTPUT_DIRECTORY")
set(CMAKE_OUTPUT_TESTS_REPORTS     "${CMAKE_BINARY_DIR}/output_tests_reports")
set(CMAKE_OUTPUT_TESTS_BIN         "${CMAKE_BINARY_DIR}/output_tests_bin")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Assume error console to print out data always
set(QT_ASSUME_STDERR_HAS_CONSOLE 1)
# To be able to build also statically linked libs inside the packages
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# Base libs directory
SET(BASE_LIBS_DIR ${PROJECT_SOURCE_DIR}/libs/QBaseLibs)
# Libraries to be included from base library
SET(BASE_LIB_DEPENDENCIES
        OpenSslLoader
        QDataStructures
        fmt
        QLogger
        QUtils
        Utils
        QHttp
        QSecurityUtils
        QGlobals
        QWidgets
        QWidgetAppElements
        QWidgetHelp
        QWidgetsThemes
        QBackendServer
        QAppPreferences
        QWorkspace
        QCrypto
        QX509
        QWidgetModels
        QGeoIP
        BigNum
        QMathEvaluator
        QWidgetMathEvaluator
)

# Add base dependencies
foreach(subdirectory ${BASE_LIB_DEPENDENCIES})
    add_subdirectory(${BASE_LIBS_DIR}/${subdirectory})
    # find_package(${subdirectory} PATHS ${BASE_LIBS_DIR}/install)
endforeach()

# Add thirdparty CMake modules
add_subdirectory(thirdparty/CryptoPrimitives)
# Default build release
if(NOT CMAKE_BUILD_TYPE)
    message(STATUS "Building ${PROJECT_NAME} by default in Release mode unless a different mode is specified")
    set(CMAKE_BUILD_TYPE Release)
endif()

# Enable Qt MOC
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# Find required Qt5 or Qt6 dependencies
find_package(QT NAMES Qt6 Qt5)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets Network Core Gui Xml Concurrent REQUIRED)

# Include thirdparty libs
include(thirdparty/thirdparty_dependencies.cmake)

# Create config file based on CMake definitions
string(TIMESTAMP PROJECT_BUILD_TIME "%Y-%m-%d %H:%M:%S UTC" UTC)
configure_file("res/img/icon.ico" "${CMAKE_EXTRA_OUTPUT_DIRECTORY}/icon.ico" COPYONLY)

# Copy the app config and build time to the generated data
file(MAKE_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/src/gendata")
configure_file("${BASE_LIBS_DIR}/cmake/Config.h.in" "${CMAKE_CURRENT_SOURCE_DIR}/src/gendata/Config.h")

# Add the include directories
include_directories(${PROJECT_SOURCE_DIR}/src/gendata)
include_directories(${PROJECT_SOURCE_DIR}/src)
# include all ui dirs recursively
file(GLOB_RECURSE TMP_UI_HEADERS "ui/*.h")
foreach (_headerFile ${TMP_UI_HEADERS})
    get_filename_component(_dir ${_headerFile} PATH)
    list (APPEND UI_HEADERS ${_dir})
endforeach()
list(REMOVE_DUPLICATES UI_HEADERS)
include_directories(${UI_HEADERS})

# All source code files (including generated resources)
file(GLOB_RECURSE ALL_SOURCES "src/*.c" "src/*.cpp" "ui/*.cpp" "ui/*.ui" "res/main.qrc" ${THIRD_PARTY_SRC} )

# Include the executable setup module
include(${BASE_LIBS_DIR}/cmake/executable_config.cmake)
# Setup platform-specific executable configuration
setup_executable_config(GLOBAL_EXE_FLAGS GLOBAL_EXE_RESOURCES)

# Add executable with the needed lags
add_executable(${PROJECT_NAME} ${GLOBAL_EXE_FLAGS} ${ALL_SOURCES} ${GLOBAL_EXE_RESOURCES})

target_link_libraries(${PROJECT_NAME} PUBLIC
        Qt${QT_VERSION_MAJOR}::Core
        Qt${QT_VERSION_MAJOR}::Gui
        Qt${QT_VERSION_MAJOR}::Network
        Qt${QT_VERSION_MAJOR}::Widgets
        Qt${QT_VERSION_MAJOR}::Xml
        Qt${QT_VERSION_MAJOR}::Concurrent
        Base::CryptoPrimitives
        ${THIRD_PARTY_LIBS})

# Link base dependencies
foreach(subdirectory ${BASE_LIB_DEPENDENCIES})
    target_link_libraries(${PROJECT_NAME} PUBLIC Base::${subdirectory})
endforeach()

# Move OpenSSL library to the same folder as the binary
include(${BASE_LIBS_DIR}/OpenSslLoader/deploy_openssl.cmake)

# Copy logo to the output for LINUX OS, so that it can be used as an icon
if(UNIX AND NOT APPLE)
    configure_file("res/img/logo.png" "${CMAKE_EXTRA_OUTPUT_DIRECTORY}/${PROJECT_NAME}.png" COPYONLY)
endif()

# Tests
#include(CTest)
#if(BUILD_TESTING)
#    add_subdirectory(tests)
#endif()

# Include relevant deployment modules
include(${BASE_LIBS_DIR}/DeploySupport/deploy_app.cmake)
include(${BASE_LIBS_DIR}/DeploySupport/create_deliverables.cmake)

# Remove old docs and copy documentation files to the output (overwrite if exists)
#file(REMOVE_RECURSE ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/docs)
#file(COPY ${CMAKE_SOURCE_DIR}/docs/source/ DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/docs)
