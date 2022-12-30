class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int arr[n];
        arr[0] = nums[0];
        for (int i=1; i<n; i++) {
            arr[i] = max(nums[i], nums[i]+arr[i-1]);
        }
        int res = INT_MIN;
        for (int i=0; i<n; i++) {
            res = max(res, arr[i]);
        }
        return res;
    }
};
