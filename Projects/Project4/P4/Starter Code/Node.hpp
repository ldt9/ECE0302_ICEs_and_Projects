#ifndef NODE_
#define NODE_

template<class ItemType>
class Node
{
private:
   ItemType        item; // A data item
   Node<ItemType>* next; // Pointer to next node

   //Node<ItemType>* getNodeBefore(const ItemType& anEntry) const;

public:
   Node();
   Node(const ItemType& anItem);
   Node(const ItemType& anItem, Node<ItemType>* nextNodePtr);
   void setItem(const ItemType& anItem);
   void setNext(Node<ItemType>* nextNodePtr);
   ItemType getItem() const ;
   Node<ItemType>* getNext() const ;
   //Node<ItemType>* getNodeBefore(const ItemType& anEntry) const ;
}; // end Node

#include "Node.cpp"
#endif
