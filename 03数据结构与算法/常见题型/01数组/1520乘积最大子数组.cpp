class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size(), res = INT_MIN;
        vector<vector<int>> f(n + 1, vector<int>(2, 1));
        // f[i][0]表示以第i个数字结尾的最小子数组乘积
        // f[i][1]表示以第i个数字结尾的最大子数组乘积
        for(int i = 1; i <= n; ++i)
        {
            if(nums[i - 1] > 0)
            {
                f[i][0] = min(nums[i - 1], nums[i - 1] * f[i - 1][0]);
                f[i][1] = max(nums[i - 1], nums[i - 1] * f[i - 1][1]);
            }
            else if(nums[i - 1] < 0)
            {
                f[i][0] = min(nums[i - 1], nums[i - 1] * f[i - 1][1]);
                f[i][1] = max(nums[i - 1], nums[i - 1] * f[i - 1][0]);
            }
            else 
                f[i][0] = f[i][1] = 0;
            
            res = max(res, f[i][1]);
        }

        return res;
    }
};