class Solution {
public:
    bool subsetSum(vector<int>& nums, int sum, int n, vector<vector<int>>& dp) {
        if (sum == 0) return true;
        if (sum < 0 || n < 0) return false;
        if (dp[n][sum] != -1) return dp[n][sum];
        return dp[n][sum] = (subsetSum(nums, sum, n-1, dp) 
                             || subsetSum(nums, sum-nums[n], n-1, dp));
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (int num : nums) sum += num;
        if (sum % 2 != 0) return false;
        vector<vector<int>> dp(n, vector<int>((sum/2)+1, -1));
        return subsetSum(nums, sum/2, n-1, dp);
    }
};
