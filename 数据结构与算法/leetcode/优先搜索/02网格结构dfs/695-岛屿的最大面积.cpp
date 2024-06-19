class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i = 0; i < grid.size(); ++i) {
            for(int j = 0; j < grid[0].size(); ++j) {
                ans = max(ans, dfs(grid, i, j));
            }
        }

        return ans;
    }

    int dfs(vector<vector<int>>& grid, int x, int y) {
        if(x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || !grid[x][y])
            return 0;
        grid[x][y] = 0;

        int area = 1;
        int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
        for(int i = 0; i < 4; ++i)
            area += dfs(grid, x + dx[i], y + dy[i]);

        return area;
    }
};