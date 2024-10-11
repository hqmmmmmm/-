class Solution {
public:
    bool isHappy(int n) {
        int slow = n, fast = step(n);
        while(slow != fast) {
            slow = step(slow);
            fast = step(step(fast));
        }

        return slow == 1;
    }

    int step(int x) {
        int res = 0;
        while(x) {
            int tmp = x % 10;
            x /= 10;
            res += tmp * tmp;
        }
        return res;
    }
};