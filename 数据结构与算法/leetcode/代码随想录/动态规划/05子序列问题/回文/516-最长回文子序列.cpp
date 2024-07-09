class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> f(n + 1, vector<int>(n + 1));
        for(int j = 1; j <= n; ++j) {
            for(int i = j; i >= 1; --i) {
                if(s[i - 1] == s[j - 1]) {
                    if(j - i < 2) f[i][j] = j - i + 1;
                    else {
                        f[i][j] = max(f[i + 1][j], f[i][j - 1]);
                        f[i][j] = max(f[i][j], f[i + 1][j - 1] + 2);
                    }
                } else {
                    f[i][j] = max(f[i + 1][j], f[i][j - 1]);
                }
            }
        }

        return f[1][n];
    }
};
/*
    f[i][j]表示s的第i个字符到第j个字符中最长的回文子序列
        s[i - 1] == s[j - 1]  max(f[i+1][j], f[i][j-1], f[i+1][j-1]+2)
        s[i - 1] != s[j - 1]  max(f[i+1][j], f[i][j-1])

*/