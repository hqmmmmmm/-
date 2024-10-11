class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> h1, h2;
        for(int num1 : nums1) {
            for(int num2 : nums2) {
                h1[num1 + num2]++;
            }
        }

        int res = 0;
        for(int num3 : nums3) {
            for(int num4 : nums4) {
                if(h1.count(-num3 - num4)) {
                    res += h1[-num3 - num4];
                }
            }
        }

        return res;
    }
};