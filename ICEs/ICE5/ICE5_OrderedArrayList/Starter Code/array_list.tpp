#include "array_list.hpp"

template <typename T>
ArrayList<T>::ArrayList() {
  //ptr to dynamic array
  arrayPtr = new T[101];

  //ptr to the start of the array, measures current size, starting at 1 per instructions
  size = 1;

  //to hold the maxsize of the array
  maxSize = 101;
}

template <typename T>
ArrayList<T>::~ArrayList() {

  //deallocate the memory and set the size back to 1;
  delete [] arrayPtr;
  clear();

}

template <typename T>
ArrayList<T>::ArrayList(const ArrayList & rhs){
  //ArrayList a;
  //ArrayList b(a);

  //create a new array of type T
  arrayPtr = new T[rhs.maxSize];

  //copy the size pointer to where rhs left off
  size = rhs.size;

  //set the maxSize the same
  maxSize = rhs.maxSize;

  //copy each element over to the new array
  for (int i = 1; i <= size; i++){
    std::size_t temp = rhs.arrayPtr[i];
    arrayPtr[i] = temp;
  }
}

template <typename T>
ArrayList<T> & ArrayList<T>::operator=(const ArrayList & rhs){
  //ArrayList a;
  //ArrayList b = a;

  //to make sure the memory is located before unnallocating
  if(arrayPtr != nullptr){delete [] arrayPtr;}

  //create a new array of type T
  arrayPtr = new T[rhs.maxSize];

  //copy the size pointer to where rhs left off
  size = rhs.size;

  //set the maxSize the same
  maxSize = rhs.maxSize;

  //copy each element over to the new array
  for (int i = 1; i <= size; i++){
    std::size_t temp = rhs.arrayPtr[i];
    arrayPtr[i] = temp;
  }

  return *this;
}

template <typename T>
bool ArrayList<T>::isEmpty() const{
  return (size == 1); //return true if the size pointer is at the beginning of the array
}

template <typename T>
std::size_t ArrayList<T>::getLength() const{
  return size-1; //return where the pointer is at in the array
}

template <typename T>
bool ArrayList<T>::insert(const T& item){
  //check to see if we are at the end of the array (size == maxSize), if not insert as usual
  int count = 0; //to count the element that item can exist between
  if (size != maxSize || size != 1){
    for (int i = 1; i <= size; i++){
      ++count; //loop through the size of the array and increase count when item is greater than arrayPtr[i]
      if (item < arrayPtr[i]) break;
    }
    //shift everything down to the right one element before inserting
    for(int i = size-1; i >= count; i--){
      arrayPtr[i+1] = arrayPtr[i]; //move all element to the right
    }
    //insert the item at arrayPtr[count]
    arrayPtr[count] = item;
    size++; //increase the size pointer because we successfully added an item
    return true;
  }

  /**EDGE CONDITIONS**/
  else if(size == 1){
    arrayPtr[1] = item;//set the item to the first element because the array is starting empty
    size++; //increase the size pointer because we successfully added an item
    return true;
  }
  //if this next case is true we're gonna have to make a new array thats of length maxSize+100
  //then feed the new array with the values of the original before inserting
  else if(size == maxSize){
    //new array to hold values
    T* temp = new T[maxSize + 100];
    //feed values into new array
    for (int i = 1; i < maxSize; i++){
      temp[i] = arrayPtr[i];
    }
    for (int i = 1; i <= size; i++){
      ++count; //loop through the size of the array and increase count when item is greater than arrayPtr[i]
      if (item < arrayPtr[i]) break;
    }
    //shift everything down to the right one element before inserting
    for(int i = size-1; i >= count; i--){
      arrayPtr[i+1] = arrayPtr[i]; //move all element to the right
    }
    //insert the item at arrayPtr[count]
    arrayPtr[count] = item;
    size++; //increase the size pointer because we successfully added an item
    return true;
  }
  //if none of these cases are true then the item is unable to be added
  return false;
  }

template <typename T>
bool ArrayList<T>::remove(std::size_t position){
  //if theres nothing to remove quit the method
  if(size == 1) return false;

  //if it happens to be outside the array, break the method again because thats an error
  if(position > size+1 || position >= maxSize || position < 1) return false;

  //then shift left the values below it
  for(std::size_t i = position; i < size; ++i){
    arrayPtr[i] = arrayPtr[i+1];
  }
  size--; //decrement the size pointer because we removed an item
  return true;
}

template <typename T>
void ArrayList<T>::clear() {
  size = 1; //set the size pointer back to the beginning
}

template <typename T>
T ArrayList<T>::getEntry(std::size_t position) const {
  //if its out of scope return -1 as an error value
  if(position < 1 || position >= size){return -1;}
  //else return what is at the position
  return arrayPtr[position];
}

template <typename T>
void ArrayList<T>::setEntry(std::size_t position, const T& newValue) {
  //if its out of scope maintain the value
  if(position < 1 || position >= maxSize){arrayPtr[position] = arrayPtr[position];}
  //replace existing value with newValue
  arrayPtr[position] = newValue;
}
