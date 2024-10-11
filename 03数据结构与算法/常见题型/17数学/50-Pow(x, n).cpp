class Solution {
public: // 快速幂
    double fast_power(double x, long long y) // 注意int最小值转成abs绝对值会超出int范围，可以使用longlong
    {
        double res = 1;
        while(y)
        {
            if(y & 1)
                res *= x;
            x *= x;
            y >>= 1; 
        }
        return res;
    }

    double myPow(double x, int n) {
        if(n < 0) return 1 / fast_power(x, abs(n));
        return fast_power(x, abs(n));
    }
};