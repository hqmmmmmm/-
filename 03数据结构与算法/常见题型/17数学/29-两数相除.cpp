class Solution {
public:
    int divide(int dividend, int divisor) {
        int x = dividend, y = divisor;
        bool sign = (x > 0 && y < 0) || (x < 0 && y > 0);

        if(x > 0) x = -x;
        if(y > 0) y = -y;
        
        // x = 2^0 * y + 2^1 * y + 2^2 * y + ...
        // i存放数2^i * y，j存放幂2^i   
        // 使用负数存放幂，因为答案可能溢出
        vector<pair<int, int>> exp;
        for(int i = y, j = -1; i >= x; i += i, j += j) {
            exp.push_back({i, j});
            if(i < INT_MIN / 2) break;
        }

        int res = 0;
        for(int i = exp.size() - 1; i >= 0; --i) {
            if(exp[i].first >= x) {
                x -= exp[i].first;
                res += exp[i].second;
            }
        }

        if(sign) return res;
        if(res ==  INT_MIN) return INT_MAX;
        return -res;
    }
};