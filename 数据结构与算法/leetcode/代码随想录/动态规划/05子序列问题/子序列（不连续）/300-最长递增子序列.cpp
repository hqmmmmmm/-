class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(), res = 1;
        vector<int> f(n + 1, 1);
        // f[i]表示以nums中第i个数结尾的最长LIS

        for(int i = 1; i <= n; ++i) { // 枚举结尾数字
            for(int j = 1; j < i; j++) { // 枚举结尾的前一个数字
                if(nums[j - 1] < nums[i - 1]) 
                    f[i] = max(f[i], f[j] + 1);
            }
            res = max(res, f[i]);
        }

        return res;
    }
};