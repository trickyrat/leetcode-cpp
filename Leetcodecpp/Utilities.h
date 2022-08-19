#pragma once

#include "ListNode.h"
#include "TreeNode.h"

#include <string>
#include <vector>

class Utilities {
private:
  TreeNode *dfs(std::vector<std::string> &data);

public:
  TreeNode *create_treenode_with_bfs(std::string &data);
  TreeNode *create_treenode_with_dfs(std::string &data);

  static ListNode *create_listnode(std::vector<int> &nums);

  static std::vector<std::string> split(const std::string &input, const std::string &delimeter);
};