class Solution {
public:
    int trailingZeroes(int n) {
        // 解法1：每隔5个数出现一个5，每隔5^2个数出现一个5^2，res=n/5 + n/5^2 + ...
        int res = 0;
        while(n) {
            n /= 5;
            res += n;
        }

        return res;

        // 解法2：统计每个数有几个5    O(n)
        // int res = 0;
        // for(int i = 1; i <= n; ++i) {
        //     if(i % 5 == 0) {
        //         for(int j = i; j % 5 == 0; j /= 5) ++res;
        //     }
        // }

        // return res;
    }
};


/*
https://www.bilibili.com/video/BV1dd4y1T71f/?vd_source=290e10e6da0d78fd6c632cdb3be20ba1
*/