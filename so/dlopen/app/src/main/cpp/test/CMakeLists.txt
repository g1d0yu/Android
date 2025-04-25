cmake_minimum_required(VERSION 3.22.1)
project(test)

add_library(test SHARED main.cpp)

find_library(
        log-lib
        log
)
target_link_libraries(
        test
        ${log-lib}
)