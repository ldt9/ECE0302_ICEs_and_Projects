#include "ring_buffer.h"

#include <cassert>

int main()
{
  RingBuffer<int> buff(3);
    
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

  
  return 0;
}
