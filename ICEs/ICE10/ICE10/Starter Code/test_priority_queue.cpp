#include <cassert>

#include "dynamic_array_list.h"
#include "heap_priority_queue.h"

int main()
{
  HeapPriorityQueue<int>  pq;
  assert(pq.isEmpty());

  //std:: cout << "past line 9" << std:: endl;

  pq.add(25);
  assert(!pq.isEmpty());
  assert(pq.peek() == 25);

  //std:: cout << "past line 15" << std:: endl;

  pq.add(1);
  //std:: cout << "past line 19" << std:: endl;

  assert(pq.peek() == 25);

  //std:: cout << "past line 22" << std:: endl;

  pq.add(78);
  assert(pq.peek() == 78);

  //std:: cout << "past line 25" << std:: endl;

  pq.remove();
  pq.remove();
  pq.remove();
  assert(pq.isEmpty());

  for(int i = 0; i < 11; i++){
    pq.add(i);
  }

  assert(!pq.isEmpty());

  for(int i = 10; i >= 0; i--){
    assert(pq.peek() == i);
    pq.remove();
  }

  assert(pq.isEmpty());

  return 0;
}
