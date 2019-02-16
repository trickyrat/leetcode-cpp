#include <iostream>
#include <vector>

using namespace std;

template <typename T>
int partition(std::vector<T> &vec, int li, int hi)
{
  T pivot = vec[hi];
  int i = li - 1;

  for (int j = li; j < hi; j++)
  {
    if (vec[j] < pivot)
    {
      i++;
      std::swap(vec[i], vec[j]);
    }
  }
  std::swap(vec[i + 1], vec[hi]);
  return i + 1;
}

template <typename T>
void quick_sort(vector<T> &vec, int li, int hi)
{
  if (li <= hi)
  {
    int index = partition(vec, li, hi);
    quick_sort(vec, li, index - 1);
    quick_sort(vec, index + 1, hi);
  }
}

int main()
{
  // vector<int> vec = {3, 4, 2, 5, 6};
  // vector<double> vec = {3.2, 4.8, 2.1, 5.7, 6.8,6.88};
  vector<float> vec = {1.1f, 2.3f, 1.004f, 0.005f, -0.22f};
  cout << "Unorderd List: ";

  for (auto &i : vec)
  {
    cout << i << " ";
  }
  cout << endl;
  quick_sort(vec, 0, vec.size() - 1);
  cout << "Ordered  List: ";
  for (auto &i : vec)
  {
    cout << i << " ";
  }
  cout << endl;
  return 0;
}
