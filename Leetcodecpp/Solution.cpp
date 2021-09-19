#include "Solution.h"

int Solution::hammingWeight(uint32_t n) {
  int res = 0;
  while (n) {
    n &= n - 1;
    res++;
  }
  return res;
}

std::vector<int> Solution::twoSum(std::vector<int>& nums, int target) {
    size_t size = nums.size();
    std::unordered_map<int, size_t> hash;
    std::vector<int> result;
    for (size_t i = 0; i < size; i++) {
        int numberToFind = target - nums[i];
        if (hash.contains(numberToFind)) {
            result.push_back(hash[numberToFind]);
            result.push_back(i);
            return result;
        }
        hash[nums[i]] = i;
    }
    return result;
}

ListNode* Solution::addTwoNumbers(ListNode* l1, ListNode* l2) {
    if (l1 == nullptr && l2 == nullptr)
        return nullptr;
    ListNode* head = new ListNode(0);
    ListNode* current = head;
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

double Solution::findMedianSortedArrays(std::vector<int>& nums1,
    std::vector<int>& nums2) {
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
    auto* P = new int[n];
    auto C = 0, R = 0;
    for (int i = 1; i < n - 1; i++) {
        int i_mirror = 2 * C - i;

        P[i] = (R > i) ? std::min(R - i, P[i_mirror]) : 0;
        while (T[i + 1 + P[i]] == T[i - 1 - P[i]])
            P[i]++;
        if (i + P[i] > R) {
            C = i;
            R = i + P[i];
        }
    }
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

int Solution::maxArea(std::vector<int>& height) {
    int maxArea = 0;
    int left = 0, right = height.size() - 1;
    while (left < right) {
        maxArea = std::max(maxArea,
            std::min(height[left], height[right]) * (right - left));
        if (height[left] < height[right])
            left++;
    }
    return maxArea;
}

std::string Solution::intToRoman(int num) {
    std::vector<std::string> M = { "", "M", "MM", "MMM" };
    std::vector<std::string> C = { "",  "C",  "CC",  "CCC",  "CD",
                                  "D", "DC", "DCC", "DCCC", "CM" };
    std::vector<std::string> X = { "",  "X",  "XX",  "XXX",  "XL",
                                  "L", "LX", "LXX", "LXXX", "XC" };
    std::vector<std::string> I = { "",  "I",  "II",  "III",  "IV",
                                  "V", "VI", "VII", "VIII", "IX" };
    return M[num / 1000] + C[(num % 1000) / 100] + X[(num % 100) / 10] +
        I[num % 10];
}

int Solution::romanToInteger(std::string s) {
    std::unordered_map<char, int> dic = { {'I', 1},   {'V', 5},   {'X', 10},
                                         {'L', 50},  {'C', 100}, {'D', 500},
                                         {'M', 1000} };
    int value = 0;
    char prev = s[0];
    for (auto& curr : s) {
        value += dic[curr];
        if (dic[prev] < dic[curr])
            value -= dic[prev] * 2;
        prev = curr;
    }
    return value;
}

std::string Solution::longestCommonPrefix(std::vector<std::string>& strs) {
    // TODO
    return "";
}

std::vector<std::vector<int>> Solution::threeSum(std::vector<int>& nums) {
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
                std::vector<int> tmp{ nums[i], nums[left], nums[right] };
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

int Solution::threeSumClosest(std::vector<int>& nums, int target) {
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
            }
            else {
                second++;
            }
        }
    }
    return closest;
}

std::vector<std::string> Solution::letterCombinations(std::string digits) {
    std::vector<std::string> result;
    if (digits.empty())
        return std::vector<std::string>();
    static const std::vector<std::string> maps = {
        "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
    result.push_back("");
    for (size_t i = 0; i < digits.size(); i++) {
        int num = digits[i] - '0';
        if (num < 0 || num > 9)
            break;
        const std::string& candidate = maps[num];
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

std::vector<std::vector<int>> Solution::fourSum(std::vector<int>& nums,
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

ListNode* Solution::removeNthFromEnd(ListNode* head, int n) {
    ListNode* dummy(0);
    dummy->next = head;
    ListNode* first = dummy;
    ListNode* second = dummy;
    for (int i = 1; i <= n + 1; i++)
        first = first->next;
    while (first != nullptr) {
        first = first->next;
        second = second->next;
    }
    second->next = second->next->next;
    return dummy->next;
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

ListNode* Solution::mergeTwoLists(ListNode* l1, ListNode* l2) {
    // Recursive
    if (l1 == nullptr)
        return l2;
    if (l2 == nullptr)
        return l1;
    ListNode* ans = nullptr;
    if (l1->val < l2->val) {
        ans = l1;
        ans->next = mergeTwoLists(l1->next, l2);
    }
    else {
        ans = l2;
        ans->next = mergeTwoLists(l1, l2->next);
    }
    return ans;
    // Iteratively
    // ListNode head(0);
    // ListNode* point = &head;
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
    // return head.next;
}

std::vector<std::string> Solution::generateParenthesis(int n) {
    std::vector<std::string> ans;
    if (n == 0)
        ans.push_back("");
    else {
        for (int c = 0; c < n; c++)
            for (std::string left : generateParenthesis(c))
                for (std::string right : generateParenthesis(n - 1 - c))
                    ans.push_back("(" + left + ")" + right);
    }
    return ans;
}

ListNode* Solution::mergeKLists(std::vector<ListNode*>& lists) {
    int len = lists.size();
    int interval = 1;
    while (interval < len) {
        for (int i = 0; i < len - interval; i += interval * 2)
            lists[i] = mergeTwoLists(lists[i], lists[i + interval]);
        interval *= 2;
    }
    return len > 0 ? lists[0] : nullptr;
}

ListNode* Solution::swapPairs(ListNode* head) {
    ListNode** pp = &head, * a, * b;
    while ((a = *pp) && (b = a->next)) {
        a->next = b->next;
        b->next = a;
        *pp = b;
        pp = &(a->next);
    }
    return head;
}

ListNode* Solution::reverseKGroup(ListNode* head, int k) {
    int n = 0;
    for (ListNode* i = head; i; n++, i = i->next)
        ;
    ListNode dummy(-1);
    dummy.next = head;
    for (ListNode* prev = &dummy, *tail = head; n >= k; n -= k) {
        for (int i = 1; i < k; i++) {
            ListNode* next = tail->next->next;
            tail->next->next = prev->next;
            prev->next = tail->next;
            tail->next = next;
        }
        prev = tail;
        tail = tail->next;
    }
    return dummy.next;
}

int Solution::removeDuplicates(std::vector<int>& nums) {
    int i = nums.size() > 0 ? 1 : 0;
    for (int n : nums)
        if (n > nums[i - 1])
            nums[i++] = n;
    return i;
}

int Solution::removeElement(std::vector<int>& nums, int val) {
    int len = nums.size();
    int found = 0;
    for (int i = 0; i < len; i++) {
        if (found > 0)
            nums[i - found] = nums[i];
        if (nums[i] == val)
            found++;
    }
    return len - found;
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

int Solution::divide(int dividend, int divisor) {
    // divisor = 0 dividend = INT_MIN  divisor = -1
    if (divisor == 0 || (dividend == INT32_MIN && divisor == -1))
        return INT32_MAX;
    int sign = dividend < 0 ^ divisor < 0 ? -1 : 1;
    long dvd = labs(dividend);
    long dvs = labs(divisor);
    long res = 0;
    while (dvd >= dvs) {
        long tmp = dvs;
        int multiple = 1;
        while (dvd >= (tmp << 1)) {
            tmp <<= 1;
            multiple <<= 1;
        }
        dvd -= tmp;
        res += multiple;
    }
    return sign * res;
}

std::vector<int> Solution::findSubstring(std::string s,
    std::vector<std::string>& words) {
    if (s.empty() || words.empty())
        return {};
    int n = s.size();
    int size = words.size();
    int len = words[0].size();
    std::unordered_map<std::string, int> map;
    for (auto& word : words)
        map[word]++;
    std::vector<int> ret;
    for (int i = 0; i < len; i++) {
        int left = i, count = 0;
        std::unordered_map<std::string, int> window;
        for (int j = i; j + len - 1 < n; j += len) {
            std::string str = s.substr(j, len);
            if (map.count(str) == 0) {
                window.clear();
                count = 0;
                left = j + len;
            }
            else {
                window[str]++;
                count++;
                while (left + len - 1 < n && window[str] > map[str]) {
                    window[s.substr(left, len)]--;
                    count--;
                    left += len;
                }
                if (count == size) {
                    ret.push_back(left);
                    window[s.substr(left, len)]--;
                    count--;
                    left += len;
                }
            }
        }
    }
    return ret;
}

void Solution::nextPermutation(std::vector<int>& nums) {
    int len = nums.size() - 1;
    int i = len - 1;
    while (i >= 0 && nums[i + 1] <= nums[i])
        i--;
    if (i >= 0) {
        int j = len;
        while (j >= 0 && nums[j] <= nums[i])
            j--;
        std::swap(nums[i], nums[j]);
    }
    std::reverse(nums.begin() + i + 1, nums.end());
}

int Solution::longestValidParentheses(std::string &s) {
  int left = 0, right = 0, maxLen = 0;
  int len = s.size() - 1;
  for (int i =0;i<len;i++) {
    if (s[i] == '(') {
      left++;
    } else {
      right++;
    }
    if (left == right) {
      maxLen = std::max(maxLen, 2 * right);
    } else if (right > left) {
      left = right = 0;
    }
  }
  left = right = 0;
  for (int i = len; i >= 0; i--) {
    if (s[i] == '(') {
      left++;
    } else {
      right++;
    }
    if (left == right) {
      maxLen = std::max(maxLen, 2 * left);
    } else if (left > right) {
      left = right = 0;
    }
  }
  return maxLen;
}

int Solution::search(std::vector<int>& nums, int target) {
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

std::vector<int> Solution::searchRange(std::vector<int>& nums, int target) {
    // binary-search
    if (nums.empty())
        return { -1, -1 };
    int lo = 0, hi = nums.size() - 1;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (nums[mid] >= target)
            hi = mid;
        else
            lo = mid + 1;
    }
    int first = (nums[lo] == target ? lo : -1);
    if (first == -1)
        return { -1, -1 };
    lo = first, hi = nums.size() - 1;
    while (lo < hi) {
        int mid = lo + (hi - lo + 1) / 2;
        if (nums[mid] <= target)
            lo = mid;
        else
            hi = mid - 1;
    }
    return { first, lo };
}

int Solution::searchInsert(std::vector<int>& nums, int target) {
    int lo = 0, hi = nums.size() - 1;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (nums[mid] < target)
            lo = mid + 1;
        else
            hi = mid;
    }
    return nums[lo] < target ? lo + 1 : lo;
}

bool Solution::isValidSudoku(std::vector<std::vector<char>>& board) {
    int rows[9][9] = { 0 };
    int cols[9][9] = { 0 };
    int blocks[3][3][9] = { 0 };
    for (int r = 0; r < 9; r++)
        for (int c = 0; c < 9; c++)
            if (board[r][c] != '.') {
                int number = board[r][c] - '1';
                if (rows[r][number]++ || cols[c][number]++ ||
                    blocks[r / 3][c / 3][number]++)
                    return false;
            }
    return true;
}

void Solution::solveSudoku(std::vector<std::vector<char>>& board) {
    doSolve(board, 0, 0);
}

std::string Solution::countAndSay(int n) {
    if (n == 0)
        return "";
    std::string res = "1";
    while (--n) {
        std::string tmp = "";
        for (int i = 0; i < res.size(); i++) {
            int count = 1;
            while (i + 1 < res.size() && res[i] == res[i + 1]) {
                count++;
                i++;
            }
            tmp += std::to_string(count) + res[i];
        }
        res = tmp;
    }
    return res;
}

std::vector<std::vector<int>>
Solution::combinationSum(std::vector<int>& candidates, int target) {
  return std::vector<std::vector<int>>();
}

std::vector<std::vector<int>>
Solution::combinationSum2(std::vector<int>& candidates, int target) {
  return std::vector<std::vector<int>>();
}

int Solution::firstMissingPositive(std::vector<int>& nums) {
    size_t n = nums.size();
    for (size_t i = 0; i < n; i++) {
        while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i])
            std::swap(nums[i], nums[nums[i] - 1]);
    }
    for (size_t i = 0; i < n; i++) {
        if (nums[i] != i + 1)
            return i + 1;
    }
    return n + 1;
}

std::string Solution::multiply(std::string num1, std::string num2) {
    int m = num1.size(), n = num2.size();
    std::string sum(m + n, '0');
    for (int i = m - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            int mul = (sum[i + j + 1] - '0') + (num1[i] - '0') * (num2[j] - '0');
            sum[i + j + 1] = mul % 10 + '0';
            sum[i + j] += mul / 10;
        }
    }
    for (int i = 0; i < m + n; i++) {
        if (sum[i] != '0')
            return sum.substr(i);
    }
    return "0";
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

std::vector<std::vector<std::string>> Solution::solveNQueens(int n) {
    std::vector<std::vector<std::string>> res;
    std::vector<std::string> nQueens(n, std::string(n, '.'));
    std::vector<int> flag(5 * n - 2, 1);
    solveNQueens(res, nQueens, flag, 0, n);
    return res;
}

std::vector<int> Solution::spiralOrder(std::vector<std::vector<int>>& matrix) {
    if (matrix.size() == 0)
        return std::vector<int>(0);
    int startRow = 0, startColumn = 0;
    size_t height = matrix.size(), width = matrix[0].size();
    std::vector<int> result;
    while (true) {
        if (height == 0 || width == 0)
            break;
        for (int col = startColumn; col < startColumn + width; col++)
            result.push_back(matrix[startRow][col]);
        startRow++;
        height--;
        if (height == 0 || width == 0)
            break;
        for (int row = startRow; row < startRow + height; row++)
            result.push_back(matrix[row][startColumn + width - 1]);
        width--;
        if (height == 0 || width == 0)
            break;
        for (int col = startColumn + width - 1; col >= startColumn; col--)
            result.push_back(matrix[startRow + height - 1][col]);
        height--;
        if (height == 0 || width == 0)
            break;
        for (int row = startRow + height - 1; row >= startRow; row--)
            result.push_back(matrix[row][startColumn]);
        startColumn++;
        width--;
    }
    return result;
}

bool Solution::canJump(std::vector<int>& nums) {
    int n = nums.size();
    if (n <= 1)
        return false;
    int i = 0;
    for (int reach = 0; i < n && i <= reach; i++) {
        reach = std::max(i + nums[i], reach);
    }
    return i == n;
}

int Solution::lengthOfLastWord(std::string s) {
    int len = 0, tail = s.length() - 1;
    while (tail >= 0 && s[tail] == ' ')
        tail--;
    while (tail >= 0 && s[tail] != ' ') {
        len++;
        tail--;
    }
    return len;
}

std::vector<std::vector<int>> Solution::generateMatrix(int n) {
    std::vector<std::vector<int>> matrix(n, std::vector<int>(n));
    if (n == 0)
        return matrix;
    int startRow = 0, startColumn = 0;
    int index = 1, height = n, width = n;
    while (true) {
        if (height == 0 || width == 0)
            break;
        for (int col = startColumn; col < startColumn + width; col++)
            matrix[startRow][col] = index++;
        startRow++;
        height--;
        if (height == 0 || width == 0)
            break;
        for (int row = startRow; row < startRow + height; row++)
            matrix[row][startColumn + width - 1] = index++;
        width--;
        if (height == 0 || width == 0)
            break;
        for (int col = startColumn + width - 1; col >= startColumn; col--)
            matrix[startRow + height - 1][col] = index++;
        height--;
        if (height == 0 || width == 0)
            break;
        for (int row = startRow + height - 1; row >= startRow; row--)
            matrix[row][startColumn] = index++;
        startColumn++;
        width--;
    }
    return matrix;
}

ListNode* Solution::rotateRight(ListNode* head, int k) {
    if (head == nullptr)
        return nullptr;
    if (head->next == nullptr)
        return head;
    ListNode* old_tail = head;
    int n;
    for (n = 1; old_tail->next; n++)
        old_tail = old_tail->next;
    old_tail->next = head;
    ListNode* new_tail = head;
    for (int i = 0; i < n - k % n - 1; i++)
        new_tail = new_tail->next;
    ListNode* new_head = new_tail->next;
    new_tail->next = nullptr;
    return new_head;
}

int Solution::uniquePaths(int m, int n) {
    std::vector<int> dp(n, 1);
    for (int i = 1; i < m; i++)
        for (int j = 1; j < n; j++)
            dp[j] += dp[j - 1];
    return dp[n - 1];
}

int Solution::uniquePathsWithObstacles(
    std::vector<std::vector<int>>& obstacleGrid) {
    // int height = obstacleGrid.size();
    // int width = obstacleGrid[0].size();
    // std::vector<long> dp(height, 0);
    // for(int i = 0; i < height; i++) {
    //   if(!obstacleGrid[i][0])
    //     dp[i] = 1;
    //   else break;
    // }
    // for(int j = 1; j < width; j++) {
    //   bool flag = false;
    //   if(obstacleGrid[0][j])
    //     dp[0] = 0;
    //   else flag = true;
    //   for(int i = 1;i < height; i++) {
    //     if(!obstacleGrid[i][j]) {
    //       dp[i] += dp[i - 1];
    //       if(dp[i])
    //         flag = true;
    //     } else dp[i] = 0;
    //   }
    //   if(!flag) return 0;
    // }
    // return dp[height - 1];
  return 0;
}

std::vector<int> Solution::plusOne(std::vector<int>& digits) {
    for (size_t i = digits.size(); i--; digits[i] = 0)
        if (digits[i]++ < 9)
            return digits;
    digits[0]++;
    digits.push_back(0);
    return digits;
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

int Solution::climbStairs(int n) {
    int a = 1, b = 1;
    while (n--)
        a = (b += a) - a;
    return a;
}

bool Solution::searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
    int row = matrix.size();
    if (row == 0)
        return false;
    int col = matrix[0].size();
    int low = 0, high = row * col - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        int r = mid / col;
        int c = mid % col;
        if (matrix[r][c] > target)
            high = mid - 1;
        else if (matrix[r][c] < target)
            low = mid + 1;
        else
            return true;
    }
    return false;
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

std::vector<int> Solution::inorderTraversal(TreeNode* root) {
    std::vector<int> res;
    std::stack<TreeNode*> stack;
    TreeNode* curr = root;
    while (curr != nullptr || !stack.empty()) {
        while (curr != nullptr) {
            stack.push(curr);
            curr = curr->left;
        }
        curr = stack.top();
        stack.pop();
        res.push_back(curr->val);
        curr = curr->right;
    }
    return res;
}

bool Solution::isSameTree(TreeNode* p, TreeNode* q) {
    if (p == nullptr || q == nullptr)
        return p == q;
    return p->val == q->val && isSameTree(p->left, q->left) &&
        isSameTree(p->right, q->right);
}

bool Solution::isSymmetric(TreeNode* root) {
    // 4ms by recursion

    // return isMirror(root, root);

    // 4ms by literation

    std::queue<TreeNode*> q;
    q.push(root);
    q.push(root);
    while (!q.empty()) {
        TreeNode* l1 = q.front();
        q.pop();
        TreeNode* l2 = q.front();
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

int Solution::maxDepth(TreeNode* root) {
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
    std::queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        res++;
        for (int i = 0, n = q.size(); i < n; i++) {
            TreeNode* p = q.front();
            q.pop();
            if (p->left != nullptr)
                q.push(p->left);
            if (p->right != nullptr)
                q.push(p->right);
        }
    }
    return res;
}

std::vector<std::vector<int>> Solution::levelOrderBottom(TreeNode* root) {
    std::vector<std::vector<int>> ret;
    if (!root)
        return ret;
    std::queue<TreeNode*> que;
    que.push(root);
    while (true) {
        auto nodeCount = que.size();
        if (nodeCount == 0)
            break;
        std::vector<int> tmp;

        while (nodeCount > 0) {
            TreeNode* dataNode = que.front();
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

int Solution::minDepth(TreeNode* root) {
    if (!root)
        return 0;
    int left = minDepth(root->left), right = minDepth(root->right);
    return 1 + (std::min(left, right) ? std::min(left, right)
        : std::max(left, right));
}

bool Solution::hasPathSum(TreeNode* root, int sum) {
    if (root == nullptr)
        return false;
    if (root->val == sum && root->left == nullptr && root->right == nullptr)
        return true;
    return hasPathSum(root->left, sum - root->val) ||
        hasPathSum(root->right, sum - root->val);
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

bool Solution::isPalindrome(std::string s) {
    for (int i = 0, j = s.size() - 1; i < j;) {
        if (!std::isalnum(s[i]))
            i++;
        else if (!std::isalnum(s[j]))
            j--;
        else if (std::tolower(s[i++]) != std::tolower(s[j--]))
            return false;
    }
    return true;
}

int Solution::singleNumber(std::vector<int>& nums) {
    int res = 0;
    for (auto& i : nums)
        res ^= i;
    return res;
}

bool Solution::hasCycle(ListNode* head) {
    if (head == nullptr || head->next == nullptr)
        return false;
    ListNode* slow = head;
    ListNode* fast = head->next;
    while (slow != fast) {
        if (fast == nullptr || fast->next == nullptr)
            return false;
        slow = slow->next;
        fast = fast->next->next;
    }
    return true;
}

std::vector<int> Solution::preorderTraversal(TreeNode* root) {
    std::vector<int> res;
    std::stack<TreeNode*> stack;
    while (root != nullptr) {
        res.push_back(root->val);
        if (root->right != nullptr)
            stack.push(root->right);
        root = root->left;
        if (root == nullptr && !stack.empty()) {
            root = stack.top();
            stack.pop();
        }
    }
    return res;
}

std::vector<int> Solution::postorderTraversal(TreeNode* root) {
    std::vector<int> res;
    std::stack<TreeNode*> stack;
    TreeNode* last = nullptr;
    while (root || !stack.empty()) {
        if (root) {
            stack.push(root);
            root = root->left;
        }
        else {
            TreeNode* curr = stack.top();
            if (curr->right && last != curr->right) {
                root = curr->right;
            }
            else {
                res.push_back(curr->val);
                last = curr;
                stack.pop();
            }
        }
    }
    return res;
}

ListNode* Solution::sortList(ListNode* head) {
    if (!head || !(head->next))
        return head;
    // length of the list
    ListNode* current = head;
    int len = 0;
    while (current) {
        len++;
        current = current->next;
    }
    ListNode dummy(0);
    dummy.next = head;
    ListNode* left, * right, * last;
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

int Solution::majorityElement(std::vector<int>& nums) {
    int count = 0, candidate = 0;
    for (auto& num : nums) {
        if (count == 0)
            candidate = num;
        count += num == candidate ? 1 : -1;
    }
    return candidate;
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

int Solution::rob(std::vector<int>& nums) {
    auto notrob = 0;
    auto rob = 0;
    for (auto& item : nums) {
        auto current = notrob + item;
        notrob = std::max(notrob, rob);
        rob = current;
    }
    return std::max(rob, notrob);
}

bool Solution::isAnagram(std::string s, std::string t) {
    if (s.length() != t.length())
        return false;
    int tables[26] = { 0 };
    for (int i = 0; i < s.length(); i++) {
        tables[s[i] - 'a']++;
        tables[t[i] - 'a']--;
    }
    for (int i = 0; i < 26; i++)
        if (tables[i])
            return false;
    return true;
}

int Solution::missingNumber(std::vector<int>& nums) {
    int n = nums.size();
    int sum = n * (n + 1) / 2;
    int actual = 0;
    for (int& num : nums) {
        actual += num;
    }
    return sum - actual;
}

void Solution::moveZeroes(std::vector<int>& nums) {
    auto pos = 0;
    for (auto& num : nums)
        if (num)
            std::swap(nums[pos++], num);
}

int Solution::findDuplicate(std::vector<int>& nums) {
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

void Solution::reverseString(std::vector<char>& s) {
    // two pointers
    int l = 0, r = s.size() - 1;
    while (l < r) {
        std::swap(s[l++], s[r--]);
    }
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

std::string Solution::addStrings(std::string &num1, std::string &num2) {
  int i = num1.size() - 1, j = num2.size() - 1, carry = 0;
  std::string ans = "";
  while (i >= 0 || j >= 0 || carry != 0) {
    int x = i >= 0 ? num1[i] - '0' : 0;
    int y = j >= 0 ? num2[j] - '0' : 0;
    int result = x + y + carry;
    ans.push_back('0' + result % 10);
    carry = result / 10;
    i--;
    j--;
  }
  std::reverse(ans.begin(), ans.end());
  return ans;
}

std::vector<std::vector<int>> Solution::levelOrder(Node *root) {
    if (root == nullptr)
        return {};
    std::vector<std::vector<int>> res;
    std::queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        size_t size = q.size();
        std::vector<int> tmp;
        for (size_t i = 0; i < size; ++i) {
            Node* cur = q.front();
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

TreeNode* Solution::mergeTrees(TreeNode* t1, TreeNode* t2) {
    if (t1 == nullptr)
        return t2;
    if (t2 == nullptr)
        return t1;
    t1->val += t2->val;
    t1->left = mergeTrees(t1->left, t2->left);
    t1->right = mergeTrees(t1->right, t2->right);
    return t1;
}

TreeNode* Solution::trimBST(TreeNode* root, int L, int R) {
    // Recursively
    if (root == nullptr)
        return root;
    if (root->val > R)
        return trimBST(root->left, L, R);
    if (root->val < L)
        return trimBST(root->right, L, R);
    root->left = trimBST(root->left, L, R);
    root->right = trimBST(root->right, L, R);
    return root;
}

TreeNode* Solution::searchBST(TreeNode* root, int val) {
    while (root && root->val != val)
        root = val < root->val ? root->left : root->right;
    return root;
}

TreeNode* Solution::insertIntoBST(TreeNode* root, int val) {
    // recursive
    // if(root == nullptr
    //     return new TreeNode(val);
    // if(val > root->val)
    //     root->right = InsertIntoBST(root->right, val);
    // else
    //     root->left = InsertIntoBST(root->left, val);
    // return root;
    // iterative
    if (root == nullptr)
        return new TreeNode(val);
    TreeNode* currentNode = root;
    TreeNode* newNode = new TreeNode(val);
    while (currentNode) {
        if (currentNode->val > val) {
            if (currentNode->left)
                currentNode = currentNode->left;
            else {
                currentNode->left = newNode;
                break;
            }
        }
        else {
            if (currentNode->right)
                currentNode = currentNode->right;
            else {
                currentNode->right = newNode;
                break;
            }
        }
    }
    return root;
}

std::string Solution::toLowerCase(std::string str) {
    for (auto& c : str) {
        if ('A' <= c && c <= 'Z')
            c = c - 'A' + 'a';
    }
    return str;
}

std::vector<int> Solution::dailyTemperatures(std::vector<int>& T) {
    std::stack<int> s;
    int len = T.size();
    std::vector<int> ans(len, 0);
    for (int i = 0; i < len; i++) {
        while (!s.empty() != 0 && T[i] > T[s.top()]) {
            int t = s.top();
            s.pop();
            ans[t] = i - t;
        }
        s.push(i);
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

int Solution::peakIndexInMountainArray(std::vector<int>& A) {
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

ListNode* Solution::middleNode(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int Solution::projectionArea(std::vector<std::vector<int>>& grid) {
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

int Solution::surfaceArea(std::vector<std::vector<int>>& grid) {
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

std::vector<int> Solution::sortArrayByParity(std::vector<int>& A) {
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

int Solution::rangeSumBST(TreeNode* root, int L, int R) {
    int sum = 0;
    if (root == nullptr)
        return sum;
    if (root->val > L)
        sum += rangeSumBST(root->left, L, R);
    if (root->val < R)
        sum += rangeSumBST(root->right, L, R);
    if (root->val >= L && root->val <= R)
        sum += root->val;
    return sum;
}

std::vector<int> Solution::sortedSquares(std::vector<int> &nums) {
  int n = nums.size();
  std::vector<int> ans(n);
  for (int i = 0, j = n - 1, pos = n - 1; i <= j;) {
    if (nums[i] * nums[i] > nums[j] * nums[j]) {
      ans[pos] = nums[i] * nums[i];
      ++i;
    } else {
      ans[pos] = nums[j] * nums[j];
      --j;
    }
    --pos;
  }
  return ans;
}

std::vector<std::vector<int>>
Solution::shiftGrid(std::vector<std::vector<int>>& grid, int k) {
    int n = grid.size(), m = grid[0].size();
    std::vector<std::vector<int>> res = grid;
    k %= m * n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int index = (i * m + j + k) % (m * n);
            int x = index / m, y = index % m;
            res[x][y] = grid[i][j];
        }
    }
    return res;
}

int Solution::minPushBox(std::vector<std::vector<char>>& grid) {
    // TODO
    return -1;
}

int Solution::xorOperation(int n, int start) { 
  int s = start >> 1;
  int e = n & start & 1;
  int res = sumXor(s - 1) ^ sumXor(s + n - 1);
  return res << 1 | e;
}


/*Private methods*/

bool Solution::isMirror(TreeNode *l1, TreeNode *l2) {
    if (l1 == nullptr && l2 == nullptr)
        return true;
    if (l1 == nullptr || l2 == nullptr)
        return false;
    return (l1->val == l2->val) && isMirror(l1->left, l2->right) &&
        isMirror(l1->right, l2->left);
}

bool Solution::doSolve(std::vector<std::vector<char>>& board, int row,
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

bool Solution::isValid(std::vector<std::vector<char>>& board, int row, int col,
    char num) {
    int blkrow = (row / 3) * 3, blkcol = (col / 3) * 3;
    for (int i = 0; i < 9; i++)
        if (board[i][col] == num || board[row][i] == num ||
            board[blkrow + i / 3][blkcol + i % 3] == num)
            return false;
    return true;
}

ListNode* Solution::split(ListNode* head, int n) {
    for (int i = 1; head && i < n; i++)
        head = head->next;
    if (!head)
        return nullptr;
    ListNode* second = head->next;
    head->next = nullptr;
    return second;
}

ListNode* Solution::merge(ListNode* l1, ListNode* l2, ListNode* head) {
    ListNode* current = head;
    while (l1 && l2) {
        if (l1->val > l2->val) {
            current->next = l2;
            current = l2;
            l2 = l2->next;
        }
        else {
            current->next = l1;
            current = l1;
            l1 = l1->next;
        }
    }
    current->next = l1 ? l1 : l2;
    while (current->next)
        current = current->next;
    return current;
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

bool Solution::isValid(std::vector<std::string>& nQueens, int row, int col,
    int& n) {
    for (int i = 0; i != row; ++i)
        if (nQueens[i][col] == 'Q')
            return false;
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j)
        if (nQueens[i][j] == 'Q')
            return false;
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j)
        if (nQueens[i][j] == 'Q')
            return false;
    return true;
}

void Solution::solveNQueens(std::vector<std::vector<std::string>>& res,
    std::vector<std::string> nQueens,
    std::vector<int>& flag, int row, int& n) {
    if (row == n) {
        res.push_back(nQueens);
        return;
    }
    for (int col = 0; col != n; ++col) {
        if (flag[col] && flag[n + row + col] && flag[4 * n - 2 + col - row]) {
            flag[col] = flag[n + row + col] = flag[4 * n - 2 + col - row] = 0;
            nQueens[row][col] = 'Q';
            solveNQueens(res, nQueens, flag, row + 1, n);
            nQueens[row][col] = '.';
            flag[col] = flag[n + row + col] = flag[4 * n - 2 + col - row] = 1;
        }
    }
}

std::vector<int> Solution::kmpProcess(std::string& needle) {
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

int Solution::sumXor(int x) {
  if (x % 4 == 0) {
    return x;
  }
  if (x % 4 == 1) {
    return 1;
  }
  if (x % 4 == 2) {
    return x + 1;
  }
  return 0;
}
