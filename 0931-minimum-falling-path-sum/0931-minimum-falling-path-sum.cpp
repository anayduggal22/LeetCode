class Solution {
public:
    int fact(vector<vector<int>>& matrix, vector<vector<int>>& dp) {

        
        for (int j = 0; j < matrix[0].size(); j++) {
            // Base Case
            dp[0][j] = matrix[0][j];
        }

        for(int i = 1; i < matrix.size() ; i++){
            for(int j = 0 ; j < matrix[0].size(); j++){

            int up = dp[i-1][j] + matrix[i][j];
            int leftdiag = 1e9;
            int rightdiag = 1e9;

            if(j > 0){
                leftdiag = dp[i-1][j-1] +  matrix[i][j];
            }

            if(j < matrix[0].size() - 1){
                rightdiag = dp[i-1][j+1] + matrix[i][j];
            }

            dp[i][j] = min(up,min(leftdiag,rightdiag));

            }
        }



        int mini = INT_MAX;

        for (int j = 0; j < matrix[0].size(); j++) {
            mini = min(mini, dp[dp.size() - 1][j]);
        }

        return mini;
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {

        vector<vector<int>> dp(matrix.size(),
                               vector<int>(matrix[0].size(), 1e9));

        
        return fact(matrix,dp);
    }
};