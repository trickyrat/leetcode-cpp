#include "medianfinder.h"


MedianFinder::MedianFinder()
    : lo_median_(data_.end()), hi_median_(data_.end()) {}

MedianFinder::~MedianFinder() {}

void MedianFinder::add_num_by_heap(int num) {
  lo_.push(num);
  hi_.push(lo_.top());
  lo_.pop();
  if (lo_.size() < hi_.size()) {
    lo_.push(hi_.top());
    hi_.pop();
  }
}
double MedianFinder::find_median_by_heap() {
  return lo_.size() > hi_.size() ? static_cast<double>(lo_.top())
                                 : (lo_.top() + hi_.top()) * 0.5;
}

// using Multiset and Two Pointers

void MedianFinder::add_num_by_pointers(int num) {
  auto n = data_.size();
  data_.insert(num);
  if (!n)
    // no elements before, one element now
    lo_median_ = hi_median_ = data_.begin();
  else if (n & 1) {
    // odd size before, even size now
    if (num < *lo_median_)
      --lo_median_;
    else
      ++hi_median_; // insertion at end of equal range
  } else {
    // even size before, odd size now
    if (num > *lo_median_ && num < *hi_median_) {
      ++lo_median_;
      --hi_median_;
    } else if (num >= *hi_median_)
      ++lo_median_;
    else
      lo_median_ = --hi_median_;
  }
}
double MedianFinder::find_median_by_pointers() {
  return (*lo_median_ + *hi_median_) * 0.5;
}
