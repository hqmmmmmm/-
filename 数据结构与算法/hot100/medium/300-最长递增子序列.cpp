class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int res = 0, n = nums.size();
        vector<int> f(n + 1, 1);
        
        for(int i = 1; i <= n; ++i)
        {
            for(int j = 1; j < i; ++j)
                if(nums[j - 1] < nums[i - 1])
                    f[i] = max(f[i], f[j] + 1);
            res = max(res, f[i]);
        }

        return res;
    }
};