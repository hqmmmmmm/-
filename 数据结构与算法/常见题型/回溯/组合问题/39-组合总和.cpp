class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;

    void dfs(int u, vector<int> &candidates, int target) {
        if(target == 0) {
            res.push_back(path);
            return;
        }
        if(u == candidates.size() || target < 0) return;

        path.push_back(candidates[u]);
        dfs(u, candidates, target - candidates[u]);;
        path.pop_back();

        dfs(u + 1, candidates, target);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(0, candidates, target);
        return res;
    }
};