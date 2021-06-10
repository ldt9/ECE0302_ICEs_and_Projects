#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"
#include "FindPalindrome.hpp"

// There should be at least one test per FindPalindrome method

TEST_CASE( "Test FindPalindrome add a non-allowable word", "[FindPalindrome]" )
{
	INFO("Hint: add a single non-allowable word");
	FindPalindrome b;
	REQUIRE(!b.add("kayak1"));
}

TEST_CASE( "add a single palindrom string", "[FindPalindrome]" )
{
	//create a palindrome object
	FindPalindrome a;
	//create some test strings
	std::string testString1 = "b";
	std::string testString2 = "bb";
	std::string testString3 = "bbb";
	std::string testString4 = "bbbb";

	//see which ones add and which ones don't
	REQUIRE(a.add(testString1) == true);
	REQUIRE(a.add(testString2) == true);
	REQUIRE(a.add(testString3) == true);
	REQUIRE(a.add(testString4) == true);
	/**
	//testing output functions: number of palindomes, clear, and toVector
	FindPalindrome f;
	std::string newString("a");
	for (int i=0; i<3; i++) {
		if(f.add(newString)) {
			newString += "a";
		}
	}
	*/
	//number of palindromes should = !N or 24 in this case (!4 = 24 = 4 * 3 * 2 * 1)
	REQUIRE(a.number() == 24);

	//std::cout << "\nThe sentence palindromes are:" << std::endl;
	std::vector<std::vector<std::string>> vectorList = a.toVector();

	/**
	for (int i=0; i<vectorList.size(); i++) {
		for (int j=0; j<vectorList[i].size(); j++) {
			std::cout << vectorList[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	*/
	
	//test that the number of palindromes is correct and matches a.number()
	REQUIRE(vectorList.size() == 24);

	//testing clear
	a.clear();
	REQUIRE(a.number() == 0);
}

TEST_CASE( "add a vector of strings", "[FindPalindrome]" )
{
	//create a palindome object
	FindPalindrome a;
	//create a vector of words
	std::vector <std::string> testVector;
	testVector.push_back("Race");
	testVector.push_back("car");
	REQUIRE(a.add(testVector) == true);
}

TEST_CASE("cut test 1", "[FindPalindrome]"){
	//create a palindome object
	FindPalindrome a;
	//create a vector of words
	std::vector <std::string> testVector;
	testVector.push_back("Race");
	testVector.push_back("car");
	REQUIRE(a.cutTest1(testVector));

	//create a vector of words that are not palindromes
	std::vector <std::string> badVector;
	badVector.push_back("seede");
	REQUIRE(!a.cutTest1(badVector));
}
TEST_CASE("cut test 2", "[FindPalindrome]"){
	//create a palindome object
	FindPalindrome a;
	//create a vector of words
	std::vector <std::string> testVector1;
	std::vector <std::string> testVector2;
	testVector1.push_back("Race");
	testVector2.push_back("car");
	REQUIRE(a.cutTest2(testVector1, testVector2));

	//clears previous entries
	a.clear();

	//create a vector of words that are not palindromes
	std::vector <std::string> badVector1;
	std::vector <std::string> badVector2;
	badVector1.push_back("seede");
	badVector2.push_back("a");
	REQUIRE(!a.cutTest2(badVector2, badVector1));
}
/**
TEST_CASE("isPalindrome", "[FindPalindrome]"){
	std::string temp = "Racecar";
	FindPalindrome a;
	REQUIRE(a.isPalindrome(temp));
}
*/
