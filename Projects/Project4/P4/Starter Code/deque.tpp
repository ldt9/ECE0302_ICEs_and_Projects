#include "deque.hpp"
//main functions

  //CONSTRUCTOR//
  template<typename T>
  Deque<T>::Deque()
  {
    //initialize pointers to null
    frontPtr = nullptr;
    backPtr = nullptr;

    //set element amount to 0
    count = 0;

  }

  //DESTRUCTOR//
  template<typename T>
  Deque<T>::~Deque()
  {
    //reset all private variables
    while(!isEmpty()){
      popFront();
    }
    //no need to unallocate pointers because they're smart
  }

  //COPY ASSIGNMENT//
  template<typename T>
  Deque<T>& Deque<T>::operator=(const Deque<T>& x)
  {
    //set the size's equal to eachother
    count = x.count;

    //create a new pointer that is the head of the x LinkedList
    Node<T>* newNodePtr = (x.frontPtr);

    if(newNodePtr == nullptr){
      //linked list is is Empty
      frontPtr = backPtr = nullptr;
    }
    else{
      //linked list is not empty
      //copy all the nodes from x into tempPtr
      //allocating memory to head
      frontPtr = new Node<T>();
      //copy head pointer of x
      frontPtr->setItem(newNodePtr->getItem());
      //tell temp pointer to point to the next node in its list
      newNodePtr = newNodePtr->getNext();
      //then save the head pointer in tempPtr1
      Node<T>* tempPtr1 = (frontPtr);
      //then while tempPtr still has stuff in it
      while (newNodePtr != nullptr){
        T nextVal = newNodePtr->getItem(); //getting next item from tempPtr
        Node<T>* newNode = new Node<T>(nextVal);
        //create a new node to hold that value
        tempPtr1->setNext(newNode); //then move the temporary head pointer to the next node until the next node is nullptr
        newNodePtr = newNodePtr->getNext();//shift both pointers to their next elements
        tempPtr1 = tempPtr1->getNext();
      }
    }
    return *this;
  }

  //COPY CONSTRUCTOR//
  template<typename T>
  Deque<T>::Deque(const Deque<T>& x)
  {
    //set the size's equal to eachother
    count = x.count;

    //create a new pointer that is the head of the x LinkedList
    Node<T>* newNodePtr = (x.frontPtr);

    if(newNodePtr == nullptr){
      //linked list is is Empty
      frontPtr = backPtr = nullptr;
    }
    else{
      //linked list is not empty
      //copy all the nodes from x into tempPtr
      //allocating memory to head
      frontPtr = new Node<T>();
      //copy head pointer of x
      frontPtr->setItem(newNodePtr->getItem());
      //tell temp pointer to point to the next node in its list
      newNodePtr = newNodePtr->getNext();
      //then save the head pointer in tempPtr1
      Node<T>* tempPtr1 = (frontPtr);
      //then while tempPtr still has stuff in it
      while (newNodePtr != nullptr){
        T nextVal = newNodePtr->getItem(); //getting next item from tempPtr
        Node<T>* newNode = new Node<T>(nextVal);
        //create a new node to hold that value
        tempPtr1->setNext(newNode); //then move the temporary head pointer to the next node until the next node is nullptr
        newNodePtr = newNodePtr->getNext();//shift both pointers to their next elements
        tempPtr1 = tempPtr1->getNext();
      }
    }
  }

  //---//TEMPLATE FUNCTIONS//---//

  //returns true if the deque is empty
  template<typename T>
  bool Deque<T>::isEmpty() const noexcept
  {
    //return false as default
    return (count == 0);
  }

  //add item to the front of the deque
  template<typename T>
  void Deque<T>::pushFront(const T & item)
  {
    Node<T>* newNodePtr = new Node<T>(item);
    //Insert the new Node
    if (isEmpty()){
      frontPtr = newNodePtr;    //The queue was empty
    }
    else{
      newNodePtr->setNext(frontPtr); //the queue was not empty
      frontPtr = newNodePtr;         //New node is inserted at front
    }
    count++;
  }

  //remove an item at the front of a deque
  template<typename T>
  void Deque<T>::popFront()
  {
    bool result = false;
    if (!isEmpty()){
      //queue is not empty remove front element
      Node<T>* nodeToDeletePtr = frontPtr;
      if(frontPtr == backPtr){
        //special case of one node in queue
        //set frontPtr and backPtr to nullptr
        frontPtr = nullptr;
        backPtr = nullptr;
      }
      else{
        frontPtr = frontPtr->getNext();
        //maintain an accurate reference count for first node
        nodeToDeletePtr->setNext(nullptr);
        //removed node will be deallocated when method exits
        result = true;
      }
    }
    count--;
  }

  //returns the item at the front of the deque
  template<typename T>
  T Deque<T>::front() const
  {
    return frontPtr->getItem();
  }

  //at item to the back of the deque
  template<typename T>
  void Deque<T>::pushBack(const T & item)
  {
    Node<T>* newNodePtr = new Node<T>(item);
    //Insert the new Node
    if (isEmpty()){
      frontPtr = newNodePtr;    //The queue was empty
    }
    else{
      backPtr->setNext(newNodePtr); //the queue was not empty
      backPtr = newNodePtr;         //New node is inserted at back
    }
    count++;
  }

  //private helper function to make popping from the back easier
  template<typename T>
  Node<T>* Deque<T>::getNodeBefore(const T& anEntry) const
  {
    Node<T>* curPtr = frontPtr;
    Node<T>* prevPtr;
    //traverse the list until the end is reached and set ptrs accordingly
    while((curPtr != nullptr) && (anEntry != curPtr->getItem())){
      prevPtr = curPtr;
      curPtr = curPtr->getNext();
    }
    return prevPtr;
  }

  //remove an item at the back of the deque
  template<typename T>
  void Deque<T>::popBack()
  {
    bool result = false;
    if (!isEmpty()){
      //queue is not empty remove back element
      Node<T>* nodeToDeletePtr = backPtr;
      if(frontPtr == backPtr){
        //special case of one node in queue
        //set frontPtr and backPtr to nullptr
        frontPtr = nullptr;
        backPtr = nullptr;
      }
      else{
        T currentEntry = backPtr->getItem();
        backPtr = backPtr->getNodeBefore(currentEntry);
        //maintain an accurate reference count for back node
        nodeToDeletePtr->setNext(nullptr);
        //removed node will be deallocated when method exits
        result = true;
      }
    }
    count--;
  }

  //returns the item at the back of the deque
  template<typename T>
  T Deque<T>::back() const
  {
    return backPtr->getItem();

  }
