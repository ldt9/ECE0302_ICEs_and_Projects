#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "fancyPower.hpp"

// write your test cases here
TEST_CASE("Test case even n", "fancyPower"){

  REQUIRE(fancyPower(2, 2) == 4);
  REQUIRE(fancyPower(4, 2) == 16);
  REQUIRE(fancyPower(6, 2) == 64);
  REQUIRE(fancyPower(8, 2) == 256);
}

TEST_CASE("Test case odd n", "fancyPower"){

  REQUIRE(fancyPower(3, 2) == 8);
  REQUIRE(fancyPower(5, 2) == 32);
  REQUIRE(fancyPower(7, 2) == 128);
  REQUIRE(fancyPower(9, 2) == 512);
}

TEST_CASE("Test case for n = 0", "fancyPower"){

  REQUIRE(fancyPower(0, 2) == 1);
  REQUIRE(fancyPower(0, 5) == 1);
  REQUIRE(fancyPower(0, 10) == 1);
  REQUIRE(fancyPower(0, 1) == 1);
}

TEST_CASE("Test case for n = 1", "fancyPower"){

  REQUIRE(fancyPower(1, 2) == 2);
  REQUIRE(fancyPower(1, 5) == 5);
  REQUIRE(fancyPower(1, 10) == 10);
  REQUIRE(fancyPower(1, 1) == 1);
}
