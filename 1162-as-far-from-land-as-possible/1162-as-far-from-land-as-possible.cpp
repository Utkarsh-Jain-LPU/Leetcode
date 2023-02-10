class Solution {
public:
    int calculate(vector<vector<int>>& dp, int i, int j, int n) {
        if (i < 0 || i == n || j < 0 || j == n) return INT_MAX;
        return dp[i][j];
    }
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dp(n, vector<int>(n));
        int zero = 0, one = 0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (grid[i][j] == 1) {
                    dp[i][j] = 0;
                    one++;
                    continue;
                }
                zero++;
                int val = min(calculate(dp, i, j-1, n), calculate(dp, i-1, j, n));
                dp[i][j] = (val != INT_MAX) ? val+1 : val;
            }
        }
        int res = 0;
        if (zero == n*n || one == n*n) return -1;
        for (int i=n-1; i>=0; i--) {
            for (int j=n-1; j>=0; j--) {
                if (grid[i][j] == 1) {
                    dp[i][j] = 0;
                    continue;
                }
                int val = min(calculate(dp, i, j+1, n), calculate(dp, i+1, j, n));
                dp[i][j] = min(dp[i][j], (val != INT_MAX) ? val+1 : val);
                res = max(res, dp[i][j]);
            }
        }
        return res;
    }
};
