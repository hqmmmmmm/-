class Solution {
public:
    string path;
    vector<string> res;

    vector<string> generateParenthesis(int n) {
        dfs(n, n);
        return res;
    }

    // dfs(l, r)表示l个左括号以及r个右括号能生成的有效的括号组合
    void dfs(int l, int r)
    {
        if(l > r) return;
        if(l == 0 && r == 0)
        {
            res.push_back(path);
            return;
        }
        
        // 当前选左括号
        if(l > 0)
        {
            path.push_back('(');
            dfs(l - 1, r);
            path.pop_back();
        }


        // 当前选右括号(右括号的数量不需要判断，一定会大于0的)
        path.push_back(')');
        dfs(l, r - 1);
        path.pop_back();
    }
};