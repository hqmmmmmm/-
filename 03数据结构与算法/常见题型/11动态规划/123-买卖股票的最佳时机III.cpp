class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> f(n + 1, vector<vector<int>>(3, vector<int>(2, INT_MIN / 2)));
        for(int i = 0; i <= n; ++i) f[i][0][0] = 0;
        for(int j = 0; j <= 2; ++j) f[0][j][0] = 0;

        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= 2; ++j) {
                f[i][j][0] = max(f[i - 1][j][0], f[i - 1][j][1] + prices[i - 1]);
                f[i][j][1] = max(f[i - 1][j][1], f[i - 1][j - 1][0] - prices[i - 1]);
            }
        }

        return f[n][2][0];
    }
};

/*
    f[i][j][0]表示第i天不持有股票最多完成j笔交易的最大利润
    f[i][j][1]表示第i天持有股票最多完成j笔交易的最大利润


    注意：这题必须要在卖出的时候变换状态，买入的时候变换状态就错了（暂时还不知道为什么）
    注意初始化数组f
*/