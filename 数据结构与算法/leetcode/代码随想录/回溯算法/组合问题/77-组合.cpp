class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;

    void dfs(int u, int n, int k) {
        if(path.size() == k) {
            res.push_back(path);
            return;
        }
        if(n - u + 1 + path.size() < k) return;

        path.push_back(u);
        dfs(u + 1, n, k);
        path.pop_back();;

        dfs(u + 1, n, k);
    }

    vector<vector<int>> combine(int n, int k) {
        dfs(1, n, k);
        return res;
    }
};