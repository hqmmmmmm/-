class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;
    vector<int> candidates;

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        this->candidates = candidates;
        dfs(0, target);
        return res;
    }

    void dfs(int u, int target)
    {
        if(target == 0) // 因为全是正数，target=0之后不会再有等于0的情况，push完就return就行了。
        {
            res.push_back(path);
            return;
        }
        if(u == candidates.size() || target < 0) return; // 剪枝

        path.push_back(candidates[u]);
        dfs(u, target - candidates[u]);
        path.pop_back();

        // 根据当前元素取1,2,3,4...进行dfs
        dfs(u + 1, target);
    }
};