class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;
    vector<bool> st;

    void dfs(vector<int> &nums) {
        if(path.size() == nums.size()) {
            res.push_back(path);
            return;
        } 

        unordered_set<int> set;  // 用于树层去重，就是在同一个位置一个相同的数只能放一次，不能放两次，否则就重复计算了
        for(int i = 0; i < nums.size(); ++i) {
            if(!st[i]) {
                if(set.count(nums[i])) continue;
                else set.insert(nums[i]);

                st[i] = true;
                path.push_back(nums[i]);
                dfs(nums);
                st[i] = false;
                path.pop_back();
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        st.resize(nums.size(), false);
        dfs(nums);
        return res;
    }
};