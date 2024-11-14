class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int l = 0, res = 0, k = 0;

        for(int r = 0; r < nums.size(); ++r) {
            if(nums[r] == 0) {
                ++k;
                while(k > 1) {
                    if(nums[l] == 0) --k;
                    ++l;
                }
            }
            res = max(res, r - l + 1);
        }

        return res;
    }
};