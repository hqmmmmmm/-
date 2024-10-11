class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * longest common substring
     * @param str1 string字符串 the string
     * @param str2 string字符串 the string
     * @return string字符串
     */
    string LCS(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        // 非法状态需要取INT_MIN，这一题不需要。
        // 因为也可以不由这个非法状态转移而来（也就是直接以当前字母开头，舍弃前面的字母）
        vector<vector<int>> f(n + 1, vector<int>(m + 1));
        int max_index = 0, max_length = 0;
        // f[i][j]表示以str1的第n个字母结尾，str2的第m个字母结尾的最长公共子串
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j) {
                if(str1[i - 1] == str2[j - 1])
                    f[i][j] = f[i - 1][j - 1] + 1;
                
                if(f[i][j] > max_length) {
                    max_length = f[i][j];
                    max_index = i;
                }
            }
        }

        // 注意转换下标
        return str1.substr(max_index - 1 - max_length + 1, max_length);
    }
};