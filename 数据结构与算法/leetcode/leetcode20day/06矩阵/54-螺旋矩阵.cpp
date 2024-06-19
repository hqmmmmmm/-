#include <limits.h>
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;

        vector<int> dx = {0, 1, 0, -1}, dy = {1, 0, -1, 0};
        int i = 0, x = 0, y = 0;
        while(ans.size() < matrix.size() * matrix[0].size()) {
            ans.push_back(matrix[x][y]);
            matrix[x][y] = INT_MAX;
            if(x + dx[i] < 0 || x + dx[i] >= matrix.size() || y + dy[i] < 0 || y + dy[i] >= matrix[0].size() || matrix[x + dx[i]][y + dy[i]] == INT_MAX) {
                i = (i + 1) % 4;
            }
            x += dx[i], y += dy[i];
        }

        return ans;
    }
};