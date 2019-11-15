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
#include <unordered_set>
#include <vector>
#include <mutex>
#include <functional>

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

class Foo {
private:
  std::mutex m1, m2;
public:
  Foo() { m1.lock(), m2.lock();}

  void first(std::function<void()> printFirst) {
    printFirst();
    m1.unlock();
  }
  void second(std::function<void()> printSecond) {
    m1.lock();
    printSecond();
    m1.unlock();
    m2.unlock();
  }
  void third(std::function<void()> printThird) {
    m2.lock();
    printThird();
    m2.unlock();
  }
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
   * 20. Valid Parentheses
  */
  static bool isValid(std::string s);

  /**
   * 21. Merge Two Sorted Lists
  */
  static ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);

  /**
   * 22. Generate Parentheses
  */
  static std::vector<std::string> generateParenthesis(int n);

  /**
   * 23. Merge K Sorted Lists
  */
  static ListNode* mergeKLists(std::vector<ListNode*>& lists);

  /**
   * 24. Swap Node in Pairs
  */
  static ListNode* swapPairs(ListNode* head);

  /**
   * 25. Reverse Nodes in k-Group
  */
  static ListNode* reverseKGroup(ListNode* head, int k);

  /**
   * 26. Remove Duplicates from Sorted Array
  */
  static int removeDuplicates(std::vector<int>& nums);

  /**
   * 27. Remove Element
  */
  static int removeElement(std::vector<int>& nums, int val);

  /**
  * 28. Implement strStr()
  */
  static int strStr(std::string haystack, std::string needle);

  /**
   * 29. Divide Two Integers
  */
  static int divide(int dividend, int divisor);

  /**
   * 30. Substring with Concatenation of All Words
  */
  static std::vector<int> findSubstring(std::string s, std::vector<std::string>& words);


  /**
   * 33. Search in Rotated Sorted Array
   */
  static int search(std::vector<int> &nums, int target);

  /**
   * 34. Find First and Last Position of Element in Sorted Array
  */
  static std::vector<int> searchRange(std::vector<int>& nums, int target);

  /**
   * 35. Search Insert Position
  */
  static int searchInsert(std::vector<int>& nums, int target);

  /**
   * 36. Valid Sudoku
  */
  static bool isValidSudoku(std::vector<std::vector<char>> board);

  /**
   * 37. Sudoku Solver
  */
  static void solveSudoku(std::vector<std::vector<char>>& board);

  /**
   * 41. First Missing Positive
  */
  static int firstMissingPositive(std::vector<int> &nums);

  /*
   * 43. Multiply String
  */
  static std::string multiply(std::string num1, std::string num2);

  /**
   * 50. Power(x, n)
   */
  static double myPower(double x, int n);

  /**
   * 51. N-Queens
  */
  static std::vector<std::vector<std::string>> solveNQueens(int n);

  /** 
   * 55. Jump Game
   */
  static bool canJump(std::vector<int> &nums);

  /**
   * 66. Plus One
  */
  static std::vector<int> plusOne(std::vector<int> &digits);

  /**
   * 67. Add Binary
  */
  static std::string addBinary(std::string a, std::string b);

  /**
   * 69. Sqrt(x)
   */
  static int mySqrt(int x);

  /**
   * 70. Climb Stairs
  */
  static int climbStairs(int n);

  /**
   * 74. Search a 2D Matrix
  */
  static bool searchMatrix(std::vector<std::vector<int>>& nums, int target);

  /**
   * 77. Combinations
  */
  static std::vector<std::vector<int>> combine(int n, int k);

  /**
   * 94. Binary Tree Inorder Traversal
  */
  static std::vector<int> inorderTraversal(TreeNode* root);

  /**
   * 100. Same Tree
  */
  static bool isSameTree(TreeNode *p, TreeNode *q);

  /**
   * 101. Symmetric Tree
  */
  static bool isSymmetric(TreeNode *root);

  /**
   * 104. Maximum Depth of Binary Tree
  */
  static int maxDepth(TreeNode *root);

  /**
   * 107. Binary Tree Level Order Traversal II
  */
  static std::vector<std::vector<int>> levelOrderBottom(TreeNode *root); 

  /**
   * 111. Minimum Depth of Binary Tree
  */
  static int minDepth(TreeNode *root);

  /**
   *  112. Path Sum
   */
  static bool hasPathSum(TreeNode *root, int sum);

  /**
   * 118. Pascal's Triangle
  */
  static std::vector<std::vector<int>> generate(int numRows);

  /**
   * 136. Single Number
  */
  static int singleNumber(std::vector<int> &nums);

  /**
   * 141. Linked List Cycle
  */
  static bool hasCycle(ListNode *head);

  /**
   * 144. Binary Tree Preorder Traversal
  */
  static std::vector<int> preorderTraversal(TreeNode* root);

  /**
   * 145. Binary Tree Postorder Traversal
  */
  static std::vector<int> postorderTraversal(TreeNode* root);

  /**
   * 148. Sort List
   */
  static ListNode *sortList(ListNode *head);

  /**
   * 169. Majority Element
  */
  static int majorityElement(std::vector<int>& nums);

  /**
   * 190. Reverse Bits
  */
  static uint32_t reverseBits(uint32_t n);

  /**
   * 198. House Robber
   */
  static int rob(std::vector<int> &nums);

  /**
   * 242. Valid Anagram
   */
  static bool isAnagram(std::string s, std::string t);

  /** 
   * 268. Missing Number
   */
  static int missingNumber(std::vector<int> &nums);

  /**
   * 283. Move Zeroes
  */
  static void moveZeroes(std::vector<int> &nums);

  /**
   * 287. Find the Duplicate Number
   */
  static int findDuplicate(std::vector<int> &nums);

  /**
   * 344. Reverse String
  */
  static void reverseString(std::vector<char> &s);

  /**
   * 401. Binary Watch
  */
  static std::vector<std::string> readBinaryWatch(int num);

  /**
   * 429. N-ary Tree Level Order Traversal
  */
  static std::vector<std::vector<int>> levelOrder(Node *root);

  /**
   * 509. Fibonacci Number
  */
  static int fib(int N);

  /**
   * 617. Merge Two Binary Trees
   */
  static TreeNode *mergeTrees(TreeNode *t1, TreeNode *t2);

  /**
   * 669. Trim a Binary Search Tree
  */
  static TreeNode* trimBST(TreeNode* root, int L, int R);
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
   * 876. Middle of the Linked List
  */
  static ListNode *middleNode(ListNode *head);

  /** 
   * 883. Projection Area of 3D Shapes
   */
  static int projectionArea(std::vector<std::vector<int>> &grid);

  /**
   * 884. Uncommon Words from Two Sentences
  */
  static std::vector<std::string> uncommonFromSentences(std::string A,
                                                        std::string B);

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
  static int rangeSumBST(TreeNode* root, int L, int R);

  /**
   * 1114. Print Order 
  */

private:
  static bool isMirror(TreeNode *l1, TreeNode *l2);

  static bool doSolve(std::vector<std::vector<char>>& board, int row, int col); 
  static bool isValid(std::vector<std::vector<char>>& board, int row, int col, char num);

  static ListNode *split(ListNode *head, int n);
  static ListNode *merge(ListNode *l1, ListNode *l2, ListNode *head);
  static std::string preProcess(std::string s);
  
  static bool isValid(std::vector<std::string> &nQueens, int row, int col,
                      int &n);
  static void solveNQueens(std::vector<std::vector<std::string>> &res,
                            std::vector<std::string> nQueens,
                            std::vector<int> &flag, int row, int &n);
  
  static std::vector<int> kmpProcess(std::string &needle);
};

#endif /* LEETCODE_SOLUTION_H_ */