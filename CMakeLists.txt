cmake_minimum_required(VERSION 3.5)

project(CryptoPocketKnife LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 COMPONENTS Widgets Console REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets Network Core REQUIRED)
find_package(Qt${QT_VERSION_MAJOR}Widgets)

# Include EdDSA lib and it's configuration
option(USE_STACKCLEAN "clean all secret variables from stack" ON)

# Add EDDSA
include_directories("thirdparty/libeddsa/lib")
add_subdirectory("thirdparty/libeddsa/lib")
file(GLOB_RECURSE EDDSA_SRC "thirdparty/libeddsa/lib/*.c")

# Add AES
include_directories("thirdparty/tiny-AES-c")
file(GLOB_RECURSE AES_SRC "thirdparty/tiny-AES-c/aes.c")

# Add hashes
include_directories("thirdparty/hashes")
file(GLOB_RECURSE HASHES_SRC "thirdparty/hashes/*.c")

######################################Include everuthing src##################################
file(GLOB_RECURSE Proj_SOURCES "src/*.cpp" "src/*.c")
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

#if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
#    qt_add_executable(${PROJECT_NAME} ${Proj_SOURCES_ED25519} ${Proj_UIS} ${Proj_SOURCES})
#else()
#    add_executable(${PROJECT_NAME} ${Proj_SOURCES_ED25519} ${Proj_UIS} ${Proj_SOURCES})
#endif()

IF (WIN32)
    # Icon How-To:
    # https://forum.qt.io/topic/122430/setting-up-the-application-information-in-cmake/4

    set(APP_ICON_RESOURCE_WINDOWS "${CMAKE_CURRENT_SOURCE_DIR}/res/win.rc")
    add_executable(${PROJECT_NAME} WIN32 ${HASHES_SRC} ${AES_SRC} ${EDDSA_SRC} ${Proj_UIS} ${Proj_SOURCES} ${Proj_RES} ${APP_ICON_RESOURCE_WINDOWS})
ELSE()
    add_executable(${PROJECT_NAME} ${HASHES_SRC} ${AES_SRC} ${EDDSA_SRC} ${Proj_UIS} ${Proj_SOURCES} ${Proj_RES})
ENDIF()

target_link_libraries(${PROJECT_NAME} PRIVATE ${HASHES_SRC} ${AES_SRC} ${EDDSA_SRC} eddsa Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Network Qt${QT_VERSION_MAJOR}::Core)

#
# Deployment - Automatically Detect and Copy Dependencies to Deploy folder when building release (for windows)
#
IF(CMAKE_BUILD_TYPE MATCHES Release)
    # Windows deployment
    if (WIN32)
        # Copy executable to deploy folder
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_BINARY_DIR}/${PROJECT_NAME}.exe" "${CMAKE_BINARY_DIR}/../Deploy/Windows/${PROJECT_NAME}.exe" COMMENT "Copying to output directory")

        # Copy additional windows libs
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_SOURCE_DIR}/libs/Windows/libeay32.dll" "${CMAKE_BINARY_DIR}/../Deploy/Windows/libeay32.dll" COMMENT "Copying required DLLs to output directory")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_SOURCE_DIR}/libs/Windows/ssleay32.dll" "${CMAKE_BINARY_DIR}/../Deploy/Windows/ssleay32.dll")

        # Copy required DLLs to deploy folder
        get_target_property(QT_QMAKE_EXECUTABLE Qt${QT_VERSION_MAJOR}::qmake IMPORTED_LOCATION)
        get_filename_component(QT_WINDEPLOYQT_EXECUTABLE ${QT_QMAKE_EXECUTABLE} PATH)
        set(QT_WINDEPLOYQT_EXECUTABLE "${QT_WINDEPLOYQT_EXECUTABLE}/windeployqt.exe")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD COMMAND ${QT_WINDEPLOYQT_EXECUTABLE} --release --qmldir ${CMAKE_SOURCE_DIR}/../Deployed "${CMAKE_BINARY_DIR}/../Deploy/Windows/${PROJECT_NAME}.exe")
    endif(WIN32)
ENDIF(CMAKE_BUILD_TYPE MATCHES Release)

