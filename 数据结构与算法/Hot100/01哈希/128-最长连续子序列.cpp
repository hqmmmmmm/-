class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res = 0;
        unordered_set<int> st(nums.begin(), nums.end());
        for(int num : st) {
            if(!st.count(num - 1)) {
                int x = num + 1;
                while(st.count(x)) ++x;
                res = max(res, x - num);
            }
        }

        return res;
    }
};