class Solution {
public:
    void calculate(vector<int>& nums, int i, int n, vector<int> vec, set<vector<int>>& res) {
        if (i == n) {
            res.insert(vec);
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
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> vec;
        set<vector<int>> res;
        calculate(nums, 0, nums.size(), vec, res);
        vector<vector<int>> ans;
        for (vector<int> v : res) ans.push_back(v);
        return ans;
    }
};
