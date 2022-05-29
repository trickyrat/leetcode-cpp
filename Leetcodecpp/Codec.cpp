#include "Codec.h"
#include "Utilities.h"

TreeNode *Codec::build(int lower, int upper, std::stack<int> &st) {
  int val = st.top(); 
  if (st.empty() || val < lower || val > upper) {
    return nullptr;
  }
  st.pop();
  TreeNode *root = new TreeNode(val);
  root->right = build(val, upper, st);
  root->left = build(lower, val, st);
  return root;
}

void Codec::postOrder(TreeNode *root, std::vector<int> &arr) {
  if (root == nullptr) {
    return;
  }
  postOrder(root->left, arr);
  postOrder(root->right, arr);
  arr.emplace_back(root->val);
}

std::string Codec::serialize(TreeNode *root) { 
  std::string res;
  std::vector<int> arr;
  postOrder(root, arr);
  if (arr.empty()) {
    return res;
  }
  for (int i = 0; i < arr.size() - 1; i++) {
    res.append(std::to_string(arr[i]) + ",");
  }
  res.append(std::to_string(arr.back()));
  return res;
}

TreeNode *Codec::deserialize(std::string data) { 
  if (data.size() == 0) {
    return nullptr;
  }
  Utilities utilities;
  std::string delimeter = ",";
  std::vector<std::string> arr = utilities.split(data, delimeter);
  std::stack<int> st;
  for (auto &str : arr) {
    st.emplace(std::stoi(str));
  }
  return build(INT_MIN, INT_MAX, st);
}
