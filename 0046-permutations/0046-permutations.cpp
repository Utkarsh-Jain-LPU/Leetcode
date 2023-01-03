class Solution {
public:
    void calculate(vector<int>& nums, int i, int n, vector<int> vec, vector<vector<int>>& res) {
        if (i == n) {
            res.push_back(vec);
            return;
        }
        int size = vec.size();
        for (int k=0; k<size; k++) {
            vec.insert(vec.begin()+k, nums[i]);
            calculate(nums, i+1, n, vec, res);
            vec.erase(vec.begin()+k);
        }
        vec.push_back(nums[i]);
        calculate(nums, i+1, n, vec, res);
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> vec;
        vector<vector<int>> res;
        calculate(nums, 0, nums.size(), vec, res);
        return res;
    }
};
