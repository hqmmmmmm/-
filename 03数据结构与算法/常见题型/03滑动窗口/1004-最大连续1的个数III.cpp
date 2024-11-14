class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0, res = 0, t = 0;
        for(int r = 0; r < nums.size(); ++r) {
            if(nums[r] == 0) {
                ++t;
                while(t > k) {
                    if(nums[l] == 0) --t;
                    ++l;
                }
            }

            res = max(res, r - l + 1);
        }

        return res;
    }
};