#ifdef _WINDOWS
#pargma once
#endif

#ifndef LEETCODE_SOLUTION_H_
#define LEETCODE_SOLUTION_H_

#include <algorithm>
#include <bitset>
#include <cmath>
#include <queue>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

class Node {
public:
  int val;
  std::vector<Node *> children;
  Node() {}
  Node(int _val, std::vector<Node *> _children): val(_val), children(_children) {}
};

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
  /**
   * 1. Two Sum
   */
  static std::vector<int> twoSum(std::vector<int> &nums, int target);

  /**
   * 2. Add Two Numbers
   */
  static ListNode *addTwoNumbers(ListNode *l1, ListNode *l2);

  /**
   * 3. Longest Substring Without Repeating Characters
   */
  static int lengthOfLongestSubstring(std::string s);

  /**
   * 4. Median of Two Sorted Arrays
   */
  static double findMedianSortedArrays(std::vector<int> &nums1,
                                       std::vector<int> &nums2);

  /**
   * 5. Longest Palindromic Substring
   */
  static std::string longestPalindrome(std::string s);

  /**
   * 6. ZigZag Conversion
   */
  static std::string convert(std::string s, int numRows);

  /**
   * 7. Reverse Integer
  */
  static int Reverse(int x);

  /**
   * 8. String to Integer(atoi)
  */
  static int Atoi(std::string str); 

  /**
   * 9. Palindrome Number
  */
  static bool IsPalindrome(int x);

  /**
   * 10. Regular Expression Matching
  */
  static bool IsMatch(std::string s, std::string p);

  /**
   * 11. Container With Most Water
   */
  static int maxArea(std::vector<int> &height);

  /**
   * 12. Integer to Roman
  */
  static std::string intToRoman(int num);

  /**
   * 13. Roman to Integer
  */
  static int romanToInteger(std::string s);

  /**
   * 14. Longest Common Prefix
  */
  static std::string longestCommonPrefix(std::vector<std::string>& strs);

  /**
   * 15. 3Sum
   */
  static std::vector<std::vector<int>> threeSum(std::vector<int> &nums);

  /**
   * 16. 3Sum Closest
   */
  static int threeSumClosest(std::vector<int> &nums, int target);

  /**
   * 17. Letter Combinations of a Phone Number 
  */
  static std::vector<std::string> letterCombinations(std::string digits);

  /**
   * 18. 4Sum
   */
  static std::vector<std::vector<int>> fourSum(std::vector<int> &nums,
                                               int target);
  /**
   * 19. Remove Nth Node From End of List
  */
  static ListNode* removeNthFromEnd(ListNode* head, int n);

  /**
   * 33. Search in Rotated Sorted Array
   */
  static int search(std::vector<int> &nums, int target);

  /**
   * 50. Power(x, n)
   */
  static double myPower(double x, int n);

  /** 
   * 55. Jump Game
   */
  static bool canJump(std::vector<int> &nums);

  /**
   * 69. Sqrt(x)
   */
  static int mySqrt(int x);

  /**
   * 136. Single Number
  */
  static int singleNumber(std::vector<int> &nums);

  /** 
   * 268. Missing Number
   */
  static int missingNumber(std::vector<int> &nums);

  /**
   * 198. House Robber
   */
  static int rob(std::vector<int> &nums);

  /**
   * 242. Valid Anagram
   */
  static bool isAnagram(std::string s, std::string t);

  /**
   * 287. Find the Duplicate Number
   */
  static int findDuplicate(std::vector<int> &nums);

  /**
   * 429. N-ary Tree Level Order Traversal
  */
  static std::vector<std::vector<int>> levelOrderBottom(TreeNode *root);

  /**
   * 509. Fibonacci Number
  */
  static int fib(int N);

  static std::vector<std::vector<int>> levelOrder(Node *root);

  static void reverseString(std::vector<char> &s);

  /**
   * 617. Merge Two Binary Trees
   */
  static TreeNode *mergeTrees(TreeNode *t1, TreeNode *t2);

  /**
   * 709. To Lower Case
   */
  static std::string toLowerCase(std::string str);

  /** 
   * 821. Shortest Distance to a Character
   */
  static std::vector<int> shortestToChar(std::string S, char C);

  /** 
   * 852. Peak Index in a Mountain Array
   */
  static int peakIndexInMountainArray(std::vector<int> &A);

  /** 
   * 883. Projection Area of 3D Shapes
   */
  static int projectionArea(std::vector<std::vector<int>> &grid);

  /** 
   * 892. Surface Area of 3D Shapes
   */
  static int surfaceArea(std::vector<std::vector<int>> &grid);

  /**
   * 905. Sort Array By Parity
  */
  static std::vector<int> sortArrayByParity(std::vector<int>& A);

  /** 
   * 938. Range Sum of BST
   */

  static ListNode *middleNode(ListNode *head);
  static std::vector<std::string> uncommonFromSentences(std::string A,
                                                        std::string B);
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

  /**
   *
   */
  static ListNode *sortList(ListNode *head);

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
  static bool isValid(std::vector<std::string> &nQueens, int row, int col,
                      int &n);
  static void solve_NQueens(std::vector<std::vector<std::string>> &res,
                            std::vector<std::string> nQueens,
                            std::vector<int> &flag, int row, int &n);
  static std::vector<int> kmpProcess(std::string &needle);
};

#endif /* LEETCODE_SOLUTION_H_ */