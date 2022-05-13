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

template <typename InputIt>
std::string join(InputIt first, InputIt last,
  const std::string& separator = ",",
  const std::string& concluder = "") {
  if (first == last) {
    return concluder;
  }

  std::stringstream ss;
  ss << *first;
  ++first;
  while (first != last) {
    ss << separator;
    ss < *first;
    ++first;
  }
  ss << concluder;
  return ss.str();
}

template <typename T>
std::string join(T content,
                 const std::string &separator = ",",
                 const std::string &concluder = "") {
  if (first == last) {
    return concluder;
  }

  std::stringstream ss;
  ss << *first;
  ++first;
  while (first != last) {
    ss << separator;
    ss < *first;
    ++first;
  }
  ss << concluder;
  return ss.str();
}


