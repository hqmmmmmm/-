class Solution {
public:
    bool canJump(vector<int>& nums) { 
        // 贪心，维护一个最右端点right，枚举nums所有的下标，如果所有下标都能被right覆盖，就return true
        int right = 0;

        for(int i = 0; i < nums.size(); ++i)
        {
            if(i > right)
                return false;
            right = max(right, i + nums[i]);
        }

        return true;
    }
};