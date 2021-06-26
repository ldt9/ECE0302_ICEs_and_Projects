//  Adapated from Frank M. Carrano and Timothy M. Henry.

/** ADT Stack implementation.
    @file Stack.cpp */

#include <iostream>
#include <cstddef>
#include <cassert>
#include "Stack.hpp"
#include "Node.hpp"

// TODO: Implement the constructor here
template<class ItemType>
Stack<ItemType>::Stack() : headPtr(nullptr), currentSize(0)
{
}  // end default constructor

// TODO: Implement the destructor here
template<class ItemType>
Stack<ItemType>::~Stack()
{
	clear(); // run clear command it does same thing
}  // end destructor

// TODO: Implement the isEmpty method here
template<class ItemType>
bool Stack<ItemType>::isEmpty() const
{
	//check to see if the headPtr is pointing to anything
	return headPtr == nullptr;
}  // end isEmpty

// TODO: Implement the size method here
template<class ItemType>
int Stack<ItemType>::size() const
{
	return currentSize;
}  // end size

// TODO: Implement the push method here
template<class ItemType>
bool Stack<ItemType>::push(const ItemType& newItem)
{
	Node<ItemType>* newNode = new Node<ItemType>(newItem, headPtr);//create node for the newItem and have its nextNodePtr point to the headPtr
	headPtr = newNode; //set the head pointer to the head of the newNode
	newNode = nullptr; //then nullify the newNodePtr since it was used temporarily
	currentSize++; //increment the size
	return true;
}  // end push

// TODO: Implement the peek method here
template<class ItemType>
ItemType Stack<ItemType>::peek() const throw(logic_error)
{
	assert(!isEmpty()); //enforce pre condition before checking

	//if assert passes the stack has items
	return headPtr->getItem(); //return what headPtr points to
}  // end peek

// TODO: Implement the pop method here
template<class ItemType>
bool Stack<ItemType>::pop()
{
	if(!isEmpty()){
		//stack is not empty, so delete top most element
		Node<ItemType>* tempDeleteNode = headPtr; // crease a temp node to delete with
		headPtr = headPtr->getNext(); //get node after head ptr and move head ptr to that node ptr

		//return deleted node to system
		tempDeleteNode->setNext(nullptr); //set the previous headptr to null, effectivley deleteing node
		delete tempDeleteNode; //clean up the temp variable
		tempDeleteNode = nullptr;
		currentSize--; //decrement the size

		return true;//successful deletion/pop
	}
	return false;
}  // end pop

// TODO: Implement the clear method here
template<class ItemType>
void Stack<ItemType>::clear()
{
	//pop stack until empty
	while (!isEmpty()){
		pop();
	}
}  // end clear
