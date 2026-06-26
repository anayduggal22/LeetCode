class Solution {
public:
    int fact(int n, int m, vector<vector<int>>& grid, vector<vector<int>>& dp) {

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {

                if (i == 0 && j == 0) {
                    // Base Case
                    dp[i][j] = grid[i][j];
                }

                else {

                    int up = 1e9;   // Should be default big
                    int left = 1e9; // Should be default big

                    if (i > 0) {
                        up = grid[i][j] + dp[i - 1][j];
                    }

                    if (j > 0) {
                        left = grid[i][j] + dp[i][j - 1];
                    }

                    dp[i][j] = min(up, left);
                }
            }
        }

        return dp[n][m];
    }

    int minPathSum(vector<vector<int>>& grid) {

        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), -1));

        int n = grid.size();
        int m = grid[0].size();

        return fact(n - 1, m - 1, grid, dp);
    }
};