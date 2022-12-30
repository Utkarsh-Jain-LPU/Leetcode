class Solution {
public:
    int getSum(vector<vector<int>>& vec, int &row1, int &col1, int &row2, int &col2, int &m, int &n) {
        int res = vec[row1][col1];
        if (row2 < m-1) res -= vec[row2+1][col1];
        if (col2 < n-1) res -= vec[row1][col2+1];
        if (row2 < m-1 && col2 < n-1) res += vec[row2+1][col2+1];
        return res;
    }
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> vec(m, vector<int>(n));
        vec[m-1][n-1] = matrix[m-1][n-1];
        for (int j=n-2; j>=0; j--) vec[m-1][j] = vec[m-1][j+1]+matrix[m-1][j];
        for (int i=m-2; i>=0; i--) vec[i][n-1] = vec[i+1][n-1]+matrix[i][n-1];
        for (int i=m-2; i>=0; i--) {
            for (int j=n-2; j>=0; j--) {
                vec[i][j] = vec[i][j+1]+vec[i+1][j]-vec[i+1][j+1]+matrix[i][j];
            }
        }
        vector<vector<int>> res(m, vector<int>(n));
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                int row1 = (i-k) < 0 ? 0 : i-k;
                int col1 = (j-k) < 0 ? 0 : j-k;
                int row2 = (i+k) >= m ? m-1 : i+k;
                int col2 = (j+k) >= n ? n-1 : j+k;
                res[i][j] = getSum(vec, row1, col1, row2, col2, m, n);
            }
        }
        return res;
    }
};
