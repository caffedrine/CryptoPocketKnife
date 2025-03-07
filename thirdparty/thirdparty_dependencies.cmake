# Variable to store thirdparty sources used by main CMake file
set(THIRD_PARTY_SRC "")
set(THIRD_PARTY_LIBS "")
set(THIRD_PARTY_INCLUDES "")
set(THIRD_PARTY_COPY_TO_OUTPUT "")

## Include x509 parser
#list(APPEND THIRD_PARTY_INCLUDES ${CMAKE_CURRENT_LIST_DIR}/x509-parser/src)
#file(GLOB_RECURSE lib_x509_parser_src ${CMAKE_CURRENT_LIST_DIR}/x509-parser/src/*.cpp ${CMAKE_CURRENT_LIST_DIR}/x509-parser/src/*.c)
#add_library(x509-parser-lib ${lib_x509_parser_src})
#list(APPEND THIRD_PARTY_LIBS x509-parser-lib)

# Include GnuTLS
#list(APPEND THIRD_PARTY_INCLUDES ${CMAKE_CURRENT_LIST_DIR}/GnuTLS/includes)
##find_library(GnuTLS_LIB NAMES libgnutls HINTS "${CMAKE_CURRENT_LIST_DIR}/GnuTLS/lib" REQUIRED)
#list(APPEND THIRD_PARTY_LIBS ${CMAKE_CURRENT_LIST_DIR}/GnuTLS/lib/libgnutls.dll.a)

# Include random analyzer
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/random_test)
list(APPEND THIRD_PARTY_LIBS Random::RandomTest)

# Add AES as a separete library since this is C code
list(APPEND THIRD_PARTY_INCLUDES ${CMAKE_CURRENT_LIST_DIR}/Qt-AES)
# add_library(Qt-AES ${CMAKE_CURRENT_LIST_DIR}/Qt-AES/qaesencryption.cpp)
# list(APPEND THIRD_PARTY_LIBS Qt-AES)
list(APPEND THIRD_PARTY_SRC ${CMAKE_CURRENT_LIST_DIR}/Qt-AES/qaesencryption.cpp)

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
