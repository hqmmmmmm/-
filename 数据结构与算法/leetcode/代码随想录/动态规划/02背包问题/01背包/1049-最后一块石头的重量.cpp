class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = accumulate(stones.begin(), stones.end(), 0);
        int n = stones.size();
        vector<vector<int>> f(n + 1, vector<int>(sum / 2 + 1, 0));
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= sum / 2; ++j) {
                f[i][j] = f[i - 1][j];
                if(j >= stones[i - 1])
                    f[i][j] = max(f[i][j], f[i - 1][j - stones[i - 1]] + stones[i - 1]);
            }
        }

        return sum - f[n][sum / 2] * 2;
    }
};