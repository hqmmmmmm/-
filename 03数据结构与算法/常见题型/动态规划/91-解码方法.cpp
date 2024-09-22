class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> f(n + 1, 0);
        f[0] = 1;
        // f[i]表示以s中第i个字符结尾的子串的解码方式
        for(int i = 1; i <= n; ++i)
        {
            // 不需要额外判断无法解析的字符，因为会记录在f数组中
            // if(s[i - 1] == '0' && (i == 1 || s[i - 2] != '1' && s[i - 2] != '2'))
            //     return 0; // 无法解析的字符
            
            if(s[i - 1] != '0')
                f[i] += f[i - 1];
            if(i >= 2 && (s[i - 2] == '1' || s[i - 2] == '2' && s[i - 1] <= '6'))
                f[i] += f[i - 2];
        }

        return f[n];
    }
};