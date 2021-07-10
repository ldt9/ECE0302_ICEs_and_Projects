#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "deque.hpp"

// TODO

TEST_CASE( "Tests pushFront, popFront, front and is empty", "[deque]" ) {
  Deque<int> a;

  REQUIRE(a.isEmpty());
  a.pushFront(1);
  a.pushFront(2);
  a.pushFront(3);
  REQUIRE(!a.isEmpty());
  REQUIRE(a.front() == 3);
  a.popFront();
  REQUIRE(!a.isEmpty());
  REQUIRE(a.front() == 2);
  a.popFront();
  REQUIRE(!a.isEmpty());
  REQUIRE(a.front() == 1);
  a.popFront();
  REQUIRE(a.isEmpty());
}

TEST_CASE( "Tests pushBack, popBack, back and is empty", "[deque]" ) {
  Deque<int> a;

  REQUIRE(a.isEmpty());
  a.pushBack(1);
  a.pushBack(2);
  a.pushBack(3);
  REQUIRE(!a.isEmpty());
  REQUIRE(a.back() == 3);
  a.popBack();
  REQUIRE(!a.isEmpty());
  REQUIRE(a.back() == 2);
  a.popBack();
  REQUIRE(!a.isEmpty());
  REQUIRE(a.back() == 1);
  a.popBack();
  REQUIRE(a.isEmpty());
}

TEST_CASE( "Tests pushFront, popBack, front and is empty", "[deque]" ) {
  Deque<int> a;

  REQUIRE(a.isEmpty());
  a.pushFront(1);
  a.pushFront(2);
  a.pushFront(3);
  REQUIRE(!a.isEmpty());
  REQUIRE(a.front() == 3);
  a.popBack();
  REQUIRE(!a.isEmpty());
  REQUIRE(a.front() == 3);
  a.popBack();
  REQUIRE(!a.isEmpty());
  REQUIRE(a.front() == 3);
  a.popBack();
  REQUIRE(a.isEmpty());
}

TEST_CASE( "Tests pushBack, popFront, back and is empty", "[deque]" ) {
  Deque<int> a;

  REQUIRE(a.isEmpty());
  a.pushBack(1);
  a.pushBack(2);
  a.pushBack(3);
  REQUIRE(!a.isEmpty());
  REQUIRE(a.back() == 3);
  a.popFront();
  REQUIRE(!a.isEmpty());
  REQUIRE(a.back() == 3);
  a.popFront();
  REQUIRE(!a.isEmpty());
  REQUIRE(a.back() == 3);
  a.popFront();
  REQUIRE(a.isEmpty());
}

TEST_CASE( "Tests copy constructor and assignment", "[deque]" ) {
  Deque<int> a;
  Deque<int> b;

  REQUIRE(a.isEmpty());
  a.pushBack(1);
  a.pushBack(2);
  a.pushBack(3);
  REQUIRE(!a.isEmpty());

  b = a;
  Deque<int> c(b);
  
  REQUIRE(a.back() == b.back());
  REQUIRE(b.back() == c.back());
  a.popFront();
  b.popFront();
  c.popFront();
  REQUIRE(!a.isEmpty());
  REQUIRE(!b.isEmpty());
  REQUIRE(!c.isEmpty());
  REQUIRE(a.back() == b.back());
  REQUIRE(b.back() == c.back());
  a.popFront();
  b.popFront();
  c.popFront();
  REQUIRE(!a.isEmpty());
  REQUIRE(!b.isEmpty());
  REQUIRE(!c.isEmpty());
  REQUIRE(a.back() == b.back());
  REQUIRE(b.back() == c.back());
  a.popFront();
  b.popFront();
  c.popFront();
  REQUIRE(a.isEmpty());
  REQUIRE(b.isEmpty());
  REQUIRE(c.isEmpty());

}
