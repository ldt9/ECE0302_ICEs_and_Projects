#include "deque.hpp"
//main functions

  //CONSTRUCTOR//
  template<typename T>
  Deque<T>::Deque()
  { //using the linked list constructor will be fine
  }

  //DESTRUCTOR//
  template<typename T>
  Deque<T>::~Deque()
  {
    while(!isEmpty()){
      popFront(); //pop the front till empty
    }
  }

  //set entry to help with copy assignment and constructor
  template<typename T>
  T Deque<T>::getEntry(std::size_t position) const{
    return deque.getEntry(position);
  }

  //COPY ASSIGNMENT//
  template<typename T>
  Deque<T>& Deque<T>::operator=(const Deque<T>& x)
  {
    /**
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
    }*/

    //go through the whole x deque and use Linked list set entry feature to make an exact copy at each place
    for(int i = 0; i < x.deque.getLength(); i++){
      deque.setEntry(i, x.getEntry(i));
    }
    /**
    for(int i = 0; i < deque.getLength(); i++){
      std:: cout << getEntry(i) << std:: endl;
    }
    */
    return *this;
  }

  //COPY CONSTRUCTOR//
  template<typename T>
  Deque<T>::Deque(const Deque<T>& x)
  {
    /**
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
    */

    //go through the whole x deque and use Linked list set entry feature to make an exact copy at each place
    for(int i = 0; i < x.deque.getLength(); i++){
      deque.setEntry(i, x.getEntry(i));
    }
  }

  //---//TEMPLATE FUNCTIONS//---//

  //returns true if the deque is empty
  template<typename T>
  bool Deque<T>::isEmpty() const noexcept
  {
    //return false as default
    return (deque.isEmpty());
  }

  //add item to the front of the deque
  template<typename T>
  void Deque<T>::pushFront(const T & item)
  {
    /**
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
    */

    deque.insert(0, item); //insert item at front
  }

  //remove an item at the front of a deque
  template<typename T>
  void Deque<T>::popFront()
  {
    /**
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
    */

    deque.remove(0); //remove first element
  }

  //returns the item at the front of the deque
  template<typename T>
  T Deque<T>::front() const
  {
    return deque.getEntry(0);
  }

  //at item to the back of the deque
  template<typename T>
  void Deque<T>::pushBack(const T & item)
  {
    /**
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
    */

    //insert item at end of linked list
    if(deque.getLength() == 0) deque.insert(0, item);
    else deque.insert(deque.getLength(), item);
  }

  //remove an item at the back of the deque
  template<typename T>
  void Deque<T>::popBack()
  {
    /**
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
    */

    //remove item at end
    deque.remove(deque.getLength() - 1);
  }

  //returns the item at the back of the deque
  template<typename T>
  T Deque<T>::back() const
  {
    return deque.getEntry(deque.getLength()-1);
  }
