#include <eosio/eosio.hpp>
using namespace eosio;

class [[eosio::contract]] hello : public contract {
   public:
      using contract::contract;

      [[eosio::action]] 
      void test( name a, name b );

      using test_action = action_wrapper<"test"_n, &hello::test>;
};
