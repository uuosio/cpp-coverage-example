#include "chaintester.h"
#include "test.h"

#include <eosio/eosio.hpp>

TEST_CASE( "test hello", "[hello]" ) {
    // load_native_contract(HELLO_SO);
    set_apply(hello_native_apply);

    ChainTester tester(true);
    tester.enable_debug_contract("hello", true);

    tester.deploy_contract("hello", HELLO_WASM, HELLO_ABI);

    auto permissions = R""""(
    {
        "hello": "active"
    }
    )"""";
    auto args = R""""(
    {
        "a": "hello",
        "b": "alice"
    }
    )"""";
    tester.push_action("hello", "test", args, permissions);
    tester.produce_block();
{
    //action arguments in raw data format
    auto args = eosio::pack(std::make_tuple(eosio::name("hello"), eosio::name("alice")));
    tester.push_action("hello", "test", args, permissions);
    tester.produce_block();
}

}
