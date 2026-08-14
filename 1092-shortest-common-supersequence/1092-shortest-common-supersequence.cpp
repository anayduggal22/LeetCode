class Solution {
public:

    void fact(int i, int j, string str1, string str2, vector<vector<int>>& dp){

        for(int n = 0 ; n < dp.size(); n++){
            dp[n][0] = 0;
        }
        for(int n = 0 ; n < dp[0].size(); n++){
            dp[0][n] = 0;
        }


        for(int n = 1; n < dp.size(); n++){
            for(int m = 1; m < dp[0].size(); m++){

                if(str1[n-1] == str2[m-1]){

                    dp[n][m] = 1 + dp[n-1][m-1];
                }
                else{

                    dp[n][m] = max(dp[n-1][m], dp[n][m-1]);
                }
            }
        }


    }

    string shortestCommonSupersequence(string str1, string str2) {
        
        // Not subtracting by 1, because of the base case
        // to be zero, when there is empty substring
        int i = str1.length();
        int j = str2.length();

        vector<vector<int>> dp(i + 1, vector<int>(j + 1, -1));

        fact(i, j, str1, str2, dp);

        string ans = "";

        while(i > 0 && j > 0){

            if(str1[i-1] == str2[j-1]){
                ans += str1[i-1];
                i--;
                j--;
            }
            else if(dp[i-1][j] > dp[i][j-1]){
                ans += str1[i-1];
                i--;
            }
            else{
                ans += str2[j-1];
                j--;
            }
        }

        while(i > 0){
            ans += str1[i-1];
            i--;
        }
        while(j > 0){
            ans += str2[j-1];
            j--;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};