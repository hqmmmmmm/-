class Solution {
public:
    vector<string> path;
    vector<string> res;

    void dfs(int u, string s) {
        if(path.size() == 4) {
            if(u == s.size()) {
                res.push_back(path[0] + "." + path[1] + "." + path[2] + "." + path[3]);
                return ;
            }
        }
        if(u == s.size()) return ;

        for(int i = u; i < s.size() && i - u <= 2; ++i) {
            string tmp = s.substr(u, i - u + 1);
            if(stoi(tmp) > 255 || tmp.size() >= 2 && tmp[0] == '0') continue;

            path.push_back(tmp);
            dfs(i + 1, s);
            path.pop_back();
        }
    }

    vector<string> restoreIpAddresses(string s) {
        dfs(0, s);
        return res;
    }
};