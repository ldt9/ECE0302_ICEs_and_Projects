// Project 3 -- XML Parsing Project

/** XML parsing class implementation.
    @file XMLParser.cpp */

#include <string>
#include <assert.h>
#include "XMLParser.hpp"

// TODO: Implement the constructor here
XMLParser::XMLParser()
{
	//instantiate dynamic memory
	elementNameBag = new Bag<std:: string>;
	parseStack = new Stack<std:: string>;
}  // end default constructor

// TODO: Implement the destructor here
XMLParser::~XMLParser()
{
	Tokenize, Parse = false; //set bool flags low
	clear(); //run clear command
}  // end destructor

// TODO: Implement the tokenizeInputString method
bool XMLParser::tokenizeInputString(const std::string &inputString)	{
		//instantiate a TokenStruct instance
		TokenStruct newStruct;
		//create string variables to hold names to be pushed
		string tempTag, tagName, tagType = "";
		//create a variable for the position of the cursor
		int pos = 0;
		//create a variable to say if the tag needs to be tested
		bool test = false;

		//have the length of the string and the string itself outputted for testing
		std:: cout << "The string is: " << inputString << std:: endl << "Its length is: " << inputString.size() << std::endl;

		//loop from the start to the end of the string
		while(pos < inputString.size()-1){
			//empty the strings just to be sure
			tempTag, tagName, tagType = "";

			//check for the beginning of a tag
			if(inputString[pos] == '<'){
				//use a nested while loop to check for validity of different tags
				while(inputString[pos] != '>' && inputString[pos+1] != '>'){
					//feed the values between the < and > into the temp string
					tempTag += inputString[pos+1];
					pos++; //increment the cursor ptr
				}
				//once the while loops break, see what came out of it
				std:: cout << "Complete String Input: " << inputString << std:: endl;
				std:: cout << "this is the potential tag: " << tempTag << std:: endl;
				//now that we have whats inside the < and > saved we can use the loop hang to our advantage

				//END_TAG starts with a '/'
				if(tempTag[0] == '/'){
					//clear the tag name
					//tagName = "";
					tagType = "END_TAG";
					//next we want to test content at the end
					test = true;
					for(int j = 1; j < tempTag.size(); j++){
						tagName += tempTag[j]; // basically we're removing the '/' infront of the tag name
					}
					//testing correct output
					std::cout << "tagName: " << tagName << std:: endl;
				}

				//EMPTY_TAG ends with a '/'
				else if(tempTag[tempTag.size() - 1] == '/'){
					//clear the tag name
					//tagName = "";
					tagType = "EMPTY_TAG";
					//next we want to test content at the end
					test = true;
					for(int j = 0; j < tempTag.size()-1; j++){
						tagName += tempTag[j]; // basically we're removing the '/' at the end of the tag name
					}
					//testing correct output
					std::cout << "tagName: " << tagName << std:: endl;
				}

				//DECLARATION begins and ends witha '?'
				else if(tempTag[0] == '?' && tempTag[tempTag.size() - 1] == '?'){
					//clear the tag name
					//tagName = "";
					tagType = "DECLARATION";
					test = false; // because there will be no content
					for (int j = 1;  j < tempTag.size() - 1; j++){
						tagName += tempTag[j]; // copies the shortend string to tagName
					}
					//testing for correct output
					std::cout << "tagName: " << tagName << std::endl;
				}

				//START_TAG only has < and >
				else{
					//clear the tag name
					//tagName = "";
					tagType = "START_TAG";
					test = true; //want to test for content at end
					tagName = tempTag; //nothing to remove if start tag
					int j = 0;

					//testing for correct output
					std::cout << "tagName: " << tagName << std::endl;
				}
				//update the Token name and type
				if(tagType == "END_TAG")
				{
					std::cout << "Token is EndTag" << std:: endl << std:: endl;
					newStruct.tokenType = END_TAG;
					break; //break here causes errors after finding content if i dont
				}
				else if (tagType == "START_TAG")
				{
					std::cout << "Token is StartTag" << std:: endl;
					newStruct.tokenType = START_TAG;
				}
				else if(tagType == "EMPTY_TAG")
				{
					std::cout << "Token is EmptyTag" << std:: endl;
					newStruct.tokenType = EMPTY_TAG;
				}
				else if (tagType == "DECLARATION")
				{
					std::cout << "Token is Declaration" << std:: endl;
					newStruct.tokenType = DECLARATION;
				}
				//also need to send the name of the tag
				newStruct.tokenString = tagName;

				//need to make sure tag passes tests
				if(test == true){
					//NEED TO MAKE SURE THE TAG DOESNT START WITH ILLEGAL CHARACTERS
					if (tagName[0]== ' ' || tagName[0]== '-' || tagName[0] == '.')
					{
						//invalid tag name, return false
						return false;
					}
					//Switch a case statment on numbers that it cant start with
					switch (tagName[0])
					{
						case '0':
							return false;
							break;
						case '1':
							return false;
							break;
						case '2':
							return false;
							break;
						case '3':
							return false;
							break;
						case '4':
							return false;
							break;
						case '5':
							return false;
							break;
						case '6':
							return false;
							break;
						case '7':
							return false;
							break;
						case '8':
							return false;
							break;
						case '9':
							return false;
							break;
						default:
							//do nothing
							//std:: cout << "there are no illegal characters at first index" << std::endl;
							break;
					}

					//need to make sure the tag names don't include non letters
					for(int i = 0; i < tagName.size(); i++){
						//make a char array to temporary hold each element at each index
						char inx = tagName[i];

						//switch though the case statement
						switch(inx){
							case '!' :
								std:: cout << "ILLEGAL!!" << std::endl;
								return false;
								break;
							case '"' :
								std:: cout << "ILLEGAL!!" << std::endl;
								return false;
								break;
							case '#' :
								std:: cout << "ILLEGAL!!" << std::endl;
								return false;
								break;
							case '$' :
								std:: cout << "ILLEGAL!!" << std::endl;
								return false;
								break;
							case '%' :
								std:: cout << "ILLEGAL!!" << std::endl;
								return false;
								break;
							case '&' :
								std:: cout << "ILLEGAL!!" << std::endl;
								return false;
								break;
							case '\'' :
								std:: cout << "ILLEGAL!!" << std::endl;
								return false;
								break;
							case '(' :
								std:: cout << "ILLEGAL!!" << std::endl;
								return false;
								break;
							case ')' :
								std:: cout << "ILLEGAL!!" << std::endl;
								return false;
								break;
							case '*' :
								std:: cout << "ILLEGAL!!" << std::endl;
								return false;
								break;
							case '+' :
								std:: cout << "ILLEGAL!!" << std::endl;
								return false;
								break;
							case ',' :
								std:: cout << "ILLEGAL!!" << std::endl;
								return false;
								break;
							case '/' :
								std:: cout << "ILLEGAL!!" << std::endl;
								return false;
								break;
							case ';' :
								std:: cout << "ILLEGAL!!" << std::endl;
								return false;
								break;
							case '<' :
								std:: cout << "ILLEGAL!!" << std::endl;
								return false;
								break;
							case '=' :
								std:: cout << "ILLEGAL!!" << std::endl;
								return false;
								break;
							case '>' :
								std:: cout << "ILLEGAL!!" << std::endl;
								return false;
								break;
							case '?' :
								std:: cout << "ILLEGAL!!" << std::endl;
								return false;
								break;
							case '@' :
								std:: cout << "ILLEGAL!!" << std::endl;
								return false;
								break;
							case '[' :
								std:: cout << "ILLEGAL!!" << std::endl;
								return false;
								break;
							case '\\' :
								std:: cout << "ILLEGAL!!" << std::endl;
								return false;
								break;
							case ']' :
								std:: cout << "ILLEGAL!!" << std::endl;
								return false;
								break;
							case '^' :
								std:: cout << "ILLEGAL!!" << std::endl;
								return false;
								break;
							case '`' :
								std:: cout << "ILLEGAL!!" << std::endl;
								return false;
								break;
							case '{' :
								std:: cout << "ILLEGAL!!" << std::endl;
								return false;
								break;
							case '|' :
								std:: cout << "ILLEGAL!!" << std::endl;
								return false;
								break;
							case '}' :
								std:: cout << "ILLEGAL!!" << std::endl;
								return false;
								break;
							case '~' :
								std:: cout << "ILLEGAL!!" << std::endl;
								return false;
								break;
							case ' ' :
								std:: cout << "ILLEGAL!!" << std::endl;
								return false;
								break;
							default:
								//do nothing
								//std:: cout << "there are no illegal characters throughout" << std::endl;
								break;
						}
					}
				}
				//need to update the vector and tags
				tokenizedInputVector.push_back(newStruct);
				//tell the terminal what happened
				std:: cout << "successful push..." << std:: endl;
			}

			pos++;
			//clear the tag name
			tagName = "";

			//after tags, we know our cursor it outside the tag and it should be content after
			if (inputString[pos+1] != tempTag[pos]){
				//before we reach the next tag we want to collect whats between it
				while (inputString[pos+1] != '<'){
					tagName += inputString[pos+1]; //load it into the tag name string
					pos++;//increment the cursor
				}
				//testing correct output
				std:: cout << "tagName: " << tagName << std:: endl;
				//make sure tag is not completley white space
				int whiteSpace = 0;
				for (int i = 0; i < tagName.size(); i++){
					if (isspace(tagName[i])){ //if theres a space increment`
						whiteSpace++;
					}
				}
				if(whiteSpace < tagName.size()){
					//if its not completley white space we can make it a CONTENT tag
					newStruct.tokenString = tagName;
					std::cout << "Token is CONTENT" << std:: endl;
					newStruct.tokenType = CONTENT;

					//push back into the input vector
					tokenizedInputVector.push_back(newStruct);
					std:: cout << "successful push" << std::endl;
				}
			}
			//END OF ALL ITERATIONS
			tempTag = ""; //clear temp
			tagName = ""; //clear tag name
			pos++;
		}
	Tokenize = true;
	return true;
	//return false;
}  // end

// TODO: Implement a helper function to delete attributes from a START_TAG
// or EMPTY_TAG string (you can change this...)
static std::string deleteAttributes(std::string input)
{
	return input;
}

// TODO: Implement the parseTokenizedInput method here
bool XMLParser::parseTokenizedInput()
{
	return false;
}

// TODO: Implement the clear method here
void XMLParser::clear()
{
}

vector<TokenStruct> XMLParser::returnTokenizedInput() const
{
	return tokenizedInputVector;
}

// TODO: Implement the containsElementName method
bool XMLParser::containsElementName(const std::string &inputString) const
{
	return false;
}

// TODO: Implement the frequencyElementName method
int XMLParser::frequencyElementName(const std::string &inputString) const
{
	return -1;
}
