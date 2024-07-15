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

        for(int i = 0; i < nums.size(); ++i) {
            if(st[i] == false) {
                st[i] = true;
                path.push_back(nums[i]);
                dfs(nums);
                st[i] = false;
                path.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        st.resize(nums.size(), false);
        dfs(nums);
        return res;
    }
};