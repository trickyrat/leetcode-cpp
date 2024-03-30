#include "pch.h"

#include <future>
#include <string>

#include "../LeetCode/Foo.h"

using namespace std;
TEST(FooUnitTest, Test) {
  string actual = "";
  vector<int> task_sequences{1, 2, 3};
  Foo foo;

  for (auto task : task_sequences) {
    if (task == 1) {
      auto printFirstFuture = std::async(std::launch::async, [&foo, &actual]() {
        foo.first([&actual]() { actual.append("first"); });
      });
    } else if (task == 2) {
      auto printSecondFuture =
          std::async(std::launch::async, [&foo, &actual]() {
            foo.second([&actual]() { actual.append("second"); });
          });
    } else {
      auto printThirdFuture = std::async(std::launch::async, [&foo, &actual]() {
        foo.third([&actual]() { actual.append("third"); });
      });
    }
  }

  EXPECT_EQ(actual, "firstsecondthird");
}