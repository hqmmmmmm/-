#include <iostream>
#include <vector>
using namespace std;
// 快排中基准pivot的选择
/*
    1、固定位置选取：第一个、中间的、最后一个。
        最差情况：每次都是选择最大或最小的元素，那每次子数组的规模只会-1，要进行n次递归，时间复杂度为O(n2)
        最好情况：O(nlogn)
    2、三数取中：选取第一个、中间和最后一个数的中位数作为pivot，能避免最坏情况的发生，尽量减小时间复杂度。
    3、随机选取。
*/

void quick_sort(vector<int> &nums, int l, int r)
{
    if(l >= r) return;
    int i = l - 1, j = r + 1, x = nums[l + r >> 1];
    while(i < j)
    {
        do ++i; while(nums[i] < x);
        do --j; while(nums[j] > x);
        if(i < j)
            swap(nums[i], nums[j]);
    }
    
    quick_sort(nums, l, j);
    quick_sort(nums, j + 1, r);
}
