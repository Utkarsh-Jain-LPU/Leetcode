class Solution {
public:
    vector<int> getRow(int rowIndex) {
        rowIndex++;
        if (rowIndex == 1) {
            return {1};
        }
        if (rowIndex == 2) {
            return {1,1};
        }
        vector<vector<int>> res(rowIndex);
        res[0] = {1};
        res[1] = {1,1};
        for (int i=2; i<rowIndex; i++) {
            vector<int> vec;
            vec.push_back(1);
            for (int j=1; j<i; j++) {
                vec.push_back(res[i-1][j-1]+res[i-1][j]);
            }
            vec.push_back(1);
            res[i] = vec;
        }
        return res[rowIndex-1];
    }
};
