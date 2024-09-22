class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> f(n + 1, vector<int>(m + 1, 0));
        for(int i = 1; i <= n; ++i) f[i][0] = i;
        for(int j = 1; j <= m; ++j) f[0][j] = j;
        // f[i][j]表示将word1的前i个字符转换成word2的前j个字符所用的最少操作数
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j) {
                f[i][j] = min(f[i][j - 1], f[i - 1][j]) + 1;  //  插入 or 删除
                f[i][j] = min(f[i][j], f[i - 1][j - 1] + 1);  // 替换
                if(word1[i - 1] == word2[j - 1])
                    f[i][j] = min(f[i][j], f[i - 1][j - 1]);
            }
        }

        return f[n][m];
    }
};