class Solution {
public:
    void find(vector<int>& nums, int i, int n, vector<int>& vec, vector<vector<int>>& res) {
        if (i == n) {
            res.push_back(vec);
            return;
        }
        find(nums, i+1, n, vec, res);
        vec.push_back(nums[i]);
        find(nums, i+1, n, vec, res);
        vec.erase(vec.begin()+(vec.size()-1));
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> vec;
        vector<vector<int>> res;
        find(nums, 0, nums.size(), vec, res);
        return res;
    }
};
