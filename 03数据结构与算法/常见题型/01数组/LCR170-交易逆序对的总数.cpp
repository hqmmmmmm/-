class Solution {
public:
    int merge_sort(vector<int> &nums, vector<int> &tmp, int l, int r) {
        if(l >= r) return 0;

        int mid = l + r >> 1;
        int res = merge_sort(nums, tmp, l, mid) + merge_sort(nums, tmp, mid + 1, r);

        int i = l, j = mid + 1, k = l;
        while(i <= mid && j <= r) {
            if(nums[i] > nums[j]) {
                tmp[k++] = nums[j++];
                res += mid - i + 1;
            } else {
                tmp[k++] = nums[i++];
            }
        }

        while(i <= mid) tmp[k++] = nums[i++];
        while(j <= r) tmp[k++] = nums[j++];

        for(i = l; i <= r; ++i) nums[i] = tmp[i];
        
        return res;
    }

    int reversePairs(vector<int>& record) {
        int n = record.size();
        vector<int> tmp(n);
        return merge_sort(record, tmp, 0, n - 1);
    }
};