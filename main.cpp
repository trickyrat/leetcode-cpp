#include <iostream>
#include <memory>

#include "solution.h"

using namespace std;

template <typename T> class MyQueue {
private:
  int start, end, capcity;
  vector<T> data;

public:
  MyQueue(int k) {
    start = -1;
    end = -1;
    capcity = k;
    data.resize(k);
  }

  bool enqueue(T value) {
    if (isFull())
      return false;
    if (isEmpty())
      start = 0;
    end = (end + 1) % capcity;
    data[end] = value;
    return true;
  }
  bool dequeue() {
    if (isEmpty())
      return false;
    if (start == end) {
      start = -1;
      end = -1;
      return true;
    }
    start = (start + 1) % capcity;
    return true;
  }
  T Front() { return isEmpty() ? -1 : data[start]; }
  T Rear() { return isEmpty() ? -1 : data[end]; }
  bool isEmpty() { return start == -1; }
  bool isFull() { return ((end + 1) % capcity) == start; }
};

void twoSumTest() {
  vector<int> nums{2, 7, 11, 15};
  vector<int> res = Solution::twoSum(nums, 9);
  for (const auto &i : res)
    cout << i << " ";
  cout << endl;
}

int BFS(TreeNode *root, TreeNode *target) {
  std::queue<TreeNode *> q;
  int step = 0;
  q.push(root);
  while (!q.empty()) {
    step++;
    int size = q.size();
    for (int i = 0; i < size; ++i) {
      TreeNode *current = q.front();
      if (current->val == target->val)
        return step - 1;
      // TODO: add the neighbors of current node to the queue.
      if (current->left != nullptr)
        q.push(current->left);
      if (current->right != nullptr) {
        q.push(current->right);
      }
      // TODO: remove the first node from queue.
      q.pop();
    }
  }
  return -1;
}

int main() {
  MyQueue<int> queue = MyQueue<int>(10);
  bool p0 = queue.enqueue(10);
  bool p1 = queue.enqueue(12);
  bool p2 = queue.dequeue();
  int p3 = queue.Front();
  int p4 = queue.Rear();
  bool p5 = queue.isEmpty();
  bool p6 = queue.isFull();

  cout << p0 << " " << p1 << " " << p2 << " " << p3 << " " << p4 << " " << p5
       << " " << p6 << endl;

  std::queue<int> q;
  q.push(5);
  q.push(4);
  q.push(3);
  q.push(2);
  q.push(1);
  cout << q.size() << endl;
  q.pop();
  cout << q.size() << endl;
  cout << "front=" << q.front() << ", and back=" << q.back() << endl;

  int num = 5;
  int *p = &num;
  int **pp = &p;
  cout << num << "\n" << p << "\n" << pp << endl;

  TreeNode *t = new TreeNode(10);
  t->left = new TreeNode(5);
  t->right = new TreeNode(3);
  t->right->left = new TreeNode(4);
  t->right->left->left = new TreeNode(2);
  TreeNode *target = new TreeNode(2);
  cout << BFS(t, target) << endl;

  auto sol = make_shared<Solution>();
	Solution solution;
	cout << solution.myPower(2.002, 2) << endl;                    // called by instance
  cout << sol->myPower(2.002, 2) << endl;        // called by shared_ptr
  cout << Solution::myPower(2.20001, 2) << endl; // called by static method
  twoSumTest();
  vector<char> ch{'H', 'e', 'l', 'l', 'o'};
  sol->reverseString(ch);
  for (const auto &c : ch)
    cout << c;

  for (vector<char>::iterator itor = ch.begin(); itor != ch.end(); itor++) {
    char &c = *itor; // 对指针的引用
    cout << c;
  }

  return 0;
}



