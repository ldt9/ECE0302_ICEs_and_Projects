#include "dynamic_array_list.h"
#include "sorted_list.h"
#include <cassert>

int main()
{
  typedef SortedList<int, DynamicArrayList<int> > slst;

  slst sl;

  assert(sl.isEmpty());
  sl.insert(1);
  sl.insert(2);
  sl.insert(3);
  assert(!sl.isEmpty());

  sl.remove(1);
  sl.remove(2);
  sl.remove(3);
  assert(sl.isEmpty());

  sl.insert(1);
  sl.insert(2);
  sl.insert(6);
  assert(!sl.isEmpty());

  sl.removeAt(2);
  sl.removeAt(1);
  sl.removeAt(0);
  assert(sl.isEmpty());

  sl.insert(1);
  sl.insert(2);
  sl.insert(6);
  assert(!sl.isEmpty());
  sl.clear();
  assert(sl.isEmpty());

  sl.insert(1);
  sl.insert(2);
  sl.insert(6);
  assert(sl.getEntry(0) == 1);
  assert(sl.getEntry(1) == 2);
  assert(sl.getEntry(2) == 6);
  assert(!sl.isEmpty());

  slst sl1;
  sl1 = sl;

  assert(sl1.getEntry(0) == 1);
  assert(sl1.getEntry(1) == 2);
  assert(sl1.getEntry(2) == 6);
  assert(!sl1.isEmpty());

  slst sl2(sl1);

  assert(sl2.getEntry(0) == 1);
  assert(sl2.getEntry(1) == 2);
  assert(sl2.getEntry(2) == 6);
  assert(!sl2.isEmpty());

  assert(sl2.getPosition(6) == 2);
  assert(sl2.getPosition(2) == 1);
  assert(sl2.getPosition(1) == 0);
  assert(sl2.getLength() == 3);


  return 0;
}
