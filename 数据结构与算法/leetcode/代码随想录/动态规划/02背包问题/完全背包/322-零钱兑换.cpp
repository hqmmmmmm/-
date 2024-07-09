class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n =  coins.size(), m = amount;
        vector<vector<int>> f(n + 1, vector<int>(m + 1, INT_MAX / 2));
        f[0][0] = 0;
        for(int i = 1; i <= n; ++i) {
            for(int j = 0; j <= m; ++j) {
                f[i][j] = f[i - 1][j];
                if(j >= coins[i - 1])
                    f[i][j] = min(f[i][j], f[i][j - coins[i - 1]] + 1);
            }
        }

        if(f[n][m] == INT_MAX / 2) return -1;
        return f[n][m];
    }
};


/*
    f[i][j]表示从前i个数选，总和等于j的最少硬币数
    状态划分：当前硬币取还是不取
        取    f[i][j - coins[i - 1]] + 1;
        不取  f[i - 1][j]
    因为这里是取min，注意不合法的状态要设置为INT_MAX
*/