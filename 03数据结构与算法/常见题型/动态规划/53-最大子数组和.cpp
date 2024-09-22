class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size(), res = INT_MIN;
        vector<int> f(n + 1, 0);
        // f[i]表示以nums中第i个数结尾的连续子数组的最大和
        for(int i = 1; i <= n; ++i) {
            f[i] = nums[i - 1] + max(f[i - 1], 0);
            res = max(res, f[i]);
        }

        return res;
    }
};