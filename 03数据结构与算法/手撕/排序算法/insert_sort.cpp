#include <iostream>
#include <vector>
using namespace std;

// 将数组划分为有序和无序的部分，找出无序的第一个数应该放在有序哪个位置

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