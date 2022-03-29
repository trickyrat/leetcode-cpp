#include "pch.h"

#include "../Leetcodecpp/Solution.cpp"
#include "../Leetcodecpp/Solution.h"
#include "../Leetcodecpp/AllOne.h"
#include "../Leetcodecpp/AllOne.cpp"


using namespace std;

TEST(SolutionTest, TwoSumTest) {
  vector<int> expected1 = {0, 1};
  vector<int> input1 = {2, 7, 11, 15};
  vector<int> actual1 = Solution::twoSum(input1, 9);
  EXPECT_EQ(expected1, actual1);

  vector<int> expected2 = {1, 2};
  vector<int> input2 = {3, 2, 4};
  vector<int> actual2 = Solution::twoSum(input2, 6);
  EXPECT_EQ(expected2, actual2);

  vector<int> expected3 = {0, 1};
  vector<int> input3 = {3, 3};
  vector<int> actual3 = Solution::twoSum(input3, 6);
  EXPECT_EQ(expected3, actual3);
}

TEST(SolutionTest, LengthOfLongestSubstring) {
  EXPECT_EQ(3, Solution::lengthOfLongestSubstring("abcabcbb"));
  EXPECT_EQ(1, Solution::lengthOfLongestSubstring("bbbbb"));
  EXPECT_EQ(3, Solution::lengthOfLongestSubstring("pwwkew"));
}

TEST(SolutionTest, LengthOfLongestSubstringTest) {
  EXPECT_EQ(3, Solution::lengthOfLongestSubstring("pwwkew"));
  EXPECT_EQ(1, Solution::lengthOfLongestSubstring("bbbbb"));
  EXPECT_EQ(3, Solution::lengthOfLongestSubstring("abcabcbb"));
}

TEST(SolutionTest, IntToRomanTest) {
  EXPECT_EQ("I", Solution::intToRoman(1));
  EXPECT_EQ("X", Solution::intToRoman(10));
  EXPECT_EQ("VI", Solution::intToRoman(6));
}

TEST(SolutionTest, SearchInsertTest) {
  vector<int> nums1 = {1, 3, 5, 6};
  vector<int> nums2 = {1, 3, 5, 6};
  vector<int> nums3 = {1, 3, 5, 6};
  vector<int> nums4 = {1, 3, 5, 6};
  vector<int> nums5 = {1};
  EXPECT_EQ(2, Solution::searchInsert(nums1, 5));
  EXPECT_EQ(1, Solution::searchInsert(nums2, 2));
  EXPECT_EQ(4, Solution::searchInsert(nums3, 7));
  EXPECT_EQ(0, Solution::searchInsert(nums4, 0));
  EXPECT_EQ(0, Solution::searchInsert(nums5, 0));
}

TEST(SolutionTest, TrailingZeroesTest) {
  EXPECT_EQ(0, Solution::trailingZeroes(3));
  EXPECT_EQ(1, Solution::trailingZeroes(5));
  EXPECT_EQ(0, Solution::trailingZeroes(0));
}

TEST(FindDiagonalOrderTest, Test1) {
  vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  vector<int> expected = {1, 2, 4, 7, 5, 3, 6, 8, 9};
  vector<int> actual = Solution::findDiagonalOrder(matrix);
  EXPECT_EQ(expected, actual);
}



TEST(SolutionTest, ConvertToBase7Test) {
  EXPECT_EQ("202", Solution::convertToBase7(100));
  EXPECT_EQ("-10", Solution::convertToBase7(-7));
}

TEST(SolutionTest, PivotIndexTest) {

  vector<int> nums1 = {2, 3, -1, 8, 4};
  vector<int> nums2 = {1, -1, 4};
  vector<int> nums3 = {2, 5};
  EXPECT_EQ(3, Solution::pivotIndex(nums1));
  EXPECT_EQ(2, Solution::pivotIndex(nums2));
  EXPECT_EQ(-1, Solution::pivotIndex(nums3));
}
TEST(PlatesBetweenCandles, Test1) {
  vector<vector<int>> queries1 = {{2, 5}, {5, 9}};
  vector<int> expected = {2, 3};
  auto actual = Solution::platesBetweenCandles("**|**|***|", queries1);

  EXPECT_EQ(expected, actual);
}

TEST(PlatesBetweenCandles, Test2) {
  vector<vector<int>> queries1 = {{1, 17}, {4, 5}, {14, 17}, {5, 11}, {15, 16}};
  vector<int> expected = {9, 0, 0, 0, 0};
  auto actual =
      Solution::platesBetweenCandles("***|**|*****|**||**|*", queries1);

  EXPECT_EQ(expected, actual);
}


TEST(AllOneTest, Test1) { 
  AllOne allOne; 
  allOne.inc("hello");
  allOne.inc("hello");
  string actualMaxKey1 = allOne.getMaxKey();
  string expected1 = "hello";
  EXPECT_EQ(expected1, actualMaxKey1);
  string actualMinKey1 = allOne.getMinKey();
  string expected2 = "hello";
  EXPECT_EQ(expected2, actualMinKey1);
  allOne.inc("leet");
  string actualMaxKey2 = allOne.getMaxKey();
  string expected3 = "hello";
  EXPECT_EQ(expected3, actualMaxKey2);
  string actualMinKey2 = allOne.getMinKey();
  string expected4 = "leet";
  EXPECT_EQ(expected4, actualMinKey2);
}