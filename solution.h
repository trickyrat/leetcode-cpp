#ifndef LEETCODE_SOLUTION_H_
#define LEETCODE_SOLUTION_H_

#include <cmath>
#include <algorithm>
#include <bitset>
#include <queue>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
 public:
  /*1. Two Sum
  Description:
        Given an array of integers, return indices of the two numbers such that
  they add up to a specific target. You may assume that each input would have
  exactly one solution, and you may not use the same element twice.
  */
  std::vector<int> twoSum(std::vector<int> &nums, int target);

  /*2. Add Two Numbers
  Description:
        You are given two non-empty linked lists representing two non-negative
  integers. The digits are stored in reverse order and each of their nodes
  contain a single digit. Add the two numbers and return it as a linked list.
  You may assume the two numbers do not contain any leading zero, except
  the number 0 itself.
  */
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2);

  /*3. Longest Substring Without Repeating Characters
  Description:
        Given a string, find the length of the longest substring without
  repeating characters.
  */
  int lengthOfLongestSubstring(std::string s);

  /*4. Median of Two Sorted Arrays
  Description:
        There are two sorted arrays nums1 and nums2 of size m and n
  respectively. Find the median of the two sorted arrays. The overall run time
  complexity should be O(log (m+n)). You may assume nums1 and nums2 cannot be
  both empty.
  */
  double findMedianSortedArrays(std::vector<int> &nums1,
                                std::vector<int> &nums2);

  /*5. Longest Palindromic Substring
  Description:
        Given a string s, find the longest palindromic substring in s. You may
  assume that the maximum length of s is 1000.
  */
  std::string longestPalindrome(std::string s);

  /*11. Container With Most Water
  Description:
        Given n non-negative integers a1, a2, ..., an , where each represents a
  point at coordinate (i, ai). n vertical lines are drawn such that the two
  endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together
  with x-axis forms a container, such that the container contains the most
  water.
  */
  int maxArea(std::vector<int> &height);

  /*15. 3Sum
  Description:
        Given an array nums of n integers, are there elements a, b, c in nums
  such that a + b + c = 0? Find all unique triplets in the array which gives the
  sum of zero.
  */
  std::vector<std::vector<int>> threeSum(std::vector<int> &nums);

  /*16. 3Sum Closest
        Given an array nums of n integers and an integer target, find three
  integers in nums such that the sum is closest to target. Return the sum of the
  three integers. You may assume that each input would have exactly one
  solution.
  */
  int threeSumClosest(std::vector<int> &nums, int target);

  /*18. 4Sum
        Given an array nums of n integers and an integer target, are there
  elements a, b, c, and d in nums such that a + b + c + d = target? Find all
  unique quadruplets in the array which gives the sum of target.
  */
  std::vector<std::vector<int>> fourSum(std::vector<int> &nums, int target);

  /*Given an array containing n distinct numbers taken from 0, 1, 2, ..., n,
  find the one that is missing from the array.
  */
  int missingNumber(std::vector<int> &nums);

  int mySqrt(int x);
  int search(std::vector<int> &nums, int target);
  int rob(std::vector<int> &nums);
  int singleNumber(std::vector<int> &nums);
  bool isAnagram(std::string s, std::string t);
  int surfaceArea(std::vector<std::vector<int>> &grid);
  int findDuplicate(std::vector<int> &nums);
  int projectionArea(std::vector<std::vector<int>> &grid);
  std::vector<int> shortestToChar(std::string S, char C);
  int peakIndexInMountainArray(std::vector<int> &A);
  ListNode *middleNode(ListNode *head);
  std::vector<std::string> uncommonFromSentences(std::string A, std::string B);
  std::vector<std::vector<int>> combine(int n, int k);
  uint32_t reverseBits(uint32_t n);
  std::vector<std::vector<int>> generate(int numRows);
  bool isSymmetric(TreeNode *root);
  bool isMirror(TreeNode *l1, TreeNode *l2);
  bool hasCycle(ListNode *head);
  std::string addBinary(std::string a, std::string b);
  int climbStairs(int n);
  int maxDepth(TreeNode *root);
  int minDepth(TreeNode *root);
  bool hasPathSum(TreeNode *root, int sum);
  int divide(int dividend, int divisor);
  std::vector<std::vector<int>> levelOrderBottom(TreeNode *root);
  ListNode *sortList(ListNode *head);
  std::vector<std::string> letterCombinations(std::string digits);
  bool canJump(std::vector<int> &nums);
  std::vector<int> plus_one(std::vector<int> &digits);
  void move_zeroes(std::vector<int> &nums);
  std::vector<std::vector<std::string>> solve_NQueens(int n);
  bool isValid(std::string s);
  std::vector<std::string> readBinaryWatch(int num);
  bool isSameTree(TreeNode *p, TreeNode *q);
  int firstMissingPositive(std::vector<int> &nums);
  int strStr(std::string haystack, std::string needle);

 private:
  ListNode *split(ListNode *head, int n);
  ListNode *merge(ListNode *l1, ListNode *l2, ListNode *head);
  std::string preProcess(std::string s);
  bool isValid(std::vector<std::string> &nQueens, int row, int col, int &n);
  void solve_NQueens(std::vector<std::vector<std::string>> &res,
                     std::vector<std::string> nQueens, std::vector<int> &flag,
                     int row, int &n);
  std::vector<int> kmpProcess(std::string &needle);
};

#endif /* LEETCODE_SOLUTION_H_ */