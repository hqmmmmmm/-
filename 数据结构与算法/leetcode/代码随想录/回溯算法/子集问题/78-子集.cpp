class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;

    void dfs(int u, vector<int> &nums) {
        if(u == nums.size()) {
            res.push_back(path);
            return;
        }

        path.push_back(nums[u]);
        dfs(u + 1, nums);
        path.pop_back();

        dfs(u + 1, nums);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(0, nums);
        return res;
    }
};