#pragma once

#include <vector>

class ATM {
private:
  std::vector<long long> count;
  std::vector<long long> value;

public:
  ATM() {
    count = {0, 0, 0, 0, 0};
    value = {20, 50, 100, 200, 500};
  }

  void deposit(std::vector<int> banknotesCount);
  std::vector<int> withdraw(int amount);
};
