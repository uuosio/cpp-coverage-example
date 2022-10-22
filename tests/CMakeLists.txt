message(STATUS "++++++++++CMAKE_CXX_FLAGS: ${CMAKE_CXX_FLAGS}")
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

add_executable( hello_tests 
    src/test_hello.cpp
    src/main.cpp
)

target_compile_options(hello_tests PRIVATE 
    -fprofile-arcs -ftest-coverage
    -DEOSIO_NATIVE
    -Wno-unknown-attributes
    -Wno-deprecated-declarations
    -Wno-unused-value
)

target_link_options(hello_tests PRIVATE -fprofile-arcs -ftest-coverage)

target_link_libraries ( hello_tests
    hello_native
    chaintester
)

add_dependencies(hello_tests chaintester)

set(CDT_INCLUDE_PATH
    ${CMAKE_SOURCE_DIR}/external/cpp-chaintester/libs/cdt/include
    ${CMAKE_SOURCE_DIR}/external/cpp-chaintester/libs/cdt/include/eosiolib/capi
    ${CMAKE_SOURCE_DIR}/external/cpp-chaintester/libs/cdt/include/eosiolib/native
    ${CMAKE_SOURCE_DIR}/external/cpp-chaintester/libs/cdt/include/eosiolib/core
    ${CMAKE_SOURCE_DIR}/external/cpp-chaintester/libs/cdt/include/eosiolib/contracts
)

target_include_directories(hello_tests PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/src"
    "${CMAKE_CURRENT_BINARY_DIR}"
    ${CDT_INCLUDE_PATH}
    "${CMAKE_SOURCE_DIR}/external/cpp-chaintester/libs/Catch2/src"
    "${CMAKE_SOURCE_DIR}/external/cpp-chaintester/chaintester/src"
    "${CMAKE_BINARY_DIR}/generated-includes"
)

configure_file(src/test.h.in ${CMAKE_CURRENT_BINARY_DIR}/test.h @ONLY )
