class Solution {
public: // https://www.bilibili.com/video/BV1dT4y1y78u
    void nextPermutation(vector<int>& nums) {
        // 123->132
        int n = nums.size(), i = n - 1;
        while(i && nums[i - 1] >= nums[i]) --i;
        
        if(i == 0) 
        {
            reverse(nums.begin(), nums.end());
            return;
        }
        
        int j = n - 1;
        while(nums[j] <= nums[i - 1]) --j;
        swap(nums[j], nums[i - 1]);

        reverse(nums.begin() + i, nums.end());
    }
};