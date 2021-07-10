#ifndef _LINKED_LIST_HPP_
#define _LINKED_LIST_HPP_

#include "abstract_list.hpp"
#include "Node.hpp"

template <typename T>
class LinkedList: public AbstractList<T>
{
public:

  // default constructor
  LinkedList();

  // copy constructor
  LinkedList(const LinkedList& x);

  // destructor
  ~LinkedList();

  // copy assignment
  LinkedList& operator=(const LinkedList& x);

  // swap two lists
  void swap(LinkedList& x, LinkedList& y);

  // determine if a list is empty
  bool isEmpty() const;

  // return current length of the list
  std::size_t getLength() const;

  // insert item at position in the list using 0-based indexing
  bool insert(std::size_t position, const T& item);

  // remove item at position in the list using 0-based indexing
  bool remove(std::size_t position);

  // remove all items from the list
  void clear();

  // get a copy of the item at position using 0-based indexing
  T getEntry(std::size_t position) const;

  // set the value of the item at position using 0-based indexing
  void setEntry(std::size_t position, const T& newValue);

private:

  //we are creating a singly linked list which only goes in one direction,
  //and only needs a pointer to the head of the list
  Node<T>* head;

  //to point to the last element in the array so as to keep a running total of the size
  size_t size;

  //this private function locates the node at a given position by traversing the chain
  Node<T>* getNodeAt(std::size_t position) const;

};

#include "linked_list.tpp"

#endif
