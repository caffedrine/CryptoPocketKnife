# Variable to store thirdparty sources used by main CMake file
set(THIRD_PARTY_SRC "")
set(THIRD_PARTY_LIBS "")
set(THIRD_PARTY_INCLUDES "")

# Include spdlog logger
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/spdlog)
#include_directories(thirdparty/spdlog/include) # there is also to build sources instead of lib
list(APPEND THIRD_PARTY_LIBS spdlog::spdlog)

# Include BigIntegers
list(APPEND THIRD_PARTY_INCLUDES ${CMAKE_CURRENT_LIST_DIR}/BigInt)
list(APPEND THIRD_PARTY_SRC ${CMAKE_CURRENT_LIST_DIR}/BigInt/*.cpp)

# Add AES as a separete library since this is C code
list(APPEND THIRD_PARTY_INCLUDES ${CMAKE_CURRENT_LIST_DIR}/tiny-AES-c)
add_library(tiny-AES-lib ${CMAKE_CURRENT_LIST_DIR}/tiny-AES-c/aes.c)
list(APPEND THIRD_PARTY_LIBS tiny-AES-lib)

## Add hashes
list(APPEND THIRD_PARTY_INCLUDES ${CMAKE_CURRENT_LIST_DIR}/hashes)
file(GLOB_RECURSE lib_hashes_src ${CMAKE_CURRENT_LIST_DIR}/hashes/*.c ${CMAKE_CURRENT_LIST_DIR}/hashes/*.cpp)
add_library(hashes-lib ${lib_hashes_src})
list(APPEND THIRD_PARTY_LIBS hashes-lib)

# Add EdDSA library
list(APPEND THIRD_PARTY_INCLUDES ${CMAKE_CURRENT_LIST_DIR}/libeddsa/lib)
file(GLOB_RECURSE lib_eddsa_src ${CMAKE_CURRENT_LIST_DIR}/libeddsa/lib/*.c)
add_library(eddsa-lib ${lib_eddsa_src})
list(APPEND THIRD_PARTY_LIBS eddsa-lib)

#
# Resolve wildchars
#
file(GLOB_RECURSE THIRD_PARTY_SRC ${THIRD_PARTY_SRC})
include_directories(${THIRD_PARTY_INCLUDES})
