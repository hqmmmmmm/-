class Solution {
public:  // 先找到旋转点，再左右二分
    bool search(vector<int>& nums, int target) {
        // 先找到旋转点（有重复数字版）
        int l = 0, r = nums.size() - 1;
        while(l < r && nums[l] == nums[r]) ++l;

        while(l < r) {
            int mid = l + r >> 1;
            if(nums[mid] <= nums.back())
                r = mid;
            else 
                l = mid + 1;
        }

        // 对左或右半部分进行二分查找
        if(nums.back() >= target)
            r = nums.size() - 1;
        else 
            r = l - 1, l = 0;

        while(l < r) {
            int mid = l + r >> 1;
            if(nums[mid] >= target)
                r = mid;
            else 
                l = mid + 1;
        }

        return nums[l] == target;
    }
};