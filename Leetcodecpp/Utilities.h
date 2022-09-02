#pragma once

#include "ListNode.h"
#include "TreeNode.h"

#include <string>
#include <stack>
#include <vector>
#include <queue>

class Utilities {
private:
  static TreeNode *dfs(std::vector<std::string> &data);

public:
  static TreeNode *createTreeNodeIteratively(std::string &data);

  static ListNode *createListNode(std::vector<int> &nums);

  static std::vector<std::string> split(const std::string &input, const std::string &delimeter);

  static std::vector<int> inorderTraversal(TreeNode *root);

  static std::vector<int> preordereTraversal(TreeNode *root);

  static bool isSameTree(TreeNode *lhs, TreeNode *rhs);
};