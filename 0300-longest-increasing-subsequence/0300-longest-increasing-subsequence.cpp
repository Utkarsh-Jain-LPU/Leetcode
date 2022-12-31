class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(), res = 0;
        vector<int> vec(n);
        for (int i=0; i<n; i++) {
            int currMax = 0;
            for (int j=i-1; j>=0; j--) {
                if (nums[j] < nums[i]) currMax = max(currMax, vec[j]);
            }
            vec[i] = currMax+1;
            res = max(res, vec[i]);
        }
        return res;
    }
};
