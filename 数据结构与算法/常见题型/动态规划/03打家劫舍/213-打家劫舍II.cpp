class Solution {
public:
    int myrob(vector<int> &nums) {
        int n = nums.size(); 
        vector<vector<int>> f(n + 1, vector<int>(2, 0));
        for(int i = 1; i <= n; ++i) {
            f[i][0] = max(f[i - 1][0], f[i - 1][1]);
            f[i][1] = f[i - 1][0] + nums[i - 1];
        }

        return max(f[n][0], f[n][1]);
    }

    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];

        vector<int> v1(nums.begin() + 1, nums.end());
        vector<int> v2(nums.begin(), nums.end() - 1);

        return max(myrob(v1), myrob(v2));
    }
};

/*
    第一个不偷，最后一个不偷
    分两种情况讨论
*/