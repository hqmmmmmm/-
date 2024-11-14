class Solution {
public:
// 因为要将被捕获的区域设置为X，所以可以将没被捕获的位置先设置为A，然后将所有的O设置为X，再将A设置为O
    void solve(vector<vector<char>>& board) {
        for(int i = 0; i < board.size(); ++i) {
            if(board[i][0] == 'O')
                dfs(board, i, 0);
            if(board[i][board[0].size() - 1] == 'O')
                dfs(board, i, board[0].size() - 1);
        }

        for(int j = 0; j < board[0].size(); ++j) {
            if(board[0][j] == 'O')
                dfs(board, 0, j);
            if(board[board.size() - 1][j] == 'O')
                dfs(board, board.size() - 1, j);
        }

        for(int i = 0; i < board.size(); ++i) {
            for(int j = 0; j< board[0].size(); ++j) {
                if(board[i][j] == 'A')
                    board[i][j] = 'O';
                else 
                    board[i][j] = 'X';
            }
        }
    }

    void dfs(vector<vector<char>>& board, int x, int y) {
        board[x][y] = 'A';
        int dx[] = {0, -1, 0, 1}, dy[] = {-1, 0, 1, 0};
        for(int k = 0; k < 4; ++k) {
            int tx = x + dx[k], ty = y + dy[k];
            if(tx >= 0 && tx < board.size() && ty >= 0 && ty < board[0].size() && board[tx][ty] == 'O')
                dfs(board, tx, ty);
        }
    }
};