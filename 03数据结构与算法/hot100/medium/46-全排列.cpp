class Solution {
public: // 回溯算法，每次选择之前没有选过的
    vector<vector<int>> res;
    vector<int> path;
    vector<int> st;

    vector<vector<int>> permute(vector<int>& nums) {
        st.resize(nums.size(), 0);
        dfs(nums);
        return res;
    }


    void dfs(vector<int> &nums)
    {
        if(path.size() == nums.size()) 
        {
            res.push_back(path);
            return ;
        }

        for(int i = 0; i < nums.size(); ++i)
        {
            if(!st[i])
            {
                path.push_back(nums[i]);
                st[i] = 1;
                dfs(nums);
                path.pop_back();
                st[i] = 0;
            }
        }
    }
};