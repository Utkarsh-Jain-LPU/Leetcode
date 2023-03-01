class Solution {
public:
    vector<int> merge(vector<int>& vec, int i, int j) {
        if (i == j) return {vec[i]};
        int mid = (i+j)/2;
        vector<int> left = merge(vec, i, mid);
        vector<int> right = merge(vec, mid+1, j);
        int x = 0, m = left.size();
        int y = 0, n = right.size();
        vector<int> v;
        while (x < m && y < n) {
            if (left[x] < right[y]) v.push_back(left[x++]);
            else v.push_back(right[y++]);
        }
        while (x < m) v.push_back(left[x++]);
        while (y < n) v.push_back(right[y++]);
        return v;
    }
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = n-1;
        return merge(nums, i, j);
    }
};
