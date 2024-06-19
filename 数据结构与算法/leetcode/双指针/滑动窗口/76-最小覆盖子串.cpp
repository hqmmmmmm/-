class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> ht;
        for(auto c : t) ht[c]++;
        int cnt = ht.size(); // 先记录t中一共多少个字符

        string ans = s + t;
        unordered_map<char, int> hs;
        int l = 0, r = 0, vaild = 0;

        while(r < s.size()) {
            hs[s[r++]]++;
            if(hs[s[r - 1]] == ht[s[r - 1]]) vaild++;

            while(hs[s[l]] > ht[s[l]]) hs[s[l++]]--;  // 左边的指针向右移动，注意更改哈希表中的内容。

            if(vaild == cnt && r - l < ans.size()) {
                ans = s.substr(l, r - l);
            }   
        }

        return ans == s + t ? "" : ans;
    }
};