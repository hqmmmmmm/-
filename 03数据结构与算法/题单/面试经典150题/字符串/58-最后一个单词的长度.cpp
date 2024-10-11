class Solution {
public:
    int lengthOfLastWord(string s) {
        // 先处理空格
        int i = s.size() - 1; 
        while(i >= 0 && s[i] == ' ') --i;

        int ans = 0;
        while(i >= 0 && s[i--] != ' ') 
            ++ans;

        return ans;
    }
};