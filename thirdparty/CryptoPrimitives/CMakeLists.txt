cmake_minimum_required(VERSION 3.12)

set(PROJECT_NAME CryptoPrimitives)
project(${PROJECT_NAME} VERSION 1.0.0 DESCRIPTION "Cryptographic primitives" LANGUAGES C CXX)

add_compile_definitions(DLL_DECL_SPEC=Q_DECL_EXPORT)

# Define the library target - SHARED by default
if(NOT DEFINED QBASE_LIB_TYPE)
    set(QBASE_LIB_TYPE SHARED)
endif()

# Add third-party libraries
add_subdirectory(thirdparty/asr)

file(GLOB_RECURSE ALL_SOURCES "src/*.c" "src/*.cpp" "src/*.cc")
add_library(${PROJECT_NAME} ${QBASE_LIB_TYPE} ${ALL_SOURCES})
add_library(Base::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

# Link current library
target_link_libraries(${PROJECT_NAME} PRIVATE Base::AsrCrypto)

# Set the include directories for users of this library
target_include_directories(${PROJECT_NAME} PRIVATE include/${PROJECT_NAME})
target_include_directories(${PROJECT_NAME} PRIVATE src/)

target_include_directories(${PROJECT_NAME} PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>)

# Install rules
install(TARGETS ${PROJECT_NAME}
        EXPORT ${PROJECT_NAME}Config
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        RUNTIME DESTINATION bin)

install(DIRECTORY include/ DESTINATION include)

# Generate and install the package configuration
install(EXPORT ${PROJECT_NAME}Config
        NAMESPACE Base::
        DESTINATION cmake)

message(STATUS "Build base library ${PROJECT_NAME} ${CMAKE_PROJECT_VERSION}")