class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {

        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        // Base Case
        // 1st row and 1st col of dp is same as matrix

        for (int i = 0; i < n; i++) {
            dp[i][0] = matrix[i][0];
        }

        for (int j = 0; j < m; j++) {
            dp[0][j] = matrix[0][j];
        }

        // For every matirx[i][j], if it is 1, then dp[i][j]
        // is minimum of its upper value, back value and diagnal back
        // value of dp, if matrix[i][j] = 0, then dp[i][j] = 0

        // So we will skip 1st row and 1st column
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {

                if (matrix[i][j] == 1) {

                    dp[i][j] =1 + min(dp[i - 1][j],min(dp[i][j - 1],dp[i - 1][j - 1]));
                }

                else if (matrix[i][j] == 0) {
                    dp[i][j] = 0;
                }
            }
        }

        // Answer is sum of all elements of dp matirx
        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                ans += dp[i][j];
            }
        }

        return ans;
    }
};