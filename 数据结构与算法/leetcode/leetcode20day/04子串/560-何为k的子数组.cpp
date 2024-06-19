class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> h;
        h[0] = 1;


        // 相当于一个循环枚举子数组的结尾，子数组的开头不使用循环来枚举，使用空间换时间，采用哈希表
        int res = 0, pre = 0;
        for(int num : nums) {
            pre += num;
            if(h.count(pre - k)) {
                res += h[pre - k];
            }
            h[pre]++;
        }

        return res;
    }
};