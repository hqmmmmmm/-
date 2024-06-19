class Solution {
public:
    void hanota(vector<int>& A, vector<int>& B, vector<int>& C) {
        recur(A.size(), A, B, C);
    }

    // n表示要移动盘子的个数
    void recur(int n, vector<int> &A, vector<int>& B, vector<int>& C) {
        if(n == 1) {
            C.push_back(A.back());
            A.pop_back();
            return;
        }

        recur(n - 1, A, C, B);
        C.push_back(A.back());
        A.pop_back();
        recur(n - 1, B, A, C);
    }
};