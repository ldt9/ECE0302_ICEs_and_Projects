#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "linked_list.hpp"

template class LinkedList<int>;

TEST_CASE( "General Testing: constructor, insert and getEntry", "[LinkedList]" ) {
    //create a linked list
    LinkedList<int> a;

    //inserting numbers and testing their entry results
    for(int i = 1; i < 101; i++){
      int x = rand() % 100;
      //insert a random number
      REQUIRE(a.insert(i, x));
      //test to see if the number exists
      REQUIRE(a.getEntry(i) == x);
    }
}

TEST_CASE("copy assignment", "[LinkedList]"){
  //create a linked list
  LinkedList<int> a;

  //inserting numbers and testing their entry results
  for(int i = 1; i < 101; i++){
    int x = rand();
    //insert a random number
    REQUIRE(a.insert(i, x));
    //test to see if the number exists
    REQUIRE(a.getEntry(i) == x);
  }

  //create list to copy into
  LinkedList<int> b;
  //copy a into b
  b = a;

  //check that their entry results match
  for(int i = 1; i < 101; i++){
    REQUIRE(a.getEntry(i) == b.getEntry(i));
  }
}

TEST_CASE("copy constructor", "[LinkedList]"){
  //create a linked list
  LinkedList<int> a;

  //inserting numbers and testing their entry results
  for(int i = 1; i < 101; i++){
    int x = rand();
    //insert a random number
    REQUIRE(a.insert(i, x));
    //test to see if the number exists
    REQUIRE(a.getEntry(i) == x);
  }

  //create list to copy into
  LinkedList<int> b(a);

  //check that their entry results match
  for(int i = 1; i < 101; i++){
    REQUIRE(a.getEntry(i) == b.getEntry(i));
  }
}
TEST_CASE("swap", "[LinkedList]"){
  LinkedList<int> a;
  LinkedList<int> b;

  //inserting numbers and testing their entry results
  for(int i = 1; i < 51; i++){
    //insert 1 to 50
    REQUIRE(a.insert(i, i));
    //make sure the entry makes it
    REQUIRE(a.getEntry(i) == i);
    //std::cout << a.getEntry(i) << std::endl;
  }

  //inserting numbers and testing their entry results
  for(int i = 51; i < 101; i++){
    //insert 1 to 50
    REQUIRE(b.insert(i-50, i));
    //make sure the entry makes it
    REQUIRE(b.getEntry(i-50) == i);
    //std::cout << b.getEntry(i-50) << std::endl;
  }

  LinkedList<int> c;
  //sawp the 2 lists
  c.swap(a, b);

  for (int i = 1; i < 51; i++){
    REQUIRE(a.getEntry(i) == i+50);
    REQUIRE(b.getEntry(i) == i);
  }

}
TEST_CASE("isEmpty", "[LinkedList]"){
  //create a list
  LinkedList<int> a;
  //make sure initial lists are empty
  REQUIRE(a.isEmpty());
  //insert a value
  REQUIRE(a.insert(1,1));
  //make sure its not empty
  REQUIRE(!a.isEmpty());
  //clear the list
  a.clear();
  //make sure its empty
  REQUIRE(a.isEmpty());
  //insert another value
  REQUIRE(a.insert(1,1));
  //make sure its not empty
  REQUIRE(!a.isEmpty());
  //remove the value
  REQUIRE(a.remove(1));
  //make sure its empty
  REQUIRE(a.isEmpty());
}
TEST_CASE("getLength", "[LinkedList]"){
  //create a linked list
  LinkedList<int> a;
  //make sure base length is 0
  REQUIRE(a.getLength() == 0);

  //inserting numbers and testing their entry results
  for(int i = 1; i < 101; i++){
    int x = rand();
    //insert a random number
    REQUIRE(a.insert(i, x));
    //test to see if the number exists
    REQUIRE(a.getEntry(i) == x);
  }
  //make sure length is counter correctly
  REQUIRE(a.getLength() == 100);
}
TEST_CASE("remove", "[LinkedList]"){
  //create a linked list
  LinkedList<int> a;

  //inserting numbers and testing their entry results
  for(int i = 1; i < 101; i++){
    int x = rand();
    //insert a random number
    REQUIRE(a.insert(i, x));
    //test to see if the number exists
    REQUIRE(a.getEntry(i) == x);
  }

  //remove all the values from the list
  for(int i = 101; i > 1; i--){
    REQUIRE(a.remove(1));
  }

  //make sure list size is reset to 0
  REQUIRE(a.getLength() == 0);

}
TEST_CASE("clear", "[LinkedList]"){
  //create a list
  LinkedList<int> a;
  //make sure initial lists are empty
  REQUIRE(a.isEmpty());
  //insert a value
  REQUIRE(a.insert(1,1));
  //make sure its not empty
  REQUIRE(!a.isEmpty());
  //clear the list
  a.clear();
  //make sure its empty
  REQUIRE(a.isEmpty());
}
TEST_CASE("setEntry", "[LinkedList]"){
  //create a list
  LinkedList<int> a;
  //make sure initial lists are empty
  REQUIRE(a.isEmpty());
  //insert a value
  a.setEntry(1,1);
  //make sure its not empty
  REQUIRE(!a.isEmpty());
  //clear the list
  a.clear();
  //make sure its empty
  REQUIRE(a.isEmpty());
}
