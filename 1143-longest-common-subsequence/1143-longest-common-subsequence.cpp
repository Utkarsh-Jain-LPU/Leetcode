class Solution {
public:
    int solve(string &str1, string &str2, int m, int n, vector<vector<int>> &dp) {
        if (m == 0 || n == 0) return 0;
        if (dp[m][n] != -1) return dp[m][n];
        if (str1[m-1] == str2[n-1]) {
            return dp[m][n] = solve(str1, str2, m-1, n-1, dp) + 1;
        }
        return dp[m][n] = max(solve(str1, str2, m-1, n, dp), solve(str1, str2, m, n-1, dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        return solve(text1, text2, m, n, dp);
    }
};
