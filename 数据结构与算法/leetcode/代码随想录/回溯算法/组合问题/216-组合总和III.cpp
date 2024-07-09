class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;

    void dfs(int u, int k, int target) {
        if(path.size() == k) {
            if(target == 0) {
                res.push_back(path);
            }
            return;
        }
        if(u == 10 || target < 0) return;

        path.push_back(u);
        dfs(u + 1, k, target - u);
        path.pop_back();

        dfs(u + 1, k, target);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        dfs(1, k, n);
        return res;
    }
};