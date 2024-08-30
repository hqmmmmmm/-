class Solution {
public: // 先找到分界点，再在两个有序的子数组中二分查找
    int search(vector<int>& nums, int target) {
        int n = nums.size();

        // 先找到边界(最小的那个数)
        int l = 0, r = n - 1;
        while(l < r)
        {
            int mid = l + r >> 1;
            // 注意这里不能跟nums[l]比，因为右半部分也是递增的，l可能在右半部分，直接跟nums.back比就可以，这是个分界线
            if(nums[mid] > nums.back()) 
                l = mid + 1;
            else 
                r = mid;
        }
        int edge = l;
        cout << "edge = " << edge << endl;
        
        // 在两个有序的部分分别进行二分查找
        // [0, edge - 1]   [edge, n - 1]
        l = 0, r = edge - 1;
        if(target <= nums[n - 1]) 
            l = edge, r = n - 1;
        else 
            l = 0, r = edge - 1;
        while(l < r)
        {
            int mid = l + r >> 1;
            if(nums[mid] < target) l = mid + 1;
            else r = mid;
        }

        return nums[l] == target ? l : -1;
    }
};