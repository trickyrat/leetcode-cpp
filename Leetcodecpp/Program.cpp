#include <iostream>
#include "Utilities.h"

int main() { 
  std::cout << "Hello, world\n";
  Utilities utilities;
  std::string nums = "1,2,3";
  std::string delimeter = ",";
  std::vector<std::string> res = utilities.split(nums, delimeter);
  TreeNode *root = utilities.create_treenode_with_bfs(nums);
  return 0;
}