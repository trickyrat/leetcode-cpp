#pragma once

#include <mutex>
#include <functional>

class Foo {
private:
  std::mutex m1, m2;

public:
  Foo() { m1.lock(), m2.lock(); }

  void first(std::function<void()> printFirst) {
    printFirst();
    m1.unlock();
  }
  void second(std::function<void()> printSecond) {
    m1.lock();
    printSecond();
    m1.unlock();
    m2.unlock();
  }
  void third(std::function<void()> printThird) {
    m2.lock();
    printThird();
    m2.unlock();
  }
};
