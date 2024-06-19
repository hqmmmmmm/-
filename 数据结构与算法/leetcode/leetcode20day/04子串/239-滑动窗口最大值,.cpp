class Solution {
public: // 单调队列
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> deq;
        vector<int> res;

        // for(int i = 0; i < k; ++i) {
        //     while(!deq.empty() && deq.front() < nums[i]) {
        //         deq.pop_front();
        //     }
        //     deq.push_front(nums[i]);
        // }
        // res.push_back(deq.back());

        for(int i = 0; i < nums.size(); ++i) {
            if(i >= k && deq.back() == nums[i - k]) {
                deq.pop_back();
            }

            while(!deq.empty() && deq.front() < nums[i]) {
                deq.pop_front();
            }
            deq.push_front(nums[i]);
            if(i >= k - 1) res.push_back(deq.back());
        }

        return res;
    }
};