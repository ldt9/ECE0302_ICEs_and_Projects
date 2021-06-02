#include "bag.hpp"
#include <stdio.h>

// empty implementation                                                                                                     

template <typename T> Bag<T>::Bag() {
	size = 0; // any time size=0 is when the bag is reset since it adds incrementally from 0th position
}

template <typename T> Bag<T>::~Bag() {
	//delete bag, since memory isn't dynamically allocated we don't need anything here
}

template <typename T> std::size_t Bag<T>::getCurrentSize() const { return size; } //returns the size of the bag

template <typename T> bool Bag<T>::isEmpty() const { return size == 0 ; } //emptys the bag by setting size pointer to 0

template <typename T> bool Bag<T>::add(const T& entry) { 

	if (size >= 10) return false; 

	bag[size] = entry; //place the entry at current size
	size ++; //add new spot for next entry
	return true; //return true if successfully added

}

template <typename T> bool Bag<T>::remove(const T& entry) { 
if (size==0) return false; //everything was removed from the bag 

for (int i = 0; i < size; i++){ //look through the bag
	//std::cout<<entry<< std::endl; //testing entries
	if (entry == bag[i]) { //if any entry matches the entry we're looking for
		for (int j = i; j < size; j++){ //shift down one entry to replace it
			bag[j] = bag[j+1]; // ex) 1 2 3 4 5 --> 1 3 4 5 0
		}
		size--; //decrement the size to account for removed entry
		return true;
}

}
//std::cout << entry << std::endl; //testing entries
return false;

}

template <typename T> void Bag<T>::clear() {
	size = 0; //adds incrementally so retart from 0
}

template <typename T> std::size_t Bag<T>::getFrequencyOf(const T& entry) const { //how many times an entry occurs
	int count = 0;
	for (int i = 0; i < size; i++){
		if (bag[i] == entry){ //if the entry exists...
			count++; //increment the counter each time the entry is found
		}
	} 
	return count;
}

template <typename T> bool Bag<T>::contains(const T& entry) const { //loops through the bag and returns if the value exists in the bag
	for (int i = 0; i < size; i++){
		if (bag[i] == entry){ 
			return true; //if the entry exists return true
		}
	}
return false; //else returns false
}

