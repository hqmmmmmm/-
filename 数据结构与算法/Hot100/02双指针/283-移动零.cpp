class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // i负责填入nums，j负责遍历nums。
        // 填入所有的非0元素后，将最后没填入的位置全置为0即可。
        int i = 0, j = 0;
        while(j < nums.size()) {
            if(nums[j]) nums[i++] = nums[j];
            ++j;
        }
        while(i < j) nums[i++] = 0;
    }
};