#pragma once
#include <vector>
class NumArray {
public:
  NumArray(std::vector<int>& nums) {
    size_t len = nums.size();
    sum = std::vector<int>(len + 1);
    for (int i = 0; i < len; i++) {
      sum[i + 1] = sum[i] + nums[i];
    }
  };
  ~NumArray() = default;

  int sumRange(int i, int j) { return sum[j + 1] - sum[i]; }

private:
  std::vector<int> sum;
};
