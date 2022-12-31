class Solution {
public:
    int calculate(string& s, vector<vector<int>>& dp, int i, int j) {
        if (i > j) return 0;
        if (i == j) return dp[i][j] = 1;
        if (dp[i][j] != -1) return dp[i][j];
        if (s[i] == s[j]) return dp[i][j] = 2 + calculate(s, dp, i+1, j-1);
        return dp[i][j] = max(calculate(s, dp, i+1, j), calculate(s, dp, i, j-1));
    }
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return calculate(s, dp, 0, n-1);
    }
};
