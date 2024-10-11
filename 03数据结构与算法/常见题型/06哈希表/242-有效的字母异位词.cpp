/*
 * @Descripttion: your project
 * @version: 1.0
 * @Author: yuy77
 * @Date: 2024-07-14 22:18:22
 * @LastEditors: yuy77
 * @LastEditTime: 2024-07-14 22:18:34
 */
class Solution {
public:
  bool isAnagram(string s, string t) {
    unordered_map<char, int> hs, ht;
    for (char c : s)
      hs[c]++;
    for (char c : t)
      ht[c]++;

    return hs == ht;
  }
};