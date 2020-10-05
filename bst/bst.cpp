#include "bst.h"

#include <iostream>
#include <stack>

bst_node* insert(bst_node* root, int data) {
  if (!root) {
    auto node_ptr = new bst_node{data};
    return node_ptr;
  }

  auto node_ptr = root;
  while (true) {
    if (data == node_ptr->val) break;

    if (data > node_ptr->val) {
      if (node_ptr->right) {
        node_ptr = node_ptr->right;
        continue;
      } else {
        node_ptr->right = new bst_node{data};
        break;
      }
    } else {
      if (node_ptr->left) {
        node_ptr = node_ptr->left;
        continue;
      } else {
        node_ptr->left = new bst_node{data};
        break;
      }
    }

  }  // End while loop

  return root;
}

void preorder_recursive(bst_node* root, vector<int>& v) {
  if (!root) return;

  v.push_back(root->val);

  if (root->left) preorder_recursive(root->left, v);

  if (root->right) preorder_recursive(root->right, v);

  return;
}

void inorder_recursive(bst_node* root, vector<int>& v) {
  if (!root) return;

  if (root->left) inorder_recursive(root->left, v);

  v.push_back(root->val);

  if (root->right) inorder_recursive(root->right, v);

  return;
}

void postorder_recursive(bst_node* root, vector<int>& v) {
  if (!root) return;

  if (root->left) postorder_recursive(root->left, v);

  if (root->right) postorder_recursive(root->right, v);

  v.push_back(root->val);

  return;
}

void preorder_iterative(bst_node* root, vector<int>& v) {
  if (!root) return;

  stack<bst_node*> s;

  s.push(root);
 
  while (s.empty() == false) {
    auto node_ptr = s.top();
    v.push_back(node_ptr->val);
    s.pop();
    if (node_ptr->right) s.push(node_ptr->right);
    if (node_ptr->left) s.push(node_ptr->left);
  }

  return;
}

void inorder_iterative(bst_node* root, vector<int>& v) {
  if (!root) return;

  if (root->left) preorder_recursive(root->left, v);

  v.push_back(root->val);

  if (root->right) preorder_recursive(root->right, v);

  return;
}

void postorder_iterative(bst_node* root, vector<int>& v) {
  if (!root) return;

  stack<bst_node*> s;

  s.push(root);
 
  while (s.empty() == false) {
    auto node_ptr = s.top();
    v.push_back(node_ptr->val);
    s.pop();
    if (node_ptr->right) s.push(node_ptr->right);
    if (node_ptr->left) s.push(node_ptr->left);
  }

  return;
}