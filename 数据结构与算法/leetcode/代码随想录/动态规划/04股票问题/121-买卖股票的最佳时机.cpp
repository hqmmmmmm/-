class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minprice = INT_MAX, res = 0;
        for(int price : prices) {
            res = max(res, price - minprice);
            minprice = min(minprice, price);
        }
        
        return res;
    }
};
