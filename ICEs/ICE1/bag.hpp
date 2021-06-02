#ifndef STUDENT_BAG_HPP
#define STUDENT_BAG_HPP

#include <cstdlib>

template<typename T> class Bag{
private:
	T bag[10]; //Defining variable to be used as array in constructor/deconstructor
	int size; //size of bag

public:

  Bag();
  
  ~Bag();

  std::size_t getCurrentSize() const;

  bool isEmpty() const;

  bool add(const T& entry);

  bool remove(const T& entry);

  void clear();

  std::size_t getFrequencyOf(const T& entry) const;

  bool contains(const T& entry) const;

};

#include "bag.tpp"

#endif
