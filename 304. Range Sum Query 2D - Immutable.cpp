class NumMatrix {
private:
    int rows, cols;
    vector<vector<int>> sums;
public:
    NumMatrix(vector<vector<int>> &matrix) {
        rows = matrix.size();
        cols = rows > 0? matrix[0].size() : 0;
        
        sums.resize(rows+1, vector<int>(cols+1, 0));
        
        for(int i = 1; i <= rows; ++i){
            for(int j = 1; j <= cols; ++j){
                sums[i][j] = matrix[i-1][j-1] + 
                             sums[i-1][j] + sums[i][j-1] - sums[i-1][j-1] ;
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return sums[row2+1][col2+1] - sums[row2+1][col1] - sums[row1][col2+1] + sums[row1][col1];
    }
};
/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */