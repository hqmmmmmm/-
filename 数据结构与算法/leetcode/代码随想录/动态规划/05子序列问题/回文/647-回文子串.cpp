class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size(), res = 0;
        vector<vector<int>> f(n + 1, vector<int>(n + 1));
        
        for(int j = 1; j <= n; ++j) {
            for(int i = 1; i <= j; ++i) {
                if(s[i - 1] == s[j - 1] && (j - i < 2 || f[i + 1][j - 1]))
                    f[i][j] = 1;
                else
                    f[i][j] = 0;
                res += f[i][j];
            }
        }

        return res;
    }
};

/*
    f[i][j]表示s的第i个字符到第j个字符是否为回文子串
        if s[i - 1] == s[j - 1] && (j - i < 2 || f[i + 1][j - 1] == 1) 是
        else 不是
*/