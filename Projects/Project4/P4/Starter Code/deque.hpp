#ifndef DEQUE_HPP
#define DEQUE_HPP

#include "abstract_deque.hpp"

template <typename T>
class Deque: public AbstractDeque<T>{

private:



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
   bool isEmpty() const noexcept = 0;

  /** Add item to the front of the deque
   * may throw std::bad_alloc
   */
   void pushFront(const T & item) = 0;

  /** Remove the item at the front of the deque
   * throws std::runtime_error if the deque is empty
   */
   void popFront() = 0;

  /** Returns the item at the front of the deque
   * throws std::runtime_error if the deque is empty
   */
   T front() const = 0;

  /** Add item to the back of the deque
   * may throw std::bad_alloc
   */
   void pushBack(const T & item) = 0;

  /** Remove the item at the back of the deque
   * throws std::runtime_error if the deque is empty
   */
   void popBack() = 0;


  /** Returns the item at the back of the deque
   * throws std::runtime_error if the deque is empty
   */
   T back() const = 0;

};

#include "deque.tpp"

#endif
