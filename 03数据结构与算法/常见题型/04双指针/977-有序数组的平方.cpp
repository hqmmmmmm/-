class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> res;

        int l = 0, r = 0;
        while(r < nums.size() && nums[r] < 0) ++r;
        l = r - 1;

        while(l >= 0 && r < nums.size())
        {
            if(abs(nums[l]) < abs(nums[r]))
                res.push_back(nums[l] * nums[l--]);
            else 
                res.push_back(nums[r] * nums[r++]);
        }

        while(l >= 0)
            res.push_back(nums[l] * nums[l--]);
        while(r < nums.size())
            res.push_back(nums[r] * nums[r++]);

        return res;
    }
};