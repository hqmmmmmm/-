class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n + 1, 1);
        f[0] = 0;
        // f[i]表示以第i个数字结尾的最长严格递增子序列的长度
        // f[i] = f[j] + 1

        int res = 0;
        for(int i = 1; i <= n; ++i)
        {
            // 要想清楚这个j代表什么意思？  这里表示前一个数字是第几个
            for(int j = 1; j < i; ++j) 
            {
                if(nums[j - 1] < nums[i - 1])
                    f[i] = max(f[i], f[j] + 1);
            }
            res = max(res, f[i]);
        }

        return res;
    }
};