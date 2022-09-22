#include "chaintester.h"
#include "test.h"

#include <eosio/eosio.hpp>

TEST_CASE( "test hello", "[hello]" ) {
    // load_native_contract(HELLO_SO);
    set_apply(hello_native_apply);

    ChainTester tester(true);
    tester.enable_debug_contract("hello", true);

    tester.deploy_contract("hello", HELLO_WASM, HELLO_ABI);

    auto args = R""""(
    {
        "nm": "alice"
    }
    )"""";

    auto permissions = R""""(
    {
        "hello": "active"
    }
    )"""";
    tester.push_action("hello", "hi", args, permissions);
    tester.produce_block();

    //the same as {"nm": "alice"}, but in raw data format
    tester.push_action("hello", "hi", eosio::pack(eosio::name("alice")), permissions);
    tester.produce_block();

    args = R""""(
    {
        "nm": "hello"
    }
    )"""";
    tester.push_action("hello", "check", args, permissions);
    tester.produce_block();

    //the same as {"nm": "hello"}, but in raw data format
    tester.push_action("hello", "hi", eosio::pack(eosio::name("hello")), permissions);
    tester.produce_block();


    //multiple action arguments
    args = R""""(
    {
        "a": "hello",
        "b": "alice"
    }
    )"""";
    tester.push_action("hello", "test", args, permissions);
    tester.produce_block();
{
    //multiple action arguments in raw data format
    auto args = eosio::pack(std::make_tuple(eosio::name("hello"), eosio::name("alice")));
    tester.push_action("hello", "test", args, permissions);
    tester.produce_block();
}

}
