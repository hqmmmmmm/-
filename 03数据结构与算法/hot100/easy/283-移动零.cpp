class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // swap
        // 左指针指向当前已经处理好的序列的尾部，右指针指向待处理序列的头部。
        // 左指针左边均为非零数；右指针左边直到左指针处均为零。
        int i = 0, j = 0;
        while(j < nums.size())
        {
            if(nums[j])
                swap(nums[j], nums[i++]);
            ++j;
        }

        // 覆盖补0
        // int i = 0, j = 0;
        // while(j < nums.size())
        // {
        //     if(nums[j]) nums[i++] = nums[j];
        //     ++j;
        // }

        // while(i < nums.size()) nums[i++] = 0;
    }
};