#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <cassert>
#include "frontier_queue.hpp"
#include "state.hpp"

// TODO implement your tests here
// note you can use any supported type for the value type T
// including the Puzzle type as in the solver code

TEST_CASE( "test basic empty, push, and pop", "[frontier_queue]" ) {
  frontier_queue<int> fq;
  REQUIRE(fq.empty());
  fq.push(1, 1, 1);
  REQUIRE(!fq.empty());
  State<int> x = fq.pop();
  REQUIRE(x.getFCost() == 2);
  REQUIRE(fq.empty());
}

TEST_CASE( "test min heap order in tact", "[frontier_queue]" ) {
  frontier_queue<int> fq;
  REQUIRE(fq.empty());
  fq.push(1, 1, 1);
  fq.push(2, 2, 2);
  fq.push(3, 3, 3);
  REQUIRE(!fq.empty());

  State<int> x(0, 0, 0);
  for(int i = 0; i < 3; i++){
    x = fq.pop();
    REQUIRE(x.getValue() == i+1);
  }

  fq.push(1, 1, 1);
  fq.push(2, 2, 2);
  fq.push(3, 3, 3);
  fq.push(4, 4, 4);
  fq.push(5, 5, 5);
  fq.push(6, 6, 6);
  fq.push(7, 7, 7);
  fq.push(8, 8, 8);
  fq.push(9, 9, 9);
  fq.push(10, 10, 10);

  for(int i = 1; i <= 10; i++){
    REQUIRE(fq.contains(i));
    x = fq.pop();
    REQUIRE(x.getValue() == i);
  }
  REQUIRE(fq.empty());
}

TEST_CASE( "test min heap order in tact with random order", "[frontier_queue]" ) {
  frontier_queue<int> fq;
  REQUIRE(fq.empty());

  State<int> x(0, 0, 0);

  fq.push(1, 1, 1);
  fq.push(2, 2, 2);
  fq.push(5, 5, 5);
  fq.push(6, 6, 6);
  fq.push(3, 3, 3);
  fq.push(9, 9, 9);
  fq.push(4, 4, 4);
  fq.push(7, 7, 7);
  fq.push(8, 8, 8);
  fq.push(10, 10, 10);

  for(int i = 1; i <= 10; i++){
    REQUIRE(fq.contains(i));
    x = fq.pop();
    REQUIRE(x.getValue() == i);
  }
  REQUIRE(fq.empty());
}

TEST_CASE( "test replaceif", "[frontier_queue]" ) {
  frontier_queue<int> fq;
  REQUIRE(fq.empty());

  State<int> x(0, 0, 0);

  fq.push(1, 1, 1);
  fq.push(2, 2, 2);
  fq.push(5, 5, 5);
  fq.push(6, 6, 6);
  fq.push(3, 3, 3);
  fq.push(9, 9, 9);
  fq.push(4, 4, 4);
  fq.push(7, 7, 7);
  fq.push(8, 8, 8);
  fq.push(10, 10, 10);

  for(int i = 1; i <= 10; i++){
    fq.replaceif(i, i+1);
  }
}
