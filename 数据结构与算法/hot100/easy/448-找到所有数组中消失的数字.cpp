class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        // 原地修改，将对应下标位置的数字*-1，如果已经是负数就不用再乘了。
        for(int i = 0; i < nums.size(); ++i)
        {
            int x = abs(nums[i]);
            nums[x - 1] = -abs(nums[x - 1]);
        }

        vector<int> res;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] > 0) 
                res.push_back(i + 1);
        }
        return res;
    }
};