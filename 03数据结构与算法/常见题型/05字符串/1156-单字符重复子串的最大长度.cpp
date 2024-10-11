class Solution {
public: // 华为0924线下二面，没撕出来。
    int maxRepOpt1(string text) {
        unordered_map<char, int> h;
        for(char c : text)
            h[c]++;

        int res = 0;
        for(int i = 0; i < text.size(); ++i)
        {
            // 1、以当前下标i为起点找一段连续相同的子串
            int j = i + 1; 
            while(j < text.size() && text[j] == text[i]) ++j;
            
            // 2、隔一个不同的字符找下一段连续相同的子串（可能没有）
            int k = j + 1;
            while(k < text.size() && text[k] == text[i]) ++k;
            
            // 3、只要将中间这个不同的字符换成相同的就可以变为一段连续相同的子串了
            // 不过可能没有相同的字符了，所以跟h[text[i]]取个min
            res = max(res, min(k - i, h[text[i]])); 

            // 4、一定要注意下次i应该从j重新开始寻找连续相同的子串，因为这个j开始不同的字符即使只有一个我们也要用，可能与后面的构成连续的子串。
            // 更何况这个j开始的可能是一段连续相同的子串呢，好好理解一下。
            // 而每次循环都会进行++i，所以i=j-1.
            i = j - 1;
        }

        return res;
    }
};