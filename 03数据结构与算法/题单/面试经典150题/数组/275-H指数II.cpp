class Solution {
public:
    int hIndex(vector<int>& citations) {
        // 右边nums[i] >= n - i  左边nums[i] < n - i
        int n = citations.size();
        // H指数为0，不存在我们需要找的边界
        if(citations[n - 1] < 1) return 0;
            
        int l = 0, r = n - 1;
        while(l < r)
        {
            int mid = l + r >> 1;
            if(citations[mid] < n - mid)
                l = mid + 1;
            else 
                r = mid;
        }

        return n - l;
    } 
};