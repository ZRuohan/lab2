// intbst.cpp
// Implements class IntBST
// Ruohan Zhou, 10/23 2026

#include "intbst.h"

#include <iostream>
using std::cout;

// constructor sets up empty tree
IntBST::IntBST() {
  root = nullptr;
}

// destructor deletes all nodes
IntBST::~IntBST() {
  clear(root);
}

// recursive helper for destructor
void IntBST::clear(Node *n) {
  if(n){
    clear(n->left);
    clear(n->right);
    delete n;
  }
  return;
}

// insert value in tree; return false if duplicate
bool IntBST::insert(int value) {
    if(!root){
      root = new Node(value);
      return true;
    }
    return insert(value, root);
}

// recursive helper for insert (assumes n is never 0)
bool IntBST::insert(int value, Node *n) {
    if (value == n->info) {
        return false;
    }

    if (value < n->info) {

        if (n->left) {
            return insert(value, n->left);
        }
        n->left = new Node(value);
        n->left->parent = n;
        return true;
    }

    if(value > n->info){
        if (n->right) {
            return insert(value, n->right);
        }
        n->right = new Node(value);
        n->right->parent = n;
        return true;
    }
}

// print tree data pre-order
void IntBST::printPreOrder() const {
    //cout << "IMPLEMENT printPreOrder public method";; // IMPLEMENT HERE
    //if (!n){
      //return;
    //}
    //printPreOrder(n->left);
    //printPreOrder(n->right);
    printPreOrder(root);
}

// recursive helper for printPreOrder()
void IntBST::printPreOrder(Node *n) const {
    if(!n){
      return;
    }
    cout << n->info << " ";
     // IMPLEMENT HERE
     printPreOrder(n->left);
     printPreOrder(n -> right);
}

//// print tree data pre-order
void IntBST::printInOrder() const {
    //cout << "IMPLEMENT printPreOrder public method";; // IMPLEMENT HERE
    //i
    printInOrder(root);
}

// recursive helper for printPreOrder()
void IntBST::printInOrder(Node *n) const {
    if(!n){
      return;
    }
    //cout << n->info << " ";
     // IMPLEMENT HERE
     printInOrder(n->left);
       cout << n->info << " ";
     printInOrder(n -> right);
}

// prints tree data post-order, with helper
void IntBST::printPostOrder() const {
    //cout << "IMPLEMENT printPreOrder public method";; // IMPLEMENT HERE
    //i
    printPostOrder(root);
}

// recursive helper for printPreOrder()
void IntBST::printPostOrder(Node *n) const {
    if(!n){
      return;
    }

     // IMPLEMENT HERE
     printPostOrder(n->left);
     printPostOrder(n -> right);
       cout << n->info << " ";
}


// return sum of values in tree
int IntBST::sum() const {
     // REPLACE THIS NON-SOLUTION
     return sum(root);
}

// recursive helper for sum
int IntBST::sum(Node *n) const {
    //return -1;
    if (!n) return 0;
    return n->info + sum(n->left) + sum(n->right); // REPLACE THIS NON-SOLUTION
}

// return count of values
int IntBST::count() const {
    return count(root);
     // REPLACE THIS NON-SOLUTION
}

// recursive helper for count
int IntBST::count(Node *n) const {
  if (!n) return 0;
  return 1 + count(n->left) + count(n->right);  // REPLACE THIS NON-SOLUTION
}

// IMPLEMENT THIS FIRST: returns the node for a given value or NULL if none exists
// Parameters:
// int value: the value to be found
// Node* n: the node to start with (for a recursive call)
// Whenever you call this method from somewhere else, pass it
// the root node as "n"
IntBST::Node* IntBST::getNodeFor(int value, Node* n) const{
    //if (!this){
    //ret
    if(!n){
      return nullptr;
    } // REPLACE THIS NON-SOLUTION
    if(value== n->info){ return n;}
    if (value < n->info) {return getNodeFor(value, n->left);}
    else{return getNodeFor(value, n->right);}
}

// returns true if value is in the tree; false if not
bool IntBST::contains(int value) const {

      if(getNodeFor(value, this->root)){
        return true;
      }// REPLACE THIS NON-SOLUTION
      return false;
}

// returns the Node containing the predecessor of the given value
IntBST::Node* IntBST::getPredecessorNode(int value) const{
  Node* n = getNodeFor(value, root);
  if (!n){
    return nullptr;
  }
  if (n->left) {
      Node* curr = n->left;
          while (curr->right) {
          curr = curr->right;
      }
      return curr;
  } else {  //l-cond
      Node* curr = n;
      Node* p = curr->parent;

      while (p && curr == p->left) {
            curr = p;
          p = p->parent;
      }
      return p;
  } // REPLACE THIS NON-SOLUTION
}

// returns the predecessor value of the given value or 0 if there is none
int IntBST::getPredecessor(int value) const{
    Node* temp = getPredecessorNode(value);
    if(temp){
      return temp->info;
    }
    return 0;
}

// returns the Node containing the successor of the given value
IntBST::Node* IntBST::getSuccessorNode(int value) const{
  Node* n = getNodeFor(value, root);
  if (!n){
    return nullptr;
  }
  if (n->right) {
      Node* curr = n->right;
          while (curr->left) {
          curr = curr->left;
      }
      return curr;
  } else {  //l-cond
      Node* curr = n;
      Node* p = curr->parent;

      while (p && curr == p->right) {
            curr = p;
          p = p->parent;
      }
      return p;
  } // REPLACE THIS NON-SOLUTION
}

// returns the successor value of the given value or 0 if there is none
int IntBST::getSuccessor(int value) const{
  Node* temp = getSuccessorNode(value);
  if(temp){
    return temp->info;
  }
  return 0; // REPLACE THIS NON-SOLUTION
}

// deletes the Node containing the given value from the tree
bool IntBST::remove(int value){
    Node* n = getNodeFor(value, root);
    if (!n) return false;

    if (!n->left && !n->right) {
        if (!n->parent) {
              this->root = nullptr;
            return true;
        }
          if (n == n->parent->left) {

            n->parent->left = nullptr;
        } else {
            n->parent->right = nullptr;
        }
        delete n;
        return true;
    }

    if (!n->left) {
        if (!n->parent) {
            this->root = n->right;
        }
        else if (n == n->parent->left) {
            n->parent->left = n->right;


        //el{
        } else {
            n->parent->right = n->right;
        }
        n->right->parent = n->parent;
        delete n;
        return true;
    }

    if (!n->right) {
        if (!n->parent) {
            root = n->left;
        } else if (n == n->parent->left) {
            n->parent->left = n->left;
        } else {
            n->parent->right = n->left;
        }
        n->left->parent = n->parent;
        delete n;
        return true;
    }

    Node* scnd = getSuccessorNode(value);
    //n->info = scnd->info;
    //return remove(scnd->info);

    n->info = scnd->info;
    if (scnd->parent->left == scnd) {
        scnd->parent->left = scnd->right;
    } else {
        scnd->parent->right = scnd->right;
    }
    if (scnd->right) {
        scnd->right->parent = scnd->parent;
    }
    delete scnd;
    return true;
}
