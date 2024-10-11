class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> st;
        while(n != 1) {
            if(st.count(n)) 
                return false;
            else {
                st.insert(n);
                n = step(n);
            }
        }

        return n == 1;
    }

    int step(int num) {
        int res = 0;
        while(num) {
            int x = num % 10;
            num /= 10;
            res += x * x;
        }
        return res;
    }
};