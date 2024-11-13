cmake_minimum_required(VERSION 3.29)
project(joincpp)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)
add_executable(joincpp main.cpp)
target_include_directories(joincpp PRIVATE ${CMAKE_SOURCE_DIR}/include)
