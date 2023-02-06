class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> v(2*n);
        int k = 0;
        for (int i=0; i<n; i++) {
            v[k++] = nums[i];
            v[k++] = nums[i+n];
        }
        return v;
    }
};
