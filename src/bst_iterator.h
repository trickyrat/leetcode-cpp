#pragma once
#include <stack>

#include "data_structure.h"

class BSTIterator {
private:
  std::stack<TreeNode*> nodes;

public:
  BSTIterator(TreeNode* root) {
    while (root) {
      nodes.push(root);
      root = root->left;
    }
  }

  /// <summary>
  /// return the next smallest number.
  /// </summary>
  /// <returns></returns>
  int next() {
    TreeNode* tmp = nodes.top();
    nodes.pop();
    TreeNode* right = tmp->right;
    while (right) {
      nodes.push(right);
      right = right->left;
    }
    return tmp->val;
  }

  /// <summary>
  ///  whether there is a next smallest number.
  /// </summary>
  /// <returns></returns>
  bool hasNext() { return !nodes.empty(); }
};