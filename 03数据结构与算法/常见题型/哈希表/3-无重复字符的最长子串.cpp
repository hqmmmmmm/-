class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int l = 0, r = 0, res = 0;

        while(r < s.size()) {
            while(l < r && st.count(s[r])) st.erase(s[l++]);
            st.insert(s[r++]);
            res = max(res, r - l);
        }

        return res;
    }
};