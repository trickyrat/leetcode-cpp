#ifndef LEETCODE_MEDIAN_FINDER_HPP_
#define LEETCODE_MEDIAN_FINDER_HPP_

#include <functional>
#include <queue>
#include <set>

class MedianFinder {
public:
  MedianFinder();
  ~MedianFinder();

  void add_num_by_heap(int num);
  double find_median_by_heap();

  void add_num_by_pointers(int num);
  double find_median_by_pointers();

private:
  std::priority_queue<int> lo;                                   // max heap
  std::priority_queue<int, std::vector<int>, std::greater<>> hi; // min heap

  std::multiset<int> data;
  std::multiset<int>::iterator lo_median, hi_median;
};
#endif /* LEETCODE_MEDIAN_FINDER_HPP_ */
