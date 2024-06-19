class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size() < t.size()) return "";

        unordered_map<char, int> hs, ht;
        for(char c : t) ht[c]++;
        int cnt = 0, tol = ht.size(), l = 0, r = 0;
        string ans = s + t;

        while(r < s.size()) {
            hs[s[r]]++;
            if(hs[s[r]] == ht[s[r++]]) cnt++;

            while(hs[s[l]] > ht[s[l]]) hs[s[l++]]--;

            if(cnt == tol && r - l < ans.size()) {
                ans = s.substr(l, r - l);
            }
        }

        return ans == s + t ? "" : ans;
    }
};