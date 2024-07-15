class Solution {
public:
    int numTrees(int n) {
        // for i = 1 to n    numTrees(i - 1) + numsTrees(n - i)
        if(n <= 1) return 1;
        int res = 0;

        // 枚举根节点
        for(int i = 1; i <= n; ++i) {
            res += numTrees(i - 1) * numTrees(n - i);
        }

        return res;
    }
};