cmake_minimum_required(VERSION 3.29)
project(joincpp VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_library(joincpp INTERFACE)
target_include_directories(joincpp
        INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

file(GLOB_RECURSE EXAMPLE_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/examples/*.cpp")

foreach(EXAMPLE_SOURCE_FILE ${EXAMPLE_SOURCES})
    get_filename_component(EXAMPLE_NAME ${EXAMPLE_SOURCE_FILE} NAME_WE)
    add_executable(${EXAMPLE_NAME} ${EXAMPLE_SOURCE_FILE})
    target_link_libraries(${EXAMPLE_NAME} PRIVATE joincpp)
endforeach()

add_subdirectory(test)