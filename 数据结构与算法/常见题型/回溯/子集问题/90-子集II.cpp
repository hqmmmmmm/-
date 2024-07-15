class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;
    unordered_map<int, int> h;  // 注意使用哈希表统计个数时，一定要注意写好那个是哈希表的key！！！

    void dfs(int u, vector<int> &nums) {
        if(u == nums.size()) {
            res.push_back(path);
            return;
        }

        while(u + 1 < nums.size() && nums[u] == nums[u + 1]) ++u;
        int cnt = h[nums[u]];
        for(int i = 0; i <= cnt; ++i) {
            for(int j = 0; j < i; ++j) path.push_back(nums[u]);
            dfs(u + 1, nums);
            for(int j = 0; j < i; ++j) path.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int num : nums) h[num]++;
        dfs(0, nums);
        return res;
    }
};