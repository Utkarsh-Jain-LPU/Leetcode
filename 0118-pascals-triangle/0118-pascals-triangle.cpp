class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows == 1) {
            return {{1}};
        }
        if (numRows == 2) {
            return {{1},{1,1}};
        }
        vector<vector<int>> res(numRows);
        res[0] = {1};
        res[1] = {1,1};
        for (int i=2; i<numRows; i++) {
            vector<int> vec;
            vec.push_back(1);
            for (int j=1; j<i; j++) {
                vec.push_back(res[i-1][j-1]+res[i-1][j]);
            }
            vec.push_back(1);
            res[i] = vec;
        }
        return res;
    }
};
