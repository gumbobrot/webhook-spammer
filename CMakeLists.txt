cmake_minimum_required(VERSION 3.26)
project(hi)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

find_library(CURL_LIBRARY NAMES curl)

if(NOT CURL_LIBRARY)
    message(FATAL_ERROR "CURL library not found")
endif()

add_executable(hi main.cpp)
target_link_libraries(hi PRIVATE ${CURL_LIBRARY})
