class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = 0, j = 0, k = nums.size() - 1;
        while(j <= k) // 注意当j=k时这个数字不能确定是0还是1还是2，所以不能直接退出循环
        {
            if(nums[j] == 0)
                swap(nums[i++], nums[j++]);
            else if(nums[j] == 2)
                swap(nums[k--], nums[j]);
            else
                ++j;
        }
    }
};