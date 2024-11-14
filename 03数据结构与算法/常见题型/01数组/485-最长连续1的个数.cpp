class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0, cur = 0;

        for(int num : nums) {
            if(num) {
                cur++;
                res = max(res, cur);
            }
            else 
                cur = 0;
        }

        return res;
    }
};