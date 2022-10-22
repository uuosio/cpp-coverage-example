#include "chaintester.h"
#include "test.h"

#include <eosio/eosio.hpp>

TEST_CASE( "test hello", "[hello]" ) {
    // load_native_contract(HELLO_SO);
    set_native_apply(hello_native_apply);

    ChainTester tester(true);
    tester.enable_debug_contract("hello"_n, true);

    tester.deploy_contract("hello"_n, HELLO_WASM, HELLO_ABI);

    vector<permission_level> permissions = {{"hello"_n, "active"_n}};

    auto args = std::make_tuple("hello"_n, "alice"_n);
    tester.push_action("hello"_n, "test"_n, args, permissions);
    tester.produce_block();

    tester.push_action("hello"_n, "test"_n, args, "hello"_n);
    tester.produce_block();
}
