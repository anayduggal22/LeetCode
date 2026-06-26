class Solution {
public:
    int fact(int row, int col, vector<vector<int>>& matrix,
             vector<vector<int>>& dp) {

        if (col < 0 || col >= matrix[0].size()) {
            // Out of bound, so return a big value
            // So that it does not get picked
            return 1e9;
        }

        if (row == 0) {
            return matrix[row][col];
        }

        if (dp[row][col] != INT_MAX) {
            return dp[row][col];
        }

        int up = fact(row - 1, col, matrix, dp) + matrix[row][col];

        int leftdiag = fact(row - 1, col - 1, matrix, dp) + matrix[row][col];

        int rightdiag = fact(row - 1, col + 1, matrix, dp) + matrix[row][col];

        return dp[row][col] = min(up, min(leftdiag, rightdiag));
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size() - 1;

        vector<vector<int>> dp(matrix.size(),
                               vector<int>(matrix[0].size(), INT_MAX));

        int mini = INT_MAX;

        for (int j = 0; j < matrix[0].size(); j++) {
            mini = min(mini, fact(n, j, matrix, dp));
        }

        return mini;
    }
};