class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;

    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(0, nums);
        return res;
    }

    // dfs(u)代表从nums[u]以及之后的元素中选取，确定子问题(u + 1)
    void dfs(int u, vector<int> &nums)
    {
        if(u == nums.size())
        {
            res.push_back(path);
            return;
        }

        path.push_back(nums[u]);
        dfs(u + 1, nums);
        path.pop_back();
        
        dfs(u + 1, nums);
    }
};