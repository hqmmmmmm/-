class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;
    int n, k;

    vector<vector<int>> combine(int n, int k) {
        this->n = n, this->k = k;
        dfs(1);
        return res;
    }

    // dfs(u)表示从u以及之后的数中选
    void dfs(int u)
    {
        if(path.size() == k)
        {
            res.push_back(path);
            return;
        }

        if(u == n + 1) return;

        // 选第u个数
        path.push_back(u);
        dfs(u + 1);
        path.pop_back();

        // 不选
        dfs(u + 1);
    }
};