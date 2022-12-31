class Solution {
public:
    int res = 0;
    int sx[4] = {-1, 0, 1,  0};
    int sy[4] = { 0, 1, 0, -1};
    void calculate(vector<vector<int>>& grid, int i, int j, int m, int n, vector<vector<bool>> visited, int currCount, int totalCount) {
        if (i < 0 || i == m || j < 0 || j == n) return;
        if (grid[i][j] == -1) return;
        if (visited[i][j]) return;
        if (grid[i][j] == 2 && currCount+1 == totalCount) {
            res++;
            return;
        }
        visited[i][j] = true;
        for (int k=0; k<4; k++) {
            calculate(grid, i+sx[k], j+sy[k], m, n, visited, currCount+1, totalCount);
        }
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0, si, sj;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (grid[i][j] == 1) {
                    si = i;
                    sj = j;
                }
                if (grid[i][j] != -1) count++;
            }
        }
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        calculate(grid, si, sj, m, n, visited, 0, count);
        return res;
    }
};
