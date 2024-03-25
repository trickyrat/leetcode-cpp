#include "pch.h"

#include <future>
#include <string>

#include "../LeetCode/Foo.h"


TEST(FooUnitTest, Test) {
  std::string actual = "";
  auto printFirstFuture =
      std::async(std::launch::async, [&actual]() { actual.append("first"); });
  auto printSecondFuture =
      std::async(std::launch::async, [&actual]() { actual.append("second"); });
  auto printThirdFuture =
      std::async(std::launch::async, [&actual]() { actual.append("third"); });

  EXPECT_EQ(actual, "firstsecondthird");
}