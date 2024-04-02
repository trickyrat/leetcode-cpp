#pragma once

#include <string>
#include <vector>

#include "data_structure.h"

class Utils {
public:
  static TreeNode *generate_tree_node(std::string &data,
                                      std::string delimeter = ",");

  static ListNode *generate_list_node(std::vector<int> &nums);

  static ListNode *detect_cycle(ListNode *head);

  static std::string list_node_to_string(ListNode *head,
                                         std::string separator = "->");

  static std::vector<std::string> split(const std::string &input,
                                        const std::string &delimeter);

  static std::vector<int> inorder_traversal(TreeNode *root);

  static std::vector<int> preordere_traversal(TreeNode *root);

  static bool is_same_tree(TreeNode *lhs, TreeNode *rhs);
};