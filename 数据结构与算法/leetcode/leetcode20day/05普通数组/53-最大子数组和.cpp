class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size(), res = INT_MIN;
        // f[i]表示以nums中第i个数结尾的连续子数组的最大和
        vector<int> f(n + 1, 0);
        for(int i = 0; i < n + 1; ++i) {
            f[i] = max(f[i - 1], 0) + nums[i - 1];
            res = max(res, f[i]);
        }

        return res;
    }
};