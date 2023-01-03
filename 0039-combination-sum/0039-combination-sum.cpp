class Solution {
public:
    void calculate(vector<int>& candidates, int j, vector<int> vec, vector<vector<int>>& res, int target) {
        if (target == 0) {
            res.push_back(vec);
            return;
        }
        if (j < 0) return;
        if (candidates[j] > target) {
            return calculate(candidates, j-1, vec, res, target);
        }
        if (candidates[j] == target) {
            vec.push_back(candidates[j]);
            res.push_back(vec);
            vec.pop_back();
            return calculate(candidates, j-1, vec, res, target);
        }
        int times = floor(target/candidates[j]);
        for (int k=times; k>0; k--) {
            for (int x=0; x<k; x++) vec.push_back(candidates[j]);
            calculate(candidates, j-1, vec, res, target-(candidates[j]*k));
            for (int x=0; x<k; x++) vec.pop_back();
        }
        calculate(candidates, j-1, vec, res, target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        int j = candidates.size()-1;
        vector<int> vec;
        vector<vector<int>> res;
        while (j >= 0) {
            if (candidates[j] > target) {
                j--;
                continue;
            }
            if (candidates[j] == target) {
                vec.push_back(candidates[j]);
                res.push_back(vec);
                vec.clear();
                j--;
                continue;
            }
            int times = floor(target/candidates[j]);
            for (int k=times; k>0; k--) {
                for (int x=0; x<k; x++) vec.push_back(candidates[j]);
                calculate(candidates, j-1, vec, res, target-(candidates[j]*k));
                vec.clear();
            }
            j--;
        }
        return res;
    }
};
