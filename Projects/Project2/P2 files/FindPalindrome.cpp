#include <string>
#include <vector>
#include <iostream>
#include <locale>
#include <algorithm>
#include "FindPalindrome.hpp"

using namespace std;

//------------------- HELPER FUNCTIONS -----------------------------------------

// non-class helper functions go here, should be declared as "static" so that
// their scope is limited

// helper function to convert string to lower case
static void convertToLowerCase(string & value)
{
	locale loc;
	for (int i=0; i<value.size(); i++) {
		value[i] = tolower(value[i],loc);
	}
}

//------------------- PRIVATE CLASS METHODS ------------------------------------

// private recursive function. Must use this signature!
void FindPalindrome::recursiveFindPalindromes(vector<string>
        candidateStringVector, vector<string> currentStringVector)
{
	//this will be used later for limits in for loops
	int rightLimit = currentStringVector.size();
	//first check to see if candidateStringVector is an empty vector
	if(candidateStringVector.empty() != false){
		//if its empty we want to see if the currentStringVector is a palindrome
		//if it is, we want to add it to the vector

		//these are the recursive function's initial conditions
		//create an empty string to copy the currentStringVector in to temporarily
		std::string temp;
		//create another empty string to contain the end result of the concatenation in lower case
		std::string tempLowerCase;
		for(int i = 0; i < rightLimit; i++){
			//copy the exact string into the temp variable
			tempExact = currentStringVector.at(i);

			//make it lowercase with given function
			convertToLowerCase(tempExact);

			//concatenate it to the end of the final result
			tempLowerCase += tempExact;
		}
		//now we want to test our concatenation to see if its actually a palindrome or not
		if(isPalindrome(tempLowerCase) != false){
			//if it is a palindrom we're gonna add it to the palinVect and increase the palinFreq
			//we want to use the original vector of strings not the concatenated version since the original will have spaces between the words
			palinVect.push_back(currentStringVector);
			palinFreq++;
			return 0;
		}
		return 0;
	}
	//make a loop through the length of the candidateStringVector (rightLimit)
	for(int i = 0; i < rightLimit; i++){
		//create temporary variables to be used in the recursion
		std::vector<std::string> tempCurrent(currentStringVector);
		std::vector<std::string> tempCandidate(candidateStringVector);

		//need to develop some cutTests before i can finish the recursion

	}

}

// private function to determine if a string is a palindrome (given, you
// may change this if you want)
bool FindPalindrome::isPalindrome(string currentString) const
{
	locale loc;
	// make sure that the string is lower case...
	convertToLowerCase(currentString);
	// see if the characters are symmetric...
	int stringLength = currentString.size();
	for (int i=0; i<stringLength/2; i++) {
		if (currentString[i] != currentString[stringLength - i - 1]) {
			return false;
		}
	}
	return true;
}

//------------------- PUBLIC CLASS METHODS -------------------------------------

FindPalindrome::FindPalindrome()
{
	//set the size of the vector and number of palindromes to 0
	vectSize = 0;
	palinFreq = 0;
}

FindPalindrome::~FindPalindrome()
{
	//no need to use delete here since we aren't using dynamic arrays
	//running clear() will do just fine
	clear();
}

int FindPalindrome::number() const
{
	// return how many palindromes are in existence
	return palinFreq;
}

void FindPalindrome::clear()
{
	//reset all integer variables
	vectSize = palinFreq = 0;

	//clear vector of sentences uing built in functions for vectors
	palinSent.clear();

	//clear vector of palindromes using built in functions for vectors
	palinVect.clear();
}

bool FindPalindrome::cutTest1(const vector<string> & stringVector)
{
	// TODO need to implement this...
	return false;
}

bool FindPalindrome::cutTest2(const vector<string> & stringVector1,
                              const vector<string> & stringVector2)
{
	// TODO need to implement this...
	return false;
}

bool FindPalindrome::add(const string & value)
{
	// TODO need to implement this...
	return false;
}

bool FindPalindrome::add(const vector<string> & stringVector)
{
	// TODO need to implement this...
	return false;
}

vector< vector<string> > FindPalindrome::toVector() const
{
	//the return type is a vector of vectors of type string, one vector is a palindrome defined as a vector of strings
	return palinVect;
}
