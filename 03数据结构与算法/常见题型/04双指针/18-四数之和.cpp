class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<vector<int>> res;

        for(int i = 0; i < n; ++i) {
            if(i && nums[i] == nums[i - 1]) continue;
            for(int j = i + 1; j < n; ++j) {
                if(j > i + 1 && nums[j] == nums[j - 1]) continue;
                int l = j + 1, r = n - 1;
                while(l < r) {
                    if(l > j + 1 && nums[l] == nums[l - 1]) {
                        ++l;
                        continue;
                    }

                    long long tmp = static_cast<long long>(nums[l]) + nums[r] + nums[i] + nums[j];
                    if(tmp > target) --r;
                    else if(tmp < target) ++l;
                    else res.push_back({nums[i], nums[j], nums[l++], nums[r--]});
                }
            }
        }

        return res;
    }
};