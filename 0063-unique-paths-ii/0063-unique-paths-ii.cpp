class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> grid(m, vector<int>(n));
        grid[0][0] = obstacleGrid[0][0] == 1 ? 0 : 1;
        for (int i=1; i<m; i++) {
            if (obstacleGrid[i][0] == 1) grid[i][0] = 0;
            else grid[i][0] = grid[i-1][0];
        }
        for (int j=1; j<n; j++) {
            if (obstacleGrid[0][j] == 1) grid[0][j] = 0;
            else grid[0][j] = grid[0][j-1];
        }
        for (int i=1; i<m; i++) {
            for (int j=1; j<n; j++) {
                if (obstacleGrid[i][j] == 1) grid[i][j] = 0;
                else grid[i][j] = grid[i-1][j] + grid[i][j-1];
            }
        }
        return grid[m-1][n-1];
    }
};
