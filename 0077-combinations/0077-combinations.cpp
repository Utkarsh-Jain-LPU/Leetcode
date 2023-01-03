class Solution {
public:
    void calculate(int i, int n, int k, vector<int> vec, vector<vector<int>>& res) {
        if (k == 0) {
            res.push_back(vec);
            return;
        }
        if (i+k-1 > n) return;
        if (i > n) return;
        calculate(i+1, n, k, vec, res);
        vec.push_back(i);
        calculate(i+1, n, k-1, vec, res);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> vec;
        vector<vector<int>> res;
        calculate(1, n, k, vec, res);
        return res;
    }
};
