#include <iostream>
#include <vector>

#include "bst.h"

using namespace std;

int main() {
  cout << "Start..." << endl << endl;

  bst_node *tree{nullptr};

  tree = insert(tree, 10);
  insert(tree, 20);
  insert(tree, 40);
  insert(tree, 30);
  insert(tree, 15);
  insert(tree, 5);
  insert(tree, 7);

  vector<int> v;

  // Recursive
  preorder_recursive(tree, v);
  cout << "Preoder recursively:" << endl;
  for (auto e : v) {
    cout << e << " ";
  }

  cout << endl;

  v.clear();
  inorder_recursive(tree, v);
  cout << "Inorder recursively:" << endl;
  for (auto e : v) {
    cout << e << " ";
  }

  cout << endl;

  v.clear();
  postorder_recursive(tree, v);
  cout << "Postorder recursively:" << endl;
  for (auto e : v) {
    cout << e << " ";
  }

  cout << endl;

  // Iterative
  v.clear();
  preorder_iterative(tree, v);
  cout << "Preoder iteratively:" << endl;
  for (auto e : v) {
    cout << e << " ";
  }

  cout << endl;

//   v.clear();
//   inorder_iterative(tree, v);
//   cout << "Inorder iteratively:" << endl;
//   for (auto e : v) {
//     cout << e << " ";
//   }

//   cout << endl;

//   v.clear();
//   postorder_iterative(tree, v);
//   cout << "Postoder iteratively:" << endl;
//   for (auto e : v) {
//     cout << e << " ";
//   }

//   cout << endl;

  delete (tree);
  cout << endl;
  cout << "End!" << endl;

  return 0;
}
