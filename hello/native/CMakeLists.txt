add_library( hello_native
    ../src/hello.cpp
    main.cpp
)

set_target_properties(hello_native PROPERTIES CXX_VISIBILITY_PRESET hidden)

target_compile_options(hello_native PRIVATE
    -fprofile-arcs -ftest-coverage
    -DEOSIO_NATIVE
    -Wno-unknown-attributes
)

set(CDT_INCLUDE_PATH
    ${CMAKE_SOURCE_DIR}/external/cpp-chaintester/libs/cdt/include
    ${CMAKE_SOURCE_DIR}/external/cpp-chaintester/libs/cdt/include/eosiolib/capi
    ${CMAKE_SOURCE_DIR}/external/cpp-chaintester/libs/cdt/include/eosiolib/native
    ${CMAKE_SOURCE_DIR}/external/cpp-chaintester/libs/cdt/include/eosiolib/core
    ${CMAKE_SOURCE_DIR}/external/cpp-chaintester/libs/cdt/include/eosiolib/contracts
)

target_include_directories(hello_native PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../include
    ${CDT_INCLUDE_PATH}
)

target_link_options(hello_native PRIVATE -fprofile-arcs -ftest-coverage)

target_link_libraries (hello_native
    chain_static
)
