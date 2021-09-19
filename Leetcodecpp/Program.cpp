#include <iostream>
#include <format>
#include <chrono>
#include "Solution.h"

using namespace std::chrono;

int main() {
  std::cout << "Hello, world\n";
  auto version = 20;
  std::cout << std::format("STL is now C++{} feature-complete!\n", version);

  std::chrono::year_month_day world_bee_day = May/20d/2021y;
  std::cout << std::format("Buzz buzz on {}!", world_bee_day);
  return 0;
}