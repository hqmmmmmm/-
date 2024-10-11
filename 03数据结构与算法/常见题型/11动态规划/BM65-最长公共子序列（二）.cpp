class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * longest common subsequence
     * @param s1 string字符串 the string
     * @param s2 string字符串 the string
     * @return string字符串
     */
    string LCS(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        vector<vector<int>> f(n + 1, vector<int>(m + 1));
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j) {
                f[i][j] = max(f[i - 1][j], f[i][j - 1]);
                if(s1[i - 1] == s2[j - 1]) 
                    f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);
            }
        }

        string res;  // 根据前面的状态，反推当前的操作
        for(int i = n, j = m; f[i][j] >= 1; ) {
            if(s1[i - 1] == s2[j - 1]) {
                res += s1[i - 1];
                --i, --j;
            }
            else if(f[i - 1][j] > f[i][j - 1])
                --i;
            else   
                --j;
        }
        reverse(res.begin(), res.end());
        return res.empty() ? "-1" : res;
    }
};