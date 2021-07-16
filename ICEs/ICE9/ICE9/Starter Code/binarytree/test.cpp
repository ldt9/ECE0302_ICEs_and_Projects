#include <iostream>
using std::cout;
using std::endl;

#include "BinaryTree.h"

typedef std::string ItemType;
typedef void (*FunctionType)(ItemType& anItem);

void PrintNode(ItemType& i) { cout << i << endl; };

int main(int argc, char** argv)
{
    BinaryTree<ItemType, FunctionType> T1("B");
    BinaryTree<ItemType, FunctionType> T2("C");
    BinaryTree<ItemType, FunctionType> T4("D");
    BinaryTree<ItemType, FunctionType> T5("E");
    BinaryTree<ItemType, FunctionType> T6("F");
    BinaryTree<ItemType, FunctionType> T7("G");
    BinaryTree<ItemType, FunctionType> T8("H");
    BinaryTree<ItemType, FunctionType> T9("I");


    BinaryTree<ItemType, FunctionType> T3("A");
    T3.attachLeftSubtree(T1);
    T3.attachRightSubtree(T2);
    T3.postorderTraverse(&PrintNode);
    T3.preorderTraverse(&PrintNode);
    T3.inorderTraverse(&PrintNode);

    T4.attachLeftSubtree(T5);
    T4.attachRightSubtree(T6);
    T4.postorderTraverse(&PrintNode);
    T4.preorderTraverse(&PrintNode);
    T4.inorderTraverse(&PrintNode);

    T7.attachLeftSubtree(T8);
    T7.attachRightSubtree(T9);
    T7.postorderTraverse(&PrintNode);
    T7.preorderTraverse(&PrintNode);
    T7.inorderTraverse(&PrintNode);

    BinaryTree<ItemType, FunctionType> T10("C", T4, T7);
    T10.postorderTraverse(&PrintNode);
    T10.preorderTraverse(&PrintNode);
    T10.inorderTraverse(&PrintNode);
    T10.detachLeftSubtree(T4);
    T10.postorderTraverse(&PrintNode);
    T10.preorderTraverse(&PrintNode);
    T10.inorderTraverse(&PrintNode);
    T10.detachRightSubtree(T7);
    T10.postorderTraverse(&PrintNode);
    T10.preorderTraverse(&PrintNode);
    T10.inorderTraverse(&PrintNode);

    BinaryTree<ItemType, FunctionType> T11(T10);
    T11.postorderTraverse(&PrintNode);
    T11.preorderTraverse(&PrintNode);
    T11.inorderTraverse(&PrintNode);

    BinaryTree<ItemType, FunctionType> T12 = T11;
    T12.postorderTraverse(&PrintNode);
    T12.preorderTraverse(&PrintNode);
    T12.inorderTraverse(&PrintNode);

    BinaryTree<ItemType, FunctionType> T13("Y");
    T13.attachLeft("Z");
    T13.attachRight("X");
    T13.postorderTraverse(&PrintNode);
    T13.preorderTraverse(&PrintNode);
    T13.inorderTraverse(&PrintNode);

    BinaryTree<ItemType, FunctionType> T14;
    T14.setRootData("J");
    assert(!T14.isEmpty());
    assert(T14.rootData() == "J");

    // now T1 and T2 are no longer trees, but empty objects

    return 0;
};
