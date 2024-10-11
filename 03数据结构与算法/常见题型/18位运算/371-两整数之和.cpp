class Solution {
public:
    int getSum(int a, int b) {
        while(b)
        {
            int add = a ^ b, carry = (a & b) << 1;
            a = add, b = carry;
        }
        return a;
    }
};