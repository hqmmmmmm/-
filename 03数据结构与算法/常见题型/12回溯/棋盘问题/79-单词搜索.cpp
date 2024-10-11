class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<int>> st(board.size(), vector<int>(board[0].size(), 0));
        for(int i = 0; i < board.size(); ++i)
        {
            for(int j = 0; j < board[0].size(); ++j)
            {
                st[i][j] = true;
                if(dfs(i, j, 0, word, board, st))
                    return true;
                st[i][j] = false;
            }
        }
        return false;
    }

    bool dfs(int x, int y, int u, string &word, vector<vector<char>>& board, vector<vector<int>> &st)
    {
        if(board[x][y] != word[u]) return false;
        if(u == word.size() - 1) return true;
        
        int dx[] = {0, -1, 0, 1}, dy[] = {-1, 0, 1, 0};
        for(int k = 0; k < 4; ++k)
        {
            int tx = x + dx[k], ty = y + dy[k];
            if(tx >= 0 && tx < board.size() && ty >= 0 && ty < board[0].size() && !st[tx][ty])
            {
                st[tx][ty] = true;
                if(dfs(tx, ty, u + 1, word, board, st))
                    return true;
                st[tx][ty] = false;
            }
        }

        return false;
    }
};