/*
 * @Descripttion: your project
 * @version: 1.0
 * @Author: yuy77
 * @Date: 2024-07-14 22:15:14
 * @LastEditors: yuy77
 * @LastEditTime: 2024-07-14 22:15:21
 */
class Solution {
public:
  int findRepeatDocument(vector<int> &documents) {
    int i = 0;
    while (i < documents.size()) {
      if (documents[i] == i) {
        ++i;
        continue;
      }
      if (documents[documents[i]] == documents[i])
        return documents[i];
      swap(documents[i], documents[documents[i]]);
    }

    return 0;
  }
};