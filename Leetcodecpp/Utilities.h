#pragma once

#include "ListNode.h"
#include "TreeNode.h"

#include <string>
#include <stack>
#include <vector>

class Utilities {
private:
  static TreeNode *dfs(std::vector<std::string> &data);

public:
  static TreeNode *create_treenode_with_bfs(std::string &data);
  static TreeNode *create_treenode_with_dfs(std::string &data);

  static ListNode *create_listnode(std::vector<int> &nums);

  static std::vector<std::string> split(const std::string &input, const std::string &delimeter);

  static std::vector<int> InorderTraversal(TreeNode *root);

  static std::vector<int> PreordereTraversal(TreeNode *root);
};