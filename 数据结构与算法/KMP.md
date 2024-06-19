```cpp
class Solution {
public:
    void getNext(const string &needle, vector<int> &next) {
        next.resize(needle.size());
        next[0] = 0;
        // i是前缀后的第一个字符的地方，j是当前要匹配的位置
        int i, j, n = needle.size(); 
        
        for(i = 0, j = 1; j < n; ++j) {
            while(i > 0 && needle[i] != needle[j]) {
                i = next[i - 1];
            }

            if(needle[i] == needle[j]) {
                ++i;
            }
            next[j] = i;
        }
    }

    int strStr(string haystack, string needle) {
        vector<int> next;
        getNext(needle, next);

        // i是文本串的位置，j是匹配串的位置
        int i = 0, j = 0, n = haystack.size();

        for(i = 0, j = 0; i < n; ++i) {
            while(j > 0 && haystack[i] != needle[j]) {
                j = next[j - 1];
            }
            
            if(haystack[i] == needle[j]) {
                ++j;
            }

            if(j == needle.size()) {
                return i - j + 1;
            }
        }

        return -1;
    }
};
```



[关于KMP算法（c++实现）](https://www.cnblogs.com/cherryg/p/14474463.html)