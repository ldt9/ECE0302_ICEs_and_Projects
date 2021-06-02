#include "bitset.hpp"
#include <iostream>
#include <stdio.h>
#include <inttypes.h>
#include <string>


  // sets default valid bitset of width 8, with all bits set to 0
  Bitset::Bitset(){

  	//sets bitset width to 8 integers long
  	width = 8;

  	//sets dynamically allocated memory to bitset
  	bitset = new char[8];

  	//fills each character with '0'
  	for (int i = 0; i < width; i++){
  		bitset[i] = '0';
  	}

  	//set validity to true
  	validity = 1;

  }

  // construction of a valid bitset of width "size", where "size" is of type intmax_t, with all bits set to 0, bitset is invalid if "size" <= 0
  Bitset::Bitset(intmax_t size){

  	//sets bitset width to 8 integers long
  	width = size;

  	//sets dynamically allocated memory to bitset
  	bitset = new char[size];

  	//fills each character with '0'
  	for (int i = 0; i < width; i++){
  		bitset[i] = '0';
  	}

  	//set validity to true if size > 0
  	if (size > 0){
  		validity = 1;
  	}
  	else{
  		validity = 0;
  	}
  }

  // bitset initialized with a string in the form "0001000" if the string contains any character other than 0 or 1, bitset is invalid
  Bitset::Bitset(const std::string & value){
  	width = value.length(); //gets length of string "value"
  	//std::cout << width << std::endl;
  	validity = 1; //sets validity to 1 before ran through test cases

  	bitset = new char[width]; //creates new array of memory to length of value

  	for (int i = 0; i < width; i++){//increments through string to check for 0 or 1
  		//std::cout << value[i] << std::endl;
		if (value[i] != '1' && value[i] != '0'){
  			 validity = 0;
  			 break;
  		 }
  		bitset[i] = value[i]; //sets each character to each character of value
  		//std::cout << bitset[i] << std::endl;
  	}
  }

  // deconstructor to delete the memory inside a bitset
  Bitset::~Bitset(){
  	//delete bitset; //deletes pointer memory
  	delete[] bitset; //deletes each array value, frees array
  }

  // returns the size of the bitset
  intmax_t Bitset::size() const{
  	return width;
  }

  // determines if the bitset is valid, can be used in constructors to test if size <= 0 or the string contains characters other than 1 or 0, return true if both condiitons fail
  bool Bitset::good() const{
  	//std::cout << validity << std::endl;
  	return validity;
  }

  // set the bit to 1 at a specific index, if index not between 0 to (size-1), bitset becomes invalid
  void Bitset::set(intmax_t index){
  	if (index < 0 || index >= width){
  		validity = 0;
  	}
  	bitset[index] = '1';
  }

  // set the bit to 0 at a specific index, if index not between 0 to (size-1), bitset becomes invalid
  void Bitset::reset(intmax_t index){
  	if (index < 0 || index >= width){
  		validity = 0;
  	}
  	bitset[index] = '0';
  }

  // toggle the bit at a specific index, if index not between 0 to (size-1), bitset becomes invalid
  void Bitset::toggle(intmax_t index){
  	if (index < 0 || index >= width){
  		validity = 0;
  	}
  	if (bitset[index] == '0') {bitset[index] = '1';}
  	else{ bitset[index] = '0';}
  }

  // test the bit at a specific index, if index not between 0 to (size-1), bitset becomes invalid, if 1 return true, if 0 return false
  bool Bitset::test(intmax_t index){
  	if (index < 0 || index >= width){
  		validity = 0;
  	}
  	if (bitset[index] == '1') {return true;}
  	else{ return false;}
  }

  // return the bitset as a string of 0 or 1, MSB to the left, LSB to the right
  std::string Bitset::asString() const{
  	std::string temp="";

  	for(int i = 0; i < width; i++){
  		temp += bitset[i];
  	}

  	return temp;
  }