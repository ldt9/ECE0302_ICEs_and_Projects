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
		std::string tempExact;
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
			return;
		}
		return;
	}
	//make a loop through the length of the candidateStringVector (rightLimit)
	for(int i = 0; i < rightLimit; i++){
		//create temporary variables to be used in the recursion
		std::vector<std::string> tempCurrent(currentStringVector);
		std::vector<std::string> tempCandidate(candidateStringVector);

		//remove a word from the candidate vector each recursion to test each word
		tempCandidate.erase(find(tempCandidate.begin(), tempCandidate.end(), tempCandidate.at(i)));

		//add the word to currentStringVector at the end
		tempCurrent.push_back(candidateStringVector.at(i));

		//call cutTest2 as the last test and then run recursiveFindPalindromes
		if(!cutTest2(tempCurrent, tempCandidate)) break;
		recursiveFindPalindromes(tempCandidate, tempCurrent);
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
	//for a palindrome, at most one character may appear an odd number of times
	//create an array to hold frequency alphabet of the sentence
	int alphaFreq[26];

	//initialize all frequency values to zero
	for(int i = 0; i < 26; i++){
		alphaFreq[i] = 0;
	}

	//this will be used later for limits in for loops
	int rightLimit = stringVector.size();
	//these are the recursive function's initial conditions
	//create an empty string to copy the currentStringVector in to temporarily
	std::string tempExact;
	//create another empty string to contain the end result of the concatenation in lower case
	std::string tempLowerCase;
	//first check to see if candidateStringVector is an empty vector
	if(stringVector.empty() != false){
		//if its empty we want to make stringVector into a long string of character

		for(int i = 0; i < rightLimit; i++){
			//copy the exact string into the temp variable
			tempExact = stringVector.at(i);

			//make it lowercase with given function
			convertToLowerCase(tempExact);

			//concatenate it to the end of the final result
			tempLowerCase += tempExact;
		}
		//loop through the tempLowerCase string and count all of the letters
		//feed their frequencies into the alphaFreq array

		for(int i = 0; i < tempLowerCase.length(); i++){
			alphaFreq[tempLowerCase[i] - 97]++;
		}

		//apply modulus 2 to every value in the array, and if
		//there is more than one flag we return flase
		int freq;//to record frequency of odd number of characters
		for(int i = 0; i < 26; i++){
			if (alphaFreq[i]%2 != 0) freq++;
		}

		//if the length is odd and the number of repeated character is odd only once,
		//return true, else false
		if (tempLowerCase.size()%2 != 0){
			if (freq > 1 | freq == 0) return false;
			else return true;
		}
		//if the length is even, all the characters must appear an even amount of times
		else{
			if (freq == 0) return true;
			else return false;
		}
	}
	return false;
}

bool FindPalindrome::cutTest2(const vector<string> & stringVector1,
                              const vector<string> & stringVector2)
{
	//for a palindrome all of the letters in the left half of the sentences
	//must appear in the right half of the sentence
	//create an array to hold frequency alphabet of the left
	//and right halves of the sentence

	int alphaFreqLeft[26];
	int alphaFreqRight[26];

	//initialize all frequency values to zero
	for(int i = 0; i < 26; i++){
		alphaFreqLeft[i] = alphaFreqRight[i] = 0;
	}

	//this will be used later for limits in for loops
	int rightLimit1 = stringVector1.size();
	int rightLimit2 = stringVector2.size();
	//these are the recursive function's initial conditions
	//create an empty string to copy the currentStringVector in to temporarily
	std::string tempExact1;
	std::string tempExact2;
	//create another empty string to contain the end result of the concatenation in lower case
	std::string tempLowerCase1;
	std::string tempLowerCase2;
	//first check to see if stringVectors are an empty vector
	if(stringVector1.empty() != false && stringVector1.empty() != false ){
		//if its empty we want to make stringVector into a long string of character

		for(int i = 0; i < rightLimit1; i++){
			//copy the exact string into the temp variable
			tempExact1 = stringVector1.at(i);

			//make it lowercase with given function
			convertToLowerCase(tempExact1);

			//concatenate it to the end of the final result
			tempLowerCase1 += tempExact1;
		}
		for(int i = 0; i < rightLimit2; i++){
			//copy the exact string into the temp variable
			tempExact2 = stringVector2.at(i);

			//make it lowercase with given function
			convertToLowerCase(tempExact2);

			//concatenate it to the end of the final result
			tempLowerCase2 += tempExact2;
		}

		//compare size of each tempLowerCase and assign the smaller length string to leftString
		std::string leftString;
		std::string rightString;

		if(tempLowerCase1.length() < tempLowerCase2.length()){
			leftString = tempLowerCase1;
			rightString = tempLowerCase2;
		}
		else{
			leftString = tempLowerCase2;
			rightString = tempLowerCase1;
		}

		//now we check to see if all of the letters in the left string
		//have the same frequency as the right string
		//loop through the tempLowerCase string and count all of the letters
		//feed their frequencies into the alphaFreq array

		for(int i = 0; i < leftString.length(); i++){
			alphaFreqLeft[leftString[i] - 97]++;
		}
		for(int i = 0; i < rightString.length(); i++){
			alphaFreqRight[rightString[i] - 97]++;
		}

		//loop to see if the arrays match, if they do return true, else false
		//if there is ever a case where the leftFreq is less than the rightFreq return false immidiatley
		//otherwise keep checking
		for(int i = 0; i < 26; i++){
			if (alphaFreqLeft[i] < alphaFreqRight[i]) return false;
		}
	}
	return true;
}

//for individual word palindromes
bool FindPalindrome::add(const string & value)
{
	//how this add function works:
	//step1: create a temp string that is equal to value and set to lowercase
	//step2: run input validation to make sure it is only letters, return false if its anything but a letter
	//step3: push back value into vector of strings (palinSent), run cutTest1 on vector of strings
	//step4: clear vector of vector of strings (palinVect) and run recursiveFindPalindromes using a dummy vector

	//clear vector and count variables
	palinVect.clear();
	palinFreq = 0;

	//create temp string to hold lowercase version of value
	std::string tempLowerCase = value;
	convertToLowerCase(tempLowerCase);

	//loop through string to make sure there are no characters other than letters in string
	for(int i = 0; i < value.length(); i++){
		if(tempLowerCase[i] < 'a' || tempLowerCase[i] > 'z'){return false;}
	}

	//create new vector of strings to make palinSent to vectors
	std::vector <std::string> lowerCasePalinSent;
	for(int i = 0; i < palinSent.size(); i++){
		lowerCasePalinSent[i] = palinSent[i];
		convertToLowerCase(lowerCasePalinSent[i]);
	}

	//check to make sure value doesn't exist already in palinSent
	for(int i = 0; i < palinSent.size(); i++){
		if(tempLowerCase == lowerCasePalinSent[i]){return false;}
	}

	//push back value into palinSent
	palinSent.push_back(value);

	//run cutTest1 on this vector of strings
	//should break the program if cutTest1 were to fail
	if(cutTest1(palinSent)){
		//clear the vector of vector of strings (palinVect)
		//just to make sure nothing is in there from previous recursions
		palinVect.clear();
		//recursiveFindPalindromes(vector of strings to fill (working vector), vector to strings in your palinSent)
		std::vector<std::string>dummyVect;
		recursiveFindPalindromes(dummyVect, palinSent);//*** MIGHT NEED TO SWITCH VECTORS??
	}
	return true; //since its successfully added
}

//for sentence palindromes or a bunch of words that are themselves palindromes
bool FindPalindrome::add(const vector<string> & stringVector)
{
	//this vector has a similar response to the previous function except its a vector
	//of strings and we need to test each string to see if it's a palindrome or note
	//NOTE 	CANNOT USE PREVIOUS FUNCTION RECURSIVLEY BECAUSE THAT'D BE TOO EASY...

	//clear vector and count variables
	palinVect.clear();
	palinFreq = 0;

	//create temp string to hold lowercase version of value
	std::string tempLowerCase;
	//create a string to hold the exact value of stringVector as each idex of the vector
	std::string tempExact;

	//loop through each word in the vector to check if there are any unacceptable words
	for(int i = 0; i < stringVector.size(); i++){
		//throw the current word into the tempLowerCase string
		//so we can convert the word to lowercase
		tempLowerCase = stringVector.as(i);
		convertToLowerCase(tempLowerCase);

		//check to see if there are any non ascii alphabet characters
		for(int i = 0; i < tempLowerCase.length(); i++){
			if(tempLowerCase[i] < 'a' || tempLowerCase[i] > 'z'){return false;}
		}
	}

	//create new vector of strings to make palinSent to vectors
	std::vector <std::string> lowerCasePalinSent;
	for(int i = 0; i < palinSent.size(); i++){
		lowerCasePalinSent[i] = palinSent[i];
		convertToLowerCase(lowerCasePalinSent[i]);
	}

	//check to make sure value doesn't exist already in palinSent
	for(int i = 0; i < palinSent.size(); i++){
		if(tempLowerCase == lowerCasePalinSent[i]){return false;}
	}

	//after filtering out all non allowables, we will create a dummyVect and
	//run recursiveFindPalindromes
	std::vector <std::string> dummyVect;
	//test the vector using cutTest1 as before
	if(cutTest1){
		//clear the vector of vector of strings (palinVect)
		//just to make sure nothing is in there from previous recursions
		palinVect.clear();
		//recursiveFindPalindromes(vector of strings to fill (working vector), vector to strings in your palinSent)
		std::vector<std::string>dummyVect;
		recursiveFindPalindromes(dummyVect, palinSent);//*** MIGHT NEED TO SWITCH VECTORS??
	}
	return true; //since its successfully added

}

vector< vector<string> > FindPalindrome::toVector() const
{
	//the return type is a vector of vectors of type string, one vector is a palindrome defined as a vector of strings
	return palinVect;
}
