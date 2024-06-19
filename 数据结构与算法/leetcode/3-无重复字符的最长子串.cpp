class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<int> st;
        int l = 0, r = 0, res = 0;

        while(r < s.size()) {
            if(st.count(s[r])) {
                st.erase(s[l++]);
            } else {
                st.insert(s[r++]);
                res = max(res, r - l);
            }
        }

        return res;
    }
};