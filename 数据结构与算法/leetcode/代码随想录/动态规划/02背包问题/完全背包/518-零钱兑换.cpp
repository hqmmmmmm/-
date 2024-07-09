class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> f(n + 1, vector<int>(amount + 1, 0));
        // f[i][j]表示从前i个数选，总和=amount的组合数
        f[0][0] = 1;
        for(int i = 1; i <= n; ++i) {
            for(int j = 0; j <= amount; ++j) {
                f[i][j] = f[i - 1][j];
                if(j >= coins[i - 1]) 
                    f[i][j] += f[i][j - coins[i - 1]];
            }
        }

        return f[n][amount];
    }   
};

/*
    f[i][j]: 从前i个硬币中选，总金额等于j的组合数
        不选第i个硬币： f[i -1][j]
        选第i个硬币：   f[i][j - coins[i]]
*/