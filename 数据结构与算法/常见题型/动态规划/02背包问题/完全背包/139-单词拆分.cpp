class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = wordDict.size(), m = s.size();
        vector<vector<bool>> f(n + 1, vector<bool>(m + 1, false));
        f[0][0] = true;
        for(int j = 0; j <= m; ++j) {
            for(int i = 1; i <= n; ++i) {
                int len = wordDict[i - 1].size();
                f[i][j] = f[i - 1][j];
                if(j >= len && s.substr(j - len, len) == wordDict[i - 1]) 
                    f[i][j] = f[i][j] || f[n][j - len];
            }
        }

        return f[n][m];
    }
};

/*
    f[i][j]表示用wordDict中的前i个单词能否拼出s(0, j)
        第i个单词结尾    f[n][j - wordDict[i - 1]]
        第1-i个单词结尾     f[i - 1][j]


    这题跟377组合总和IV很像
*/