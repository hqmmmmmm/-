class Solution {
public:  // 先搜索到旋转处，再分左右两边进行二分查找
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while(l < r) {
            int mid = l + r >> 1;
            if(nums[mid] > nums.back()) 
                l = mid + 1;
            else 
                r = mid;
        }

        if(nums.back() >= target) // 稍微优化一下
            return binary_search(nums, l, nums.size() - 1, target);
        else  
            return binary_search(nums, 0, l - 1, target);
    }


    int binary_search(vector<int> &nums, int l, int r, int target) {
        while(l < r) {
            int mid = l + r >> 1;
            if(nums[mid] >= target) 
                r = mid;
            else
                l = mid + 1;
        }

        return nums[l] == target ? l : -1;
    }
};