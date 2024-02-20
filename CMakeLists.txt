cmake_minimum_required(VERSION 3.26)

project(Interpretor VERSION 1.0 LANGUAGES CXX)

add_executable(interpretor main.cpp)
include_directories(${CMAKE_SOURCE_DIR})

target_compile_options(interpretor PRIVATE -Wall)
