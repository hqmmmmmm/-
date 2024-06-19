class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        for(int i = 0; i < grid.size(); ++i) {
            for(int j = 0; j < grid[0].size(); ++j) {
                if(grid[i][j] == '1') {
                    res += 1;
                    dfs(grid, i, j);
                }
            }
        }

        return res;
    }

    void dfs(vector<vector<char>>& grid, int x, int y) {
        int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
        if(x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && grid[x][y] == '1') {
            grid[x][y] = '0';
            for(int i = 0; i < 4; ++i)
                dfs(grid, x + dx[i], y + dy[i]);
        }
    }
};