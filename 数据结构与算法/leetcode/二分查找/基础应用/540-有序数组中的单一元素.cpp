class Solution {
public: // 二分查找，mid左右子数组的长度一奇一偶，只出现一次的数一定在奇数长度的子数组中
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;

        while(l < r) {
            int mid = l + r >> 1;
            if(mid > l && nums[mid] == nums[mid - 1]) {
                if((mid - l + 1) % 2)
                    r = mid;
                else 
                    l = mid + 1;
            } else if(mid < r && nums[mid] == nums[mid + 1]) {
                if((mid - 1 - l + 1) % 2)
                    r = mid - 1;
                else
                    l = mid;
            } else {
                return nums[mid];
            }
        }

        return nums[l];
    }
};