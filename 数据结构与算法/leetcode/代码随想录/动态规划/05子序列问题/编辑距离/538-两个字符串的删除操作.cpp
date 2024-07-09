class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> f(n + 1, vector<int>(m + 1, 0));
        // f[i][j]表示word1前i个字符与word2前j个字符相同所需的最小步数
        for(int i = 1; i <= n; ++i) f[i][0] = i;
        for(int j = 1; j <= m; ++j) f[0][j] = j;
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j) {
                f[i][j] = min(f[i - 1][j], f[i][j - 1]) + 1;
                if(word1[i - 1] == word2[j - 1]) // 当前字符相同
                    f[i][j] = min(f[i][j], f[i - 1][j - 1]);
            }
        }

        return f[n][m];
    }
};

// 这题也可以求出最长公共子序列的长度l，然后n+m-l就是需要删除字符的个数。