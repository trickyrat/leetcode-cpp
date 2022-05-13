#pragma once

#include <string>
#include <stack>
#include <vector>

#include "TreeNode.h"

class Codec {
private:
  TreeNode* build(int lower, int upper, std::stack<int> &st);
  void postOrder(TreeNode *root, std::vector<int> &arr);


public:
  std::string serialize(TreeNode *root);
  TreeNode *deserialize(std::string data);
};
