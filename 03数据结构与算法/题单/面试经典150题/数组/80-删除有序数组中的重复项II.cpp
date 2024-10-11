class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() < 2) return 1;  // 处理一下越界问题

        int i = 2, j = 2;  // 2个相同数字，前两个肯定可以直接保留
        while(j < nums.size())
        {
            // 只要nums[j]和已经放进去的元素倒数第二个不相同就可以，因为这样就意味着不可能超过两个相同的元素
            // 不用跟j比，只要和i比就可以了，26题也是这样的做法，无非就是k不同
            if(nums[j] != nums[i - 2])  
                nums[i++] = nums[j];
            ++j;
        }

        return i;
    }
};