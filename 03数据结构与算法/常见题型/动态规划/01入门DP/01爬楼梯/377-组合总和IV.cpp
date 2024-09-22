class Solution {
public: // 等价于爬楼梯
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned long long> dp(target + 1, 0);
        dp[0] = 1;

        for(int i = 1; i <= target; ++i)
        {
            for(int num : nums)
            {
                if(i >= num)
                    dp[i] += dp[i - num];
            }
        }
                
        return dp[target];
    }
};