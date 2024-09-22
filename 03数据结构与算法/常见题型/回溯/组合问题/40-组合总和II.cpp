class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;
    unordered_map<int, int> h;

    void dfs(int u, vector<int> &candidates, int target) {
        while(u + 1 < candidates.size() && candidates[u + 1] == candidates[u]) ++u;
        if(target == 0) {
            res.push_back(path);
            return;
        }
        if(u == candidates.size() || target < 0) return;

        int cnt = h[candidates[u]];
        for(int i = 0; i <= cnt; ++i) {
            for(int j = 0; j < i; ++j) path.push_back(candidates[u]);
            dfs(u + 1, candidates, target - candidates[u] * i);
            for(int j = 0; j < i; ++j) path.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        for(int num : candidates) h[num]++;

        dfs(0, candidates, target);
        return res;
    }
};