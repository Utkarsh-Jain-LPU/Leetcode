class Solution {
public:
    int res = INT_MAX;
    int calculate(vector<vector<int>>& matrix, int i, int j, int n, vector<vector<int>>& data) {
        if (j < 0 || j == n) return INT_MAX;
        if (data[i][j] != INT_MAX) return data[i][j];
        if (i == n-1) return matrix[i][j];
        int a = calculate(matrix, i+1, j-1, n, data);
        int b = calculate(matrix, i+1, j, n, data);
        int c = calculate(matrix, i+1, j+1, n, data);
        int temp = min(min(a, b), c) + matrix[i][j];
        data[i][j] = temp;
        return temp;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> data(n, vector<int>(n, INT_MAX));
        for (int j=0; j<n; j++) {
            int sum = calculate(matrix, 0, j, n, data);
            res = min(res, sum);
        }
        return res;
    }
};
