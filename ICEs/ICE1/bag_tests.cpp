#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "bag.hpp"

// force template expansion

//TODO: please add more tests here to cover different cases.
template class Bag<int>;

int MAXSIZE = 3;

TEST_CASE("Test Construction/Destruction", "[Bag]") {

  Bag<int> b;
  REQUIRE(b.getCurrentSize() == 0);
  REQUIRE(b.isEmpty());
}

TEST_CASE("Test add", "[Bag]") {

  Bag<int> b;
  REQUIRE(b.getCurrentSize() == 0);
  REQUIRE(b.isEmpty());

  for (int i = 0; i < MAXSIZE; ++i) {
    REQUIRE(b.add(i));
    REQUIRE(b.getCurrentSize() == i + 1);
    REQUIRE(!b.isEmpty());
  }
 
}

TEST_CASE("Test getFrequencyOf", "[Bag]") {

  Bag<int> b;
  REQUIRE(b.getCurrentSize() == 0);
  REQUIRE(b.isEmpty());

  for (int i = 0; i < MAXSIZE; ++i) {
    REQUIRE(b.add(i));
    REQUIRE(b.getCurrentSize() == i + 1);
    REQUIRE(!b.isEmpty());
  }

  REQUIRE(b.getFrequencyOf(1)==1);
  REQUIRE(b.getFrequencyOf(5)==0);
}

TEST_CASE("Test contains", "[Bag]") {

  Bag<int> b;
  REQUIRE(b.getCurrentSize() == 0);
  REQUIRE(b.isEmpty());

  for (int i = 0; i < MAXSIZE; ++i) {
    REQUIRE(b.add(i));
    REQUIRE(b.getCurrentSize() == i + 1);
    REQUIRE(!b.isEmpty());
  }

  REQUIRE(b.contains(1));
  REQUIRE(!b.contains(5));  
}

TEST_CASE("Test remove and clear", "[Bag]") {

  Bag<int> b;
  REQUIRE(b.getCurrentSize() == 0);
  REQUIRE(b.isEmpty());

  for (int i = 0; i < MAXSIZE; ++i) {
    REQUIRE(b.add(i));
    REQUIRE(b.getCurrentSize() == i + 1);
    REQUIRE(!b.isEmpty());
  }

  REQUIRE(!b.remove(-1));

  for (int i = 0; i < MAXSIZE; ++i) {
    REQUIRE(b.remove(i));
  }
  REQUIRE(!b.remove(0));

  b.clear();
  REQUIRE(b.getCurrentSize() == 0);
}
