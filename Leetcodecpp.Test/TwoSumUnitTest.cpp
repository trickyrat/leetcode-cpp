#include "pch.h"
#include "../Leetcodecpp/Solution.h"
#include <vector>

using namespace std;

namespace SolutionTest {
TEST(TwoSumTest, AllPositive) {
  vector<int> expected1 = {0, 1};
  vector<int> input1 = {2, 7, 11, 15};
  vector<int> actual1 = Solution::twoSum(input1, 9);
  EXPECT_EQ(expected1, actual1);

  vector<int> expected2 = {1, 2};
  vector<int> input2 = {3, 2, 4};
  vector<int> actual2 = Solution::twoSum(input2, 6);
  EXPECT_EQ(expected2, actual2);
}

TEST(TwoSumTest, AllNegative) {
  vector<int> expected1 = {0, 1};
  vector<int> input1 = {-2, -7, -11, -15};
  vector<int> actual1 = Solution::twoSum(input1, -9);
  EXPECT_EQ(expected1, actual1);

  vector<int> expected2 = {1, 2};
  vector<int> input2 = {-3, -2, -4};
  vector<int> actual2 = Solution::twoSum(input2, -6);
  EXPECT_EQ(expected2, actual2);
}
}
