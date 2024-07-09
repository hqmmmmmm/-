class Solution {
public:
    vector<string> path;
    vector<vector<string>> res;

    void dfs(int u, string s) {
        if(u == s.size()) {
            res.push_back(path);
            return ;
        }

        for(int i = u; i < s.size(); ++i) {
            string tmp = s.substr(u, i - u + 1);
            if(check(tmp)) {
                path.push_back(tmp);
                dfs(i + 1, s);
                path.pop_back();
            }
        }
    }

    bool check(string str) {
        for(int i = 0; i < str.size() - 1 - i; ++i) {
            if(str[i] != str[str.size() - 1 - i]) {
                return false;
            }
        }
        return true;
    }

    vector<vector<string>> partition(string s) {
        dfs(0, s);
        return res;
    }
};