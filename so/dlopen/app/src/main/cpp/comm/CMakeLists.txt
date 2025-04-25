cmake_minimum_required(VERSION 3.22.1)
project(jni_lib)

add_library(comm SHARED other.cpp)

#set_target_properties(comm PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/libs)

# 指定 JNI 头文件路径
#不使用头文件时，必须要在调用模块，手动去定义函数签名
target_include_directories(comm PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include)
# 查找 log 库，log库是java的必须要target_link_libraries引入
find_library(
        log-lib
        log
)
# 链接日志库
target_link_libraries(
        comm
        ${log-lib}
)