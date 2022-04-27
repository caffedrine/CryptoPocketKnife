# Variable to store thirdparty sources
set(THIRD_PARTY_SRC "")
set(THIRD_PARTY_LIBS "")

# Include spdlog logger
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/spdlog)
#include_directories(thirdparty/spdlog/include) # to build sources
list(APPEND THIRD_PARTY_LIBS spdlog::spdlog)

# Include BigNumber
include_directories(${CMAKE_CURRENT_LIST_DIR}/BigNumber/src)
list(APPEND THIRD_PARTY_SRC ${CMAKE_CURRENT_LIST_DIR}/BigNumber/src/bignumber.cpp)
