class Solution {
public: // 一、位运算   二、求和然后做减法
    int missingNumber(vector<int>& nums) {
        int res = 0, n = nums.size();
        for(int i = 0; i <= n; ++i) 
            res ^= i;
        for(int num : nums)
            res ^= num;
        
        return res;
    }
};