#pragma once

#include <list>
#include <string>
#include <vector>

#include "data_structure.h"
#include "utils.h"
namespace leetcode {
class Codec {
private:
  TreeNode *deserialize_core(std::list<std::string> &data_array) {
    if (data_array.front() == "None") {
      data_array.erase(data_array.begin());
      return nullptr;
    }
    TreeNode *root = new TreeNode(std::stoi(data_array.front()));
    data_array.erase(data_array.begin());
    root->left = deserialize_core(data_array);
    root->right = deserialize_core(data_array);
    return root;
  }
  void serialize_core(TreeNode *root, std::string &ret) {
    if (root == nullptr) {
      ret += "None,";
    } else {
      ret += std::to_string(root->val) + ",";
      serialize_core(root->left, ret);
      serialize_core(root->right, ret);
    }
  }

public:
  std::string serialize(TreeNode *root) {
    std::string res;
    serialize_core(root, res);
    return res;
  }
  TreeNode *deserialize(std::string data) {
    std::list<std::string> data_array;
    std::string str;
    for (auto &ch : data) {
      if (ch == ',') {
        data_array.push_back(str);
        str.clear();
      } else {
        str.push_back(ch);
      }
    }

    if (!str.empty()) {
      data_array.push_back(str);
      str.clear();
    }

    return deserialize_core(data_array);
  }
};
} // namespace leetcode