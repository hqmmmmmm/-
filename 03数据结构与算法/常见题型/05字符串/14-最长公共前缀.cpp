class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // 横向扫描，不断跟下一个字符串比较；纵向扫描也可以。
        string res = strs[0];
        for(int i = 1; i < strs.size(); ++i)
        {
            res = helper(res, strs[i]);
            if(res == "")
                return res;
        }

        return res;
    }

    string helper(string &a, string &b)
    {
        int i = 0, l = min(a.size(), b.size());
        while(i < l && a[i] == b[i])
        {
            ++i;
        }

        return a.substr(0, i);
    }
};