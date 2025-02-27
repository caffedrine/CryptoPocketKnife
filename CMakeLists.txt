cmake_minimum_required(VERSION 3.16)

set(PROJECT_NAME VectorPocketKnife)
project(VectorPocketKnife DESCRIPTION "Vector Pocket Knife" VERSION 1.0.0 LANGUAGES CXX C)
set(PROJECT_APP_COMPANY "ByteSight")
set(PROJECT_APP_WEBSITE "www.bytesight.net")
set(PROJECT_APP_ID "vectorpocketknife")
set(PROJECT_APP_BACKEND_API_URL "https://bytesight.net/api/v1")

# Put all the artifacts on a single place so they can be easily copied when application is deployed
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/output_lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/output_bin")
SET(CMAKE_EXTRA_OUTPUT_DIRECTORY   "${CMAKE_BINARY_DIR}/output_extra" CACHE INTERNAL "CMAKE_EXTRA_OUTPUT_DIRECTORY")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Libraries to be included from base library
SET(BASE_LIB_DEPENDENCIES
        BigNum
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
        QWidgetsThemes
        QBackendServer
        QAppPreferences
        QWorkspace
)

# Add base dependencies
foreach(subdirectory ${BASE_LIB_DEPENDENCIES})
    add_subdirectory(libs/QBaseLibs/${subdirectory})
    # find_package(${subdirectory} PATHS libs/QBaseLibs/install)
endforeach()

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# Assume error console to print out data always
set(QT_ASSUME_STDERR_HAS_CONSOLE 1)

# Default build release
if(NOT CMAKE_BUILD_TYPE)
    message(STATUS "Building ${PROJECT_NAME} by default in Release mode unless a different mode is specified")
    set(CMAKE_BUILD_TYPE Release)
endif()

# Find required Qt5 or Qt6 dependencies
find_package(QT NAMES Qt6 Qt5)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets Network Core Gui Xml Concurrent REQUIRED)

# Include thirdparty libs
include(thirdparty/trace32api/t32.cmake)

# Create config file based on CMake definitions
configure_file(${CMAKE_CURRENT_LIST_DIR}/libs/QBaseLibs/cmake/Config.h.in ${CMAKE_CURRENT_LIST_DIR}/src/gendata/Config.h)
configure_file("res/img/icon.ico" "${CMAKE_EXTRA_OUTPUT_DIRECTORY}/icon.ico" COPYONLY)
# Dummy source file to trigger post build steps after every run of cmake
file(WRITE "${CMAKE_BINARY_DIR}/gendata/include/DummyTriggerRebuild.h" "")
include_directories(${CMAKE_BINARY_DIR}/gendata/include  "src" "ui")

# All source code files (including generated resources)
file(GLOB_RECURSE ALL_SOURCES "src/*.c" "src/*.cpp" "ui/*.cpp" "ui/*.ui" "res/main.qrc" "thirdparty/trace32api/src" )

# Proj executable files - if this is not added, application will launch a console simultaneously with the gui app.
IF (WIN32)
    configure_file(${CMAKE_CURRENT_LIST_DIR}/libs/QBaseLibs/DeploySupport/Windows/res/win.rc.in ${CMAKE_BINARY_DIR}/gendata/win.rc)
    list(APPEND ${ALL_SOURCES} ${CMAKE_BINARY_DIR}/gendata/win.rc)

    # Icon How-To: https://forum.qt.io/topic/122430/setting-up-the-application-information-in-cmake/4
    set(APP_ICON_RESOURCE_WINDOWS ${CMAKE_BINARY_DIR}/gendata/win.rc)
    add_executable(${PROJECT_NAME} WIN32 ${ALL_SOURCES} ${APP_ICON_RESOURCE_WINDOWS})

    # Workaround: disable win executable for debugging mode in order to show console messages in CLION.
    # If this will be enabled, the application will also launch a console in the background.
    if(CMAKE_BUILD_TYPE STREQUAL "Debug")
        set_target_properties(${PROJECT_NAME} PROPERTIES WIN32_EXECUTABLE OFF)
    endif()
ELSEIF(APPLE)
    # Add Apple icon
    set(MACOSX_BUNDLE_ICON_FILE icon_apple.icns)
    # And the following tells CMake where to find and install the file itself.
    set(app_icon_macos "${CMAKE_CURRENT_SOURCE_DIR}/res/img/icon_apple.icns")
    set_source_files_properties(${app_icon_macos} PROPERTIES MACOSX_PACKAGE_LOCATION "Resources")

    add_executable(${PROJECT_NAME} MACOSX_BUNDLE ${ALL_SOURCES} ${app_icon_macos})
ELSE()
    add_executable(${PROJECT_NAME} ${ALL_SOURCES})
ENDIF()

target_link_libraries(${PROJECT_NAME} PUBLIC
        Qt${QT_VERSION_MAJOR}::Core
        Qt${QT_VERSION_MAJOR}::Gui
        Qt${QT_VERSION_MAJOR}::Network
        Qt${QT_VERSION_MAJOR}::Widgets
        Qt${QT_VERSION_MAJOR}::Xml
        Qt${QT_VERSION_MAJOR}::Concurrent
        trace32api-lib
)
# Link base dependencies
foreach(subdirectory ${BASE_LIB_DEPENDENCIES})
    target_link_libraries(${PROJECT_NAME} PUBLIC Base::${subdirectory})
endforeach()

# Move OpenSSL library to the same folder as the binary
include(${CMAKE_CURRENT_SOURCE_DIR}/libs/QBaseLibs/OpenSslLoader/deploy_openssl.cmake)

# Copy logo to the output for LINUX OS, so that it can be used as an icon
if(UNIX AND NOT APPLE)
    configure_file("res/img/logo.png" "${CMAKE_EXTRA_OUTPUT_DIRECTORY}/${PROJECT_NAME}.png" COPYONLY)
endif()

# Include relevant deployment modules
include(${CMAKE_CURRENT_SOURCE_DIR}/libs/QBaseLibs/DeploySupport/deploy_app.cmake)
include(${CMAKE_CURRENT_SOURCE_DIR}/libs/QBaseLibs/DeploySupport/create_deliverables.cmake)
