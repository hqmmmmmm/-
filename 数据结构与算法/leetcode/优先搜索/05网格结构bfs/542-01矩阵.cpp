class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>> res(mat.size(), vector<int>(mat[0].size(), INT_MAX));
        queue<pair<int, int>> q;
        for(int i = 0; i < mat.size(); ++i) {
            for(int j = 0; j < mat[0].size(); ++j) {
                if(mat[i][j] == 0) {
                    q.push({i, j});
                    res[i][j] = 0;
                }
            }
        }

        while(!q.empty()) {
            int dx[] = {0, -1, 0, 1}, dy[] = {-1, 0, 1, 0};
            auto [x, y] = q.front();
            q.pop();

            for(int i = 0; i < 4; ++i) {
                int tx = x + dx[i], ty = y + dy[i];
                if(tx >= 0 && tx < mat.size() && ty >= 0 && ty < mat[0].size()) {
                    if(res[tx][ty] > res[x][y] + 1) { // 满足这个条件的需要加入队列，因为这个点更新了，所以需要以这个点为源进行更新。
                        res[tx][ty] = res[x][y] + 1;
                        q.push({tx, ty});
                    }
                }
            }
        }

        return res;
    }
};
