#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "limited_size_bag.hpp"

// force template expansion for ints
template class LimitedSizeBag<int>;

TEST_CASE("Empty Test", "[LimitedSizeBag]"){
  REQUIRE(true);
}

TEST_CASE("Add and Remove methods", "[LimitedSizeBag]"){
  LimitedSizeBag<int> b;

  //testing adding a number and removing it
  REQUIRE(b.add(1));
  REQUIRE(!b.isEmpty());
  REQUIRE(b.getCurrentSize() == 1);
  REQUIRE(b.remove(1));
  REQUIRE(b.isEmpty());
  REQUIRE(b.getCurrentSize() == 0);
}
TEST_CASE("Frequency and Size returner methods", "[LimitedSizeBag]"){
  LimitedSizeBag<int> b;

  //testing frequency in same situation as before, making sur eprogram knows int exists
  REQUIRE(b.add(1));
  REQUIRE(b.getFrequencyOf(1) == 1);
  REQUIRE(b.contains(1));
  REQUIRE(!b.isEmpty());
  REQUIRE(b.getCurrentSize() == 1);
}

TEST_CASE("Clear method", "[LimitedSizeBag]"){
  LimitedSizeBag<int> b;

  //testing clear functionality and making sure other methods are affected
  b.clear();
  REQUIRE(b.getCurrentSize() == 0);
  REQUIRE(b.contains(1) == 0);
  REQUIRE(b.getCurrentSize() == 0);
  REQUIRE(b.isEmpty());
}

TEST_CASE("Adding more than one element", "[LimitedSizeBag]"){
  LimitedSizeBag<int> b;

  //testing multiple numbers to make sure methods can handle multiple ints
  REQUIRE(b.add(1));
  REQUIRE(b.add(2));
  REQUIRE(b.getFrequencyOf(1) == 1);
  REQUIRE(b.getFrequencyOf(2) == 1);
  REQUIRE(b.contains(1));
  REQUIRE(b.contains(2));
  REQUIRE(!b.isEmpty());
  REQUIRE(b.getCurrentSize() == 2);
  b.clear();

}

TEST_CASE("copy constructor and assignment tests"){
  LimitedSizeBag<int> b;
  LimitedSizeBag<int> a;

  //testing making 2 bags and setting them equal to eachother in 2 different ways
  REQUIRE(b.add(1));
  REQUIRE(b.add(2));
  REQUIRE(b.getFrequencyOf(1) == 1);
  REQUIRE(b.getFrequencyOf(2) == 1);
  REQUIRE(b.contains(1));
  REQUIRE(b.contains(2));
  REQUIRE(!b.contains(3));
  REQUIRE(!b.contains(4));
  REQUIRE(b.getCurrentSize() == 2);

  REQUIRE(a.add(3));
  REQUIRE(a.add(4));
  REQUIRE(a.getFrequencyOf(3) == 1);
  REQUIRE(a.getFrequencyOf(4) == 1);
  REQUIRE(!a.contains(1));
  REQUIRE(!a.contains(2));
  REQUIRE(a.contains(3));
  REQUIRE(a.contains(4));
  REQUIRE(a.getCurrentSize() == 2);

  //testing assignment operator
  b = a;

  REQUIRE(b.getFrequencyOf(3) == 1);
  REQUIRE(b.getFrequencyOf(4) == 1);
  REQUIRE(!b.contains(1));
  REQUIRE(!b.contains(2));
  REQUIRE(b.contains(3));
  REQUIRE(b.contains(4));
  REQUIRE(b.getCurrentSize() == 2);
  b.clear();
  REQUIRE(b.isEmpty());

  //testing copy constructor
  LimitedSizeBag<int> c(a);
  REQUIRE(c.getFrequencyOf(3) == 1);
  REQUIRE(c.getFrequencyOf(4) == 1);
  REQUIRE(!c.contains(1));
  REQUIRE(!c.contains(2));
  REQUIRE(c.contains(3));
  REQUIRE(c.contains(4));
  REQUIRE(c.getCurrentSize() == 2);
  c.clear();
  REQUIRE(c.isEmpty());
}
