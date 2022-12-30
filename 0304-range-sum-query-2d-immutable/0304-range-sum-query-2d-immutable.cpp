class NumMatrix {
public:
    int m, n;
    vector<vector<int>> vec;
    
    NumMatrix(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        vec.resize(m);
        for (int i=0; i<m; i++) {
            vec[i].resize(n);
        }
        vec[m-1][n-1] = matrix[m-1][n-1];
        for (int j=n-2; j>=0; j--) vec[m-1][j] = vec[m-1][j+1]+matrix[m-1][j];
        for (int i=m-2; i>=0; i--) vec[i][n-1] = vec[i+1][n-1]+matrix[i][n-1];
        for (int i=m-2; i>=0; i--) {
            for (int j=n-2; j>=0; j--) {
                vec[i][j] = vec[i][j+1]+vec[i+1][j]-vec[i+1][j+1]+matrix[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int res = vec[row1][col1];
        if (row2 < m-1) res -= vec[row2+1][col1];
        if (col2 < n-1) res -= vec[row1][col2+1];
        if (row2 < m-1 && col2 < n-1) res += vec[row2+1][col2+1];
        return res;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
