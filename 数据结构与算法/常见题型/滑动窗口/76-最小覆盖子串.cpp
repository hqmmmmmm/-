/*
 * @Descripttion: your project
 * @version: 1.0
 * @Author: yuy77
 * @Date: 2024-07-10 21:56:56
 * @LastEditors: yuy77
 * @LastEditTime: 2024-07-10 22:19:03
 */
class Solution {
public:
  string minWindow(string s, string t) {
    if (s.size() < t.size())
      return "";
    unordered_map<char, int> hs, ht;
    for(char c : t) ht[c]++;

    string res = s + t;
    int l = 0, r = 0, cnt = 0, tol = ht.size();  // 先记录一下ht中有几个元素，不然下面的[]访问会让htsize变化
    while(r < s.size()) 
    {
        hs[s[r++]]++;
        if(hs[s[r - 1]] == ht[s[r - 1]]) cnt++;
        while(l < r && hs[s[l]] > ht[s[l]]) hs[s[l++]]--;
        if(cnt == tol && r - l < res.size())
            res = s.substr(l, r - l);
    }

    return res == s + t ? "" : res;
  }
};
