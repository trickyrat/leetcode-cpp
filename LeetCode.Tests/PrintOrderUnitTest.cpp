#include "pch.h"

#include "../LeetCode/Foo.h"

using namespace std;

class PrintOrderFixture {
public:
  Foo foo;
  vector<int> task_sequences;
  string expected;

  PrintOrderFixture(Foo _foo, vector<int> _task_sequences, string _expected)
      : foo(_foo), task_sequences(_task_sequences), expected(_expected){};
};

class OrderPrintTest : public testing::TestWithParam<PrintOrderFixture> {};

INSTANTIATE_TEST_CASE_P(
    PrintOrderTestCases, OrderPrintTest,
    testing::Values(PrintOrderFixture(Foo(), {1, 2, 3}, "firstsecondthird"),
                    PrintOrderFixture(Foo(), {1, 3, 2}, "firstsecondthird"),
                    PrintOrderFixture(Foo(), {2, 1, 3}, "firstsecondthird"),
                    PrintOrderFixture(Foo(), {2, 3, 1}, "firstsecondthird"),
                    PrintOrderFixture(Foo(), {3, 2, 1}, "firstsecondthird"),
                    PrintOrderFixture(Foo(), {3, 1, 2}, "firstsecondthird")));

TEST_P(OrderPrintTest, Test) {
  string actual = "";
  PrintOrderFixture fixture = GetParam();
  for (auto task : fixture.task_sequences) {
    if (task == 1) {
      auto printFirstFuture =
          std::async(std::launch::async, [&fixture, &actual]() {
            fixture.foo.first([&actual]() { actual.append("first"); });
          });
    } else if (task == 2) {
      auto printSecondFuture =
          std::async(std::launch::async, [&fixture, &actual]() {
            fixture.foo.second([&actual]() { actual.append("second"); });
          });
    } else {
      auto printThirdFuture =
          std::async(std::launch::async, [&fixture, &actual]() {
            fixture.foo.third([&actual]() { actual.append("third"); });
          });
    }
  }

  EXPECT_EQ(actual, fixture.expected);
}