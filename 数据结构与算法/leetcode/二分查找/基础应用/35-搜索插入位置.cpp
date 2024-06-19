class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        if(nums[r] < target) return r + 1;

        // 等价于寻找第一个大于等于target的位置？
        while(l < r) {
            int mid = l + r >> 1;
            if(nums[mid] >= target) 
                r = mid;
            else 
                l = mid + 1;
        }

        return l;
    }
};