class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int num = 1;
        vector<vector<int>> res(n, vector<int> (n));
        int i1 = 0, i2 = n-1, j1 = 0, j2 = n-1;
        while (i1 <= i2) {
            if (i1 == i2 && j1 == j2) {
                res[i1][j1] = num;
                break;
            }
            for (int k=j1; k<j2; k++) {
                res[i1][k] = num++;
            }
            for (int k=i1; k<i2; k++) {
                res[k][j2] = num++;
            }
            for (int k=j2; k>j1; k--) {
                res[i2][k] = num++;
            }
            for (int k=i2; k>i1; k--) {
                res[k][j1] = num++;
            }
            i1++, j1++, i2--, j2--;
        }
        return res;
    }
};
