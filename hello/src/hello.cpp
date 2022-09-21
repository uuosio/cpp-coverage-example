#include <hello.hpp>
[[eosio::action]]
void hello::hi( name nm ) {
   print_f("Name : %\n", nm);
}

[[eosio::action]]
void hello::check( name nm ) {
   print_f("Name : %\n", nm);
   eosio::check(nm == "hello"_n, "check name not equal to `hello`");
}

[[eosio::action]]
void hello::test( name a, name b ) {
   print_f("Name : % %\n", a, b);
   eosio::check(a != b, "a != b");
}
