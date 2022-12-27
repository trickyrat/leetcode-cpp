#include "Utilities.h"

#include <ranges>

TreeNode *Utilities::createTreeNodeIteratively(std::string &data) {
  if (data.empty()) {
    return nullptr;
  }
  std::string delimeter = ",";
  std::vector<std::string> nums = split(data, delimeter);
  if (nums[0] == "null") {
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
    if (cursor > len - 1 || nums[cursor] == "null") {
      node->left = nullptr;
    } else {
      TreeNode *left = new TreeNode(std::stoi(nums[cursor]));
      if (node != nullptr) {
        node->left = left;
      }
      q.push(left);
    }
    if (cursor + 1 > len - 1 || nums[cursor + 1] == "null") {
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

ListNode *Utilities::createListNode(std::vector<int> &nums) {
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

std::vector<std::string> Utilities::split(const std::string &input,
                                          const std::string &delimiter) {
  std::vector<std::string> result;

  std::size_t current = 0;
  std::size_t p = input.find_first_of(delimiter, 0);

  while (p != std::string::npos) {
    result.emplace_back(input, current, p - current);
    current = p + 1;
    p = input.find_first_of(delimiter, current);
  }

  result.emplace_back(input, current);

  return result;
}

std::vector<int> Utilities::inorderTraversal(TreeNode *root) {
  std::vector<int> res;
  std::stack<TreeNode *> stk;
  while (root != nullptr || !stk.empty()) {
    stk.push(root);
    root = root->left;
  }
  root = stk.top();
  stk.pop();
  res.push_back(root->val);
  root = root->right;
  return res;
}

std::vector<int> Utilities::preordereTraversal(TreeNode *root) {
  std::vector<int> res;
  if (root == nullptr) {
    return res;
  }

  std::stack<TreeNode *> stk;
  TreeNode *node = root;
  while (!stk.empty() || node != nullptr) {
    while (node != nullptr) {
      res.emplace_back(node->val);
      stk.emplace(node);
      node = node->left;
    }
    node = stk.top();
    stk.pop();
    node = node->right;
  }
  return res;
}

bool Utilities::isSameTree(TreeNode *lhs, TreeNode *rhs) { 
  if (lhs == nullptr && rhs == nullptr) {
    return true;
  } else if (lhs == nullptr || rhs == nullptr) {
    return false;
  }
  std::queue<TreeNode *> q1, q2;
  q1.push(lhs);
  q2.push(rhs);
  while (!q1.empty() && !q2.empty()) {
    auto node1 = q1.front();
    q1.pop();
    auto node2 = q2.front();
    q2.pop();
    if (node1->val != node2->val) {
      return false;
    }
    auto left1 = node1->left, right1 = node1->right, left2 = node2->left,
         right2 = node2->right;
    if ((left1 == nullptr) ^ (left2 == nullptr)) {
      return false;
    }
    if ((right1 == nullptr) ^ (right2 == nullptr)) {
      return false;
    }
    if (left1 != nullptr) {
      q1.push(left1);
    }
    if (right1 != nullptr) {
      q1.push(right1);
    }
    if (left2 != nullptr) {
      q2.push(left2);
    }
    if (right2 != nullptr) {
      q1.push(right2);
    }
  }

  return q1.empty() && q2.empty();
}

