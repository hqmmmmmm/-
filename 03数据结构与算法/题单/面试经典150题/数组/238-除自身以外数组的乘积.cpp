class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        // suf记录后缀, nums存放结果, 动态构建前缀pre
        vector<int> suf(nums.begin(), nums.end());
        for(int i = n - 2; i >= 0; --i)
            suf[i] *= suf[i + 1];

        int pre = 1;
        for(int i = 0; i < n - 1; ++i)
        {
            int x = nums[i];
            nums[i] = (pre * suf[i + 1]);
            pre *= x;
        }
        nums[n - 1] = pre;

        return nums;
    }
};