#include "dynamic_array_list.h"
#include "sorted_list.h"
#include "priority_queue.h"
#include <cassert>

int main()
{
  typedef SortedList<int, DynamicArrayList<int> > SortedListType;
  typedef PriorityQueue<int, SortedListType>  PriorityQueueType;

    PriorityQueueType pq;

    assert(pq.isEmpty());
    pq.add(1);
    assert(!pq.isEmpty());
    pq.add(3);
    pq.add(2);
    assert(pq.peek() == 3);
    pq.add(4);
    assert(pq.peek() == 4);
    pq.remove();
    assert(pq.peek() == 3);
    pq.remove();
    pq.remove();
    pq.remove();
    assert(pq.isEmpty());

  return 0;
}
