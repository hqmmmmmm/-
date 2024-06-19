class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans, vs(26, 0), vp(26, 0);
        if(s.size() < p.size()) return ans;

        // 统计字符串p
        for(auto c : p) vp[c - 'a']++;

        // 维护一个滑动窗口，大小是字符串p的长度
        int l = 0, r = 0;
        while(r - l < p.size()) {
            vs[s[r++] - 'a']++;
        }

        if(vs == vp) {  // vector已经实现了operator==
            ans.push_back(l);
        } 

        // 移动滑动窗口
        while(r < s.size()) {
            vs[s[r++] - 'a']++;
            vs[s[l++] - 'a']--;
            if(vs == vp) {
                ans.push_back(l);
            } 
        }

        return ans;
    }

    
};