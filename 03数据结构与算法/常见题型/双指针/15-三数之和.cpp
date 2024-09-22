/*
 * @Descripttion: your project
 * @version: 1.0
 * @Author: yuy77
 * @Date: 2024-07-09 11:38:17
 * @LastEditors: yuy77
 * @LastEditTime: 2024-07-15 22:06:29
 */
class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    for(int i = 0; i < nums.size(); ++i) 
    {
        if(i && nums[i] == nums[i - 1]) continue;
        int j = i + 1, k = nums.size() - 1;
        while(j < k)
        {
            if(j > i + 1 && nums[j] == nums[j - 1]) {
                j++;
                continue;
            }
            if(nums[j] + nums[k] > -nums[i]) --k;
            else if(nums[j] + nums[k] < -nums[i]) ++j;
            else res.push_back({nums[i], nums[j++], nums[k--]});
        }
    }

    return res;
  }
};