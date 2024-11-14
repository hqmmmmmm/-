#include <iostream>
#include <vector>
using namespace std;

// 这里其实不需要up，只有在插入元素才需要up
void up(int u, vector<int> &nums) {
  while ((u - 1) / 2 >= 0 && nums[(u - 1) / 2] < nums[u]) {
    swap(nums[(u - 1) / 2], nums[u]);
    u = (u - 1) / 2;
  }
}

void down(int u, vector<int> &nums, int len) {
  int j = u;
  if (2 * u + 1 < len && nums[2 * u + 1] > nums[j])
    j = 2 * u + 1;
  if (2 * u + 2 < len && nums[2 * u + 2] > nums[j])
    j = 2 * u + 2;
  if (j != u) {
    swap(nums[u], nums[j]);
    down(j, nums, len);
  }
}

void heap_sort(vector<int> &nums) {
  int n = nums.size();
  // 将无序的n个数转为堆，从第一个非叶子节点开始down，这样可以保证每个节点down之后它的下面没有比他的元素，模拟想一下就可以了。
  for (int i = n / 2 - 1; i >= 0; --i) {
    down(i, nums, n);
  }

  for (int i = n - 1; i >= 0; --i) {
    swap(nums[0], nums[i]);
    down(0, nums, i);
  }
}

int main() {
  vector<int> nums = {3, 2, 1, 0, 5, 4};
  heap_sort(nums);
  for (int x : nums)
    cout << x << " ";
  cout << endl;

  return 0;
}