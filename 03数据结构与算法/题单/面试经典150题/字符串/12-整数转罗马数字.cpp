class Solution {
public:
    unordered_map<int, string> h = 
    {
        {1, "I"}, {5, "V"}, {10, "X"}, {50, "L"},
        {100, "C"}, {500, "D"}, {1000, "M"}
    };

    string intToRoman(int num) {
        string res;
        int x = 10;
        while(num)
        {
            int y = num % x;  // 取到当前位数
            if(y == 4 * x / 10)
                res = h[x / 10] + h[x / 10 * 5] + res;
            else if(y == 9 * x / 10)
                res = h[x / 10] + h[x] + res;
            else 
            {
                for(int i = 0; i < (y / (x / 10)) % 5; ++i)
                    res = h[x / 10] + res;
                if(y >= x / 10 * 5)
                    res = h[x / 10 * 5] + res;
            }

            num -= y; // 减去低位的数
            x *= 10;
        }

        return res;
    }
};