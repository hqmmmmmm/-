class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        target += sum;
        if(target % 2 || target < 0) return 0; // 这题输入target有点恶心人。

        target /= 2;

        vector<vector<int>> f(nums.size() + 1, vector<int>(target + 1, 0));
        f[0][0] = 1;
        // f[i][j]表示从前i个数选，总和等于target的选法种类
        for(int i = 1; i <= nums.size(); ++i) {
            for(int j = 0; j <= target; ++j) {
                f[i][j] = f[i - 1][j];
                if(j >= nums[i - 1]) 
                    f[i][j] += f[i - 1][j - nums[i - 1]];
            }
        }

        return f[nums.size()][target];
    }
};  

/*
    设总正数为x，总负数为y（绝对值），所以  x - y = target   x + y = sum
    => x = (target + sum) / 2;
    01背包模型：前n个选，空间为x
*/