class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (int i=0; i<matrix.size(); i++) {
            vector<int> vec = matrix[i];
            if (vec[0] > target) return false;
            if (vec[vec.size()-1] < target) continue;
            for (int j=0; j<matrix[i].size(); j++) {
                if (matrix[i][j] == target) return true;
                if (matrix[i][j] > target) return false;
            }
        }
        return false;
    }
};
