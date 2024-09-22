class Solution {
public:
    // 可以采用滚动数组的思维简化空间复杂度到O(1)
    int climbStairs(int n) {
        vector<int> f(n + 1, 1);
        for(int i = 2; i <= n; ++i)
            f[i] = f[i - 1] + f[i - 2];
        return f[n];
    }
};