#ifndef LEETCODE_SOLUTION_HPP_
#define LEETCODE_SOLUTION_HPP_

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
  static std::vector<int> twoSum(std::vector<int> &nums, int target);

  /*2. Add Two Numbers
  Description:
      You are given two non-empty linked lists representing two non-negative
  integers. The digits are stored in reverse order and each of their nodes
  contain a single digit. Add the two numbers and return it as a linked list.
  You may assume the two numbers do not contain any leading zero, except
  the number 0 itself.
  */
  static ListNode *addTwoNumbers(ListNode *l1, ListNode *l2);

  /*3. Longest Substring Without Repeating Characters
  Description:
      Given a string, find the length of the longest substring without
  repeating characters.
  */
  static int lengthOfLongestSubstring(std::string s);

  /*4. Median of Two Sorted Arrays
  Description:
      There are two sorted arrays nums1 and nums2 of size m and n
  respectively. Find the median of the two sorted arrays. The overall run time
  complexity should be O(log (m+n)). You may assume nums1 and nums2 cannot be
  both empty.
  */
  static double findMedianSortedArrays(std::vector<int> &nums1,
                                std::vector<int> &nums2);

  /*5. Longest Palindromic Substring
  Description:
      Given a string s, find the longest palindromic substring in s. You may
  assume that the maximum length of s is 1000.
  */
  static std::string longestPalindrome(std::string s);

  /*6. ZigZag Conversion
  Description:
    The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this:
  (you may want to display this pattern in a fixed font for better legibility)
  */
  static std::string convert(std::string s, int numRows);

  /*11. Container With Most Water
  Description:
      Given n non-negative integers a1, a2, ..., an , where each represents a
  point at coordinate (i, ai). n vertical lines are drawn such that the two
  endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together
  with x-axis forms a container, such that the container contains the most
  water.
  */
  static int maxArea(std::vector<int> &height);

  /*15. 3Sum
  Description:
      Given an array nums of n integers, are there elements a, b, c in nums
  such that a + b + c = 0? Find all unique triplets in the array which gives the
  sum of zero.
  */
  static std::vector<std::vector<int>> threeSum(std::vector<int> &nums);

  /*16. 3Sum Closest
  Description:
      Given an array nums of n integers and an integer target, find three
  integers in nums such that the sum is closest to target. Return the sum of the
  three integers. You may assume that each input would have exactly one
  solution.
  */
  static int threeSumClosest(std::vector<int> &nums, int target);

  /*18. 4Sum
  Description:
      Given an array nums of n integers and an integer target, are there
  elements a, b, c, and d in nums such that a + b + c + d = target? Find all
  unique quadruplets in the array which gives the sum of target.
  */
  static std::vector<std::vector<int>> fourSum(std::vector<int> &nums, int target);

  /*33. Search in Rotated Sorted Array
  Description:
      Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
  (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
  You are given a target value to search. If found in the array return its index, otherwise return -1.
  You may assume no duplicate exists in the array.
  Your algorithm's runtime complexity must be in the order of O(log n).
  */
  static int search(std::vector<int> &nums, int target);
 
  /*50. Power(x, n)
  Description:
    
  */
  static double myPower(double x, int n);

  /*69. Sqrt(x)
  Description:
      Implement int sqrt(int x). Compute and return the square root of x, 
  where x is guaranteed to be a non-negative integer. Since the return type is an integer,
  the decimal digits are truncated and only the integer part of the result is returned.    
  */
  static int mySqrt(int x);
  
  /*136. Single Number
  Description:
  */
  static int singleNumber(std::vector<int> &nums);

  /*268. Missing Number
      Given an array containing n distinct numbers taken from 0, 1, 2, ..., n,
  find the one that is missing from the array.
  */
  static int missingNumber(std::vector<int> &nums);

  /*198. House Robber
  Description:
      You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, 
  the only constraint stopping you from robbing each of them is that adjacent houses have security system connected 
  and it will automatically contact the police if two adjacent houses were broken into on the same night.
  Given a list of non-negative integers representing the amount of money of each house, 
  determine the maximum amount of money you can rob tonight without alerting the police.
  */
  static int rob(std::vector<int> &nums);

  /*242. Valid Anagram
  Description:
  */
  static bool isAnagram(std::string s, std::string t);

  /*287. Find the Duplicate Number
  Description:
  */
  static int findDuplicate(std::vector<int> &nums);

  /*821. Shortest Distance to a Character
  Description:
  */ 
  static std::vector<int> shortestToChar(std::string S, char C);

  /*852. Peak Index in a Mountain Array
  Description:
  */
  static int peakIndexInMountainArray(std::vector<int> &A);

  /*883. Projection Area of 3D Shapes
  Description:
  */
  static int projectionArea(std::vector<std::vector<int>> &grid);

    /*892. Surface Area of 3D Shapes
  Description:
  */
  static int surfaceArea(std::vector<std::vector<int>> &grid);

  static ListNode *middleNode(ListNode *head);
  static std::vector<std::string> uncommonFromSentences(std::string A, std::string B);
  static std::vector<std::vector<int>> combine(int n, int k);
  static uint32_t reverseBits(uint32_t n);
  static std::vector<std::vector<int>> generate(int numRows);
  static bool isSymmetric(TreeNode *root);
  static bool isMirror(TreeNode *l1, TreeNode *l2);
  static bool hasCycle(ListNode *head);
  static std::string addBinary(std::string a, std::string b);
  static int climbStairs(int n);
  static int maxDepth(TreeNode *root);
  static int minDepth(TreeNode *root);
  static bool hasPathSum(TreeNode *root, int sum);
  static int divide(int dividend, int divisor);
  static std::vector<std::vector<int>> levelOrderBottom(TreeNode *root);
  static ListNode *sortList(ListNode *head);
  static std::vector<std::string> letterCombinations(std::string digits);
  static bool canJump(std::vector<int> &nums);
  static std::vector<int> plus_one(std::vector<int> &digits);
  static void move_zeroes(std::vector<int> &nums);
  static std::vector<std::vector<std::string>> solve_NQueens(int n);
  static bool isValid(std::string s);
  static std::vector<std::string> readBinaryWatch(int num);
  static bool isSameTree(TreeNode *p, TreeNode *q);
  static int firstMissingPositive(std::vector<int> &nums);
  static int strStr(std::string haystack, std::string needle);

 private:
  static ListNode *split(ListNode *head, int n);
  static ListNode *merge(ListNode *l1, ListNode *l2, ListNode *head);
  static std::string preProcess(std::string s);
  static bool isValid(std::vector<std::string> &nQueens, int row, int col, int &n);
  static void solve_NQueens(std::vector<std::vector<std::string>> &res,
                     std::vector<std::string> nQueens, std::vector<int> &flag,
                     int row, int &n);
  static std::vector<int> kmpProcess(std::string &needle);
};

#endif /* LEETCODE_SOLUTION_H_ */
