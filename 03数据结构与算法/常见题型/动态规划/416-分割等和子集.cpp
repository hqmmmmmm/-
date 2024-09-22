class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2 == 1) return false;
        vector<vector<int>> f(nums.size() + 1, vector<int>(sum / 2 + 1, 0));
        // f[i]][j]表示从前i个数字选，总和不大于j的最大和
        for(int i = 1; i <= nums.size(); ++i) {
            for(int j = 0; j <= sum / 2; ++j) {
                f[i][j] = f[i - 1][j];
                if(j >= nums[i - 1])
                    f[i][j] = max(f[i][j], f[i - 1][j - nums[i - 1]] + nums[i - 1]);
            }
        }

        return f[nums.size()][sum / 2] == sum / 2;
    }
};