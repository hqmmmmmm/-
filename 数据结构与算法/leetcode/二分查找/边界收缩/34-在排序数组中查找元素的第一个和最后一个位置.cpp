#include <queue>
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        if(nums.size() == 0) return {-1, -1};

        int l = 0, r = nums.size() - 1;
        while(l < r) {
            int mid = l + r >> 1;
            if(nums[mid] >= target) 
                r = mid;
            else 
                l = mid + 1;
        }
        
        if(nums[l] != target) return {-1, -1};
        ans.push_back(l);

        l = 0, r = nums.size() - 1;
        while(l < r) {
            int mid = l + r + 1 >> 1;
            if(nums[mid] <= target) 
                l = mid;
            else
                r = mid - 1;
        }

        ans.push_back(l);
        
        return ans;
    }
};