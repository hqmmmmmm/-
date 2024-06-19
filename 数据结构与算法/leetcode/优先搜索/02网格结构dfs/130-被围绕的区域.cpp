class Solution {
public:
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
            for(int j = 0; j < board[0].size(); ++j) {
                if(board[i][j] == 'Y')
                    board[i][j] = 'O';
                else  
                    board[i][j] = 'X';
            } 
        }
    }

    void dfs(vector<vector<char>>& board, int x, int y) {
        if(x >= 0 && x < board.size() && y >= 0 && y < board[0].size() && board[x][y] == 'O') {
            board[x][y] = 'Y';
            int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
            for(int i = 0; i < 4; ++i)
                dfs(board, x + dx[i], y + dy[i]);
        }
    }
};