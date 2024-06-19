class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.begin(), nums.end());
        for(int i = ans.size() - 2; i >= 0; --i) {
            ans[i] *= ans[i + 1];
        }

        int pre = 1;
        for(int i = 0; i < nums.size() - 1; ++i) {
            ans[i] = pre * ans[i + 1];
            pre *= nums[i];
        }
        ans[nums.size() - 1] = pre;

        return ans;
    }
};