class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int num : nums)
            sum += num;
        if(sum % 2) return false;
        
        int n = nums.size();
        vector<vector<int>> f(n + 1, vector<int>(sum / 2 + 1));
        // f[i][j]表示从前i个数取，容量为j，能取到的最大值
        // 状态划分：根据第i个数字取还是不取
        // 状态转移：f[i][j] = max(f[i - 1][j - nums[i - 1]] + nums[i - 1], f[i - 1][j])
        for(int i = 1; i <= n; ++i)
        {
            for(int j = 1; j <= sum / 2; ++j)
            {
                f[i][j] = f[i - 1][j];
                if(j >= nums[i - 1])
                    f[i][j] = max(f[i][j], f[i - 1][j - nums[i - 1]] + nums[i - 1]);
            }
        }

        return f[n][sum / 2] == sum / 2;
    }
};