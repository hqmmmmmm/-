class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for(int i = 0; i < n; ++i) {
            for(int j = i + 1; j < n; ++j) {
                int l = j + 1, r = n - 1;
                while(l < r) {
                    long long t = static_cast<long long>(target) - nums[i] - nums[j];
                    if(nums[l] + nums[r] > t) --r;
                    else if(nums[l] + nums[r] < t) ++l;
                    else {
                        res.push_back({nums[i], nums[j], nums[l++], nums[r--]});
                        while(l < r && nums[l] == nums[l - 1]) ++l; // 避免第三个数字重复
                    }
                }
                while(j + 1 < n && nums[j + 1] == nums[j]) ++j; // 避免第二个数字重复
            }

            while(i + 1 < n && nums[i + 1] == nums[i]) ++i;  // 避免第一个数字重复
        }

        return res;
    }
};