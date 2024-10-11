class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        // 其实这一步做不做无所谓吧，前面半部分即使没有也无所谓（即数组按升序排序），因为我们是根据nums[r]来二分，不涉及到前半部分
        if(nums[n - 1] > nums[0]) return nums[0]; 
        
        // 二分模板一
        int l = 0, r = n - 1;
        while(l < r)
        {
            int mid = l + r >> 1;
            if(nums[mid] <= nums[r])
                r = mid;
            else 
                l = mid + 1;
        } 

        return nums[l];
    }
};