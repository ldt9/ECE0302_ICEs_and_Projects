#include "ring_buffer.h"

#include <cassert>

int main()
{
  //initialization
  RingBuffer<int> buff(10);

  /*********
  * TEST 1 *
  *********/

  buff.enqueue_back(89);
  buff.enqueue_back(4);
  buff.enqueue_back(45);
  buff.enqueue_back(12);
  buff.enqueue_back(455);
  buff.enqueue_back(1);

  //RingBuffer<int> buff2 = buff;

  assert(buff.getCount() == 6);
  assert(buff.dequeue_front() == 89);
  assert(buff.dequeue_front() == 4);
  assert(buff.dequeue_front() == 45);
  assert(buff.dequeue_front() == 12);
  assert(buff.dequeue_front() == 455);
  assert(buff.dequeue_front() == 1);
  assert(buff.getCount() == 0);

  /*********
  * TEST 2 *
  *********/

  buff.enqueue_back(45);
  buff.enqueue_back(16);
  buff.enqueue_back(58);
  buff.enqueue_back(111);
  buff.enqueue_back(23);
  buff.enqueue_front(35);
  buff.enqueue_back(21);
  buff.enqueue_back(99);
  buff.enqueue_front(11);
  buff.enqueue_back(88);

  //11 35 58 16 45 111 23 21 99 88

  assert(buff.getCount() == 10);
  assert(buff.dequeue_front() == 11);
  assert(buff.dequeue_front() == 35);
  assert(buff.dequeue_back() == 88);
  assert(buff.dequeue_back() == 99);
  assert(buff.dequeue_back() == 21);
  assert(buff.dequeue_back() == 23);
  assert(buff.dequeue_back() == 111);
  assert(buff.dequeue_back() == 58);
  assert(buff.dequeue_back() == 16);
  assert(buff.dequeue_back() == 45);
  assert(buff.getCount() == 0);

  /*********
  * TEST 3 *
  *********/

  buff.enqueue_front(45);
  buff.enqueue_front(16);
  buff.enqueue_front(58);
  buff.enqueue_back(111);
  buff.enqueue_back(23);
  buff.enqueue_front(35);
  buff.enqueue_back(21);
  buff.enqueue_back(99);
  buff.enqueue_front(11);
  buff.enqueue_back(88);

  //45 16 58 35 11 88 99 21 23 111

  assert(buff.getCount() == 10);
  assert(buff.dequeue_back() == 88);
  assert(buff.dequeue_back() == 99);
  assert(buff.dequeue_back() == 21);
  assert(buff.dequeue_back() == 23);
  assert(buff.dequeue_back() == 111);
/**
  assert(buff.dequeue_front() == 11);
  assert(buff.dequeue_front() == 35);
  assert(buff.dequeue_front() == 58);
  assert(buff.dequeue_front() == 16);
  assert(buff.dequeue_front() == 45);
*/

  assert(buff.dequeue_back() == 45);
  assert(buff.dequeue_back() == 16);
  assert(buff.dequeue_back() == 58);
  assert(buff.dequeue_back() == 35);
  assert(buff.dequeue_back() == 11);
  assert(buff.getCount() == 0);


  return 0;
}
