#include "dynamic_bag.hpp"

template<typename T>
DynamicBag<T>::DynamicBag() {
  //array with starter dimension of 100
  anArray = new T[100];

  //setting the pointer to the last element in the array
  last = 100;

  //setting pointer to zero so it starts at beginning of array
  size = 0;
}

template<typename T>
DynamicBag<T>::DynamicBag(const DynamicBag& x){
  //allocate an array
  anArray = new T[x.last];

  //copying all elements to new bag
  for (int i = 0; i < x.getCurrentSize(); i++){
    anArray[i] = x.anArray[i];
  }

  //setting the size ptr to the same element that x left off on
  size = x.getCurrentSize();

  //setting the last ptr to the same length of the x Array
  last = x.last;
}

template<typename T>
DynamicBag<T>::~DynamicBag(){
  //deletiing array contents and resetting ptrs
  delete [] anArray;
  size = 0;
  last = 0;
}

template<typename T>
DynamicBag<T>& DynamicBag<T>::operator=(DynamicBag<T>& x)
{
  //reset the memory in anArray
  delete [] anArray;

  //allocate an array to a new size
  anArray = new T[x.last];

  //copying all elements to new bag
  for (int i = 0; i < x.getCurrentSize(); i++){
    anArray[i] = x.anArray[i];
  }

  //setting the size ptr to the same element that x left off on
  size = x.getCurrentSize();
  last = x.last;

  // so you can make multiple assertions in a row (ie a = b = c)
  return *this;
}

template<typename T>
bool DynamicBag<T>::add(const T& item)
{
  //if the bag reaches the max size create a new array of size+100 and copy all the original elements into the new array
  if(size >= last){
    //new array to hold values
    T* temp = new T[size + 100];
    //feed values into new array
    for (int i = 0; i < size; i++){
      temp[i] = anArray[i];
    }

    //unallocate memory in anArray so no mem leaks
    delete [] anArray;

    //use compy assignment to replace elements
    anArray = temp;

    //then add the element onto the end and increment the size pointer
    anArray[size] = item;
    ++size;
    last += 100;
    return true;
  }
  //if there is room in the area, act as usual
  else {
    anArray[size] = item;
    ++size;
    return true;
  }
  //is there a false case?? nah
}

template<typename T>
bool DynamicBag<T>::remove(const T& item)
{
  //if theres nothing to remove quit the method
  if(size == 0) return false;

  //increment through the array until the element is found and save the index
  std::size_t idx = 0;
  for(std::size_t i = 0; i < size; ++i){
    if(anArray[i] == item) break;
    ++idx;
  }

  //if it happens to be outside the array, break the method again because thats an error
  if(idx == size) return false;

  //decrement the size ptr to act as a removal of an element and return true
  --size;
  //then shift up the values below it
  for(std::size_t i = idx; i < size; ++i){
    anArray[i] = anArray[i+1];
  }
  return true;
}

template<typename T>
bool DynamicBag<T>::isEmpty() const
{
  //return true if the size = 0
  return  (size == 0);
}

template<typename T>
std::size_t DynamicBag<T>::getCurrentSize() const
{
  //return size variable
  return size;
}

template<typename T>
bool DynamicBag<T>::contains(const T& item) const
{
  //return if the frequency is true or != 0
  return (getFrequencyOf(item) != 0);
}

template<typename T>
void DynamicBag<T>::clear(){ size = 0;}

template<typename T>
std::size_t DynamicBag<T>::getFrequencyOf(const T & item) const
{
  //set a counter variable
  std::size_t freq = 0;

  //loop through the array and look for element, increment freq when it exists
  for(std::size_t i = 0; i < size; ++i){
    if(anArray[i] == item) ++freq;
  }
  //return the number of times the element appears
  return freq;
}
