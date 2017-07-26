cmake_minimum_required(VERSION 2.8.12)

project("hbase_benchmark")

set(CMAKE_CXX_FLAGS "-g -std=c++11 -I ~/include/thrift/ -I ~/include/  -L ~/lib/ -lthrift")

aux_source_directory(./gen-cpp/ GEN_CPP)

add_executable(${PROJECT_NAME} main.cpp ${GEN_CPP})
