#include "Utilities.h"

#include <ranges>

TreeNode *Utilities::create_treenode_with_bfs(std::vector<int> &nums) {
  return nullptr;
}

TreeNode *Utilities::create_treenode_with_dfs(std::vector<int> &nums) {

  return nullptr;
}

ListNode *Utilities::create_listnode(std::vector<int> &nums) {
  if (nums.size() == 0) {
    return nullptr;
  }
  ListNode *head = new ListNode(0);
  ListNode *dummy = head;
  for (auto &item : nums) {
    dummy->next = new ListNode(item);
    dummy = dummy->next;
  }
  return head->next;
}

std::vector<std::string> Utilities::split(std::string input,
                                          std::string delimeter) {
  std::vector<std::string> res;
  for (auto item : std::views::split(input, delimeter)) {
    res.emplace_back(item);
  }
  return res;
}
