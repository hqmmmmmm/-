/*
 * @Descripttion: your project
 * @version: 1.0
 * @Author: yuy77
 * @Date: 2024-07-14 22:52:24
 * @LastEditors: yuy77
 * @LastEditTime: 2024-07-14 22:52:29
 */
class Solution {
public: // 正难则反
  int leastBricks(vector<vector<int>> &wall) {
    unordered_map<int, int> h;

    for (int i = 0; i < wall.size(); ++i) {
      int cur = wall[i][0];
      for (int j = 1; j < wall[i].size(); ++j) {
        h[cur]++;
        cur += wall[i][j];
      }
    }

    int cnt = 0;
    for (auto &[k, v] : h)
      cnt = max(cnt, v);

    return wall.size() - cnt;
  }
};