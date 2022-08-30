cmake_minimum_required(VERSION 3.16.3)

project(hello)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

add_subdirectory(external/cpp-chaintester)
add_subdirectory(hello)
add_subdirectory(tests)
