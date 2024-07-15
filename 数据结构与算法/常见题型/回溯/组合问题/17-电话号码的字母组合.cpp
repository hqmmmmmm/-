class Solution {
public:
    unordered_map<char, string> h = {
        {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, 
        {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, 
        {'8', "tuv"}, {'9', "wxyz"}
    };

    string path;
    vector<string> res;

    void dfs(int u, string digits) {
        if(u == digits.size()) {
            res.push_back(path);
            return ;
        }

        string tmp = h[digits[u]];
        for(int i = 0; i < tmp.size(); ++i) {
            path += tmp[i];
            dfs(u + 1, digits);
            path.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return {};
        dfs(0, digits);
        return res;
    }
};