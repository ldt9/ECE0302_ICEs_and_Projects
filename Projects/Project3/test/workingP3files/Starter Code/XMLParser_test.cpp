#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include <iostream>
#include "catch.hpp"
#include "XMLParser.cpp"

using namespace std;

// TODO Implement tests of your Stack class and XMLParser class here

TEST_CASE( "Test Bag add", "[XMLParser]" )
{
	   INFO("Hint: testing Bag add()");
		// Create a Bag to hold ints
		Bag<int> intBag;
		int testSize = 2;
		int bagSize;
		bool success;
		for (int i=0; i<testSize; i++) {
			success = intBag.add(i);
			REQUIRE(success);
			bagSize = intBag.size();
			success = (bagSize == (i+1));
			REQUIRE(success);
		}
}

TEST_CASE( "Test Stack push, peek, pop", "[XMLParser]" )
{
	   INFO("Hint: testing Stack push()");
		// Create a Stack to hold ints
		Stack<int> intStack;
		int testSize = 3;
		int stackSize;
		bool success;
		for (int i=0; i<testSize; i++) {
			//testing values can be pushed onto the stack
			success = intStack.push(i);
			REQUIRE(success);
			//testing the size increases
			stackSize = intStack.size();
			success = (stackSize == (i+1));
			REQUIRE(success);
			//testing that the value pushed can be peeked at
			success = (intStack.peek() == i);
			REQUIRE(success);
		}
		//testing that items can be popped
		for (int i=0; i<testSize; i++) {
			intStack.pop();
		}
		//and that the size will decrement each time
		success = (intStack.size()==0);
		REQUIRE(success);

}

TEST_CASE( "Test XMLParser tokenizeInputString for DECLARATION, EMPTY_TAG, START_TAG, END_TAG", "[XMLParser]" )
{
	   INFO("Hint: tokenize single element test of XMLParse");
		// Create an instance of XMLParse
		XMLParser myXMLParser;
//		string testString = "<test>stuff</test>";
		string testString = "<?DEC abc?><start><empty/></start><start2></start2>";
		bool success;
		success = myXMLParser.tokenizeInputString(testString);
		REQUIRE(success);
		myXMLParser.clear();
}

TEST_CASE( "Test XMLParser tokenizeInputString for CONTENT", "[XMLParser]" )
{
	   INFO("Hint: tokenize single element test of XMLParse");
		// Create an instance of XMLParse
		XMLParser myXMLParser;
		string testString = "<?Ultimate CONTENT Test?><test> how much can I add here before this breaks? HAHAHAHA it will never break HAHAHAHAHA I love coding lolololololol. </test><empty/>";
//		string testString = "<?DEC?><start></start></empty>";
		bool success;
		success = myXMLParser.tokenizeInputString(testString);
		REQUIRE(success);
		myXMLParser.clear();
}

TEST_CASE( "Test XMLParser tokenizeInputString for removing attributes", "[XMLParser]" )
{
	   INFO("Hint: tokenize single element test of XMLParse");
		// Create an instance of XMLParse
		XMLParser myXMLParser;
		string testString = "<?dec user = 'yeee' remove this too yadda yadda yadda     ?><start>This is some content because why not</start><emptytag/>";
//		string testString = "<?DEC?><start></start></empty>";
		bool success;
		success = myXMLParser.tokenizeInputString(testString);
		REQUIRE(success);
		REQUIRE(myXMLParser.parseTokenizedInput());

		REQUIRE(myXMLParser.containsElementName("start"));
		REQUIRE(myXMLParser.frequencyElementName("start") == 1);

		myXMLParser.clear();
}

TEST_CASE( "Test XMLParser for edge cases", "[XMLParser]" ){
	INFO("Hint: testing how spaces are treated");
 // Create an instance of XMLParse
 XMLParser myXMLParser;
 string testString = "<?dec user = 'yeee' remove this too yadda yadda yadda     ?><start>This is some content because why not</start><emptytag/>  ";
//		string testString = "<?DEC?><start></start></empty>";
 bool success;
 success = myXMLParser.tokenizeInputString(testString);
 REQUIRE(success);
 REQUIRE(myXMLParser.parseTokenizedInput());

 myXMLParser.clear();
}

TEST_CASE( "Test XMLParser for failing parse", "[XMLParser]" ){
	INFO("Hint: testing how spaces are treated");
 // Create an instance of XMLParse
 XMLParser myXMLParser;
 string testString = "<start><start2></start>";
//		string testString = "<?DEC?><start></start></empty>";
 bool success;
 success = myXMLParser.tokenizeInputString(testString);
 REQUIRE(success);
 REQUIRE(!myXMLParser.parseTokenizedInput());

 myXMLParser.clear();
}

TEST_CASE( "Test XMLParser for failing tokenize", "[XMLParser]" ){
	INFO("Hint: testing how spaces are treated");
 // Create an instance of XMLParse
 XMLParser myXMLParser;
 string testString = "<start><'aw;eihfdsa;250987;lk4rt>";
//		string testString = "<?DEC?><start></start></empty>";
 bool success;
 success = myXMLParser.tokenizeInputString(testString);
 REQUIRE(!success);

 myXMLParser.clear();
}
