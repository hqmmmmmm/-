class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        // priority_queue<int, vector<int>, greater<int>> heap;
        // for(auto num : nums) heap.push(num);

        // for(int i = 0; i < k; ++i)
        // {
        //     auto val = heap.top();
        //     heap.pop();
        //     heap.push(-val);
        // }

        // int ans = 0;
        // while(!heap.empty())
        // {
        //     ans += heap.top();
        //     heap.pop();
        // }

        // return ans;
    
        sort(nums.begin(), nums.end());
        auto it = lower_bound(nums.begin(), nums.end(), 0);
        int len_neg = it - nums.begin();  // 这里有很多种情况

        for(int i = 0; i < min(k, len_neg); ++i)
        {
            nums[i] = -nums[i];
        }

        if(k > len_neg)
        {
            k -= len_neg;
            sort(nums.begin(), nums.end());
            if(nums[0] != 0 && k % 2 == 1)
                nums[0] = -nums[0];
        }

        return accumulate(nums.begin(), nums.end(), 0);
    }
};