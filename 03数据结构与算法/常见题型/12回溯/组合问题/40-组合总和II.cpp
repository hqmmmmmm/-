class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;
    vector<int> candidates;
    unordered_map<int, int> h; // 哈希表记录相同的元素有多少个

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        this->candidates = candidates;
        for(int x : candidates) h[x]++;
        dfs(0, target);
        return res;
    }

    // dfs(u)表示从nums[u]及之后的元素中选择
    void dfs(int u, int target)
    {
        if(target == 0)
        {
            res.push_back(path);
            return ;
        }

        if(u == candidates.size() || target < 0) return;


        // 之前统计了相同元素的个数，根据当前元素选多少个来进行dfs
        for(int i = 0; i <= h[candidates[u]]; ++i)
        {
            for(int j = 0; j < i; ++j) path.push_back(candidates[u]);
            dfs(u + h[candidates[u]], target - candidates[u] * i);
            for(int j = 0; j < i; ++j) path.pop_back();
        }
    }

};