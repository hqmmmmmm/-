// 给M、N、K，表示字符串由不超过M个'a'和不超过N个'b'组成，返回字典排序第K小的字符串
// 这题拿到题目后，要返回字典排序第k小的字符串，肯定不能直接求出来，那就只有先把所有的字符串都求出来=穷举所有情况，可以转化为组合问题。

void dfs(int m, int n) {
  res.push_back(path);
  if (m == 0 && n == 0)
    return;

  // 因为需要按字典序，所有当前位置优先选字典序更小的a
  if (m == 0) {
    path.push_back('b');
    dfs(m, n - 1);
  } else {
    path.push_back('a');
    dfs(m - 1, n);
  }
}