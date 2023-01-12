# inspiration
cmake_minimum_required(VERSION 3.9)

project(RandomTest VERSION 1.0.1 DESCRIPTION "ENT — Fourmilab Random Sequence Tester")

include(GNUInstallDirs)

if (MSVC)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
endif()

# Get all sources
file(GLOB_RECURSE LIB_SOURCES "src/*.c" "src/*.cpp")

add_library(RandomTest ${LIB_SOURCES})
add_library(Random::RandomTest ALIAS RandomTest)
set_target_properties(RandomTest PROPERTIES VERSION ${PROJECT_VERSION} SOVERSION 1)
include_directories(src)

configure_file(RandomTest.pc.in RandomTest.pc @ONLY)

# Public API headers
target_include_directories(RandomTest PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
        $<INSTALL_INTERFACE:src>)

install(TARGETS RandomTest LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR} PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install(TARGETS RandomTest EXPORT RandomTestConfig LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
export(TARGETS RandomTest FILE "${CMAKE_CURRENT_BINARY_DIR}/RandomTestConfig.cmake")
install(EXPORT RandomTestConfig DESTINATION "${CMAKE_INSTALL_LIBDIR}/RandomTest/cmake" NAMESPACE Random::)
install(DIRECTORY src DESTINATION ${CMAKE_INSTALL_PREFIX})
install(FILES ${CMAKE_BINARY_DIR}/RandomTest.pc DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/pkgconfig)