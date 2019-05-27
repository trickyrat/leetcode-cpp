#include "solution.h"

std::vector<int> Solution::twoSum(std::vector<int> &nums, int target) {
  auto size = nums.size();
  std::unordered_map<int, int> hash;
  std::vector<int> result;
  for (auto i = 0; i < size; i++) {
    int numberToFind = target - nums[i];
    if (hash.find(numberToFind) != hash.end()) {
      result.push_back(hash[numberToFind]);
      result.push_back(i);
      return result;
    }
    hash[nums[i]] = i;
  }
  return result;
}

ListNode *Solution::addTwoNumbers(ListNode *l1, ListNode *l2) {
  if (l1 == nullptr && l2 == nullptr)
    return nullptr;
  ListNode *head = new ListNode(0);
  ListNode *current = head;
  int carry = 0;
  while (l1 || l2) {
    int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
    carry = sum / 10;
    current->next = new ListNode(sum % 10);
    if (l1)
      l1 = l1->next;
    if (l2)
      l2 = l2->next;
    current = current->next;
  }
  if (carry)
    current->next = new ListNode(carry);
  return head->next;
}

int Solution::lengthOfLongestSubstring(std::string s) {
  std::vector<int> dic(256, -1);
  int maxlen = 0, start = -1;
  int len = s.length();
  for (int i = 0; i != len; i++) {
    if (dic[s[i]] > start)
      start = dic[s[i]];
    dic[s[i]] = i;
    maxlen = std::max(maxlen, i - start);
  }
  return maxlen;
}

double Solution::findMedianSortedArrays(std::vector<int> &nums1,
                                        std::vector<int> &nums2) {
  int m = nums1.size();
  int n = nums2.size();
  if (m > n) {
    std::swap(nums1, nums2);
    std::swap(m, n);
  }
  int iMin = 0, iMax = m, halfLen = (m + n + 1) / 2;

  while (iMin <= iMax) {
    int i = (iMin + iMax) / 2;
    int j = halfLen - i;
    if (i < iMax && nums2[j - 1] > nums1[i])
      iMin++;
    else if (i > iMin && nums1[i - 1] > nums2[j])
      iMax--;
    else {
      int maxLeft = 0;
      if (i == 0)
        maxLeft = nums2[j - 1];
      else if (j == 0)
        maxLeft = nums1[i - 1];
      else
        maxLeft = std::max(nums1[i - 1], nums2[j - 1]);
      if ((m + n) % 2 == 1)
        return maxLeft;

      int minRight = 0;
      if (i == m)
        minRight = nums2[j];
      else if (j == n)
        minRight = nums1[i];
      else
        minRight = std::min(nums1[i], nums2[j]);
      return (maxLeft + minRight) / 2.0;
    }
  }
  return 0.0;
}

std::string Solution::longestPalindrome(std::string s) {
  auto T = preProcess(s);
  auto n = T.length();
  auto *P = new int[n];
  auto C = 0, R = 0;
  for (auto i = 1; i < n - 1; i++) {
    auto i_mirror = 2 * C - i; // equals to i' = C - (i-C)

    P[i] = (R > i) ? std::min(R - i, P[i_mirror]) : 0;

    // Attempt to expand palindrome centered at i
    while (T[i + 1 + P[i]] == T[i - 1 - P[i]])
      P[i]++;

    // If palindrome centered at i expand past R,
    // adjust center based on expanded palindrome.
    if (i + P[i] > R) {
      C = i;
      R = i + P[i];
    }
  }

  // Find the maximum element in P.
  auto maxLen = 0;
  auto centerIndex = 0;
  for (auto i = 1; i < n - 1; i++) {
    if (P[i] > maxLen) {
      maxLen = P[i];
      centerIndex = i;
    }
  }
  delete[] P;

  return s.substr((centerIndex - 1 - maxLen) / 2, maxLen);
}

std::string Solution::convert(std::string s, int numRows) {
  if (numRows == 1)
    return s;
  std::string ret;
  int n = s.size();
  int cycleLen = 2 * numRows - 2;

  for (int i = 0; i < numRows; i++) {
    for (int j = 0; j + i < n; j += cycleLen) {
      ret += s[j + i];
      if (i != 0 && i != numRows - 1 && j + cycleLen - i < n)
        ret += s[j + cycleLen - i];
    }
  }
  return ret;
}

std::vector<std::vector<int>> Solution::threeSum(std::vector<int> &nums) {
  std::vector<std::vector<int>> res;
  int count = nums.size();
  std::sort(nums.begin(), nums.end());
  for (int i = 0; i < count; i++) {
    int target = -nums[i];
    int left = i + 1;
    int right = count - 1;
    if (target < 0)
      break;
    while (left < right) {
      int sum = nums[left] + nums[right];
      if (sum < target)
        left++;
      else if (sum > target)
        right--;
      else {
        std::vector<int> tmp{nums[i], nums[left], nums[right]};
        res.push_back(tmp);
        while (left < right && nums[left] == tmp[1])
          left++;
        while (left < right && nums[right] == tmp[2])
          right--;
      }
    }
    while (i + 1 < count && nums[i + 1] == nums[i])
      i++;
  }
  return res;
}

int Solution::threeSumClosest(std::vector<int> &nums, int target) {
  if (nums.size() < 3)
    return 0;
  int closest = nums[0] + nums[1] + nums[2];
  sort(nums.begin(), nums.end());
  for (int first = 0; first < nums.size() - 2; first++) {
    if (first > 0 && nums[first] == nums[first - 1])
      continue;
    int second = first + 1;
    int third = nums.size() - 1;
    while (second < third) {
      int currentSum = nums[first] + nums[second] + nums[third];
      if (currentSum == target)
        return currentSum;
      if (abs(target - currentSum) < abs(target - closest)) {
        closest = currentSum;
      }
      if (currentSum > target) {
        third--;
      } else {
        second++;
      }
    }
  }
  return closest;
}

void Solution::reverseString(std::vector<char> &s) {
  // two pointers
  int l = 0, r = s.size() - 1;
  while (l < r) {
    std::swap(s[l++], s[r--]);
  }
}

std::vector<std::vector<int>> Solution::fourSum(std::vector<int> &nums,
                                                int target) {
  std::vector<std::vector<int>> res;
  size_t n = nums.size();
  if (n < 4)
    return res;
  std::sort(nums.begin(), nums.end());
  for (size_t i = 0; i < n - 3; i++) {
    if (i > 0 && nums[i] == nums[i - 1])
      continue;
    if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target)
      break;
    if (nums[i] + nums[n - 3] + nums[n - 2] + nums[n - 1] < target)
      continue;
    for (size_t j = i + 1; j < n - 2; j++) {
      if (j > i + 1 && nums[j] == nums[j - 1])
        continue;
      if (nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target)
        break;
      if (nums[i] + nums[j] + nums[n - 2] + nums[n - 1] < target)
        continue;
      size_t left = j + 1, right = n - 1;
      while (left < right) {
        int sum = nums[left] + nums[right] + nums[i] + nums[j];
        if (sum < target)
          left++;
        else if (sum > target)
          right--;
        else {
          res.push_back(
              std::vector<int>{nums[i], nums[j], nums[left], nums[right]});
          do {
            left++;
          } while (nums[left] == nums[left - 1] && left < right);
          do {
            right--;
          } while (nums[right] == nums[right + 1] && left < right);
        }
      }
    }
  }
  return res;
}

int Solution::singleNumber(std::vector<int> &nums) {
  int res = 0;
  for (auto &i : nums)
    res ^= i;
  return res;
}

bool Solution::isAnagram(std::string s, std::string t) {
  if (s.length() != t.length())
    return false;
  int tables[26] = {0};
  for (int i = 0; i < s.length(); i++) {
    tables[s[i] - 'a']++;
    tables[t[i] - 'a']--;
  }
  for (int i = 0; i < 26; i++)
    if (tables[i])
      return false;
  return true;
}

int Solution::rob(std::vector<int> &nums) {
  auto notrob = 0;
  auto rob = 0;
  for (auto &item : nums) {
    auto current = notrob + item;
    notrob = std::max(notrob, rob);
    rob = current;
  }
  return std::max(rob, notrob);
}

int Solution::surfaceArea(std::vector<std::vector<int>> &grid) {
  int res = 0;
  int n = grid.size();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (grid[i][j])
        res += grid[i][j] * 4 + 2;
      if (i)
        res -= std::min(grid[i][j], grid[i - 1][j]) * 2;
      if (j)
        res -= std::min(grid[i][j], grid[i][j - 1]) * 2;
    }
  }
  return res;
}

int Solution::missingNumber(std::vector<int> &nums) {
  int n = nums.size();
  int sum = n * (n + 1) / 2;
  int actual = 0;
  for (int &num : nums) {
    actual += num;
  }
  return sum - actual;
}

int Solution::findDuplicate(std::vector<int> &nums) {
  int slow = nums[0];
  int fast = nums[0];
  do {
    slow = nums[slow];
    fast = nums[nums[fast]];
  } while (slow != fast);
  int ptr1 = nums[0];
  int ptr2 = slow;
  while (ptr1 != ptr2) {
    ptr1 = nums[ptr1];
    ptr2 = nums[ptr2];
  }
  return ptr1;
}

double Solution::myPower(double x, int n) {
  double res = 1.0;
  for (int i = n; i != 0; i /= 2) {
    if (i % 2 != 0)
      res *= x;
    x *= x;
  }
  return n < 0 ? 1 / res : res;
}

int Solution::projectionArea(std::vector<std::vector<int>> &grid) {
  size_t N = grid.size();
  int ans = 0;
  for (size_t i = 0; i < N; i++) {
    int row = 0;
    int column = 0;
    for (size_t j = 0; j < N; j++) {
      if (grid[i][j] > 0)
        ans++;
      row = std::max(row, grid[i][j]);
      column = std::max(column, grid[j][i]);
    }
    ans += row + column;
  }
  return ans;
}

std::vector<int> Solution::shortestToChar(std::string S, char C) {
  int n = S.size();
  std::vector<int> ans(n, 0);
  int prev = INT32_MIN / 2;
  for (int i = 0; i < n; i++) {
    if (S[i] == C)
      prev = i;
    ans[i] = i - prev;
  }
  prev = INT32_MAX / 2;
  for (int i = n - 1; i >= 0; i--) {
    if (S[i] == C)
      prev = i;
    ans[i] = std::min(ans[i], prev - i);
  }
  return ans;
}

int Solution::peakIndexInMountainArray(std::vector<int> &A) {
  size_t left = 0, right = A.size();
  while (left < right) {
    size_t mid = (left + right) / 2;
    if (A[mid] < A[mid + 1])
      left = mid + 1;
    else
      right = mid;
  }
  return left;
}

ListNode *Solution::middleNode(ListNode *head) {
  ListNode *slow = head;
  ListNode *fast = head;
  while (fast != nullptr && fast->next != nullptr) {
    slow = slow->next;
    fast = fast->next->next;
  }
  return slow;
}

std::vector<std::string> Solution::uncommonFromSentences(std::string A,
                                                         std::string B) {
  std::unordered_map<std::string, int> count;
  std::istringstream iss(B + " " + A);
  while (iss >> A)
    count[A]++;
  std::vector<std::string> res;
  for (auto w : count)
    if (w.second == 1)
      res.push_back(w.first);
  return res;
}

std::vector<std::vector<int>> Solution::combine(int n, int k) {
  std::vector<std::vector<int>> res;
  int i = 0;
  std::vector<int> p(k, 0);
  while (i >= 0) {
    p[i]++;
    if (p[i] > n)
      --i;
    else if (i == k - 1)
      res.push_back(p);
    else {
      ++i;
      p[i] = p[i - 1];
    }
  }
  return res;
}

uint32_t Solution::reverseBits(uint32_t n) {
  n = (n >> 16) | (n << 16);
  n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
  n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
  n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
  n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
  return n;
  // if (n == 0) return 0;
  // uint res = 0;
  // for (int i = 0; i < 32; i++)
  //{
  //    res <<= 1;
  //    if ((n & 1) == 1) res++;
  //    n >>= 1;
  //}
  // return res;
}

std::vector<std::vector<int>> Solution::generate(int numRows) {
  std::vector<std::vector<int>> res;
  for (auto i = 0; i < numRows; ++i) {
    res.push_back(std::vector<int>(i + 1, 1));
    for (auto j = 1; j < i; ++j)
      res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
  }
  return res;
}

bool Solution::isSymmetric(TreeNode *root) {
  // 4ms by recursion

  // return isMirror(root, root);

  // 4ms by literation

  std::queue<TreeNode *> q;
  q.push(root);
  q.push(root);
  while (!q.empty()) {
    TreeNode *l1 = q.front();
    q.pop();
    TreeNode *l2 = q.front();
    q.pop();
    if (l1 == nullptr && l2 == nullptr)
      continue;
    if (l1 == nullptr || l2 == nullptr)
      return false;
    if (l1->val != l2->val)
      return false;
    q.push(l1->left);
    q.push(l2->right);
    q.push(l1->right);
    q.push(l2->left);
  }
  return true;
}

bool Solution::isMirror(TreeNode *l1, TreeNode *l2) {
  if (l1 == nullptr && l2 == nullptr)
    return true;
  if (l1 == nullptr || l2 == nullptr)
    return false;
  return (l1->val == l2->val) && isMirror(l1->left, l2->right) &&
         isMirror(l1->right, l2->left);
}

int Solution::climbStairs(int n) {
  int a = 1, b = 1;
  while (n--)
    a = (b += a) - a;
  return a;
}

std::string Solution::addBinary(std::string a, std::string b) {
  std::string s = "";
  int c = 0, i = a.size() - 1, j = b.size() - 1;
  while (c == 1 || i >= 0 || j >= 0) {
    c += i >= 0 ? a[i--] - '0' : 0;
    c += j >= 0 ? b[j--] - '0' : 0;
    s = char(c % 2 + '0') + s;
    c /= 2;
  }
  return s;
}

bool Solution::hasCycle(ListNode *head) {
  if (head == nullptr || head->next == nullptr)
    return false;
  ListNode *slow = head;
  ListNode *fast = head->next;
  while (slow != fast) {
    if (fast == nullptr || fast->next == nullptr)
      return false;
    slow = slow->next;
    fast = fast->next->next;
  }
  return true;
}

int Solution::maxDepth(TreeNode *root) {
  // 8 ms
  // return root == nullptr ? 0 : 1 + max(maxDepth(root->left),
  // maxDepth(root->right));
  /*if (!root) return 0;
  int left = maxDepth(root->left), right = maxDepth(root->right);
  return std::max(left, right) + 1;*/
  // 4ms
  if (!root)
    return 0;
  int res = 0;
  std::queue<TreeNode *> q;
  q.push(root);
  while (!q.empty() > 0) {
    res++;
    for (int i = 0, n = q.size(); i < n; i++) {
      TreeNode *p = q.front();
      q.pop();
      if (p->left != nullptr)
        q.push(p->left);
      if (p->right != nullptr)
        q.push(p->right);
    }
  }
  return res;
}

int Solution::minDepth(TreeNode *root) {
  if (!root)
    return 0;
  int left = minDepth(root->left), right = minDepth(root->right);
  return 1 + (std::min(left, right) ? std::min(left, right)
                                    : std::max(left, right));
}

bool Solution::hasPathSum(TreeNode *root, int sum) {
  if (root == nullptr)
    return false;
  if (root->val == sum && root->left == nullptr && root->right == nullptr)
    return true;
  return hasPathSum(root->left, sum - root->val) ||
         hasPathSum(root->right, sum - root->val);
}

int Solution::divide(int dividend, int divisor) {
  // divisor = 0 dividend = INT_MIN  divisor = -1
  if (!divisor || (dividend == INT32_MIN && divisor == -1))
    return INT32_MAX;
  int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
  auto dvd = labs(dividend);
  auto dvs = labs(divisor);
  int res = 0;
  while (dvd >= dvs) {
    auto tmp = dvs;
    auto multiple = 1;
    while (dvd >= (tmp << 1)) {
      tmp <<= 1;
      multiple <<= 1;
    }
    dvd -= tmp;
    res += multiple;
  }
  return sign == 1 ? res : -res;
}

std::vector<std::vector<int>> Solution::levelOrderBottom(TreeNode *root) {
  std::vector<std::vector<int>> ret;
  if (!root)
    return ret;
  std::queue<TreeNode *> que;
  que.push(root);
  while (true) {
    auto nodeCount = que.size();
    if (nodeCount == 0)
      break;
    std::vector<int> tmp;

    while (nodeCount > 0) {
      TreeNode *dataNode = que.front();
      que.pop();
      tmp.push_back(dataNode->val);
      if (dataNode->left) {
        que.push(dataNode->left);
      }
      if (dataNode->right) {
        que.push(dataNode->right);
      }
      nodeCount--;
    }
    ret.insert(ret.begin(), tmp);
  }
  return ret;
}

ListNode *Solution::sortList(ListNode *head) {
  if (!head || !(head->next))
    return head;
  // length of the list
  ListNode *current = head;
  int len = 0;
  while (current) {
    len++;
    current = current->next;
  }
  ListNode dummy(0);
  dummy.next = head;
  ListNode *left, *right, *last;
  for (int i = 1; i < len; i <<= 1) {
    current = dummy.next;
    last = &dummy;
    while (current) {
      left = current;
      right = split(left, i);
      current = split(right, i);
      last = merge(left, right, last);
    }
  }
  return dummy.next;
}

int Solution::strStr(std::string haystack, std::string needle) {
  int m = haystack.length(), n = needle.length();
  // empty string return 0
  if (!n)
    return 0;
  std::vector<int> lps = kmpProcess(needle);
  for (int i = 0, j = 0; i < m;) {
    if (haystack[i] == needle[j]) {
      i++;
      j++;
    }
    if (j == n)
      return i - j;
    if (i < m && haystack[i] != needle[j]) {
      if (j)
        j = lps[j - 1];
      else
        i++;
    }
  }
  return -1;
}

std::vector<std::string> Solution::letterCombinations(std::string digits) {
  std::vector<std::string> result;
  if (digits.empty())
    return std::vector<std::string>();
  static const std::vector<std::string> maps = {
      "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
  result.push_back("");
  for (size_t i = 0; i < digits.size(); i++) {
    int num = digits[i] - '0';
    if (num < 0 || num > 9)
      break;
    const std::string &candidate = maps[num];
    if (candidate.empty())
      continue;
    std::vector<std::string> tmp;
    for (size_t j = 0; j < candidate.size(); j++)
      for (size_t k = 0; k < result.size(); k++)
        tmp.push_back(result[k] + candidate[j]);
    result.swap(tmp);
  }
  return result;
}

int Solution::firstMissingPositive(std::vector<int> &nums) {
  auto n = nums.size();
  for (auto i = 0; i < n; i++) {
    while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i])
      std::swap(nums[i], nums[nums[i] - 1]);
  }
  for (auto i = 0; i < n; i++) {
    if (nums[i] != i + 1)
      return i + 1;
  }
  return n + 1;
}

int Solution::mySqrt(int x) {
  if (x <= 1)
    return x;
  int left = 0, right = x;
  int mid = 1;
  while (right >= left) {
    mid = left + (right - left) / 2;
    if (mid == x / mid)
      return mid;
    else if (mid < x / mid)
      left = mid + 1;
    else
      right = mid - 1;
  }
  return right;
}

int Solution::search(std::vector<int> &nums, int target) {
  int left = 0, right = nums.size();
  while (left < right) {
    int mid = (left + right) / 2;
    double num = (nums[mid] < nums[0]) == (target < nums[0])
                     ? nums[mid]
                     : target < nums[0] ? -INFINITY : INFINITY;
    if (num < target)
      left = mid + 1;
    else if (num > target)
      right = mid;
    else
      return mid;
  }
  return -1;
}

bool Solution::canJump(std::vector<int> &nums) {
  int n = nums.size();
  if (n <= 1)
    return false;
  int i = 0;
  for (int reach = 0; i < n && i <= reach; i++) {
    reach = std::max(i + nums[i], reach);
  }
  return i == n;
}

std::vector<int> Solution::plusOne(std::vector<int> &digits) {
  for (size_t i = digits.size(); i--; digits[i] = 0)
    if (digits[i]++ < 9)
      return digits;
  digits[0]++;
  digits.push_back(0);
  return digits;
}

void Solution::move_zeroes(std::vector<int> &nums) {
  auto pos = 0;
  for (auto &num : nums)
    if (num)
      std::swap(nums[pos++], num);
}

std::string Solution::preProcess(std::string s) {
  auto n = s.length();
  if (n == 0)
    return "^$";
  std::string ret = "^";
  for (auto i = 0; i < n; i++)
    ret += "#" + s.substr(i, 1);
  ret += "#$";
  return ret;
}

std::vector<std::vector<std::string>> Solution::solveNQueens(int n) {
  std::vector<std::vector<std::string>> res;
  std::vector<std::string> nQueens(n, std::string(n, '.'));
  std::vector<int> flag(5 * n - 2, 1);
  solve_NQueens(res, nQueens, flag, 0, n);
  return res;
}

bool Solution::isValid(std::string s) {
  std::stack<char> stack;
  for (char item : s) {
    if (item == '(' || item == '{' || item == '[')
      stack.push(item);
    else {
      if (stack.empty())
        return false;
      if (item == ')' && stack.top() != '(')
        return false;
      if (item == '}' && stack.top() != '{')
        return false;
      if (item == ']' && stack.top() != '[')
        return false;
      stack.pop();
    }
  }
  return stack.empty();
}

std::vector<std::string> Solution::readBinaryWatch(int num) {
  std::vector<std::string> rs;
  for (int h = 0; h < 12; h++)
    for (int m = 0; m < 60; m++)
      if (std::bitset<10>(h << 6 | m).count() == num)
        rs.emplace_back(std::to_string(h) + (m < 10 ? ":0" : ":") +
                        std::to_string(m));
  return rs;
}

bool Solution::isSameTree(TreeNode *p, TreeNode *q) {
  if (p == nullptr || q == nullptr)
    return p == q;
  return p->val == q->val && isSameTree(p->left, q->left) &&
         isSameTree(p->right, q->right);
}

// TODO: maxArea
int Solution::maxArea(std::vector<int> &height) { return 0; }

/*Private methods*/

ListNode *Solution::split(ListNode *head, int n) {
  for (int i = 1; head && i < n; i++)
    head = head->next;
  if (!head)
    return nullptr;
  ListNode *second = head->next;
  head->next = nullptr;
  return second;
}

ListNode *Solution::merge(ListNode *l1, ListNode *l2, ListNode *head) {
  ListNode *current = head;
  while (l1 && l2) {
    if (l1->val > l2->val) {
      current->next = l2;
      current = l2;
      l2 = l2->next;
    } else {
      current->next = l1;
      current = l1;
      l1 = l1->next;
    }
  }
  current->next = l1 ? l1 : l2;
  while (current->next) {
    current = current->next;
  }
  return current;
}

std::vector<int> Solution::kmpProcess(std::string &needle) {
  int n = needle.length();
  std::vector<int> lps(n, 0);
  for (int i = 1, len = 0; i < n;) {
    if (needle[i] == needle[len])
      lps[i++] = ++len;
    else if (len)
      len = lps[len - 1];
    else
      lps[i++] = 0;
  }
  return lps;
}

bool Solution::isValid(std::vector<std::string> &nQueens, int row, int col,
                       int &n) {
  // check if the column had a queen before
  for (int i = 0; i != row; ++i) {
    if (nQueens[i][col] == 'Q')
      return false;
  }
  // check if the 45 diagonal had a queen before
  for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j) {
    if (nQueens[i][j] == 'Q')
      return false;
  }
  // check if the 135 diagonal had a queen before
  for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j) {
    if (nQueens[i][j] == 'Q')
      return false;
  }
  return true;
}

// one array
void Solution::solve_NQueens(std::vector<std::vector<std::string>> &res,
                             std::vector<std::string> nQueens,
                             std::vector<int> &flag, int row, int &n) {
  if (row == n) {
    res.push_back(nQueens);
    return;
  }
  for (int col = 0; col != n; ++col) {
    if (flag[col] && flag[n + row + col] && flag[4 * n - 2 + col - row]) {
      flag[col] = flag[n + row + col] = flag[4 * n - 2 + col - row] = 0;
      nQueens[row][col] = 'Q';
      solve_NQueens(res, nQueens, flag, row + 1, n);
      nQueens[row][col] = '.';
      flag[col] = flag[n + row + col] = flag[4 * n - 2 + col - row] = 1;
    }
  }
}

std::string Solution::toLowerCase(std::string str) {
  for (auto &c : str) {
    if ('A' <= c && c <= 'Z')
      c = c - 'A' + 'a';
  }
  return str;
}

TreeNode *Solution::mergeTrees(TreeNode *t1, TreeNode *t2) {
  if (t1 == nullptr)
    return t2;
  if (t2 == nullptr)
    return t1;
  t1->val += t2->val;
  t1->left = mergeTrees(t1->left, t2->left);
  t1->right = mergeTrees(t1->right, t2->right);
  return t1;
}

std::vector<std::vector<int>> Solution::levelOrder(Node *root) {
  if (root == nullptr)
    return {};
  std::vector<std::vector<int>> res;
  std::queue<Node *> q;
  q.push(root);
  while (!q.empty()) {
    size_t size = q.size();
    std::vector<int> tmp;
    for (size_t i = 0; i < size; ++i) {
      Node *cur = q.front();
      tmp.push_back(cur->val);
      for (auto child : cur->children)
        q.push(child);
      q.pop();
    }
    res.push_back(tmp);
  }
  return res;
}

int Solution::fib(int N) {
  if (N < 2)
    return N;
  int f0 = 0;
  int f1 = 1;
  int res = 0;
  for (int i = 1; i < N; i++) {
    res = f0 + f1;
    f0 = f1;
    f1 = res;
  }
  return res;
}

std::vector<int> Solution::sortArrayByParity(std::vector<int> &A) {
  size_t i = 0, j = A.size() - 1;
  while (i < j) {
    if (A[i] % 2 > A[j] % 2) {
      int tmp = A[i];
      A[i] = A[j];
      A[j] = tmp;
    }
    if (A[i] % 2 == 0)
      i++;
    if (A[j] % 2 == 1)
      j--;
  }
  return A;
}

int Solution::Reverse(int x) {
  int res = 0;
  while (x) {
    int pop = x % 10;
    x /= 10;
    if (res > INT32_MAX / 10 || (res == INT32_MAX / 10 && pop > 7))
      return 0;
    if (res < INT32_MIN / 10 || (res == INT32_MIN / 10 && pop < -8))
      return 0;
  }
  return res;
}

int Solution::Atoi(std::string str) {
  if (str.empty())
    return 0;
  int sign = 1;
  int bas = 0;
  size_t i = 0;
  size_t len = str.size();
  while (str[i] == ' ')
    i++;
  if (str[i] == '-' || str[i] == '+')
    sign = str[i++] == '-' ? -1 : 1;
  while (i < len && str[i] >= '0' && str[i] <= '9') {
    if (bas > INT32_MAX / 10 || (bas == INT32_MAX / 10 && str[i] - '0' > 7)) {
      return sign == 1 ? INT32_MAX : INT32_MIN;
    }
    bas = 10 * bas + (str[i++] - '0');
  }
  return bas * sign;
}

bool Solution::IsPalindrome(int x) {
  if (x < 0 || (x != 0 && x % 10 == 0))
    return false;
  int res = 0;
  while (res < x) {
    res = res * 10 + x % 10;
    x /= 10;
  }
  return (x == res || x == res / 10);
}

bool Solution::IsMatch(std::string s, std::string p) {
  size_t m = s.size(), n = p.size();
  std::vector<std::vector<bool>> f(m + 1, std::vector<bool>(n + 1, false));
  f[0][0] = true;
  for (size_t i = 1; i <= m; i++)
    f[i][0] = false;
  for (size_t j = 1; j <= n; j++)
    f[0][j] = j > 1 && '*' == p[j - 1] && f[0][j - 2];

  for (size_t i = 1; i <= m; i++)
    for (size_t j = 1; j <= n; j++)
      if (p[j - 1] != '*')
        f[i][j] = f[i - 1][j - 1] && (s[i - 1] == p[j - 1] || '.' == p[j - 1]);
      else
        f[i][j] = f[i][j - 2] ||
                  (s[i - 1] == p[j - 2] || '.' == p[j - 2]) && f[i - 1][j];
  return f[m][n];
}

std::string Solution::intToRoman(int num) {
  std::vector<std::string> M = {"", "M", "MM", "MMM"};
  std::vector<std::string> C = {"",  "C",  "CC",  "CCC",  "CD",
                                "D", "DC", "DCC", "DCCC", "CM"};
  std::vector<std::string> X = {"",  "X",  "XX",  "XXX",  "XL",
                                "L", "LX", "LXX", "LXXX", "XC"};
  std::vector<std::string> I = {"",  "I",  "II",  "III",  "IV",
                                "V", "VI", "VII", "VIII", "IX"};
  return M[num / 1000] + C[(num % 1000) / 100] + X[(num % 100) / 10] +
         I[num % 10];
}

int Solution::romanToInteger(std::string s) {
  std::unordered_map<char, int> dic = {{'I', 1},   {'V', 5},   {'X', 10},
                                       {'L', 50},  {'C', 100}, {'D', 500},
                                       {'M', 1000}};
  int value = 0;
  char prev = s[0];
  for (auto &curr : s) {
    value += dic[curr];
    if (dic[prev] < dic[curr])
      value -= dic[prev] * 2;
    prev = curr;
  }
  return value;
}

std::string Solution::longestCommonPrefix(std::vector<std::string> &strs) {
  // TODO
}

ListNode *Solution::removeNthFromEnd(ListNode *head, int n) {
  ListNode *dummy(0);
  dummy->next = head;
  ListNode *first = dummy;
  ListNode *second = dummy;
  for (int i = 1; i <= n + 1; i++)
    first = first->next;
  while (first != nullptr) {
    first = first->next;
    second = second->next;
  }
  second->next = second->next->next;
  return dummy->next;
}

ListNode *Solution::mergeTwoLists(ListNode *l1, ListNode *l2) {
  // Recursive
  if (l1 == nullptr)
    return l2;
  if (l2 == nullptr)
    return l1;
  ListNode *ans = nullptr;
  if (l1->val < l2->val) {
    ans = l1;
    ans->next = mergeTwoLists(l1->next, l2);
  } else {
    ans = l2;
    ans->next = mergeTwoLists(l1, l2->next);
  }
  return ans;
  // Iteratively
  // ListNode* point(0);
  // ListNode* head = point;
  // while (l1 != nullptr && l2 != nullptr) {
  //    if (l1->val <= l2->val) {
  //        point->next = l1;
  //        l1 = l1->next;
  //    } else {
  //        point->next = l2;
  //        l2 = l2->next;
  //    }
  //    point = point->next;
  //}
  // if (l1 == nullptr)
  //    point->next = l2;
  // if(l2 == nullptr)
  //    point->next = l1;
  // return head->next;
}

void Solution::solveSudoku(std::vector<std::vector<char>> &board) {
  doSolve(board, 0, 0);
}
bool Solution::isValid(std::vector<std::vector<char>> &board, int row, int col,
                       char num) {
  int blkrow = (row / 3) * 3, blkcol = (col / 3) * 3;
  for (int i = 0; i < 9; i++)
    if (board[i][col] == num || board[row][i] == num ||
        board[blkrow + i / 3][blkcol + i % 3] == num)
      return false;
  return true;
}

bool Solution::doSolve(std::vector<std::vector<char>> &board, int row,
                       int col) {
  for (int i = row; i < 9; i++, col = 0) {
    for (int j = col; j < 9; j++) {
      if (board[i][j] != '.')
        continue;
      for (char num = '1'; num <= '9'; num++) {
        if (isValid(board, i, j, num)) {
          board[i][j] = num;
          if (doSolve(board, i, j + 1))
            return true;
          board[i][j] = '.';
        }
      }
      return false;
    }
  }
  return true;
}

std::vector<int> Solution::searchRange(std::vector<int> &nums, int target) {
  // binary-search
  if(nums.empty())
    return {-1,-1};
  int lo = 0, hi = nums.size() - 1;
  while(lo < hi){
    int mid = lo + (hi - lo) / 2;
    if(nums[mid] >= target)
      hi = mid;
    else
      lo = mid + 1;
  }
  int first = (nums[lo] == target ? lo : -1);
  if(first == -1)
    return {-1, -1};
  lo = first, hi = nums.size() - 1;
  while(lo < hi) {
    int mid = lo + (hi - lo + 1) / 2;
    if(nums[mid] <= target)
      lo = mid;
    else
      hi = mid - 1;
  }
  return {first, lo};
}
int Solution::searchInsert(std::vector<int>& nums, int target){
  int lo = 0, hi = nums.size() - 1;
  while(lo < hi){
    int mid = lo + (hi - lo) / 2;
    if(nums[mid] < target)
      lo = mid + 1;
    else
      hi = mid;
  }
  return nums[lo] < target ? lo + 1 : lo;
}

int Solution::rangeSumBST(TreeNode* root, int L, int R){
  int sum = 0;
  if(root == nullptr)
    return sum;
  if(root->val > L)
    sum += rangeSumBST(root->left, L, R);
  if(root->val < R)
    sum += rangeSumBST(root->right, L, R);
  if(root->val >= L && root->val <= R)
    sum += root->val;
  return sum;
}

