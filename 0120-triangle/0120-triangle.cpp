class Solution {
public:
    int calculate(vector<vector<int>>& triangle, int i, int j, int n, vector<vector<int>>& vec) {
        if (i == n) {
            return 0;
        }
        if (vec[i][j] != INT_MAX) {
            return vec[i][j];
        }
        int val = min(calculate(triangle, i+1, j, n, vec), calculate(triangle, i+1, j+1, n, vec)) + triangle[i][j];
        vec[i][j] = val;
        return val;
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> vec(n, vector<int>(n, INT_MAX));
        return calculate(triangle, 0, 0, n, vec);
    }
};
