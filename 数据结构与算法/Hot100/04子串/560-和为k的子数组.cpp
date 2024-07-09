class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> h;
        h[0] = 1;

        int pre = 0;
        int res = 0;
        for(int num : nums) {
            pre += num;
            res += h[pre - k];
            h[pre]++;
        }

        return res;
    }
};