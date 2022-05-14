#pragma once

#include "TreeNode.h"
#include "ListNode.h"


#include <string>
#include <vector>

class Utilities {
public:
  TreeNode *create_treenode_with_bfs(std::vector<int> &nums);
  TreeNode *create_treenode_with_dfs(std::vector<int> &nums);

  static ListNode *create_listnode(std::vector<int> &nums);

  std::vector<std::string> split(std::string input, std::string delimeter);

};