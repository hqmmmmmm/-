class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size(), res = 0;
        vector<int> f(n + 1);
        // 状态表示：f[i]表示以s的第i个字符结尾的最长有效括号子串
        // 状态划分：根据第i个字符是左括号还是右括号
        // 状态转移：直接写

        for(int i = 1; i <= n; ++i)
        {
            if(s[i - 1] == ')')
            {
                // 这个j表示第以i - 1个字符结尾的最长有效括号子串的前一个字符，一定要注意下标
                int j = i - 1 - f[i - 1]; 
                if(j - 1 >= 0 && s[j - 1] == '(')
                    f[i] = f[j - 1] + f[i - 1] + 2; 
            }

            res = max(res, f[i]);
        }

        return res;
    }
};