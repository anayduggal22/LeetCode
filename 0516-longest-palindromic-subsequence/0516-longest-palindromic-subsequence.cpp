class Solution {
public:

    int fact(vector<vector<int>>& dp, const string& s1, const string& s2, int i, int j){

        // Out of Bound
        for(int n = 0 ; n <= i ; n++){
            dp[n][0] = 0;
            dp[0][n] = 0;
        }

        for(int n = 1; n <= i; n++){
            for(int m = 1; m <= j; m++){

            if(s1[n-1] == s2[m-1]){
                dp[n][m] = 1 + dp[n-1][m-1];
            }
            else{
            dp[n][m] = max(dp[n-1][m], dp[n][m-1]);
            }
            
            }
        }

        return dp[i][j];

    }

    int longestPalindromeSubseq(string s) {
        // The problem can be boiled down to finding the 
        // Longest Common Subsequence between a string
        // and its reverse.

        string s1 = s;
        string s2 = s;
        reverse(s2.begin(), s2.end());

        vector<vector<int>> dp(s.length() + 1, vector<int>(s.length() + 1, -1));

        // Not subtracting by minus one as did in memoization
        // Due to base case of going negative cannot be done
        // In tabulation

        int i = s.length();
        int j = s.length();

        return fact(dp, s1, s2, i, j);
    }
};