class Solution {
public:
    vector<string> res;
    string path;

    vector<string> generateParenthesis(int n) {
        dfs(n, n);
        return res;
    }

    void dfs(int l, int r)
    {
        if(l == 0 && r == 0) 
        {
            res.push_back(path);
            return ;
        }
        if(l > r) return;
            

        // 放左括号
        if(l > 0)
        {
            path.push_back('(');
            dfs(l - 1, r);
            path.pop_back();
        }

        // 放右括号(一定有右括号)
        path.push_back(')');
        dfs(l, r - 1);
        path.pop_back();
    }
};