class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(s.size() < p.size()) return {};
        vector<int> res;
        vector<int> vp(26, 0), vs(26, 0);
        
        for(char c : p) vp[c - 'a']++;
        for(int i = 0; i < p.size(); ++i) vs[s[i] - 'a']++;

        if(vp == vs) res.push_back(0);

        int l = 0, r = p.size();
        while(r < s.size()) {
            vs[s[r++] - 'a']++;
            vs[s[l++] - 'a']--;
            if(vp == vs) res.push_back(l);
        }

        return res;
    }
};