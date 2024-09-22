class Solution {
public: 
    void rotate(vector<int>& nums, int k) {
        // 1 注意k要对nums的大小取余。
        // 2 注意reverse这些泛型算法左开右闭。
        k %= nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};