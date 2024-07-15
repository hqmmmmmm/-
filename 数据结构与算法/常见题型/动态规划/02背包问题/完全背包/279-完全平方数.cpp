class Solution {
public:
    int numSquares(int n) {
        int m = n;
        n = sqrt(n);
        vector<vector<int>> f(n + 1, vector<int>(m + 1, INT_MAX / 2));
        f[0][0] = 0;

        for(int i = 1; i <= n; ++i) {
            for(int j = 0; j <= m; ++j) {
                f[i][j] = f[i - 1][j];
                if(j >= i * i)
                    f[i][j] = min(f[i][j], f[i][j - i * i] + 1);
            }
        }

        return f[n][m];
    }
};

/*
    f[i][j]表示从1-i取，和为n的完全平方数的最少数量
        i取     f[i][j - i * i]
        i不取    f[i - 1][j]
*/