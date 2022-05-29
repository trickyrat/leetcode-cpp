#include "Utilities.h"

#include <ranges>
#include <queue>

#define NULLSTRING "null"


TreeNode *Utilities::dfs(std::vector<std::string> &data) {
  if (data.empty()) {
    return nullptr;
  }
  if (data[0] == NULLSTRING) {
    data.erase(data.begin());
    return nullptr;
  }
  TreeNode *root = new TreeNode(std::stoi(data[0]));
  data.erase(data.begin());
  root->left = dfs(data);
  root->right = dfs(data);
  return root;
}

TreeNode *Utilities::create_treenode_with_bfs(std::string &data) {
  if (data.empty()) {
    return nullptr;
  }
  std::string delimeter = ",";
  std::vector<std::string> nums = split(data, delimeter);
  if (nums[0] == NULLSTRING) {
    return nullptr;
  }
  TreeNode *root = new TreeNode(std::stoi(nums[0]));
  std::queue<TreeNode *> q;
  q.push(root);
  int cursor = 1;
  int len = nums.size();
  while (cursor < len) {
    TreeNode *node = q.front();
    q.pop();
    if (cursor > len - 1 || nums[cursor] == NULLSTRING) {
      node->left = nullptr;
    } else {
      TreeNode *left = new TreeNode(std::stoi(nums[cursor]));
      if (node != nullptr) {
        node->left = left;
      }
      q.push(left);
    }
    if (cursor + 1 > len - 1 || nums[cursor + 1] == NULLSTRING) {
      node->right = nullptr;
    } else {
      TreeNode *right = new TreeNode(std::stoi(nums[cursor + 1]));
      if (node != nullptr) {
        node->right = right;
      }
      q.push(right);
    }
    cursor += 2;
  }
  return root;
}

TreeNode *Utilities::create_treenode_with_dfs(std::string &data) {
  std::string delimeter = ",";
  std::vector<std::string> nums = split(data, delimeter);
  return dfs(nums);
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

std::vector<std::string> Utilities::split(const std::string &source,
                                          const std::string &delimeter) {
  std::vector<std::string> res;
  /*for (auto item : std::views::split(input, delimeter)) {
    res.emplace_back(item);
  }*/
  size_t prev = 0;
  size_t currentPos = 0;
  while ((currentPos = source.find_first_of(delimeter, prev)) != std::string::npos) {
    if (currentPos > prev) {
      res.push_back(source.substr(prev, currentPos - prev));
    }
    prev = currentPos + 1;
  }
  if (prev < source.length()) {
    res.push_back(source.substr(prev));
  }
  return res;
}
