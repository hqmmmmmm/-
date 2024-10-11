class Solution {
public:
    int jump(vector<int>& nums) {
        // 贪心 O(n)
        int ans = 0;
        // maxpos表示当前这一步能到达的所有数字中下一步所能到达最远的位置
        // end   表示当前这一步能到达的所有数字中最远的位置
        int maxpos = 0, end = 0; 
        for(int i = 0; i < nums.size() - 1; ++i)
        {
            maxpos = max(maxpos, i + nums[i]);
            if(end == i) // 超过当前这步的范围了，下一步
            {
                ans++;
                end = maxpos;
            }
        }

        return ans;


        // 动态规划 O(n2)
        // int n = nums.size();
        // vector<int> f(n + 1, INT_MAX / 2);
        // f[1] = 0;
        // // 状态定义：f[i]表示到第i个数的最小跳跃次数
        // // 状态划分：根据从哪跳来划分
        // // 状态转移：f[i] = min(f[j] + 1) j=1,2,3,...,i-1

        // for(int i = 1; i <= n; ++i)
        // {
        //     for(int j = 1; j < i; ++j)
        //     {
        //         if(j - 1 + nums[j - 1] >= i - 1)
        //             f[i] = min(f[i], f[j] + 1);
        //     }
        // }

        // return f[n];
    }
};