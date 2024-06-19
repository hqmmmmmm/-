class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;

        // 参考153题，因为我们是根据是否大于nums.back()进行二分，
        // 所以我们只要去除nums.back的重复元素，就可以将这题转换为153题
        while(r && nums[r - 1] == nums[r]) --r;
        while(l < r && nums[l] == nums[r]) ++l; 

        while(l < r) {
            int mid = l + r >> 1;
            if(nums[mid] > nums.back()) 
                l = mid + 1;
            else 
                r = mid;
        }

        return nums[l];
    }
};