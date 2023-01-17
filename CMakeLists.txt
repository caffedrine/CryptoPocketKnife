cmake_minimum_required(VERSION 3.5)

project(CryptoPocketKnife LANGUAGES CXX C)

set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin_output)
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin_output)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Assume error console to print out data always
set(QT_ASSUME_STDERR_HAS_CONSOLE 1)

find_package(QT NAMES Qt6 Qt5)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets Network Core Concurrent Xml REQUIRED)

# Include thirdparty libraries
include(thirdparty/thirdparty_dependencies.cmake)

# Include core functionality
add_subdirectory(libs/QtAppBase)

###################################### Include recursively all the sources ##################################
file(GLOB_RECURSE Proj_SOURCES "src/*.c" "src/*.cpp")
file(GLOB_RECURSE Proj_HEADERS "src/*.h" "src/*.hpp" "ui/*.h")
file(GLOB_RECURSE Proj_UIS     "ui/*.ui" "ui/*.cpp")
file(GLOB_RECURSE Proj_RES     "res/*.qrc")

foreach (_headerFile ${Proj_HEADERS})
    get_filename_component(_dir ${_headerFile} PATH)
    list (APPEND Proj_INCLUDE_DIRS ${_dir})
endforeach()

list(REMOVE_DUPLICATES Proj_INCLUDE_DIRS)

include_directories(${Proj_INCLUDE_DIRS})
link_directories(${Proj_INCLUDE_DIRS})
##############################################################################################

# Sum up all sources into a single variable
set(ALL_SOURCES ${Proj_UIS} ${Proj_SOURCES} ${Proj_RES} ${THIRD_PARTY_SRC})

IF (WIN32)
    # Icon How-To: https://forum.qt.io/topic/122430/setting-up-the-application-information-in-cmake/4
    set(APP_ICON_RESOURCE_WINDOWS "${CMAKE_CURRENT_SOURCE_DIR}/res/win.rc")
    add_executable(${PROJECT_NAME} WIN32 ${ALL_SOURCES} ${APP_ICON_RESOURCE_WINDOWS})
ELSE()
    add_executable(${PROJECT_NAME} ${ALL_SOURCES})
ENDIF()

target_link_libraries(${PROJECT_NAME} PRIVATE
        ${THIRD_PARTY_LIBS}
        Qt${QT_VERSION_MAJOR}::Xml
        Qt${QT_VERSION_MAJOR}::Widgets
        Qt${QT_VERSION_MAJOR}::Network
        Qt${QT_VERSION_MAJOR}::Core
        Qt${QT_VERSION_MAJOR}::Concurrent
        base::QtAppBase)

# Deployment execution
include(deploy.cmake)

# Copy additional resources to output
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_directory "${CMAKE_CURRENT_SOURCE_DIR}/data" "${CMAKE_BINARY_DIR}/data" COMMENT "Copy additional data")


