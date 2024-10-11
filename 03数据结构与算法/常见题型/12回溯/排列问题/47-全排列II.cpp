class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;
    vector<bool> st;

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        st.resize(nums.size(), false);
        sort(nums.begin(), nums.end());
        dfs(0, nums);
        return res;
    }

    void dfs(int u, vector<int> &nums)
    {
        if(u == nums.size())
        {
            res.push_back(path);
            return;
        }

        for(int i = 0; i < nums.size(); ++i)
        {
            if(!st[i]) 
            {
                // 如果nums[i-1]和nums[i]相同并且nums[i-1]没被选到过
                // 那他肯定在nums[i]之前就会被遍历过了，相同的元素只遍历一个就可以了
                // else 也可以使用unordered_set来进行”树层去重“，那样就不需要对nums排序了
                if(i && nums[i] == nums[i - 1] && !st[i - 1]) continue;
                st[i] = true;
                path.push_back(nums[i]);
                dfs(u + 1, nums);
                st[i] = false;
                path.pop_back();
            }
        }
    }
};