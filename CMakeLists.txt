cmake_minimum_required(VERSION 3.5)

project(CryptoPocketKnife LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)
find_package(Qt5Widgets)

# Include EdDSA lib and it's configuration
option(USE_STACKCLEAN "clean all secret variables from stack" ON)

# Add EDDSA
include_directories("thirdparty/libeddsa/lib")
add_subdirectory("thirdparty/libeddsa/lib")
file(GLOB_RECURSE EDDSA_SRC "thirdparty/libeddsa/lib/*.c")
# Add AES
include_directories("thirdparty/tiny-AES-c")
file(GLOB_RECURSE AES_SRC "thirdparty/tiny-AES-c/aes.c")

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
    add_executable(${PROJECT_NAME} WIN32 ${AES_SRC} ${EDDSA_SRC} ${Proj_UIS} ${Proj_SOURCES} ${Proj_RES})
ELSE()
    add_executable(${PROJECT_NAME} ${AES_SRC} ${EDDSA_SRC} ${Proj_UIS} ${Proj_SOURCES} ${Proj_RES})
ENDIF()

target_link_libraries(${PROJECT_NAME} PRIVATE ${AES_SRC} ${EDDSA_SRC} eddsa Qt${QT_VERSION_MAJOR}::Widgets)
