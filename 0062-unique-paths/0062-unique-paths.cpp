class Solution {
public:
    int fact(int m, int n, vector<vector<int>>& dp) {

        if (m == 0 && n == 0) {
            return 1;
        }

        else if (m < 0 || n < 0) {
            return 0;
        }

        else if (dp[m][n] != -1) {
            return dp[m][n];
        }

        int up = fact(m - 1, n, dp);
        int left = fact(m, n - 1, dp);

        return dp[m][n] = up + left;
    }

    int uniquePaths(int m, int n) {

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return fact(m - 1, n - 1, dp);
    }
};