class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = INT_MAX, res = 0;
        for(auto price : prices)
        {
            res = max(res, price - min_price);
            min_price = min(min_price, price);
        }
        return res;
    }
};