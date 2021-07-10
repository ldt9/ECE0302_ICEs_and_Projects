#include "sorted_list.h"

template <typename T, typename L>
SortedList<T, L>::SortedList()
{
  // nothing to do, plist gets created on the stack
}

template <typename T, typename L>
SortedList<T, L>::SortedList(const SortedList<T, L> & x)
{
  plist = x.plist; // use copy assignment to implement copy construction
}

template <typename T, typename L>
SortedList<T, L>& SortedList<T, L>::operator=(const SortedList<T, L>& x)
{
  plist = x.plist;
  return *this;
}

template <typename T, typename L>
SortedList<T, L>::~SortedList()
{
  // plist destructor gets called automatically
}

template <typename T, typename L>
bool SortedList<T, L>::isEmpty()
{
  return plist.isEmpty();
}

template <typename T, typename L>
std::size_t SortedList<T, L>::getLength()
{
  return plist.getLength();
}

template <typename T, typename L>
void SortedList<T, L>::insert(const T& item)
{ //todo
  int savedPos = 0; //variable to hold locaiton of item
  for(int i = 0; i < plist.getLength(); i++){
    if(plist.getEntry(i) < item) savedPos++; //increment when item is still greater than current
  }
  plist.insert(savedPos, item); //insert once it is at the point where everyting in the list is greater to the left

  for(int i = 0; i < plist.getLength(); i++){
    std::cout<<plist.getEntry(i) << std::endl;
  }
}

template <typename T, typename L>
void SortedList<T, L>::remove(const T& item)
{ //todo
  int savedPos = 0; //variable to hold locaiton of item
  for(int i = 0; i < plist.getLength(); i++){
    if(plist.getEntry(i) < item) savedPos++; //increment when item is still greater than current
  }
  plist.remove(savedPos); //remove at the position

  for(int i = 0; i < plist.getLength(); i++){
    std::cout<<plist.getEntry(i) << std::endl;
  }
}

template <typename T, typename L>
void SortedList<T, L>::removeAt(std::size_t position)
{
  plist.remove(position);
}

template <typename T, typename L>
void SortedList<T, L>::clear()
{
  plist.clear();
}

template <typename T, typename L>
T SortedList<T, L>::getEntry(std::size_t position)
{
  return plist.getEntry(position);
}

template <typename T, typename L>
long int SortedList<T, L>::getPosition(const T& newValue)
{ //todo
  int savedPos; //variable to hold locaiton of newValue
  for(int i = 0; i < plist.getLength(); i++){
    if(plist.getEntry(i) == newValue) savedPos = i;
  }
  return savedPos; //return the position of the new value
}
