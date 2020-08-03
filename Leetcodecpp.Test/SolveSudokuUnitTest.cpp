#include "pch.h"
#include "CppUnitTest.h"

#include <vector>

#include "../Leetcodecpp/Solution.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LeetcodecppUnitTest
{

    BEGIN_TEST_MODULE_ATTRIBUTE()
TEST_MODULE_ATTRIBUTE(L"Date", L"2010/6/12")
END_TEST_MODULE_ATTRIBUTE()

TEST_MODULE_INITIALIZE(ModuleInitialize) {
  Logger::WriteMessage("In Module Initialize");
}

TEST_MODULE_CLEANUP(ModuleCleanup) {
  Logger::WriteMessage("In Module Cleanup");
}

	TEST_CLASS(SolveSudokuTest)
	{
	public:
		
        SolveSudokuTest() { Logger::WriteMessage("In SolveSudokuTest()"); } 
        ~SolveSudokuTest() { Logger::WriteMessage("In ~SolveSudokuTest"); }

        TEST_CLASS_INITIALIZE(ClassInitialize) {
          Logger::WriteMessage("In Class Initialize");
        }

        TEST_CLASS_CLEANUP(ClassCleanup) {
          Logger::WriteMessage("In Class Cleanup");
        }

		TEST_METHOD(Test9x9) {
		
			std::vector<std::vector<char>> actual = {
                {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
            };

            Solution::solveSudoku(actual);

            std::vector<std::vector<char>> expected = {
                {'5', '3', '4', '6', '7', '8', '9', '1', '2'},
                {'6', '7', '2', '1', '9', '5', '3', '4', '8'},
                {'1', '9', '8', '3', '.', '2', '5', '6', '7'},
                {'8', '5', '9', '7', '6', '1', '4', '2', '3'},
                {'4', '2', '6', '8', '5', '3', '7', '9', '1'},
                {'7', '1', '3', '9', '2', '4', '8', '5', '6'},
                {'9', '6', '1', '5', '3', '7', '2', '8', '4'},
                {'2', '8', '7', '4', '1', '9', '6', '3', '5'},
                {'3', '4', '5', '2', '8', '6', '1', '7', '9'}
            };

            Assert::AreEqual(expected, actual);
		} 
    TEST_METHOD(TestMethod2) { 
      std::string str = "SSSAAssAAsasA";
      std::string actual = Solution::toLowerCase(str);
      std::string expected = "sssaassaasasa";
      Assert::AreEqual(expected, actual);
    }
	};
}
