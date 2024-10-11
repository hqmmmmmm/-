class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        dfs(0, nums);
        return res;
    }

    // dfs(u)表示从nums[u]之后选
    void dfs(int u, vector<int> &nums)
    {
        if(path.size() >= 2) 
            res.push_back(path);
        if(u == nums.size()) 
            return;

        unordered_set<int> st;
        for(int i = u; i < nums.size(); ++i)
        {
            if(path.size() && path.back() > nums[i]) continue;
            if(st.count(nums[i])) continue;
            else st.insert(nums[i]);
  
            path.push_back(nums[i]);
            dfs(i + 1, nums);
            path.pop_back();
            
        }
    }
};