class Solution {
public:
    int fact(int row, int col, vector<vector<int>>& triangle,
             vector<vector<int>>& dp) {

        if (row == triangle.size() - 1) {
            // Base Case
            return triangle[row][col];
        }

        else if (dp[row][col] != INT_MAX) {
            return dp[row][col];
        }

        int down = fact(row + 1, col, triangle, dp) + triangle[row][col];
        int diagonal = fact(row + 1, col + 1, triangle, dp) + triangle[row][col];

        return dp[row][col] = min(down, diagonal);
    }

    int minimumTotal(vector<vector<int>>& triangle) {

        int n = triangle.size() - 1;

        vector<vector<int>> dp(
            triangle.size(),
            vector<int>(triangle[n].size(), INT_MAX)); // nxn size dp array

        return fact(0, 0, triangle, dp);
    }
};