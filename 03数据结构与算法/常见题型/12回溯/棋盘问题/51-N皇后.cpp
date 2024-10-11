class Solution {
public:
    vector<bool> col, dg, udg; // 分别表示列，正对角线，反对角线
    vector<string> path;
    vector<vector<string>> res;

    vector<vector<string>> solveNQueens(int n) {
        col.resize(n, false);
        dg.resize(2 * n, false);
        udg.resize(2 * n, false);
        path.resize(n, string(n, '.'));

        dfs(0, n);
        return res;
    }

    // dfs(x)表示第x行及其之后的行在哪个列上选Q
    void dfs(int x, int n)
    {
        if(x == n)
        {
            res.push_back(path);
            return;
        }

        for(int y = 0; y < n; ++y)
        {
            if(!col[y] && !dg[y - x + n] && !udg[x + y])
            {
                col[y] = dg[y - x + n] = udg[x + y] = true;
                path[x][y] = 'Q';
                dfs(x + 1, n);
                path[x][y] = '.';
                col[y] = dg[y - x + n] = udg[x + y] = false;
            }
        }
    }


};