class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int maxSum = nums[0];
        int minSum = nums[0];
        int totalSum = nums[0];
        vector<int> maxVec(n), minVec(n);
        maxVec[0] = maxSum;
        minVec[0] = minSum;
        for (int i=1; i<n; i++) {
            totalSum += nums[i];
            maxVec[i] = max(nums[i], nums[i]+maxVec[i-1]);
            maxSum = max(maxSum, maxVec[i]);
            minVec[i] = min(nums[i], nums[i]+minVec[i-1]);
            minSum = min(minSum, minVec[i]);
        }
        return (maxSum > 0) ? max(maxSum, totalSum-minSum) : maxSum;
    }
};
