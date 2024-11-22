cmake_minimum_required(VERSION 3.19)

project(time)

add_compile_options(-g -O2 -Wall -Werror)

set(CMAKE_CXX_STANDARD 11)

include_directories(./)

file(GLOB_RECURSE SOURCES "utility/*.cpp")

add_executable(main ${SOURCES} main.cpp)
