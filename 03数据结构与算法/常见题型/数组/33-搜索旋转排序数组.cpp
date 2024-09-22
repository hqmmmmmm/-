class Solution {
public:
    int search(vector<int>& nums, int target) {
        // 先找到分界点（153-寻找旋转排序数组中的最小值）
        int l = 0, r = nums.size() - 1;
        while(l < r)
        {
            int mid = l + r >> 1;
            if(nums[mid] <= nums[r])
                r = mid;
            else 
                l = mid + 1;
        }

        // 在两个有序的部分分别进行二分查找
        int res = binary_search(nums, l, nums.size() - 1, target);
        if(res != -1) return res;
        return binary_search(nums, 0, l - 1, target);
    }

    // 二分模板一
    int binary_search(vector<int> &nums, int l, int r, int target)
    {
        while(l < r)
        {
            int mid = l + r >> 1;
            if(nums[mid] >= target)
                r = mid;
            else 
                l = mid + 1;
        }

        if(nums[l] == target) return l;
        return -1;
    }
};