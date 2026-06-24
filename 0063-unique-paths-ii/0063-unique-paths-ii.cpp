class Solution {
public:

        int fact(int m, int n,vector<vector<int>>& obstacleGrid,  vector<vector<int>>& dp) {

        // Obstacle
        if(m>=0 && n>= 0 && obstacleGrid[m][n] == 1){
            return 0;
        }

        else if (m == 0 && n == 0) {
            return 1;
        }

        else if (m < 0 || n < 0) {
            return 0;
        }

        else if (dp[m][n] != -1) {
            return dp[m][n];
        }

        int up = fact(m - 1, n, obstacleGrid, dp);
        int left = fact(m, n - 1, obstacleGrid,dp);

        return dp[m][n] = up + left;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return fact(m - 1, n - 1,obstacleGrid, dp);
    }
};