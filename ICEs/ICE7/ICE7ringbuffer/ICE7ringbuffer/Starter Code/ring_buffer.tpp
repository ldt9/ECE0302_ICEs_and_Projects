#include "ring_buffer.h"

#include <cassert>
#include <iostream>

template <typename T>
RingBuffer<T>::RingBuffer(std::size_t size)
{
  queueLength = size;
  data.reset(new T[queueLength]);
  front = 0;
  back = queueLength-1;
  //front = back = queueLength/2+1;
  count = 0;
}

template <typename T>
bool RingBuffer<T>::enqueue_back(const T& item)
{
  if(count != queueLength){
    back = (back + 1) % queueLength;
    //back = (back % queueLength) + 1;
    data[back] = item;
    ++count;
    //std:: cout << count << std:: endl;
/**
    for(int i = 0; i < queueLength; i++){
      std:: cout << data[i] << std:: endl;
    }
    std:: cout << "-----------------------" << std:: endl;
*/
    return true;
  }

  return false;
}

template <typename T>
bool RingBuffer<T>::enqueue_front(const T& item)
{//todo
  //std:: cout << "front: "<< front << std:: endl;
  //std:: cout << "front mod queueLength: " << (-1) % 3 << std:: endl;

  if(count != queueLength){
    if(front == 0) front = queueLength;
    front = (front - 1) % queueLength;
    //front = (front % queueLength) - 1;
    //std:: cout << front << std:: endl;
    data[front] = item;
    ++count;
/**
    for(int i = 0; i < count; i++){
      std:: cout << data[i] << std:: endl;
    }
    std:: cout << "-----------------------" << std:: endl;
*/
    return true;
  }

  return false;
}

template <typename T>
T RingBuffer<T>::dequeue_front()
{
  assert(count > 0);

  T value;

  value = data[front];
  front = (front +1) % queueLength;
  //front = (front % queueLength) + 1;
  --count;

  //std:: cout << count << std:: endl;

  return value;
}

template <typename T>
T RingBuffer<T>::dequeue_back()
{//todo
  assert(count > 0);

  T value;

  value = data[back];
  if(back == 0) back = queueLength;
  back = (back -1) % queueLength;
  //back = (back % queueLength) - 1;
  --count;

/**  for(int i = 0; i < count; i++){
    std:: cout << data[i] << std:: endl;
  }
  std:: cout << "-----------------------" << std:: endl;
*/
  //std:: cout << count << std:: endl;

  return value;
}

template <typename T>
long int RingBuffer<T>::getCount()
{
  for(int i = 0; i < queueLength; i++){
    std:: cout << data[i] << std:: endl;
  }
  std:: cout << "-----------------------" << std:: endl;

  return count;
}
