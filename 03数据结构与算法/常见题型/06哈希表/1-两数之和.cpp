class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> h;
        for(int i = 0; i < nums.size(); ++i) {
            if(h.count(target - nums[i])) 
                return {h[target - nums[i]], i};
            h[nums[i]] = i;
        }

        return {};
    }
};