#include <hello.hpp>

[[eosio::action]]
void hello::test( name a, name b ) {
   print_f("Name : % %\n", a, b);
   eosio::check(a != b, "a != b");
}
