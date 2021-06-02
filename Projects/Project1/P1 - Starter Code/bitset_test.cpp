#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"

#include "bitset.hpp"

// THIS IS JUST AN EXAMPLE
// There should be at least one test per Bitset method

TEST_CASE( "Test bitset construction", "[bitset]" ) {

    Bitset b;  
    REQUIRE(b.size() == 8);
    REQUIRE(b.good());
    //testing if size changed
    REQUIRE(b.asString() == "00000000");

}

TEST_CASE( "Test bitset construction of certain size", "[bitset]" ) {

   Bitset b(16);
   REQUIRE(b.size() == 16);
   REQUIRE(b.good());
   //testing is size changed
   REQUIRE(b.asString() == "0000000000000000");

}

TEST_CASE( "Test bitset construction using a string as input", "[bitset]" ) {

   //test valid input
   Bitset b("0101");	
   REQUIRE(b.size() == 4);
   REQUIRE(b.good());
   //test valid string
   REQUIRE(b.asString() == "0101");
   //test invalid string
   REQUIRE(b.asString() != "1010");
   //test valid index
   REQUIRE(b.test(1) == true);
   //test invalid index
   REQUIRE(b.test(6) == false);

   //test invalid input
   Bitset a("Test");
   REQUIRE(!a.good());

}

TEST_CASE( "Test bitset construction using set, reset, and toggle", "[bitset]" ) {

    Bitset b;  
    REQUIRE(b.size() == 8);
    REQUIRE(b.good());
    REQUIRE(b.asString() == "00000000");
    //setting bits high
    b.set(1);
    b.set(5);
    //testing if they went high
    REQUIRE(b.asString() == "01000100");
    b.reset(1);
    b.toggle(5);
    //testing reset and toggle features
    REQUIRE(!b.test(1));
    REQUIRE(!b.test(5));
    //outputing blank string to show it worked
    REQUIRE(b.asString() == "00000000");
    REQUIRE(b.good());


}

