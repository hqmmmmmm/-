class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> suf(nums);  // suf记录后缀和 + 答案
        for(int i = n - 2; i >= 0; --i)
            suf[i] *= suf[i + 1];

        suf[0] = suf[1]; // nums记录前缀和 
        for(int i = 1; i < nums.size() - 1; ++i)
        {
            suf[i] = (nums[i - 1] * suf[i + 1]);
            nums[i] *= nums[i - 1];
        }
        suf[n - 1] = nums[n - 2];

        return suf;
    }
};