class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> heap; // 默认大根堆
        for(int num : nums)
        {
            if(heap.size() < k)
                heap.push(num);
            else 
            {
                if(heap.top() < num)
                {
                    heap.pop();
                    heap.push(num);
                }
            }
        }

        return heap.top();
    }
};