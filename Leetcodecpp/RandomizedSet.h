#pragma once

#include <vector>
#include <unordered_map>
#include <random>

class RandomizedSet {
public:
  RandomizedSet() { 
   
  }

  bool insert(int val);
  bool remove(int val);
  int getRandom();

private:
  std::vector<int> nums;
  std::unordered_map<int, int> indices;
};
