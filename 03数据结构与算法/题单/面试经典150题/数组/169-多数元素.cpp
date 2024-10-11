class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res = INT_MAX, cnt = 0;   // 摩尔投票
        for(int num : nums)
        {
            if(cnt == 0)
            {
                res = num;
                cnt++;
            }
            else 
            {
                if(num == res)
                    ++cnt;
                else 
                    --cnt;
            }
        }

        return res;
    }
};