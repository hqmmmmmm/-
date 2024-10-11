class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(), wordDict.end());

        int n = s.size();
        vector<bool> f(n + 1, false);
        f[0] = true;
        // f[i]表示s的前i个字符是否能由wordDict中的单词拼接出
        // f[i] = f[j] && s(j, i) in wordDict
        for(int i = 1; i <= n; ++i)
        {
            for(int j = 0; j < i; ++j)
            {
                auto tmp = s.substr(j, i - j);
                f[i] = f[j] && st.count(tmp);
                if(f[i])
                    break;
            }
        }

        return f[n];
    }

};