/*
 * @Descripttion: your project
 * @version: 1.0
 * @Author: yuy77
 * @Date: 2024-07-11 21:51:32
 * @LastEditors: yuy77
 * @LastEditTime: 2024-07-11 21:55:37
 */
class Solution {
public:
  int singleNumber(vector<int> &nums) {
    // 一位一位算
    int res = 0;
    for(int i = 0; i < 32; ++i)
    {
        int cnt = 0;
        for(int num : nums)
            cnt += (num >> i) & 1;
        if(cnt % 2) res += (1 << i);
    }

    return res;


    // 异或
    // int res = 0;
    // for(int num : nums)
    //     res ^= num;
    // return res;
  }
};