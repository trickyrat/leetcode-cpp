#include "pch.h"

#include "../Leetcodecpp//Solution.h"

#include <string>
#include <vector>

using namespace std;

TEST(PlatesBetweenCandles, Test1) {
  vector<vector<int>> queries1 = {{2, 5}, {5, 9}};
  vector<int> expected = {2, 3};
  auto actual = Solution::platesBetweenCandles("**|**|***|", queries1);

  EXPECT_EQ(expected, actual);
}

TEST(PlatesBetweenCandles, Test2) {
  vector<vector<int>> queries1 = {{1, 17}, {4, 5}, {14, 17}, {5, 11}, {15, 16}};
  vector<int> expected = {9, 0, 0, 0, 0};
  auto actual =
      Solution::platesBetweenCandles("***|**|*****|**||**|*", queries1);

  EXPECT_EQ(expected, actual);
}