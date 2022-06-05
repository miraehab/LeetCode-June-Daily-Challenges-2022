class Solution {
    bool Validate(vector<string> &nQueens, int row, int col, int &n) {
        for (int i = 0; i != row; ++i)
            if (nQueens[i][col] == 'Q')
                return false;

        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j)
            if (nQueens[i][j] == 'Q')
                return false;

        for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j)
            if (nQueens[i][j] == 'Q')
                return false;
        return true;
    }
    void BackTracking(int & ans, vector<string> &nQueens, int row, int &n) {
        if (row == n) {
            ++ans;
            return;
        }
        for (int col = 0; col != n; ++col)
            if (Validate(nQueens, row, col, n)) {
                nQueens[row][col] = 'Q';
                BackTracking(ans, nQueens, row + 1, n);
                nQueens[row][col] = '.';
            }
    }
public:
    int totalNQueens(int n) {
        int ans = 0;
        vector<string> nQueens(n, string(n, '.'));
        BackTracking(ans, nQueens, 0, n);
        return ans;
    }
};