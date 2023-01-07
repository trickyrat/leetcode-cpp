#include "pch.h"

#include "../LeetCodecpp/Solution.cpp"
#include "../LeetCodecpp/Utilities.cpp"

#include <algorithm>

using namespace std;

Solution solution;

TEST(SolutionUnitTest, TwoSumTest) {
  vector<int> expected1 = {0, 1};
  vector<int> input1 = {2, 7, 11, 15};
  vector<int> actual1 = solution.twoSum(input1, 9);
  EXPECT_EQ(expected1, actual1);

  vector<int> expected2 = {1, 2};
  vector<int> input2 = {3, 2, 4};
  vector<int> actual2 = solution.twoSum(input2, 6);
  EXPECT_EQ(expected2, actual2);

  vector<int> expected3 = {0, 1};
  vector<int> input3 = {3, 3};
  vector<int> actual3 = solution.twoSum(input3, 6);
  EXPECT_EQ(expected3, actual3);
}

TEST(SolutionUnitTest, LengthOfLongestSubstring) {
  EXPECT_EQ(3, solution.lengthOfLongestSubstring("abcabcbb"));
  EXPECT_EQ(1, solution.lengthOfLongestSubstring("bbbbb"));
  EXPECT_EQ(3, solution.lengthOfLongestSubstring("pwwkew"));
}

TEST(SolutionUnitTest, LengthOfLongestSubstringTest) {
  EXPECT_EQ(3, solution.lengthOfLongestSubstring("pwwkew"));
  EXPECT_EQ(1, solution.lengthOfLongestSubstring("bbbbb"));
  EXPECT_EQ(3, solution.lengthOfLongestSubstring("abcabcbb"));
}

TEST(SolutionUnitTest, IntToRomanTest) {
  EXPECT_EQ("I", solution.intToRoman(1));
  EXPECT_EQ("X", solution.intToRoman(10));
  EXPECT_EQ("VI", solution.intToRoman(6));
}

TEST(SolutionUnitTest, SearchInsertTest) {
  vector<int> nums1 = {1, 3, 5, 6};
  vector<int> nums2 = {1, 3, 5, 6};
  vector<int> nums3 = {1, 3, 5, 6};
  vector<int> nums4 = {1, 3, 5, 6};
  vector<int> nums5 = {1};
  EXPECT_EQ(2, solution.searchInsert(nums1, 5));
  EXPECT_EQ(1, solution.searchInsert(nums2, 2));
  EXPECT_EQ(4, solution.searchInsert(nums3, 7));
  EXPECT_EQ(0, solution.searchInsert(nums4, 0));
  EXPECT_EQ(0, solution.searchInsert(nums5, 0));
}

TEST(SolutionUnitTest, TrailingZeroesTest) {
  EXPECT_EQ(0, solution.trailingZeroes(3));
  EXPECT_EQ(1, solution.trailingZeroes(5));
  EXPECT_EQ(0, solution.trailingZeroes(0));
}

TEST(SolutionUnitTest, CountNumbersWithUniqueDigitsTest) {
  EXPECT_EQ(91, solution.countNumbersWithUniqueDigits(2));
  EXPECT_EQ(1, solution.countNumbersWithUniqueDigits(0));
}

TEST(SolutionUnitTest, LexicalOrderTest) {
  vector<int> expected1 = {1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9};
  vector<int> expected2 = {1, 2};
  EXPECT_EQ(expected1, solution.lexicalOrder(13));
  EXPECT_EQ(expected2, solution.lexicalOrder(2));
}

TEST(SolutionUnitTest, FindDiagonalOrderTest) {
  vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  vector<int> expected = {1, 2, 4, 7, 5, 3, 6, 8, 9};
  vector<int> actual = solution.findDiagonalOrder(matrix);
  EXPECT_EQ(expected, actual);
}

TEST(SolutionUnitTest, ConvertToBase7Test) {
  EXPECT_EQ("202", solution.convertToBase7(100));
  EXPECT_EQ("-10", solution.convertToBase7(-7));
}

TEST(SolutionUnitTest, ExculsiveTimeTest) {
  vector<string> logs1 = {"0:start:0", "1:start:2", "1:end:5", "0:end:6"};
  vector<string> logs2 = {"0:start:0", "0:start:2", "0:end:5",
                          "0:start:6", "0:end:6",   "0:end:7"};
  vector<string> logs3 = {"0:start:0", "0:start:2", "0:end:5",
                          "1:start:6", "1:end:6",   "0:end:7"};
  vector<int> expected1 = {3, 4};
  vector<int> expected2 = {8};
  vector<int> expected3 = {7, 1};
  EXPECT_EQ(expected1, solution.exclusiveTime(2, logs1));
  EXPECT_EQ(expected2, solution.exclusiveTime(1, logs2));
  EXPECT_EQ(expected3, solution.exclusiveTime(2, logs3));
}

TEST(SolutionUnitTest, FindLongestChainTest) {
  vector<vector<int>> pairs1 = {{1, 2}, {2, 3}, {3, 4}};
  vector<vector<int>> pairs2 = {{1, 2}, {7, 8}, {4, 5}};
  EXPECT_EQ(2, solution.findLongestChain(pairs1));
  EXPECT_EQ(3, solution.findLongestChain(pairs2));
}

TEST(SolutionUnitTest, FindClosestElementsTest) {
  vector<int> arr1{1, 2, 3, 4, 5};
  vector<int> arr2{1, 2, 3, 4, 5};
  vector<int> expected1{1, 2, 3, 4};
  vector<int> expected2{1, 2, 3, 4};
  EXPECT_EQ(expected1, solution.findClosestElements(arr1, 4, 3));
  EXPECT_EQ(expected2, solution.findClosestElements(arr2, 4, -1));
}

TEST(SolutionUnitTest, ConstructArrayTest) {
  vector<int> expected1{1, 2, 3};
  vector<int> expected2{1, 3, 2};
  EXPECT_EQ(expected1, solution.constructArray(3, 1));
  EXPECT_EQ(expected2, solution.constructArray(3, 2));
}

TEST(SolutionUnitTest, WidthOfBinaryTreeTest) {
  string nums1 = "1,3,2,5,3,null,9";
  string nums2 = "1,3,2,5,null,null,9,6,null,7";
  string nums3 = "1,3,2,5";
  TreeNode *root1 = Utilities::createTreeNodeIteratively(nums1);
  TreeNode *root2 = Utilities::createTreeNodeIteratively(nums2);
  TreeNode *root3 = Utilities::createTreeNodeIteratively(nums3);
  EXPECT_EQ(4, solution.widthOfBinaryTree(root1));
  EXPECT_EQ(7, solution.widthOfBinaryTree(root2));
  EXPECT_EQ(2, solution.widthOfBinaryTree(root3));
}

TEST(SolutionUnitTest, MaximumSwapTest) {
  EXPECT_EQ(7236, solution.maximumSwap(2736));
  EXPECT_EQ(9973, solution.maximumSwap(9973));
}

TEST(SolutionUnitTest, FlipLightsTest) {
  EXPECT_EQ(2, solution.flipLights(1, 1));
  EXPECT_EQ(3, solution.flipLights(2, 1));
  EXPECT_EQ(4, solution.flipLights(3, 1));
}

TEST(SolutionUnitTest, LongestUnivaluePathTest) {
  string nums1 = "5,4,5,1,1,null,5";
  string nums2 = "1,4,5,4,4,null,5";
  TreeNode *root1 = Utilities::createTreeNodeIteratively(nums1);
  TreeNode *root2 = Utilities::createTreeNodeIteratively(nums2);
  EXPECT_EQ(2, solution.longestUnivaluePath(root1));
  EXPECT_EQ(2, solution.longestUnivaluePath(root2));
}

TEST(SolutionUnitTest, PivotIndexTest) {
  vector<int> nums1 = {1, 7, 3, 6, 5, 6};
  vector<int> nums2 = {1, 2, 3};
  vector<int> nums3 = {2, 1, -1};
  EXPECT_EQ(3, solution.pivotIndex(nums1));
  EXPECT_EQ(-1, solution.pivotIndex(nums2));
  EXPECT_EQ(0, solution.pivotIndex(nums3));
}

TEST(SolutionUnitTest, SelfDividingNumbersTest) {
  vector<int> expected1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22};
  vector<int> expected2 = {48, 55, 66, 77};
  EXPECT_EQ(expected1, solution.selfDividingNumbers(1, 22));
  EXPECT_EQ(expected2, solution.selfDividingNumbers(47, 85));
}

TEST(SolutionUnitTest, PreimageSizeFZFTest) {
  EXPECT_EQ(5, solution.preimageSizeFZF(0));
  EXPECT_EQ(0, solution.preimageSizeFZF(5));
  EXPECT_EQ(5, solution.preimageSizeFZF(3));
}

TEST(SolutionUnitTest, UniqueMorseRepresentationsTest) {
  vector<string> words1 = {"gin", "zen", "gig", "msg"};
  vector<string> words2 = {"a"};
  EXPECT_EQ(2, solution.uniqueMorseRepresentations(words1));
  EXPECT_EQ(1, solution.uniqueMorseRepresentations(words2));
}

TEST(SolutionUnitTest, NumberOfLinesTest) {
  vector<int> widths1 = {10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,
                         10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
  vector<int> widths2 = {4,  10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,
                         10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
  string s1 = "abcdefghijklmnopqrstuvwxyz";
  string s2 = "bbbcccdddaaa";
  vector<int> expected1 = {3, 60};
  vector<int> expected2 = {2, 4};
  EXPECT_EQ(expected1, solution.numberOfLines(widths1, s1));
  EXPECT_EQ(expected2, solution.numberOfLines(widths2, s2));
}

TEST(SolutionUnitTest, UniqueLetterStringTest) {
  string s1 = "ABC";
  string s2 = "ABA";
  string s3 = "LEETCODE";
  EXPECT_EQ(10, solution.uniqueLetterString(s1));
  EXPECT_EQ(8, solution.uniqueLetterString(s2));
  EXPECT_EQ(92, solution.uniqueLetterString(s3));
}

TEST(SolutionUnitTest, MinCostToHireWorkersTest) {
  vector<int> quality1{10, 20, 5};
  vector<int> quality2{3, 1, 10, 10, 1};
  vector<int> wage1{70, 50, 30};
  vector<int> wage2{4, 8, 2, 2, 7};
  EXPECT_TRUE(abs(105.00000 - solution.minCostToHireWorkers(quality1, wage1,
                                                            2)) <= 0.00001);
  EXPECT_TRUE(abs(30.66667 - solution.minCostToHireWorkers(quality2, wage2,
                                                           3)) <= 0.00001);
}

TEST(SolutionUnitTest, MinDeletionSizeTest) {
  vector<string> strs1{"cba", "daf", "ghi"};
  vector<string> strs2{"a", "b"};
  vector<string> strs3{"zyx", "wvu", "tsr"};
  EXPECT_EQ(1, solution.minDeletionSize(strs1));
  EXPECT_EQ(0, solution.minDeletionSize(strs2));
  EXPECT_EQ(3, solution.minDeletionSize(strs3));
}

TEST(SolutionUnitTest, ValidateStackSequencesTest) {
  vector<int> pushed1 = {1, 2, 3, 4, 5};
  vector<int> popped1 = {4, 5, 3, 2, 1};

  vector<int> pushed2 = {1, 2, 3, 4, 5};
  vector<int> popped2 = {4, 3, 5, 1, 2};

  EXPECT_TRUE(solution.validateStackSequences(pushed1, popped1));
  EXPECT_FALSE(solution.validateStackSequences(pushed2, popped2));
}

TEST(SolutionUnitTest, RepeatedNTimesTest) {
  vector<int> nums1{1, 2, 3, 3};
  vector<int> nums2{2, 1, 2, 5, 3, 2};
  vector<int> nums3{5, 1, 5, 2, 5, 3, 5, 4};
  EXPECT_EQ(3, solution.repeatedNTimes(nums1));
  EXPECT_EQ(2, solution.repeatedNTimes(nums2));
  EXPECT_EQ(5, solution.repeatedNTimes(nums3));
}

TEST(SolutionUnitTest, IsUnivalTreeTest) {
  string nums1 = "1,1,1,1,1,null,1";
  TreeNode *root1 = Utilities::createTreeNodeIteratively(nums1);
  EXPECT_TRUE(solution.isUnivalTree(root1));
  string nums2 = "2,2,2,5,2";
  TreeNode *root2 = Utilities::createTreeNodeIteratively(nums2);
  EXPECT_FALSE(solution.isUnivalTree(root2));
}

TEST(SolutionUnitTest, InsertIntoMaxTreeTest) {
  string nodes1 = "4,1,3,null,null,2";
  string nodes2 = "5,2,4,null,1";
  string nodes3 = "5,2,3,null,1";
  vector<int> actual1 =
      Utilities::preordereTraversal(solution.insertIntoMaxTree(
          Utilities::createTreeNodeIteratively(nodes1), 5));
  vector<int> actual2 =
      Utilities::preordereTraversal(solution.insertIntoMaxTree(
          Utilities::createTreeNodeIteratively(nodes2), 3));
  vector<int> actual3 =
      Utilities::preordereTraversal(solution.insertIntoMaxTree(
          Utilities::createTreeNodeIteratively(nodes3), 4));
  vector<int> expected1 = {5, 4, 1, 3, 2};
  vector<int> expected2 = {5, 2, 1, 4, 3};
  vector<int> expected3 = {5, 2, 1, 4, 3};
  EXPECT_EQ(expected1, actual1);
  EXPECT_EQ(expected2, actual2);
  EXPECT_EQ(expected3, actual3);
}

TEST(SolutionUnitTest, MinSubsequenceTest) {
  vector<int> nums1 = {4, 3, 10, 9, 8};
  vector<int> nums2 = {4, 4, 7, 6, 7};
  vector<int> nums3 = {6};
  vector<int> expected1 = {10, 9};
  vector<int> expected2 = {7, 7, 6};
  vector<int> expected3 = {6};
  EXPECT_EQ(expected1, solution.minSubsequence(nums1));
  EXPECT_EQ(expected2, solution.minSubsequence(nums2));
  EXPECT_EQ(expected3, solution.minSubsequence(nums3));
}

TEST(SolutionUnitTest, BusyStudentTest) {
  vector<int> startTime1 = {1, 2, 3};
  vector<int> endTime1 = {3, 2, 7};
  vector<int> startTime2 = {4};
  vector<int> endTime2 = {4};
  EXPECT_EQ(1, solution.busyStudent(startTime1, endTime1, 4));
  EXPECT_EQ(1, solution.busyStudent(startTime2, endTime2, 4));
}

TEST(SolutionUnitTest, IsPrefixOfWordTest) {
  string sentence1 = "i love eating burger";
  string sentence2 = "this problem is an easy problem";
  string sentence3 = "i am tired";
  string searchWord1 = "burg";
  string searchWord2 = "pro";
  string searchWord3 = "you";
  EXPECT_EQ(4, solution.isPrefixOfWord(sentence1, searchWord1));
  EXPECT_EQ(2, solution.isPrefixOfWord(sentence2, searchWord2));
  EXPECT_EQ(-1, solution.isPrefixOfWord(sentence3, searchWord3));
}

TEST(SolutionUnitTest, ShuffleTest) {
  vector<int> nums1 = {2, 5, 1, 3, 4, 7};
  vector<int> nums2 = {1, 2, 3, 4, 4, 3, 2, 1};
  vector<int> nums3 = {1, 1, 2, 2};
  vector<int> expected1 = {2, 3, 5, 4, 1, 7};
  vector<int> expected2 = {1, 4, 2, 3, 3, 2, 4, 1};
  vector<int> expected3 = {1, 2, 1, 2};
  EXPECT_EQ(expected1, solution.shuffle(nums1, 3));
  EXPECT_EQ(expected2, solution.shuffle(nums2, 4));
  EXPECT_EQ(expected3, solution.shuffle(nums3, 2));
}

TEST(SolutionUnitTest, FinalPricesTest) {
  vector<int> prices1 = {8, 4, 6, 2, 3};
  vector<int> prices2 = {1, 2, 3, 4, 5};
  vector<int> prices3 = {10, 1, 1, 6};
  vector<int> expected1 = {4, 2, 4, 2, 3};
  vector<int> expected2 = {1, 2, 3, 4, 5};
  vector<int> expected3 = {9, 0, 1, 6};
  EXPECT_EQ(expected1, solution.finalPrices(prices1));
  EXPECT_EQ(expected2, solution.finalPrices(prices2));
  EXPECT_EQ(expected3, solution.finalPrices(prices3));
}

TEST(SolutionUnitTest, MaxProductTest) {
  vector<int> nums1 = {3, 4, 5, 2};
  vector<int> nums2 = {1, 5, 4, 5};
  vector<int> nums3 = {3, 7};
  EXPECT_EQ(12, solution.maxProduct(nums1));
  EXPECT_EQ(16, solution.maxProduct(nums2));
  EXPECT_EQ(12, solution.maxProduct(nums3));
}

TEST(SolutionUnitTest, NumSpecialTest) {
  vector<vector<int>> mat1 = {{1, 0, 0}, {0, 0, 1}, {1, 0, 0}};
  vector<vector<int>> mat2 = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
  EXPECT_EQ(1, solution.numSpecial(mat1));
  EXPECT_EQ(3, solution.numSpecial(mat2));
}

TEST(SolutionUnitTest, ReorderSpacesTest) {
  string text1 = "  this   is  a sentence ";
  string text2 = " practice   makes   perfect";
  EXPECT_EQ("this   is   a   sentence", solution.reorderSpaces(text1));
  EXPECT_EQ("practice   makes   perfect ", solution.reorderSpaces(text2));
}

TEST(SolutionUnitTest, MinOperationsTest) {
  vector<string> logs1{"d1/", "d2/", "../", "d21/", "./"};
  vector<string> logs2{"d1/", "d2/", "./", "d3/", "../", "d31/"};
  vector<string> logs3{"d1/", "../", "../", "../"};
  EXPECT_EQ(2, solution.minOperations(logs1));
  EXPECT_EQ(3, solution.minOperations(logs2));
  EXPECT_EQ(0, solution.minOperations(logs3));
}

TEST(SolutionUnitTest, SpecialArrayTest) {
  vector<int> nums1{3, 5};
  vector<int> nums2{0, 0};
  vector<int> nums3{0, 4, 3, 0, 4};
  EXPECT_EQ(2, solution.specialArray(nums1));
  EXPECT_EQ(-1, solution.specialArray(nums2));
  EXPECT_EQ(3, solution.specialArray(nums3));
}

TEST(SolutionUnitTest, TrimMeanTest) {
  vector<int> nums1{1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3};
  vector<int> nums2{6, 2, 7, 5, 1, 2, 0, 3, 10, 2,
                    5, 0, 5, 5, 0, 8, 7, 6, 8,  0};
  vector<int> nums3{6,  0, 7, 0, 7, 5, 7, 8,  3, 4, 0, 7, 8, 1,
                    6,  8, 1, 1, 2, 4, 8, 1,  9, 5, 4, 3, 8, 5,
                    10, 8, 6, 6, 1, 0, 6, 10, 8, 2, 3, 4};
  EXPECT_TRUE((solution.trimMean(nums1) - 2.00000) <= 0.00001);
  EXPECT_TRUE((solution.trimMean(nums2) - 4.00000) <= 0.00001);
  EXPECT_TRUE((solution.trimMean(nums3) - 4.77778) <= 0.00001);
}

TEST(SolutionUnitTest, MaxLengthBetweenEqualCharactersTest) {
  string s1 = "aa";
  string s2 = "abca";
  string s3 = "bczyx";
  EXPECT_EQ(0, solution.maxLengthBetweenEqualCharacters(s1));
  EXPECT_EQ(2, solution.maxLengthBetweenEqualCharacters(s2));
  EXPECT_EQ(-1, solution.maxLengthBetweenEqualCharacters(s3));
}

TEST(SolutionUnitTest, FrequencySortTest) {
  vector<int> nums1{1, 1, 2, 2, 2, 3};
  vector<int> nums2{2, 3, 1, 3, 2};
  vector<int> nums3{-1, 1, -6, 4, 5, -6, 1, 4, 1};
  vector<int> expected1{3, 1, 1, 2, 2, 2};
  vector<int> expected2{1, 3, 3, 2, 2};
  vector<int> expected3{5, -1, 4, 4, -6, -6, 1, 1, 1};
  EXPECT_EQ(expected1, solution.frequencySort(nums1));
  EXPECT_EQ(expected2, solution.frequencySort(nums2));
  EXPECT_EQ(expected3, solution.frequencySort(nums3));
}

TEST(SolutionUnitTest, MinOperations2Test) { 
  vector<int> nums1{1, 1, 4, 2, 3};
  vector<int> nums2{5, 6, 7, 8, 9};
  vector<int> nums3{3, 2, 20, 1, 1, 3};
  EXPECT_EQ(2, solution.minOperations(nums1, 5));
  EXPECT_EQ(-1, solution.minOperations(nums2, 4));
  EXPECT_EQ(5, solution.minOperations(nums3, 10));
}

TEST(SolutionUnitTest, MaximumWealthTest) {
  vector<vector<int>> accounts1 = {{1, 2, 3}, {3, 2, 1}};
  vector<vector<int>> accounts2 = {{1, 5}, {7, 3}, {3, 5}};
  vector<vector<int>> accounts3 = {{2, 8, 7}, {7, 1, 3}, {1, 9, 5}};
  EXPECT_EQ(6, solution.maximumWealth(accounts1));
  EXPECT_EQ(10, solution.maximumWealth(accounts2));
  EXPECT_EQ(17, solution.maximumWealth(accounts3));
}

TEST(SolutionUnitTest, ReformatNumberTest) {
  EXPECT_EQ("123-456", solution.reformatNumber("1-23-45 6"));
  EXPECT_EQ("123-45-67", solution.reformatNumber("123 4-567"));
  EXPECT_EQ("123-456-78", solution.reformatNumber("123 4-5678"));
}

TEST(SolutionUnitTest, MinimumLengthTest) {
  EXPECT_EQ(2, solution.minimumLength("ca"));
  EXPECT_EQ(0, solution.minimumLength("cabaabac"));
  EXPECT_EQ(3, solution.minimumLength("aabccabba"));
}

TEST(SolutionUnitTest, CheckOnesSegmentTest) {
  EXPECT_EQ(false, solution.checkOnesSegment("1001"));
  EXPECT_EQ(true, solution.checkOnesSegment("110"));
}

TEST(SolutionUnitTest, FindMiddleIndexTest) {
  vector<int> nums1 = {2, 3, -1, 8, 4};
  vector<int> nums2 = {1, -1, 4};
  vector<int> nums3 = {2, 5};
  EXPECT_EQ(3, solution.findMiddleIndex(nums1));
  EXPECT_EQ(2, solution.findMiddleIndex(nums2));
  EXPECT_EQ(-1, solution.findMiddleIndex(nums3));
}

TEST(SolutionUnitTest, MinimumMovesTest) {
  EXPECT_EQ(1, solution.minimumMoves("XXX"));
  EXPECT_EQ(2, solution.minimumMoves("XXOX"));
  EXPECT_EQ(0, solution.minimumMoves("OOOO"));
}

TEST(SolutionUnitTest, TwoOutOfThreeTest) {
  vector<int> nums1 = {1, 1, 3, 2};
  vector<int> nums2 = {2, 3};
  vector<int> nums3 = {3};
  vector<int> actual = solution.twoOutOfThree(nums1, nums2, nums3);
  vector<int> expected = {3, 2};
  sort(actual.begin(), actual.end());
  sort(expected.begin(), expected.end());
  EXPECT_EQ(expected, actual);

  nums1 = {3, 1};
  nums2 = {2, 3};
  nums3 = {1, 2};
  actual = solution.twoOutOfThree(nums1, nums2, nums3);
  expected = {2, 3, 1};
  sort(actual.begin(), actual.end());
  sort(expected.begin(), expected.end());
  EXPECT_EQ(expected, actual);

  nums1 = {1, 2, 2};
  nums2 = {4, 3, 3};
  nums3 = {5};
  actual = solution.twoOutOfThree(nums1, nums2, nums3);
  expected = {};
  sort(actual.begin(), actual.end());
  sort(expected.begin(), expected.end());
  EXPECT_EQ(expected, actual);
}

TEST(SolutionUnitTest, MinMovesToSeatTest) { 
  vector<int> seats1{3, 1, 5};
  vector<int> seats2{4, 1, 5, 9};
  vector<int> seats3{2, 2, 6, 6};
  vector<int> students1{2, 7, 4};
  vector<int> students2{1, 3, 2, 6};
  vector<int> students3{1, 3, 2, 6};
  EXPECT_EQ(4, solution.minMovesToSeat(seats1, students1));
  EXPECT_EQ(7, solution.minMovesToSeat(seats2, students2));
  EXPECT_EQ(4, solution.minMovesToSeat(seats3, students3));
}

TEST(SolutionUnitTest, AreNumberAscendingTest) {
  EXPECT_EQ(true, solution.areNumberAscending("1 box has 3 blue 4 red 6 green and 12 yellow marbles"));
  EXPECT_EQ(false, solution.areNumberAscending("hello world 5 x 5"));
  EXPECT_EQ(false, solution.areNumberAscending("sunset is at 7 51 pm overnight lows will be in the low 50 and 60 s"));
}

TEST(SolutionUnitTest, PlatesBetweenCandlesTest) {
  vector<vector<int>> queries1 = {{2, 5}, {5, 9}};
  vector<int> expected1 = {2, 3};
  auto actual1 = solution.platesBetweenCandles("**|**|***|", queries1);

  vector<vector<int>> queries2 = {{1, 17}, {4, 5}, {14, 17}, {5, 11}, {15, 16}};
  vector<int> expected2 = {9, 0, 0, 0, 0};
  auto actual2 =
      solution.platesBetweenCandles("***|**|*****|**||**|*", queries2);

  EXPECT_EQ(expected1, actual1);
  EXPECT_EQ(expected2, actual2);
}

TEST(SolutionUnitTest, CountEvenTest) {
  EXPECT_EQ(2, solution.countEven(4));
  EXPECT_EQ(14, solution.countEven(30));
}

TEST(SolutionUnitTest, PrefixCountTest) {
  vector<string> words1{"pay", "attention", "practice", "attend"};
  vector<string> words2{"leetcode", "win", "loops", "success"};
  EXPECT_EQ(2, solution.prefixCount(words1,"at"));
  EXPECT_EQ(0, solution.prefixCount(words2, "code"));
}

TEST(SolutionUnitTest, RepeatedCharacterTest) {
  EXPECT_EQ('c', solution.repeatedCharacter("abccbaacz"));
  EXPECT_EQ('d', solution.repeatedCharacter("abcdd"));
  EXPECT_EQ('a', solution.repeatedCharacter("aa"));
  EXPECT_EQ('z', solution.repeatedCharacter("zz"));
}

TEST(SolutionUnitTest, RearrangeCharactersTest) {
  EXPECT_EQ(2, solution.rearrangeCharacters("ilovecodingonleetcode", "code"));
  EXPECT_EQ(1, solution.rearrangeCharacters("abcba", "abc"));
  EXPECT_EQ(1, solution.rearrangeCharacters("abbaccaddaeea", "aaaaa"));
}