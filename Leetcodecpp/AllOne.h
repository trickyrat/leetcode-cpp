#pragma once

#include <list>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <string>

class AllOne {
  std::list<std::pair<std::unordered_set<std::string>, int>> lst;
  std::unordered_map<
      std::string,
      std::list<std::pair<std::unordered_set<std::string>, int>>::iterator>
      nodes;

public:
  AllOne() {}
  
  void inc(std::string key);
  void dec(std::string key);

  std::string getMaxKey();

  std::string getMinKey();
};
