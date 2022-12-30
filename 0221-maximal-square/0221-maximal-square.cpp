class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int res = 0;
        vector<vector<int>> grid(m, vector<int>(n));
        for (int i=0; i<m; i++) {
            grid[i][0] = matrix[i][0]-'0';
            if (grid[i][0] == 1) res = 1;
        }
        for (int j=0; j<n; j++) {
            grid[0][j] = matrix[0][j]-'0';
            if (grid[0][j] == 1) res = 1;
        }
        for (int i=1; i<m; i++) {
            for (int j=1; j<n; j++) {
                if (matrix[i][j] == '0') {
                    grid[i][j] = 0;
                    continue;
                }
                int val = min(grid[i-1][j-1], min(grid[i-1][j], grid[i][j-1]));
                grid[i][j] = pow(sqrt(val)+1, 2);
                res = max(res, grid[i][j]);
            }
        }
        return res;
    }
};
