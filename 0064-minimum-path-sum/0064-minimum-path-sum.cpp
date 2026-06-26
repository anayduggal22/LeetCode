class Solution {
public:

    int fact(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& dp){

        if(row == 0 && col == 0){
            return grid[row][col];
        } 

        else if(row < 0 || col < 0){
            // Out of bound so return a big value
            // So that it never gets chosen
            return 1e9;
        }

        else if(dp[row][col] != -1){
            return dp[row][col];
        }

        int up = grid[row][col] + fact(row-1,col,grid,dp);
        int left = grid[row][col] + fact(row,col-1,grid,dp);

        return dp[row][col] = min(up,left);
    }

    int minPathSum(vector<vector<int>>& grid) {
        
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(),-1));

        int n = grid.size();
        int m = grid[0].size();

        return fact(n-1,m-1,grid,dp);
    }
};