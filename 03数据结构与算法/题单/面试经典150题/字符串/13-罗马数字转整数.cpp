class Solution {
public:
    unordered_map<char, int> h = {
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
        {'C', 100}, {'D', 500}, {'M', 1000}
    };

    int romanToInt(string s) {
        int ans = 0;
        for(int i = 0; i < s.size(); ++i)
        {
            if(i + 1 < s.size() && h[s[i + 1]] > h[s[i]])
                ans -= h[s[i]];
            else 
                ans += h[s[i]];
        }

        return ans;
    }
};