class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int pre = 0, res = 0;
        unordered_map<int, int> h;
        h[pre] = 1;

        for(int num : nums)
        {
            pre += num;
            res += h[pre - k];
            h[pre]++;
        }

        return res;
    }
};