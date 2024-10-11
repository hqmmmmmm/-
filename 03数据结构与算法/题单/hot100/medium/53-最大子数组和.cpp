class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // 动态规划  可以使用滚动数组思想简化空间复杂度为O(1)
        int res = INT_MIN, n = nums.size();
        vector<int> f(n + 1, 0); // f[i]表示以nums中第i个数字结尾的最大子数组和
        for(int i = 1; i <= n; ++i)
        {
            f[i] = max(0, f[i - 1]) + nums[i - 1];
            res = max(res, f[i]);
        }

        return res;
    }
};