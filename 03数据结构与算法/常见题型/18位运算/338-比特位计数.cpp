class Solution {
public: // 动态规划的思想，将规模不断缩小。
    vector<int> countBits(int n) {
        // 方法一：根据奇偶或者说最后一位是否为1.
        // vector<int> f(n + 1, 0);
        // for(int i = 1; i <= n; ++i)
        //     f[i] = f[i >> 1] + (i & 1);

        // return f;
        
        // 方法二：根据n & (n - 1)
        vector<int> f(n + 1, 0);
        for(int i = 1; i <= n; ++i)
            f[i] = f[i & (i - 1)] + 1;
        return f;
    }

};