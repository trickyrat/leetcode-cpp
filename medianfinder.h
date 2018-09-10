#ifndef LEETCODE_MEDIAN_FINDER_H_
#define LEETCODE_MEDIAN_FINDER_H_

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
  std::priority_queue<int> lo_;                                   // max heap
  std::priority_queue<int, std::vector<int>, std::greater<>> hi_; // min heap

  std::multiset<int> data_;
  std::multiset<int>::iterator lo_median_, hi_median_;
};
#endif /* LEETCODE_MEDIAN_FINDER_H_ */