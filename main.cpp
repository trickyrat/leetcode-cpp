#include <iostream>

#include "solution.hpp"

using namespace std;

void twoSumTest()
{
    vector<int> nums{2, 7, 11, 15};
    vector<int> res = Solution::twoSum(nums, 9);
    for (auto &i : res)
        cout << i << " ";
    cout << endl;
}

int main()
{
    Solution s;
    cout << s.myPower(2.2, 2) << endl;
    twoSumTest();
    return 0;
}
