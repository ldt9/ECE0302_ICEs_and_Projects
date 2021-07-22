#include "binary_search_tree.h"

template <typename KeyType, typename ItemType>
BinarySearchTree<KeyType, ItemType>::BinarySearchTree()
{
    root = 0;
}

template <typename KeyType, typename ItemType>
BinarySearchTree<KeyType, ItemType>::BinarySearchTree(
    const BinarySearchTree<KeyType, ItemType>& rhs)
{
    root = 0;
    clone(rhs.root);
}

// this is an alternative implementation using a stack to simulate the recursion
template <typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::clone(Node<KeyType, ItemType>* rhs)
{
    Node<KeyType, ItemType>** lhs = &root;

    std::stack<stackvar<KeyType, ItemType>> s;

    stackvar<KeyType, ItemType> rootvar;
    rootvar.rhs = rhs;
    rootvar.lhs = lhs;
    s.push(rootvar);

    while (!s.empty()) {
        stackvar<KeyType, ItemType> currentvar = s.top();
        s.pop();

        Node<KeyType, ItemType>* curr_rhs = currentvar.rhs;
        Node<KeyType, ItemType>** curr_lhs = currentvar.lhs;

        if (curr_rhs == 0)
            continue;

        // allocate new node and copy contents
        Node<KeyType, ItemType>* temp = new Node<KeyType, ItemType>;
        temp->key = curr_rhs->key;
        temp->data = curr_rhs->data;
        temp->left = 0;
        temp->right = 0;
        *curr_lhs = temp;

        // push left subtree
        currentvar.rhs = curr_rhs->left;
        currentvar.lhs = &((*curr_lhs)->left);
        s.push(currentvar);

        // push right subtree
        currentvar.rhs = curr_rhs->right;
        currentvar.lhs = &((*curr_lhs)->right);
        s.push(currentvar);
    }
}

template <typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::destroy()
{
    std::stack<Node<KeyType, ItemType>*> s;
    s.push(root);

    while (!s.empty()) {
        Node<KeyType, ItemType>* curr = s.top();
        s.pop();

        if (curr != 0) {
            s.push(curr->left);
            s.push(curr->right);
            delete curr;
        }
    }
    root = 0;
}

template <typename KeyType, typename ItemType>
BinarySearchTree<KeyType, ItemType>& BinarySearchTree<KeyType, ItemType>::
operator=(const BinarySearchTree<KeyType, ItemType>& rhs)
{
    if (&rhs == this)
        return *this;

    destroy();

    root = 0;
    clone(rhs.root);

    return *this;
}

template <typename KeyType, typename ItemType>
BinarySearchTree<KeyType, ItemType>::~BinarySearchTree()
{
    destroy();
}

template <typename KeyType, typename ItemType>
bool BinarySearchTree<KeyType, ItemType>::insert(
    const KeyType& key, const ItemType& item)
{
    // TODO
    //create a new node with the given parameters
    Node<KeyType, ItemType>* curr = new Node<KeyType, ItemType>;
    curr = root; //make curr equal to the root so we have a starting place

    //make a new node and point its key and data to the parameters
    Node<KeyType, ItemType>* insNode = new Node<KeyType, ItemType>;
    insNode->data = item;
    insNode->key = key;

    //make an empty node to be used as a dummy node
    Node<KeyType, ItemType>* mt = new Node<KeyType, ItemType>;
    mt = nullptr;

    //std::cout << "past here" << std::endl;

    //test to see if tree is empty
    //if it is make the new node the root
    if(root == nullptr){
      root = insNode;
      insNode = nullptr;
      curr = nullptr;
      delete curr;
      delete insNode;
      delete mt;

      return true; //because node was insterted at the root
    }

    //std::cout << "past there" << std::endl;

    //if theres something in the tree, search for the same key
    //if it exists, do not insert, else insert
    //search for the key in the tree
    search(key, curr, mt);
    mt = nullptr; // reset the empty node
    //if the key is found in the tree, return false because it already
    //exists in the tree
    if(curr->data != item){
      if(key < curr->key){
        //insert at the left child
        curr->left = insNode;
      }
      else{
        //insert at the right child
        curr->right = insNode;
      }
      insNode = nullptr;
      curr = nullptr;
      delete curr;
      delete insNode;
      delete mt;

      //std::cout << "made it here" << std::endl;

      return true; //because node was insterted
    }
    insNode = nullptr;
    curr = nullptr;
    delete curr;
    delete insNode;
    delete mt;

    //std::cout << "made it there" << std::endl;

    return false; //because node was not inserted
}

template <typename KeyType, typename ItemType>
bool BinarySearchTree<KeyType, ItemType>::isEmpty()
{
    return (root == 0);
}

template <typename KeyType, typename ItemType>
bool BinarySearchTree<KeyType, ItemType>::retrieve(
    const KeyType& key, ItemType& item)
{
    Node<KeyType, ItemType>* curr;
    Node<KeyType, ItemType>* curr_parent;
    search(key, curr, curr_parent);

    if (curr == 0)
        return false;

    if (curr->key == key) {
        item = curr->data;
        return true;
    }

    return false;
}

template <typename KeyType, typename ItemType>
bool BinarySearchTree<KeyType, ItemType>::remove(KeyType key)
{
  if (isEmpty()) return false; // empty tree

  // TODO
  Node<KeyType, ItemType>* curr = new Node<KeyType, ItemType>;
  curr = root; //make curr equal to the root so we have a starting place

  //make an empty node to be used as a dummy node
  Node<KeyType, ItemType>* parent = new Node<KeyType, ItemType>;
  parent = nullptr;

  //preliminary search for item to be removed
  search(key, curr, parent);

  //case item not found in tree
  if(curr->key != key){

    //std::cout << "no key" << std::endl;

    curr = nullptr;
    parent = nullptr;
    delete curr;
    delete parent;

    return false;
  }

  // case one thing in the tree (i.e. key was found and the tree only had one element)
  if(root->left == nullptr && root->right == nullptr && key == root->key){
    //std::cout << "one thing in tree" << std::endl;

    root = nullptr;

    curr = nullptr;
    parent = nullptr;
    delete curr;
    delete parent;

    return true;
  }

  // case, found deleted item at leaf
  if(parent != nullptr && curr->left == nullptr && curr->right == nullptr){
    //std::cout << "key at leaf" << std::endl;

    if(parent->left == curr){
      parent->left = nullptr;
    }
    else parent->right = nullptr;

    delete curr;
    parent = nullptr;
    delete parent;

    return true;
  }

  // case, item to delete has only a right child
  if(curr->left == nullptr && curr->right != nullptr){
    //std::cout << "key has right child" << std::endl;

    if(curr == root){
      root = curr->right; //move the root to the right node
    }

    else if(parent->left == curr){
      parent->left = curr->right; //Link curr's right subtree to parent left
    }

    else{
      parent->right = curr->right; //Link curr's right subtree to parent right
    }

    parent = nullptr;
    delete curr;
    delete parent;

    return true;
  }

  // case, item to delete has only a left child
  if(curr->left != nullptr && curr->right == nullptr){
    //std::cout << "key has left child" << std::endl;

    if(curr == root){
      root = curr->left; //move the root to the left node
    }

    else if(parent->left == curr){
      parent->left = curr->left; //Link curr's left subtree to parent left
    }

    else{
      parent->right = curr->left; //Link curr's left subtree to parent right
    }

    parent = nullptr;
    delete curr;
    delete parent;

    return true;
  }

  // case, item to delete has two children
  if(curr->left != nullptr && curr->right != nullptr){
    //std::cout << "key has 2 children" << std::endl;

    //make a new node to hold in order successor and successor parent
    Node<KeyType, ItemType>* in = new Node<KeyType, ItemType>;
    in = nullptr;
    Node<KeyType, ItemType>* inParent = new Node<KeyType, ItemType>;
    inParent = nullptr;

    //find in order successor
    inorder(curr->right, in, inParent);

    //replace the deleted nodes data with the successor
    curr->key = in->key;
    curr->data = in->data;

    //set parent of successor to null after moving to curr's places
    if(inParent->left == in) inParent->left = nullptr;
    else inParent->right = nullptr;

    delete in;
    inParent = nullptr;
    delete inParent;

    curr = nullptr;
    delete curr;
    parent = nullptr;
    delete parent;

    return true;
  }
}

template <typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::inorder(Node<KeyType, ItemType>* curr,
    Node<KeyType, ItemType>*& in, Node<KeyType, ItemType>*& parent)
{
  // TODO
  // move right once, actually no
  // move left as far as possible

  if(curr->left == nullptr){
    in = curr;
    return;
  }

  inorder(curr->left, in, curr);
}

template <typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::search(KeyType key,
    Node<KeyType, ItemType>*& curr, Node<KeyType, ItemType>*& parent)
{
    curr = root;
    parent = 0;

    if (isEmpty())
        return;

    while (true) {
        if (key == curr->key) {
            break;
        } else if (key < curr->key) {
            if (curr->left != 0) {
                parent = curr;
                curr = curr->left;
            } else
                break;
        } else {
            if (curr->right != 0) {
                parent = curr;
                curr = curr->right;
            } else
                break;
        }
    }
}

template <typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::treeSort(ItemType itemArray[], int arraySize)
{
  //check to make sure itemArry has no duplicates
  //make an empty tree
  //take the arraySize in a for loop and insert into a tree using method
  //then find the smallest tree node using inorder using a while loop
  //replace the starting index in item array with that value
  //delete that value from the tree
  //repeat until the whle array is overwritten/all nodes in tree don't exist

  int dup = 0; //duplicate counter
  for(int i = 0; i < arraySize; i++){
    for(int j = 0; j < i; j++){
      if(itemArray[i] == itemArray[j]) throw std::range_error("There is a duplicate in the array.");
    }
  }
  destroy(); // clear the trees
  for(int i = 0; i < arraySize; i++){
    insert(itemArray[i], itemArray[i]);
    //insert the key and data of the array to be the node in the tree
  }

  //replace every index of the array witht eh inorder successor after removing each time
  int i = 0;
  while(!isEmpty()){
    Node<KeyType, ItemType>* curr = new Node<KeyType, ItemType>;
    curr = root;
    Node<KeyType, ItemType>* in = new Node<KeyType, ItemType>;
    Node<KeyType, ItemType>* parent = new Node<KeyType, ItemType>;
    in = nullptr;
    parent = nullptr;
    inorder(curr, in, parent);
    itemArray[i] = in->data;
    i++;
    remove(in->key);
    curr = nullptr;
    in = nullptr;
    parent = nullptr;

    delete curr;
    delete in;
    delete parent;
  }


}
