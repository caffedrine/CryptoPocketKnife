cmake_minimum_required(VERSION 3.12)

set(PROJECT_NAME AsrCrypto)
project(${PROJECT_NAME} VERSION 1.0.0 DESCRIPTION "Autosar Crypto Stack" LANGUAGES C)

add_compile_definitions(DLL_DECL_SPEC=Q_DECL_EXPORT)

# Source files
file(GLOB_RECURSE ALL_SOURCES "src/*.c" "src/*.cpp" "src/*.cc")

# Link this always as static abd bind it to Base:: namespace
add_library(${PROJECT_NAME} STATIC ${ALL_SOURCES})
add_library(Base::${PROJECT_NAME} ALIAS ${PROJECT_NAME})
target_link_libraries(${PROJECT_NAME})

# Set the include directories for users of this library only (private)
target_include_directories(${PROJECT_NAME} PRIVATE src/Crypto_30_LibCv)
target_include_directories(${PROJECT_NAME} PRIVATE src/vCfg)
target_include_directories(${PROJECT_NAME} PRIVATE src/vSecPrim)
target_include_directories(${PROJECT_NAME} PRIVATE src/vStd)
target_include_directories(${PROJECT_NAME} PRIVATE src/)

target_include_directories(${PROJECT_NAME} PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src/vCfg>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src/vSecPrim>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src/vStd>
        $<INSTALL_INTERFACE:include>)

# Install rules
install(TARGETS ${PROJECT_NAME}
        EXPORT ${PROJECT_NAME}Config
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        RUNTIME DESTINATION bin)

# Generate and install the package configuration
install(EXPORT ${PROJECT_NAME}Config
        NAMESPACE Base::
        DESTINATION cmake)

message(STATUS "Build thirdparty library ${PROJECT_NAME} ${CMAKE_PROJECT_VERSION}")