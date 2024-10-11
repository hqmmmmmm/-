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

        // 选第u个元素（这种情况dfs的参数u不需要+1，因为是无限制次数取，+1的话就只能取一次）
        path.push_back(candidates[u]);
        dfs(u, candidates, target - candidates[u]);;
        path.pop_back();

        // 不选第u个元素
        dfs(u + 1, candidates, target);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(0, candidates, target);
        return res;
    }
};