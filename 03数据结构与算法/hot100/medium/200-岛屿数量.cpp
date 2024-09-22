class Solution {
public: // dfs，遍历每个坐标，如果是1的话++res，然后就将邻近的1全部置为0。
    int res = 0;

    int numIslands(vector<vector<char>>& grid) {
        for(int i = 0; i < grid.size(); ++i)
            for(int j = 0; j < grid[0].size(); ++j)
                if(grid[i][j] == '1')
                {
                    ++res;
                    dfs(i, j, grid);
                }
        return res;    
    }

    void dfs(int x, int y, vector<vector<char>> &g)
    {   
        if(x < 0 || x >= g.size() || y < 0 || y >= g[0].size()) return ;
        if(g[x][y] == '1')
        {
            g[x][y] = '0';
            int dx[] = {0, -1, 0, 1}, dy[] = {-1, 0, 1, 0};
            for(int i = 0; i < 4; ++i)
                dfs(x + dx[i], y + dy[i], g);
        }
    }
};