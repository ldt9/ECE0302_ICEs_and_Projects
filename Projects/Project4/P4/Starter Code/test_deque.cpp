#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "deque.hpp"

// TODO

TEST_CASE( "Tests", "[deque]" ) {
  Deque<int> a;

  REQUIRE(a.isEmpty());
  a.pushFront(1);
  a.pushFront(2);
  a.pushFront(3);
  REQUIRE(!a.isEmpty());

}
