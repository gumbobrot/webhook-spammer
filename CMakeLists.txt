cmake_minimum_required(VERSION 3.26)
project(hi)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

set(CURL_LIBRARY "libcurl.dll.a")

add_executable(hi main.cpp)
target_link_libraries(hi PRIVATE ${CURL_LIBRARY})
