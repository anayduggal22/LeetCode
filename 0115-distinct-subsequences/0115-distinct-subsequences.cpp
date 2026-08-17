class Solution {
public:

    int fact(string s, string t, int i , int j , vector<vector<double>>& dp){

        // Base Case

        // If j == 0, all i in dp should be 1
        for(int n = 0; n <= i ; n++){
            dp[n][0] = 1;
        }
        // Else for all j except j = 0, as it there it should be 1,
        // for i==0, dp should be 1;
        for(int n = 1; n <= j ; n++){
            dp[0][n] = 0;
        }

        for(int n = 1; n <= i ; n++ ){
            for(int m = 1; m <= j ; m++){

                // 1-indexed i and j, so
                if(s[n-1] == t[m-1]){
                    // Two things we can do now, take this char and go to new char of s and t, OR dont take this char and only go to new char of s;
                    dp[n][m] = dp[n-1][m-1] + dp[n-1][m];
                }

                else{
                    // If char of s and t not matched, we will check the next char of s
                    dp[n][m] = dp[n-1][m];
                }
            }
        }



        return (int)dp[i][j];
    }

    int numDistinct(string s, string t) {
        // Making it 1-indexed for easier base case
        int i = s.length();
        int j = t.length();

        vector<vector<double>> dp(s.length()+1, vector<double>(t.length()+1, -1));

        return fact(s, t, i, j, dp);
    }
};