#include <algorithm>
#include <array>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <sstream>
#include <string>
#include <type_traits>
#include <utility>
#include <vector>
using namespace std;
const int INF = 0x3f3f3f3f;

void quick_sort(vector<int> &nums, int l, int r) {
  if (l >= r)
    return;
  int i = l - 1, j = r + 1, x = nums[l + r >> 1];
  while (i < j) {
    do
      ++i;
    while (nums[i] < x);
    do
      --j;
    while (nums[j] > x);
    if (i < j)
      swap(nums[i], nums[j]);
  }

  quick_sort(nums, l, j);
  quick_sort(nums, j + 1, r);
}

vector<string> split(string &s, char delimiter) {
  int l = 0;
  vector<string> res;
  for (int r = 0; r < s.size(); ++r) {
    if (s[r] == delimiter) {
      res.push_back(s.substr(l, r - l));
      l = r + 1;
    }
  }

  res.push_back(s.substr(l, s.size() - l));
  return res;
}

void insert_sort(vector<int> &nums) {
    int n = nums.size();
    for(int i = 1; i < n; ++i) {
        int x = nums[i], j = i - 1;
        // 将大于x的元素向后移动
        while(j >= 0 && nums[j] > x) {
            nums[j + 1] = nums[j];
            --j;
        }
        nums[j + 1] = x;
    }

}

int main() {
  vector<int> nums = {3, 2, 1, 0, 5, 4};
  insert_sort(nums);
  for (int x : nums)
    cout << x << " ";
  cout << endl;

  return 0;
}