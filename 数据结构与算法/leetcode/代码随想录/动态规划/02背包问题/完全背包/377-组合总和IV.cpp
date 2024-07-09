class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        using ull = unsigned long long;
        int n = nums.size(), m = target;
        vector<vector<ull>> f(n + 1, vector<ull>(m + 1, 0));
        // f[i][j]表示从前i个数选，总和=j的元素组合的个数
        f[0][0] = 1;
        for(int j = 0; j <= m; ++j) {
            for(int i = 1; i <= n; ++i) {
                f[i][j] = f[i - 1][j];   
                if(j >= nums[i - 1]) {
                    f[i][j] += f[n][j - nums[i - 1]];
                }
            }
        }

        return f[n][m];
    }
};


/*
    f[i][j]  表示以第1~i个元素结尾的元素排列总和等于target的排列种数。
        状态划分：以第1~i-1个元素结尾    f[i - 1][j]
            以第i个元素结尾        f[n][j - nums[i - 1]]   
            确定了排列最后一个元素是第i个，前面的元素可以以任意元素结尾 
*/