#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "array_list.hpp"

//force class expansion
template class ArrayList<int>;

TEST_CASE("General tests for Add, Remove, isEmpty and getLength methods", "[ArrayList]"){
  ArrayList<int> b;

  //testing adding a number and removing it
  REQUIRE(b.insert(1));
  REQUIRE(!b.isEmpty());
  REQUIRE(b.getLength() == 1);
  REQUIRE(b.remove(1));
  REQUIRE(b.isEmpty());
  REQUIRE(b.getLength() == 0);
}

TEST_CASE("Clear method and getLength", "[ArrayList]"){
  ArrayList<int> b;

  //filling an array with values
  for (int i = 1; i < 6; i++){
    REQUIRE(b.insert(i));
    //std::cout << i << std::endl;
  }
  REQUIRE(b.getLength() == 5);

  //testing clear functionality and making sure other methods are affected
  b.clear();
  REQUIRE(b.getLength() == 0);
  REQUIRE(b.isEmpty());
}

TEST_CASE("insert random values then getEntry to see if in order", "[ArrayList]"){
  ArrayList<int> b;

  //filling an array with values
  REQUIRE(b.insert(1));
  REQUIRE(b.insert(5));
  REQUIRE(b.insert(2));
  REQUIRE(b.insert(3));
  REQUIRE(b.insert(8));
  REQUIRE(b.insert(4));
  REQUIRE(b.insert(2));
  REQUIRE(b.insert(6));
  REQUIRE(b.insert(36));
  REQUIRE(b.insert(12));
  REQUIRE(b.insert(5));

  //make sure length is correct
  REQUIRE(b.getLength() == 11);

  //see if the order of values is correct (added a zero to the front here since we are indexing by 1's and it likes a value here)
  int x[12] = {0, 1, 2, 2, 3, 4, 5, 5, 6, 8, 12, 36};
  for (int i = 1; i < 12; i++){
    REQUIRE(b.getEntry(i) == x[i]);
  }

  //testing clear functionality and making sure other methods are affected
  b.clear();
  REQUIRE(b.getLength() == 0);
  REQUIRE(b.isEmpty());
}
TEST_CASE("remove method in the beginning/middle/end of an array", "[ArrayList]"){
  ArrayList<int> c;

  //filling an array with 10 numbers
  for (int i = 1; i < 11; i++){
    REQUIRE(c.insert(i));
  }

  //testing remove of the first, middle and last element
  REQUIRE(c.remove(1));
  REQUIRE(c.remove(4));
  REQUIRE(c.remove(6));
  //testing 2 elements out of scope
  REQUIRE(!c.remove(15));
  REQUIRE(!c.remove(-3));

}

TEST_CASE("copy constructor and assignment tests, including getEntry and setEntry", "[ArrayList]"){
  ArrayList<int> b;
  ArrayList<int> a;

  //filling an array with 10 numbers
  for (int i = 1; i < 11; i++){
    REQUIRE(b.insert(i));
  }

  //set lists a and c equal to eachother using both copy methods
  a = b;
  ArrayList<int> c(b);

  //getEntry tests
  REQUIRE(a.getEntry(5) == b.getEntry(5));
  REQUIRE(b.getEntry(5) == c.getEntry(5));
  REQUIRE(a.getEntry(5) == c.getEntry(5));
  //returns -1 if out of scope
  REQUIRE(a.getEntry(30) == -1);
  REQUIRE(b.getEntry(-7) == -1);

  //testing remove of the first, middle and last element
  REQUIRE(b.remove(1));
  REQUIRE(b.remove(4));
  REQUIRE(b.remove(6));
  //testing 2 elements out of scope
  REQUIRE(!b.remove(15));
  REQUIRE(!b.remove(-3));

  //testing remove of the first, middle and last element
  REQUIRE(c.remove(1));
  REQUIRE(c.remove(5));
  REQUIRE(c.remove(6));
  //testing 2 elements out of scope
  REQUIRE(!c.remove(15));
  REQUIRE(!c.remove(-3));

  //setEntry tests
  a.setEntry(5, 6);
  b.setEntry(5, 7);
  c.setEntry(5, 9);
  REQUIRE(a.getEntry(5) == 6);
  REQUIRE(b.getEntry(5) == 7);
  REQUIRE(c.getEntry(5) == 9);
  //try to set out of scope
  a.setEntry(-5, 0);
  REQUIRE(a.getEntry(-5) == -1);
}
