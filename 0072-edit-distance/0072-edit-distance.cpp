class Solution {
public:

    int fact(string word1, string word2, int i, int j, vector<vector<int>>& dp){

        if(j < 0){
            // Have to delete i+1 characters from word1
            return i+1;
        }

        if(i < 0){
            // Have to insert j+1 characters into word1
            return j+1;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        if(word1[i] == word2[j]){
            // Here 0 operations will be done
            return dp[i][j] = 0 + fact(word1,word2,i-1,j-1,dp);
        }

        else{
            int insert = fact(word1,word2,i,j-1,dp);
            int del = fact(word1,word2,i-1,j,dp);
            int replace = fact(word1,word2,i-1,j-1,dp);

            return dp[i][j] = 1 + min(insert,min(del,replace));
        }
    }

    int minDistance(string word1, string word2) {
        int i = word1.length() - 1;
        int j = word2.length() - 1;

        vector<vector<int>> dp(word1.length(), vector<int>(word2.length(), -1));

        return fact(word1,word2,i,j,dp);
    }
};