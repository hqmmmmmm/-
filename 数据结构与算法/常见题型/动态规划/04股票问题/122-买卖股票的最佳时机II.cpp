class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> f(n + 1, vector<int>(2, INT_MIN / 2));
        f[0][0] = 0;
        for(int i = 1; i <= n; ++i) {
            f[i][0] = max(f[i - 1][0], f[i - 1][1] + prices[i - 1]);
            f[i][1] = max(f[i - 1][0] - prices[i - 1], f[i - 1][1]);
        }

        return f[n][0];
    }
};

/*
    动态规划：
        f[i][0]表示第i天不持有股票的最大利润，f[i][1]表示第i天持有股票的最大利润。
    贪心:
        画一个价格折线图，统计所有上升段长度即可。
*/