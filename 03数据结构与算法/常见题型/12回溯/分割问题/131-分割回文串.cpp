class Solution {
public:
    vector<string> path;
    vector<string> res;

    vector<string> restoreIpAddresses(string s) {
        dfs(0, s);
        return res;
    }


    // dfs(u)表示从s[u]开始切割获得ip地址
    void dfs(int u, string &s)
    {
        if(u == s.size() && path.size() == 4)
        {
            string ip = path[0] + "." + path[1] + "." + path[2] + "." + path[3];
            res.push_back(ip);
            return;
        }

        if(u >= s.size() || path.size() >= 4) return;

        //根据当前的.放在哪来进行dfs
        for(int i = u; i <= u + 2 && i < s.size(); ++i)
        {
            string tmp = s.substr(u, i - u + 1);
            if(check(tmp)) 
            {
                path.push_back(tmp);
                dfs(i + 1, s);
                path.pop_back();
            }
        }
    }

    bool check(string str)
    {
        if(stoi(str) > 255 || str.size() >= 2 && str[0] == '0')
            return false;
        return true;
    }

};