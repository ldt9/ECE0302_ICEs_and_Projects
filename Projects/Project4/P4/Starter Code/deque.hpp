#ifndef DEQUE_HPP
#define DEQUE_HPP

#include "abstract_deque.hpp"
//#include "Node.hpp"
#include "linked_list.hpp"
#include <memory>

template <typename T>
class Deque: public AbstractDeque<T>{

private:

    //need 2 pointers to the front and back of the linked list
    //Node<T>* frontPtr;
    //Node<T>* backPtr;

    //let's use a linked list instead of bare nodes
    LinkedList<T> deque;

    //helper function for copy assignment and constructor
    // get a copy of the item at position using 0-based indexing
    T getEntry(std::size_t position) const;

    //holds number of elements in deque
    //int count; //unnecessary now since we can let the linked list composition handle this

    //helps with popBack implementation
    //Node<T>* getNodeBefore(const T& anEntry) const; //put this in the node class

public:

    //CONSTRUCTOR//
    Deque();

    //DESTRUCTOR//
   ~Deque();

    //COPY ASSIGNMENT//
    Deque& operator=(const Deque& x);

    //COPY CONSTRUCTOR//
    Deque(const Deque& x);

  /** Returns true if the deque is empty, else false
   */
   bool isEmpty() const noexcept;

  /** Add item to the front of the deque
   * may throw std::bad_alloc
   */
   void pushFront(const T & item);

  /** Remove the item at the front of the deque
   * throws std::runtime_error if the deque is empty
   */
   void popFront();

  /** Returns the item at the front of the deque
   * throws std::runtime_error if the deque is empty
   */
   T front() const;

  /** Add item to the back of the deque
   * may throw std::bad_alloc
   */
   void pushBack(const T & item);

  /** Remove the item at the back of the deque
   * throws std::runtime_error if the deque is empty
   */
   void popBack();


  /** Returns the item at the back of the deque
   * throws std::runtime_error if the deque is empty
   */
   T back() const;

};

#include "deque.tpp"

#endif
