
#ifndef _HEAP_PRIORITY_QUEUE_H_
#define _HEAP_PRIORITY_QUEUE_H_

#include "abstract_priority_queue.h"
#include "dynamic_array_list.h"

template <typename T>
class HeapPriorityQueue: public AbstractPriorityQueue<T>
{
public:

    // return true if the priority queue is empty
    bool isEmpty();

    // insert item into the queue
    void add(const T& item);

    // remove highest priority item from the queue
    void remove();

    // get the item with the highest priority from the queue
    T peek();

private:

    DynamicArrayList<T> lst;
};

template <typename T>
bool HeapPriorityQueue<T>::isEmpty()
{
    //todo
    return lst.isEmpty();
}

template <typename T>
void HeapPriorityQueue<T>::add(const T& item)
{
    //todo
    int savedPos = 0; //variable to hold locaiton of item
    for(int i = 0; i < lst.getLength(); i++){
      if(lst.getEntry(i) > item) savedPos++; //increment when item is still greater than current
    }
    lst.insert(savedPos, item); //insert once it is at the point where everyting in the list is greater to the left

    //for(int i = 0; i < lst.getLength(); i++){
    //  std::cout<<lst.getEntry(i) << std::endl;
    //}
}

template <typename T>
void HeapPriorityQueue<T>::remove()
{
    //for(int i = 0; i < lst.getLength(); i++){
    //  std::cout<<lst.getEntry(i) << std::endl;
    //}

    //todo
    lst.remove(0);
}

template <typename T>
T HeapPriorityQueue<T>::peek()
{
    //todo
    return lst.getEntry(0);
}


#endif // _HEAP_PRIORITY_QUEUE_H_
