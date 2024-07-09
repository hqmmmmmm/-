class Solution {
public:
    int numDistinct(string s, string t) {
        int N = 1e9 + 7;
        int n = s.size(), m = t.size();
        vector<vector<int>> f(n + 1, vector<int>(m + 1, 0));
        for(int i = 0; i <= n; ++i) f[i][0] = 1;

        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j) {
                f[i][j] = f[i - 1][j];
                if(s[i - 1] == t[j - 1])
                    f[i][j] = (f[i][j] + f[i - 1][j - 1]) % N;
            }
        } 

        return f[n][m];
    }
};
/*
    f[i][j]表示s的前i个字符的子序列中t出现的个数
        s[i - 1] != t[j - 1]  第i个字符对构成t没有贡献，f[i][j] = f[i - 1][j];
        s[i - 1] == t[j - 1]  第i个字符可以选，也可以不选
            选    f[i - 1][j - 1]
            不选  f[i - 1][j]
*/
