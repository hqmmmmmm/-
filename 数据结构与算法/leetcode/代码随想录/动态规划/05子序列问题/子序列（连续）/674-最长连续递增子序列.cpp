class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int res = 1, start = 0;
        for(int i = 1; i < nums.size(); ++i) {
            if(nums[i] <= nums[i - 1]) start = i;
            res = max(res, i - start + 1);
        }

        return res;

        // 动态规划
        // int n = nums.size(), res = 1;
        // vector<int> f(n + 1, 0);
        // // f[i]表示以第i个元素结尾的最长连续递增子序列
        // for(int i = 1; i <= n; ++i) {
        //     f[i] = 1;
        //     if(i >= 2 && nums[i - 1] > nums[i - 2]) 
        //         f[i] = max(f[i], f[i - 1] + 1);
        //     res = max(res, f[i]);
        // }

        // return res;
    }
};