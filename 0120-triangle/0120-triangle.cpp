class Solution {
public:
    int fact(int row, int col, vector<vector<int>>& triangle,
             vector<vector<int>>& dp) {

        for(int j = 0 ; j <= col ; j++){
            // Base Case, Starting from down to up
            dp[row][j] = triangle[row][j];
        }

        for(int i = row - 1; i >= 0 ; i--){
            for(int j = i; j >= 0 ; j--){

                int down = dp[i+1][j] + triangle[i][j];
                int diagonal = dp[i+1][j+1] + triangle[i][j];

                dp[i][j] = min(down,diagonal);
            }
        }

        return dp[0][0];
    }

    int minimumTotal(vector<vector<int>>& triangle) {

        int n = triangle.size() - 1;
        int m = triangle.size() - 1;

        vector<vector<int>> dp(
            triangle.size(),
            vector<int>(triangle[n].size(), INT_MAX)); // nxn size dp array

        return fact(n, m, triangle, dp);
    }
};