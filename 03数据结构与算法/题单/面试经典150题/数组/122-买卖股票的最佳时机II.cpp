#include <stdexcept>
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // 动态规划
        // 状态定义：f[i][0]表示第i天不持有股票的最大利润，f[i][1]表示第i天持有股票的最大利润
        // 状态划分：根据第i天是否购买/出售来划分
        // 状态转移：f[i][0] = max(f[i - 1][1] + prices[i - 1], f[i - 1][0]);
        //         f[i][1] = max(f[i - 1][0] - prices[i - 1], f[i - 1][1]);

        int n = prices.size();
        vector<vector<int>> f(n + 1, vector<int>(2));
        f[0][1] = INT_MIN;  // 第0天肯定不能持有股票，初始化一下非法状态。
        for(int i = 1; i <= n; ++i)
        {
            f[i][0] = max(f[i - 1][1] + prices[i - 1], f[i - 1][0]);
            f[i][1] = max(f[i - 1][0] - prices[i - 1], f[i - 1][1]);
        }

        return f[n][0];


        // 贪心，将每天的价格视作一个折线图，只取折线图上升的部分
        // int res = 0;
        // for(int i = 1; i < prices.size(); ++i)
        //     res += max(0, prices[i] - prices[i - 1]);
        
        // return res;
    }
};