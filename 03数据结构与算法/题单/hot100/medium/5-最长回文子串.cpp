class Solution {
public:
    string longestPalindrome(string s) {
        // 1.中心扩散法
        int n = s.size();
        string res;
        for(int i = 0; i < n; ++i)
        {
            // 子串长度为奇数
            int l = i - 1, r = i + 1;
            while(l >= 0 && r < n && s[l] == s[r]) --l, ++r;
            if(res.size() < r - l - 1) res = s.substr(l + 1, r - l - 1); // 注意这里的l和r并不是指向回文子串，而是分别向左、右移动了一步

            // 子串长度为偶数
            l = i, r = i + 1;
            while(l >= 0 && r < n && s[l] == s[r]) --l, ++r;
            if(res.size() < r - l - 1) res = s.substr(l + 1, r - l - 1);
        }

        return res;

        // 2.动态规划 区间dp
        // int n = s.size();
        // string res;
        // vector<vector<int>> f(n + 1, vector<int>(n + 1, 0));
        // /*
        //     f[i][j]表示以s中第i个字符开始，第j个字符结束的子串是否为回文子串
        //         if s[i-1]==s[j-1] && f[i+1][j-1]     f[i][j] = 1;
        //         else                                 f[i][j] = 0;
        // */
        // for(int j = 1; j <= n; ++j)
        // {
        //     for(int i = 1; i <= j; ++i)
        //     {
        //         if(s[i - 1] == s[j - 1] && (j - i < 2 || f[i + 1][j - 1])) 
        //             f[i][j] = 1;
        //         else 
        //             f[i][j] = 0;
        //         if(f[i][j] && j - i + 1 > res.size())
        //             res = s.substr(i - 1, j - i + 1);
        //     }
        // }

        return res;
    }
};