class Solution {
public:
    int hammingWeight(int n) {
        // n & (n - 1)能将n的最右边的1置为0，计算需要做多少步才能让n变为0，即为n中1的个数
        int res = 0;
        while(n)
        {
            n = n & (n - 1);
            res++;
        }
        return res;

        // 常规做法，逐位判断，如果n中很多0，效率比较低
        // int res = 0;
        // while(n)
        // {
        //     res += n & 1;
        //     n >>= 1;
        // }
        // return res;
    }
};