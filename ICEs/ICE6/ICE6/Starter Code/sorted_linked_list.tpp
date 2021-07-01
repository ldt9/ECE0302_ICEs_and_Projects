#include "sorted_linked_list.hpp"
#include <stdexcept>

template <typename T>
SortedLinkedList<T>::SortedLinkedList(): LinkedList<T>()
{
}

template <typename T>
SortedLinkedList<T>::SortedLinkedList(const SortedLinkedList<T> & x):
  LinkedList<T>(x)
{
}

template <typename T>
SortedLinkedList<T>& SortedLinkedList<T>::operator=(const SortedLinkedList<T>& x)
{
  LinkedList<T>::operator=(x);
  return *this;
}

template <typename T>
SortedLinkedList<T>::~SortedLinkedList()
{
  // base destructor gets called automatically
}

template <typename T>
bool SortedLinkedList<T>::isEmpty()
{
  //std:: cout << getLength() << std:: endl;
  return LinkedList<T>::isEmpty();
}

template <typename T>
std::size_t SortedLinkedList<T>::getLength()
{
  return LinkedList<T>::getLength();
}

template <typename T>
void SortedLinkedList<T>::insert(const T& item)
{
  int size = getLength();
  //if there are no elements in the list
  if(size == 0){
    //insert new node at begining of the chain
    LinkedList<T>::insert(0, item);
    return;
  }
  else{
    for(int i = 0; i < size; i++){
      //traverse the list of items
      if(LinkedList<T>::getEntry(i) >= item){
        //if the item in the list at index i is >= the item, insert the item at
        //that position and shift the rest down, ie skip over every item
        //less than the item
        LinkedList<T>::insert(i, item);
        return;
      }
    }
    if(LinkedList<T>::getEntry(size - 1) < item){
      //if there are no items in the list >= item, we want to append to the end
      LinkedList<T>::insert(size, item);
      return;
    }
  }
}

template <typename T>
void SortedLinkedList<T>::remove(const T& item)
{
  if(isEmpty()) throw std::range_error("empty list in remove");

  //loop through the list and remove the item if it is == to one in the list
  for(int i = 0; i < getLength(); i++){
    if(LinkedList<T>::getEntry(i) == item){
      LinkedList<T>::remove(i);
      return;
    }
    else{
      throw std::logic_error("item does not exist in list");
    }
  }
}

template <typename T>
void SortedLinkedList<T>::removeAt(std::size_t position)
{
  if(isEmpty()) throw std::range_error("empty list in remove");
  if(position >= getLength() || position < 0) throw std::range_error("item nonexistent");

  LinkedList<T>::remove(position); //if all tests pass remove at the position
}

template <typename T>
void SortedLinkedList<T>::clear()
{
  LinkedList<T>::clear();
}

template <typename T>
T SortedLinkedList<T>::operator[](std::size_t position) const
{
  // get a copy of the item at position using 0-based indexing
  //if all tests pass return element at position
  return LinkedList<T>::getEntry(position);
}

template <typename T>
long int SortedLinkedList<T>::getPosition(const T& newValue)
{
  //loop through the list and find the index if it is == to one in the list
  for(long int i = 0; i < getLength(); i++){
    if(LinkedList<T>::getEntry(i) == newValue){
      return i;
    }
  }
    throw std::logic_error("item does not exist in list");
    return -1;
}
