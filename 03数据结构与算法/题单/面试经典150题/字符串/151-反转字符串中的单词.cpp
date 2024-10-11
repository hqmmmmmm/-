class Solution {
public:
    string reverseWords(string s) {
        int i = 0, j = 0; // i负责填入，j负责遍历
        
        while(j < s.size())
        {
            if(s[j] != ' ')
            {
                // 获取当前这个单词的左右边界
                int l = j, r = j;
                while(r < s.size() && s[r] != ' ') ++r;
                
                // 如果不是第一个单词的话，前面需要加空格
                if(i) s[i++] = ' '; 
                // 填入s中
                for(int t = l; t < r; ++t)
                    s[i++] = s[t];

                // 反转当前单词
                reverse(s.begin() + i - (r - l), s.begin() + i);

                j = r + 1;
            }
            else 
                ++j;
        }

        s = s.substr(0, i);
        reverse(s.begin(), s.end());
        return s;
    }
};