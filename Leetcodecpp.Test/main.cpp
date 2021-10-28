#include "pch.h"
#include "../Leetcodecpp/Solution.h"
#include "../Leetcodecpp/Solution.cpp"


TEST(SolutionTest, LengthOfLongestSubstringTest) {
	EXPECT_EQ(3, Solution::lengthOfLongestSubstring("pwwkew"));
	EXPECT_EQ(1, Solution::lengthOfLongestSubstring("bbbbb"));
	EXPECT_EQ(3, Solution::lengthOfLongestSubstring("abcabcbb"));
}


TEST(SolutionTest, IntToRomanTest) {
	EXPECT_EQ(std::string("I"), Solution::intToRoman(1));
	EXPECT_EQ(std::string("X"), Solution::intToRoman(10));
	EXPECT_EQ(std::string("VI"), Solution::intToRoman(6));
}


int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();
}