#include "frontier_queue.hpp"
#include <iostream>

// TODO implement the member functions here

template <typename T>
State<T> frontier_queue<T>::pop() {

  //TODO

  //implement this the same way we implemented pop in the heap lecture. Compare using getFCost

  // needs return statement

  //delete first element in vector by replacing with last element and then pop_back()
  //while true loop to interate through heap, using int values (root = 0, left = 1, right = 2) to index
  //check if the left getFcost is > the right getFcost, switch if it is
  //increment the indexes (root = root + 1), (Left = root << 1 + 1 or Left = (root * 2) + 1), (Right = Left + 1)
  //repeat while loop, break when the right > size

  if(queue.size() == 0) throw std::logic_error("nothing inside queue");

  else if(queue.size() == 1){
    State<T> x = queue[0]; //return 0th element in queue
    queue.pop_back(); //delete that element
    return x;
  }

  else{
    State<T> poppedState = queue[0];

    //defining indexes
    int root = 0;
    int left = 1;
    int right = 2;

    //delete first element in vector by replacing with last element and then pop_back()
    queue[root] = queue[queue.size()-1];
    queue.pop_back();

    //while true loop to interate through heap, using int values (root = 0, left = 1, right = 2) to index
    while(left < queue.size() && left > 0){
      //check if the left getFcost is > the right getFcost, switch if it is
      if(queue[right].getFCost() < queue[left].getFCost() && queue[right].getFCost() < queue[root].getFCost()){
        State<T> x = queue[root];
        //swap the values
        queue[root] = queue[right];
        queue[right] = x;
        root = right;
      }
      if(queue[left].getFCost() < queue[root].getFCost()){
        State<T> y = queue[root];
        //swap the values
        queue[root] = queue[left];
        queue[left] = y;
        root = left;
      }
      else break;

      //increment the indexes (root = root + 1), (Left = root << 1 + 1 or Left = (root * 2) + 1), (Right = Left + 1)
      right = (root + 1) << 1;
      left = right - 1;

      //repeat while loop, break when the right > size
      if(right > queue.size()) break;

    }

    return poppedState; //return first element that was popped
  }
}

template <typename T>
void frontier_queue<T>::push(const T &p, std::size_t cost, std::size_t heur) {

  //TODO

  //implement this the same way we implemented push in the heap lecture. Compare using getFCost

  //if queue size is 0, just push_back() once and Return
  //if queue size > 0, push_back() and
  //while loop to interate through heap, using int values (newPush = size, parent = newPush >> 1) to index
  //check if the parent getFcost is < the newPush getFcost, switch if it is
  //increment the indexes (size = parent, parent = parent >> 1)
  //repeat while parent >= 0 and queue[parent].getFCost() < queue[newPush].getFCost() keep looping

  State<T> temp(p, cost, heur); //create a new state for the queue

  if(queue.size() == 0){
    queue.push_back(temp); //if theres nothing in there push the new state
    return;
  }

  else{
    queue.push_back(temp); //push new element into queue

    int newPush = queue.size() - 1;
    int parent = newPush >> 1;

    while(parent != 0 && queue[parent].getFCost() > queue[newPush].getFCost()){
      State<T> x = queue[parent];
      //swap the values
      queue[parent] = queue[newPush];
      queue[newPush] = x;

      newPush = parent;
      parent = (parent - 1)/2; // (parent - 1)/2 if bitwise doesn't work
    }
  }
  return;
}

template <typename T>
bool frontier_queue<T>::empty() {

  //TODO
  return (queue.empty());
}

template <typename T>
bool frontier_queue<T>::contains(const T &p) {

  //TODO
  for(int i = 0; i < queue.size(); i++){
    if(queue[i].getValue() == p) return true;
  }
  return false;
}

template <typename T>
void frontier_queue<T>::replaceif(const T &p, std::size_t cost) {

  //TODO

  for(int i = 0; i < queue.size(); i++){
    if(queue[i].getValue() == p && queue[i].getPathCost() > cost) {
      queue[i].updatePathCost(cost);
      return;
    }
  }
  return;
}
