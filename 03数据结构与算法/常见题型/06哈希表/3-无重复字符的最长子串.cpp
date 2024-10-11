class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0, res = 0;
        unordered_set<char> st;
        
        while(r < s.size()) {
            while(st.count(s[r])) 
                st.erase(s[l++]);
            st.insert(s[r++]);

            res = max(res, r - l);
        }

        return res;
    }
};