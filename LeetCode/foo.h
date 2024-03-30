#pragma once

#include <functional>
#include <future>

class Foo {
private:
  std::function<void()> task = []() {};
  std::packaged_task<void()> pt1{task}, pt2{task};

public:
  Foo(const Foo& other){};
  Foo(){};

  void first(std::function<void()> printFirst) {
    printFirst();
    pt1();
  }
  void second(std::function<void()> printSecond) {
    pt1.get_future().wait();
    printSecond();
    pt2();
  }
  void third(std::function<void()> printThird) {
    pt2.get_future().wait();
    printThird();
  }
};
