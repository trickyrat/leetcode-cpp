#include <iostream>

#include "solution.h"

using namespace std;

int main(int argc, char const *argv[])
{
    Solution solution;
    cout << "hello, world" << endl;
    vector<int> nums{2, 7, 11, 15};
    vector<int> res = solution.twoSum(nums, 9);
    for (auto &i : res)
        cout << i << " ";
    cout << endl;
    return 0;
}
