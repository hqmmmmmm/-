class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        if(obstacleGrid[0][0]) return 0;

        vector<vector<int>> f(m + 1, vector<int>(n + 1));
        f[1][1] = 1;
        for(int i = 1; i <= m; ++i) {
            for(int j = 1; j <= n; ++j) {
                if(i == 1 && j == 1) continue;
                // 只需要考虑当前位置是否有障碍物，以此来更新当前位置的f
                if(obstacleGrid[i - 1][j - 1]) 
                    f[i][j] = 0;
                else 
                    f[i][j] = f[i - 1][j] + f[i][j - 1];
            }
        }

        return f[m][n];
    }
};