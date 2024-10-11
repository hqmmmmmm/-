class Solution {
public: // dfs，遍历每个坐标，如果是1的话++res，然后就将邻近的1全部置为0。
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        for(int i =0; i < grid.size(); ++i)
        {
            for(int j = 0; j < grid[0].size(); ++j)
            {
                if(grid[i][j] == '1')
                {
                    dfs(i, j, grid);
                    res++;
                }
            }
        }
        return res;   
    }

    void dfs(int x, int y, vector<vector<char>>& grid)
    {
        int dx[] = {0, -1, 0, 1}, dy[] = {-1, 0, 1, 0};
        int n = grid.size(), m = grid[0].size();

        grid[x][y] = '0';
        for(int k = 0; k < 4; ++k)
        {
            int tx = x + dx[k], ty = y + dy[k];
            if(tx >= 0 && tx < n && ty >= 0 && ty < m && grid[tx][ty] == '1')
                dfs(tx, ty, grid);
        }
    }
};