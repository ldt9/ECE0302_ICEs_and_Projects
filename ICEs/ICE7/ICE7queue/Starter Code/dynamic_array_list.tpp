#include "dynamic_array_list.h"

#include <algorithm>
#include <stdexcept>
#include <assert.h>

#include <iostream>

template <typename T>
DynamicArrayList<T>::DynamicArrayList()
{
  //create a new array of size 1
  datum = new T[1];
  //set the size pointer to point to the first element 0
  size = 0;
}

template <typename T>
DynamicArrayList<T>::DynamicArrayList(const DynamicArrayList<T>& x)
{
  //create a new array
  if(size == 0)  datum = new T[1];
  else datum = new T[x.size];

  //set the size ptrs to the same element
  size = x.size;

  //copy every element from x into the new datum
  for(int i = 0; i < size; i++){
    T temp = x.datum[i];
    datum[i] = temp;
  }
}

template <typename T>
DynamicArrayList<T>::~DynamicArrayList()
{
  std::clog << "DynamicArrayList Destructor called." << std::endl;

  //reset size pointer so values in array are overwritten
  //no need to reset entire array
  size = 0;

}

template <typename T>
DynamicArrayList<T>& DynamicArrayList<T>::operator=(DynamicArrayList<T> x)
{
  //set the size ptrs to the same element
  size = x.size;

  //std:: cout << "size is set to: " << size << std:: endl;

  for(int i = 0; i < size; i++){
    datum[i] = x.getEntry(i);
    //std:: cout << datum[i] << std:: endl;
  }

  //std:: cout << "operator assignment complete" << std:: endl;

  return *this;
}

template <typename T>
void DynamicArrayList<T>::swap(DynamicArrayList<T>& x, DynamicArrayList<T>& y)
{
  //use compy assignment to swap lists
  DynamicArrayList temp;
  temp = x;
  x = y;
  y = temp;
}

template <typename T>
bool DynamicArrayList<T>::isEmpty()
{
  //std:: cout << "Is the queue empty?: " << (size == 0) << std:: endl;
  return (size == 0);
}

template <typename T>
std::size_t DynamicArrayList<T>::getLength()
{
  return size;
}

template <typename T>
void DynamicArrayList<T>::insert(std::size_t position, const T& item)
{

  //create a new array and set it equal to the current array
  T* newDatum;

  for(int i = 0; i < size; i++){
    newDatum[i] = datum[i];
  }

  //std:: cout << "data copied into new array" << std:: endl;

  //delete datum
  delete [] datum;
  datum = nullptr;

  //then reallocate memory to datum and update size
  size++;
  datum = new T[size];

  //copy every element from newDatum back into datum
  for(int i = 0; i < size-1; i++){
    datum[i] = newDatum[i];
  }

  //set position == item
  datum[position] = item;
}

template <typename T>
void DynamicArrayList<T>::remove(std::size_t position)
{
  assert(size > 0 && position >= 0 && position < size);
  //std:: cout << "size was: " << size << std:: endl;
  //shift left the values below position
  //std:: cout << "value to be removed: " << datum[position] << std:: endl;
  for(std::size_t i = position; i < size; i++){
    datum[i] = datum[i+1];
  }
  size--; //decrement the size pointer because we removed an item
  //std:: cout << "current size is: " << size << std:: endl;
}

template <typename T>
void DynamicArrayList<T>::clear()
{
  //clear the array
  while(!isEmpty()){
    remove(0);
    size--; //decrement the size
  }
}

template <typename T>
T DynamicArrayList<T>::getEntry(std::size_t position)
{
  assert(position >= 0 && position < size);
  return datum[position];
}

template <typename T>
void DynamicArrayList<T>::setEntry(std::size_t position, const T& newValue)
{
  assert(position >= 0 && position < size);
  datum[position] = newValue;
}
