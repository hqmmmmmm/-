class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>> f(strs.size() + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));
        // f[i][j][k]表示从前i个数字选，最多j个0，k个1的最大子集的长度
        for(int i = 1; i <= strs.size(); ++i) {
            int cnt_0 = 0, cnt_1 = 0;
            for(char c : strs[i - 1]) {
                if(c == '0') cnt_0++;
                else cnt_1++;
            }
            for(int j = 0; j <= m; ++j) {
                for(int k = 0; k <= n; ++k) {
                    f[i][j][k] = f[i - 1][j][k];
                    if(j >= cnt_0 && k >= cnt_1) f[i][j][k] = max(f[i][j][k], f[i - 1][j - cnt_0][k - cnt_1] + 1);
                }
            }
        }

        return f[strs.size()][m][n];
    }
};