class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> h;
        vector<vector<string>> res;

        for(string str : strs) {
            string tmp =  str;
            sort(str.begin(), str.end());
            h[str].push_back(tmp);
        }

        for(auto &[k, v] : h) {
            res.push_back(v);
        }
        return res;
    }
};