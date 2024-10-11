class Solution {
public:
    bool isMatch(string s, string p) {
        auto match = [&](int i, int j){ // s的第i个字符和p的第j个字符能否匹配
            if(p[j - 1] == '.')
                return true;
            return s[i - 1] == p[j - 1];
        };

        // f[i][j]表示s的前i个字符和p的前j个字符能否匹配
        int n = s.size(), m = p.size();
        vector<vector<bool>> f(n + 1, vector<bool>(m + 1, false));
        // 初始化
        f[0][0] = true;
        for(int j = 2; j <= m; j+=2)
            f[0][j] = f[0][j - 2] && p[j - 1] == '*';

        for(int i = 1; i <= n; ++i)
        {
            for(int j = 1; j <= m; ++j)
            {
                // 首先根据是否有*来进行状态划分
                if(p[j - 1] == '*') // 根据使不使用这个*来进行状态划分
                    f[i][j] = f[i][j - 2] || f[i - 1][j] && match(i, j - 1);
                else 
                    f[i][j] = f[i - 1][j - 1] && match(i, j);
            }
        }

        return f[n][m];
    }
};