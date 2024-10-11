class Solution {
public:
    int integerBreak(int n) {
        vector<int> f(n + 1);
        // f[i]表示将i拆分为k个正整数的最大乘积
        for(int i = 1; i <= n; ++i) {
            int cur_max = 0;
            for(int j = 1; j < i; ++j) { // 继续拆分j，不拆分j
                cur_max = max(cur_max, max(f[j] * (i - j), j * (i - j)));
            }
            f[i] = cur_max;
        }

        return f[n];
    }
};