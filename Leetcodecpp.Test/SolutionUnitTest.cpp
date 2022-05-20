#include "pch.h"

#include "../Leetcodecpp/Solution.cpp"
#include "../Leetcodecpp/Solution.h"

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

TEST(SolutionTest, CountNumbersWithUniqueDigitsTest) {
  EXPECT_EQ(91, Solution::countNumbersWithUniqueDigits(2));
  EXPECT_EQ(1, Solution::countNumbersWithUniqueDigits(0));
}

TEST(SolutionTest, LexicalOrderTest) {
  vector<int> expected1 = {1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9};
  vector<int> expected2 = {1, 2};
  EXPECT_EQ(expected1, Solution::lexicalOrder(13));
  EXPECT_EQ(expected2, Solution::lexicalOrder(2));
}

TEST(SolutionTest, FindDiagonalOrderTest) {
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
  vector<int> nums1 = {1, 7, 3, 6, 5, 6};
  vector<int> nums2 = {1, 2, 3};
  vector<int> nums3 = {2, 1, -1};
  EXPECT_EQ(3, Solution::pivotIndex(nums1));
  EXPECT_EQ(-1, Solution::pivotIndex(nums2));
  EXPECT_EQ(0, Solution::pivotIndex(nums3));
}

TEST(SolutionTest, UniqueMorseRepresentationsTest) {
  vector<string> words1 = {"gin", "zen", "gig", "msg"};
  vector<string> words2 = {"a"};
  EXPECT_EQ(2, Solution::uniqueMorseRepresentations(words1));
  EXPECT_EQ(1, Solution::uniqueMorseRepresentations(words2));
}

TEST(SolutionTest, NumberOfLinesTest) {
  vector<int> widths1 = {10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,
                         10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
  vector<int> widths2 = {4,  10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,
                         10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
  string s1 = "abcdefghijklmnopqrstuvwxyz";
  string s2 = "bbbcccdddaaa";
  vector<int> expected1 = {3, 60};
  vector<int> expected2 = {2, 4};
  EXPECT_EQ(expected1, Solution::numberOfLines(widths1, s1));
  EXPECT_EQ(expected2, Solution::numberOfLines(widths2, s2));
}

TEST(SolutionTest, MinDeletionSizeTest) {
  vector<string> strs1{"cba", "daf", "ghi"};
  vector<string> strs2{"a", "b"};
  vector<string> strs3{"zyx", "wvu", "tsr"};
  EXPECT_EQ(1, Solution::minDeletionSize(strs1));
  EXPECT_EQ(0, Solution::minDeletionSize(strs2));
  EXPECT_EQ(3, Solution::minDeletionSize(strs3));
}

TEST(SolutionTest, RepeatedNTimesTest) {
  vector<int> nums1{1, 2, 3, 3};
  vector<int> nums2{2, 1, 2, 5, 3, 2};
  vector<int> nums3{5, 1, 5, 2, 5, 3, 5, 4};
  EXPECT_EQ(3, Solution::repeatedNTimes(nums1));
  EXPECT_EQ(2, Solution::repeatedNTimes(nums2));
  EXPECT_EQ(5, Solution::repeatedNTimes(nums3));
}

TEST(SolutionTest, MaximumWealthTest) {
  vector<vector<int>> accounts1 = {{1, 2, 3}, {3, 2, 1}};
  vector<vector<int>> accounts2 = {{1, 5}, {7, 3}, {3, 5}};
  vector<vector<int>> accounts3 = {{2, 8, 7}, {7, 1, 3}, {1, 9, 5}};
  EXPECT_EQ(6, Solution::maximumWealth(accounts1));
  EXPECT_EQ(10, Solution::maximumWealth(accounts2));
  EXPECT_EQ(17, Solution::maximumWealth(accounts3));
}

TEST(SolutionTest, FindMiddleIndexTest) {
  vector<int> nums1 = {2, 3, -1, 8, 4};
  vector<int> nums2 = {1, -1, 4};
  vector<int> nums3 = {2, 5};
  EXPECT_EQ(3, Solution::findMiddleIndex(nums1));
  EXPECT_EQ(2, Solution::findMiddleIndex(nums2));
  EXPECT_EQ(-1, Solution::findMiddleIndex(nums3));
}

TEST(SolutionTest, SelfDividingNumbersTest) {
  vector<int> expected1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22};
  vector<int> expected2 = {48, 55, 66, 77};
  EXPECT_EQ(expected1, Solution::selfDividingNumbers(1, 22));
  EXPECT_EQ(expected2, Solution::selfDividingNumbers(47, 85));
}

TEST(SolutionTest, PlatesBetweenCandlesTest) {
  vector<vector<int>> queries1 = {{2, 5}, {5, 9}};
  vector<int> expected1 = {2, 3};
  auto actual1 = Solution::platesBetweenCandles("**|**|***|", queries1);

  vector<vector<int>> queries2 = {{1, 17}, {4, 5}, {14, 17}, {5, 11}, {15, 16}};
  vector<int> expected2 = {9, 0, 0, 0, 0};
  auto actual2 =
      Solution::platesBetweenCandles("***|**|*****|**||**|*", queries2);

  EXPECT_EQ(expected1, actual1);
  EXPECT_EQ(expected2, actual2);
}

