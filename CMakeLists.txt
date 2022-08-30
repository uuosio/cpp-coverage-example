cmake_minimum_required(VERSION 3.16.3)

project(hello)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

execute_process(COMMAND python3 ${CMAKE_SOURCE_DIR}/scripts/find_cdt_path.py OUTPUT_VARIABLE CDT_PATH)
message(STATUS "++++++CDT_PATH:${CDT_PATH}")

add_subdirectory(external/cpp-chaintester)
add_subdirectory(hello)
add_subdirectory(tests)
