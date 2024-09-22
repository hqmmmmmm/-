class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        // 法一：排序取前缀+后缀 O(nlogn)
        // bool flag = true;
        // for(int i = 0; i < nums.size() - 1; ++i)
        // {
        //     if(nums[i] > nums[i + 1])
        //     {
        //         flag = false;
        //         break;
        //     }
        // }
        // if(flag == true) return 0;

        // vector<int> sorted_nums(nums);
        // sort(sorted_nums.begin(), sorted_nums.end());
        // int l = 0, r = nums.size() - 1;
        // while(nums[l] == sorted_nums[l]) ++l;
        // while(nums[r] == sorted_nums[r]) --r;
        // return r - l + 1;

        // 法二：无序子数组中最小元素的正确位置可以决定左边界，最大元素的正确位置可以决定右边界。
        /*
            从左到右看，数应该越来越大，如果某个数，比前面最大值大，那他没问题，如果小于前面的最大值，那么这个数就有问题
            从左到右不断更新最大值，遇到有问题的数，就记录下来作为right，并且right可以更新
            right更新到最后面不动了，说明right右边的数都比，right左边的max的数大，但是right自己比max小，right右边是排好序的，right左边需要重新排序，right是需要重新排序的区间的右边届。
            left同理，left就是从右往左看，数要越来越小才行，如果某个数，比右边最小值还要小，那他没问题，如果它比右边的最小值要大，说明他有问题。
        */
        int n = nums.size();
        int maxn = INT_MIN, right = -1;
        int minn = INT_MAX, left = -1;
        for(int i = 0; i < n; ++i)
        {
            if(nums[i] < maxn) left = i;
            else maxn = nums[i];

            if(nums[n - 1 - i] > minn) right = i;
            else minn = nums[n - 1 - i];
        }

        return left == -1 ? 0 : right - left + 1;


        // 自己的解法，跟法二思想一样。
        // int l = 0, r = nums.size() - 1;
        // // 找到nums不再递增的第一个位置
        // while(l + 1 < nums.size() && nums[l] <= nums[l + 1]) ++l;
        // // 反向找到nums不再递减的第一个位置
        // while(r - 1 >= 0 && nums[r] >= nums[r - 1]) --r;

        // // 如果数组是有序的，直接返回0
        // if(l == nums.size() - 1) return 0;

        // // 找到这段子数组的最大和最小值
        // int minval = nums[l], maxval = nums[l];
        // for(int i = l; i <= r; ++i)
        // {
        //     minval = min(minval, nums[i]);
        //     maxval = max(maxval, nums[i]);
        // }

        // // 找到这段子数组的最大和最小值分别应该放在nums中的哪个位置
        // while(l >= 0 && nums[l] > minval) --l;
        // while(r < nums.size() && nums[r] < maxval) ++r;
        // return r - l - 1;
    }
};