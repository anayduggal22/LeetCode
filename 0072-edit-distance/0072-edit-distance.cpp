class Solution {
public:

    int fact(string word1, string word2, int i, int j, vector<vector<int>>& dp){

        // Base Case

        for(int n = 0; n <= i ; n++){
            dp[n][0] = n;
        }
        for(int n = 0; n <= j ; n++){
            dp[0][n] = n;
        }

        for(int n = 1; n <= i ; n++){
            for(int m = 1; m <= j ; m++){

                // 1 based indexing, thats why -1
                if(word1[n-1] == word2[m-1]){
                    // Here 0 operations will be done
                    dp[n][m] = 0 + dp[n-1][m-1];
                }

                else{
                    int insert = dp[n][m-1];
                    int del = dp[n-1][m];
                    int replace = dp[n-1][m-1];

                    dp[n][m] = 1 + min(insert,min(del,replace));
                }

            }
        }

        return dp[i][j];

    }

    int minDistance(string word1, string word2) {

        // For 1base indexing, done for easy base case
        int i = word1.length();
        int j = word2.length();

        vector<vector<int>> dp(word1.length() + 1, vector<int>(word2.length() + 1, -1));

        return fact(word1,word2,i,j,dp);
    }
};