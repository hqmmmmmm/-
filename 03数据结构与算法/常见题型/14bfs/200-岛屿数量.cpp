class Solution {
public: // bfs，遍历每个坐标，如果是1的话++res，然后就将邻近的1全部置为0。
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        for(int i =0; i < grid.size(); ++i)
        {
            for(int j = 0; j < grid[0].size(); ++j)
            {
                if(grid[i][j] == '1')
                {
                    bfs(i, j, grid);
                    res++;
                }
            }
        }
        return res;   
    }

    void bfs(int x, int y, vector<vector<char>>& grid)
    {
        int dx[] = {0, -1, 0, 1}, dy[] = {-1, 0, 1, 0};
        int n = grid.size(), m = grid[0].size();

        queue<pair<int, int>> q;
        q.push({x, y});

        while(!q.empty())
        {
            auto [a, b] = q.front();
            q.pop();

            // // 写在这里会慢很多超时，因为可能有的会被重复push到队列中。或者直接使用st记录就可以写在这里
            // grid[a][b] = '0';  

            for(int k = 0; k < 4; ++k)
            {
                int tx = a + dx[k], ty = b + dy[k];
                if(tx >= 0 && tx < n && ty >= 0 && ty < m && grid[tx][ty] == '1')
                {
                    q.push({tx, ty});
                    grid[tx][ty] = '0'; // 记得将访问过的坐标设为0
                }
            }
        }
    }
};