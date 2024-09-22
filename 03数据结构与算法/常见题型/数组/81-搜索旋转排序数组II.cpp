class Solution {
public: // 33-搜索旋转排序数组的有重复数字版本
    bool search(vector<int>& nums, int target) {
        int n = nums.size(), l = 0, r = n - 1;
        // 去除边界上的重复数字，去除左边的好一点，防止去除右边的之后nums变成一个有序数组导致后面的操作不好弄
        while(l < r && nums[r] == nums[l]) ++l;  
        // 找到分界点
        while(l < r)
        {
            int mid = (l + r) >> 1;
            if(nums[mid] > nums.back())
                l = mid + 1;
            else  
                r = mid;
        }

        // 确定查找区间
        int edge = l;
        if(target <= nums.back()) l = edge, r = n - 1;
        else l = 0, r = edge - 1;
        
        // 二分查找
        while(l < r)
        {
            int mid = l + r >> 1;
            if(nums[mid] < target)
                l = mid + 1;
            else 
                r = mid;
        }

        return nums[l] == target;
    }
};