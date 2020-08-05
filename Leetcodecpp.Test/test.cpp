#include "pch.h"

#include "../Leetcodecpp/Solution.h"
TEST(SolutionTest, TestCase1) {
  std::string s = "()(())";
  int actual = Solution::longestValidParentheses(s);
  int expected = 6;
  EXPECT_EQ(expected, actual);
}