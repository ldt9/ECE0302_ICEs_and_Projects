#include "limited_size_bag.hpp"

template<typename T>
LimitedSizeBag<T>::LimitedSizeBag():size(0) {}


template<typename T>
LimitedSizeBag<T>::LimitedSizeBag(const LimitedSizeBag& x){
  //clear the values in data[] incase x does not have the same amount of values in the array
  for (int i = 0; i < size; i++){
    data[i] = 0;
  }

  //copying all elements to new bag
  for (int i = 0; i < x.getCurrentSize(); i++){
    data[i] = x.data[i];
  }

  //setting the size ptr to the same element that x left off on
  size = x.getCurrentSize();
}

template<typename T>
LimitedSizeBag<T>::~LimitedSizeBag(){}
//dont need to implement a deconstructor for non dynamic mem

template<typename T>
LimitedSizeBag<T>& LimitedSizeBag<T>::operator=(LimitedSizeBag<T>& x)
{
  //clear the values in data[] incase x does not have the same amount of values in the array
  for (int i = 0; i < size; i++){
    data[i] = 0;
  }

  //copying all elements to new bag
  for (int i = 0; i < x.getCurrentSize(); i++){
    data[i] = x.data[i];
  }

  //setting the size ptr to the same element that x left off on
  size = x.getCurrentSize();

  // so you can make multiple assertions in a row (ie a = b = c)
  return *this;
}

template<typename T>
bool LimitedSizeBag<T>::add(const T& item)
{
  if(size >= MAXSIZE){
    return false;
  }

  data[size] = item;
  ++size;

  return true;
}

template<typename T>
bool LimitedSizeBag<T>::remove(const T& item)
{
  if(size == 0) return false;

  std::size_t idx = 0;
  for(std::size_t i = 0; i < size; ++i){
    if(data[i] == item) break;
    ++idx;
  }

  if(idx == size) return false;

  --size;
  for(std::size_t i = idx; i < size; ++i){
    data[i] = data[i+1];
  }

  return true;
}
template<typename T>
bool LimitedSizeBag<T>::isEmpty() const
{
return (size == 0);
}

template<typename T>
std::size_t LimitedSizeBag<T>::getCurrentSize() const
{
  return size;
}

template<typename T>
bool LimitedSizeBag<T>::contains(const T& item) const
{
  return (getFrequencyOf(item) != 0);
}

template<typename T>
void LimitedSizeBag<T>::clear(){ size = 0; }

template<typename T>
std::size_t LimitedSizeBag<T>::getFrequencyOf(const T & item) const
{
  std::size_t freq = 0;

  for(std::size_t i = 0; i < size; ++i){
    if(data[i] == item) ++freq;
  }

  return freq;
}
