class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> f(n + 1, vector<int>(2, INT_MIN / 2));
        // f[i][0]第i天不持有股票的最大利润，f[i][1]第i天持有股票的最大利润
        // 注意第一天持有股票的情况f[1][1]需要自己初始化一下，因为i-2此时小于0嘛，循环里面无法赋值。
        f[0][0] = 0, f[1][1] = -prices[0];  

        for(int i = 1; i <= n; ++i) {
            f[i][0] = max(f[i - 1][0], f[i - 1][1] + prices[i - 1]);
            if(i >= 2)
                f[i][1] = max(f[i - 1][1], f[i - 2][0] - prices[i - 1]);
        }

        return f[n][0];
    }
};
