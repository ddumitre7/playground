//============================================================================
// Name        : circular_buffer_uint32.h
// Author      : Dan
// Version     :
// Copyright   :
// Description : Header file in C++, Ansi-style
//============================================================================

#ifndef BST_H
#define BST_H

#include <vector>

using namespace std;

struct bst_node {
  int val{0};
  bst_node *left{nullptr}, *right{nullptr};
  bst_node(int data) : val{data} {}
  virtual ~bst_node() {
    delete (left);
    delete (right);
  }
};

bst_node *insert(bst_node *root, int data);

void preorder_recursive(bst_node *root, vector<int> &v);
void inorder_recursive(bst_node *root, vector<int> &v);
void postorder_recursive(bst_node *root, vector<int> &v);

void preorder_iterative(bst_node *root, vector<int> &v);
void inorder_iterative(bst_node *root, vector<int> &v);
void postorder_iterative(bst_node *root, vector<int> &v);

#endif /* BST_H */
