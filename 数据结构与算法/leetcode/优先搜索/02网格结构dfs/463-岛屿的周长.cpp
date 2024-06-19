class Solution {
public:
    vector<vector<bool>> st;

    int islandPerimeter(vector<vector<int>>& grid) {
        int res = 0;
        int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

        for(int i = 0; i < grid.size(); ++i) {
            for(int j = 0; j < grid[0].size(); ++j) {
                if(grid[i][j]) {
                    for(int k = 0; k < 4; ++k) {
                        int x = i + dx[k], y = j + dy[k];
                        if(x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && grid[x][y] == 1);
                        else res++;
                    }
                }
            }
        }

        return res;
    }
};