class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> heap; // 默认大根堆
        for(int num : nums) heap.push(num);
        for(int i = 0; i < k - 1; ++i)
            heap.pop();

        return heap.top();
    }
};