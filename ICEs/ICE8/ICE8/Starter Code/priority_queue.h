
#ifndef _PRIORITY_QUEUE_H_
#define _PRIORITY_QUEUE_H_

#include "abstract_priority_queue.h"

// Type T must be orderable
// Type L must conform to AbstractSortedList<T>
template <typename T, typename L >
class PriorityQueue: AbstractPriorityQueue<T>
{
public:

  // return true if the priority queue is empty
  bool isEmpty(){
    return slist.isEmpty(); //use sorted list function
  }

  // insert item into the queue
  void add(const T& item){
    slist.insert(item); //use sorted list function
  }

  // remove highest priority item from the queue
  void remove(){
    slist.removeAt(slist.getLength()-1); //use sorted list function
  }

  // get the item with the highest priority from the queue
  T peek(){
    return slist.getEntry(slist.getLength()-1);
  }

private:

  //composition from sorted_list
  L slist; // internal sorted list
};


#endif // _PRIORITY_QUEUE_H_
