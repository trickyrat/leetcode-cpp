#include "medianfinder.hpp"


MedianFinder::MedianFinder()
    : lo_median(data.end()), hi_median(data.end()) {}

MedianFinder::~MedianFinder() {}

void MedianFinder::add_num_by_heap(int num) {
  lo.push(num);
  hi.push(lo.top());
  lo.pop();
  if (lo.size() < hi.size()) {
    lo.push(hi.top());
    hi.pop();
  }
}
double MedianFinder::find_median_by_heap() {
  return lo.size() > hi.size() ? static_cast<double>(lo.top())
                                 : (lo.top() + hi.top()) * 0.5;
}

// using Multiset and Two Pointers

void MedianFinder::add_num_by_pointers(int num) {
  auto n = data.size();
  data.insert(num);
  if (!n)
    // no elements before, one element now
    lo_median = hi_median = data.begin();
  else if (n & 1) {
    // odd size before, even size now
    if (num < *lo_median)
      --lo_median;
    else
      ++hi_median; // insertion at end of equal range
  } else {
    // even size before, odd size now
    if (num > *lo_median && num < *hi_median) {
      ++lo_median;
      --hi_median;
    } else if (num >= *hi_median)
      ++lo_median;
    else
      lo_median = --hi_median;
  }
}
double MedianFinder::find_median_by_pointers() {
  return (*lo_median + *hi_median) * 0.5;
}
