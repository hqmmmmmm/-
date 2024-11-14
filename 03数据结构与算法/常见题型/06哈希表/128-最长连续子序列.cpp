class Solution {
public:
// 比如1 2 3 4 8 9
// 我们只要算从1开头的子序列就可以了，2开头的肯定没有1开头的长。
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