#include "linked_list.hpp"

template <typename T>
Node<T>* LinkedList<T>::getNodeAt(std::size_t position) const{
  //checking pre CONDITIONS
  assert((position >= 0) && (position <= size));

  //count from the beginning of the list
  Node<T>* tempPtr = head;
  for (int i = 0; i < position; i++){
    //get the node at position
    tempPtr = tempPtr->getNext();
  }
  return tempPtr;
}

template <typename T>
LinkedList<T>::LinkedList()
{
  //initialize head pointer to null
  head = nullptr;

  //set the size of the list to 0
  size = 0;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
  //reset all private variables
  clear();
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& x)
{
  //set the size's equal to eachother
  size = x.size;

  //create a new pointer that is the head of the x LinkedList
  Node<T>* tempPtr = x.head;

  if(tempPtr == nullptr){
    //linked list is is Empty
    head = nullptr;
  }
  else{
    //linked list is not empty
    //copy all the nodes from x into tempPtr
    //allocating memory to head
    head = new Node<T>();
    //copy head pointer of x
    head->setItem(tempPtr->getItem());
    //tell temp pointer to point to the next node in its list
    tempPtr = tempPtr->getNext();
    //then save the head pointer in tempPtr1
    Node<T>* tempPtr1 = head;
    //then while tempPtr still has stuff in it
    while (tempPtr != nullptr){
      T nextVal = tempPtr->getItem(); //getting next item from tempPtr
      Node<T>* newNode = new Node<T>(nextVal); //create a new node to hold that value
      tempPtr1->setNext(newNode); //then move the temporary head pointer to the next node until the next node is nullptr
      tempPtr = tempPtr->getNext();//shift both pointers to their next elements
      tempPtr1 = tempPtr1->getNext();
    }
  }
}

template <typename T>
void LinkedList<T>::swap(LinkedList<T>& x, LinkedList<T>& y)
{
  LinkedList<T> z(y);
  y = x;
  x = z;
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& x)
{
  //set the size's equal to eachother
  size = x.size;

  //create a new pointer that is the head of the x LinkedList
  Node<T>* tempPtr = x.head;

  if(tempPtr == nullptr){
    //linked list is is Empty
    head = nullptr;
  }
  else{
    //linked list is not empty
    //copy all the nodes from x into tempPtr
    //allocating memory to head
    head = new Node<T>();
    //copy head pointer of x
    head->setItem(tempPtr->getItem());
    //tell temp pointer to point to the next node in its list
    tempPtr = tempPtr->getNext();
    //then save the head pointer in tempPtr1
    Node<T>* tempPtr1 = head;
    //then while tempPtr still has stuff in it
    while (tempPtr != nullptr){
      T nextVal = tempPtr->getItem(); //getting next item from tempPtr
      Node<T>* newNode = new Node<T>(nextVal); //create a new node to hold that value
      tempPtr1->setNext(newNode); //then move the temporary head pointer to the next node until the next node is nullptr
      tempPtr = tempPtr->getNext();//shift both pointers to their next elements
      tempPtr1 = tempPtr1->getNext();
    }
  }
  return *this;
}

template <typename T>
bool LinkedList<T>::isEmpty() const
{
  return (size == 0);
}

template <typename T>
std::size_t LinkedList<T>::getLength() const
{
  //return lenth of list
  return size;
}

template <typename T>
bool LinkedList<T>::insert(std::size_t position, const T& item)
{
  //checking validity of position
  bool validity = (position >= 0) && (position <= size);
  //std::cout << validity << " " << position << std::endl;
  if (validity){
    //create a new node containing the new entry
    Node<T>* newPtr = new Node<T>(item);
    //attach the new node to the chain
    if (position == 0){
      //insert new node at begining of the chain
      newPtr->setNext(head);
      head = newPtr;
    }
    else{
      //find node that will be before new node
      Node<T>* prePtr = getNodeAt(position - 1);
      //insert new node after node to which prePtr points
      newPtr->setNext(prePtr->getNext());
      prePtr->setNext(newPtr);
    }
    size++; //increase the size of the array
  }
  return validity;
}

template <typename T>
bool LinkedList<T>::remove(std::size_t position)
{
  //checking validity of position
  bool validity = (position >= 0) && (position <= size);
  if (validity){
    //create a new node containing a blank ptr
    Node<T>* tempPtr = nullptr;
    //attach blank node to the chain
    if(position == 0){
      //remove the first node in the chain
      tempPtr = head; //save the pointer to the node we want to get rid of
      head = head->getNext(); //make the head pointer point to where the next pointer was pointing too
    }
    else{
      //find the node that is before the one to remove
      Node<T>* prePtr = getNodeAt(position - 1);
      //point to node to remove
      tempPtr = prePtr->getNext();
      //disconnect indicated node from chain by connecting the
      //prior node with the one after
      prePtr->setNext(tempPtr->getNext());
    }
    //return node to system
    tempPtr->setNext(nullptr);
    delete tempPtr;
    tempPtr = nullptr;
    size--; //decrease the number of items in list
  }
  return validity;
}

template <typename T>
void LinkedList<T>::clear()
{
  //reset all private variables
  while(!isEmpty()){
    remove(0);
  }
}

template <typename T>
T LinkedList<T>::getEntry(std::size_t position) const
{
  if(isEmpty()) throw std::range_error("empty list in remove");
  if(position >= getLength() || position < 0) throw std::range_error("item nonexistent");  
  bool validity = (position >= 0) && (position <= size);
  //lets make sure we are able to access this position
  if(validity){
    //if the position exists well create a new nodePtr and get the node at that position
    Node<T>* nodePtr = getNodeAt(position);
    return nodePtr->getItem();
  }
  return false;
}

template <typename T>
void LinkedList<T>::setEntry(std::size_t position, const T& newValue)
{
  //checking validity of position
  if (position >= 0 && position <= size){
    //create a new node containing the new entry
    Node<T>* newPtr = new Node<T>(newValue);
    //attach the new node to the chain
    if (position == 0){
      //insert new node at begining of the chain
      newPtr->setNext(head);
      head = newPtr;
    }
    else{
      //find node that will be before new node
      Node<T>* prePtr = getNodeAt(position - 1);
      //insert new node after node to which prePtr points
      newPtr->setNext(prePtr->getNext());
      prePtr->setNext(newPtr);
    }
    size++; //increase the size of the array
  }
}
