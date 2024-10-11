class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // 滑动窗口+哈希集合
        int res = 0, l = 0, r = 0;
        unordered_set<char> st;
        while(r < s.size())
        {
            while(l < r && st.count(s[r])) st.erase(s[l++]);
            st.insert(s[r++]);
            res = max(res, r - l);
        }

        return res;
    }
};