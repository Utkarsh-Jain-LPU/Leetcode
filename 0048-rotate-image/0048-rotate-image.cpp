class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int i = 0, j = matrix.size()-1;
        pair<int, int> p1, p2, p3, p4;
        while (i < j) {
            p1 = make_pair (i, i);
            p2 = make_pair (i, j);
            p3 = make_pair (j, j);
            p4 = make_pair (j, i);
            for (int k=0; k<(j-i); k++) {
                int temp = matrix[p4.first][p4.second];
                matrix[p4.first][p4.second] = matrix[p3.first][p3.second];
                matrix[p3.first][p3.second] = matrix[p2.first][p2.second];
                matrix[p2.first][p2.second] = matrix[p1.first][p1.second];
                matrix[p1.first][p1.second] = temp;
                p1.second++;
                p2.first++;
                p3.second--;
                p4.first--;
            }
            i++;
            j--;
        }
    }
};
