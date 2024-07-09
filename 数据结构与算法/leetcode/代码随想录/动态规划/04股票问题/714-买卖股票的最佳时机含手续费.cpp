class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> f(n + 1, vector<int>(2));
        // f[i][0]表示第i天不持股的最大利润，f[i][1]表示第i天持股的最大利润
        f[0][0] = 0, f[0][1] = INT_MIN / 2;

        for(int i = 1; i <= n; ++i) {
            f[i][0] = max(f[i - 1][0], f[i - 1][1] + prices[i - 1]);
            f[i][1] = max(f[i - 1][1], f[i - 1][0] - prices[i - 1] - fee);
        }

        return f[n][0];
    }
};