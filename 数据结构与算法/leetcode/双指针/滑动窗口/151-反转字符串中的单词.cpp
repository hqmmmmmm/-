class Solution {
public: // 先反转字符串中的每个单词，将整个字符串反转
    string reverseWords(string s) {
        int idx = 0, i = 0;  // idx负责填入s，i负责遍历s
        int l = 0, r = 0; // l和r负责表示每个单词的左右边界

        while(i < s.size()) {
            if(s[i] != ' ') {
                l = i;
                while(i < s.size() && s[i] != ' ') ++i;
                r = i - 1;

                // 翻转当前这个单词
                if(idx != 0) s[idx++] = ' ';  // 如果不是第一个单词，需要加空格
                int start = idx;
                for(int j = l; j <= r; ++j) s[idx++] = s[j];
                int end = idx;
                reverse(s.begin() + start, s.begin() + end);
            } else ++i;
        }

        s = s.substr(0, idx);
        reverse(s.begin(), s.end());
        return s;
    }
};