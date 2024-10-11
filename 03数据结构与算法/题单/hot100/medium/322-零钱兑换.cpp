class Solution {
public:
  int coinChange(vector<int> &coins, int amount) {
    int n = coins.size(), m = amount;
    vector<vector<int>> f(n + 1, vector<int>(m + 1, INT_MAX / 2));
    for(int i = 0; i < n + 1; ++i) f[i][0] = 0; // 也可以只初始化f[0][0]，不过j要从0开始遍历

    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= m; ++j)
        {
            f[i][j] = min(f[i][j], f[i - 1][j]); // 第i个硬币不选
            if(j >= coins[i - 1]) // 选第i个硬币
                f[i][j] = min(f[i][j], f[i][j - coins[i - 1]] + 1);
        }
    }

    return f[n][m] == INT_MAX / 2 ? -1 : f[n][m];
  }
};
/*
    f[i][j]表示从前i个数选，总和等于j的最少硬币数
    状态划分：当前硬币取还是不取
        取    f[i][j - coins[i - 1]] + 1;
        不取  f[i - 1][j]

*/