class Solution {
public:

    int fact(string s, string t, int i , int j , vector<vector<int>>& dp){

        // Base Case
        if(j < 0){
            return 1; // t was found in s in a range
        }
        else if(i < 0){
            return 0; // s was traversed without finding t in a range
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        if(s[i] == t[j]){
            // Two things we can do now, take this char and go to new char of s and t, OR dont take this char and only go to new char of s;
            return dp[i][j] = fact(s,t,i-1,j-1,dp) + fact(s,t,i-1,j,dp);
        }

        else{
            // If char of s and t not matched, we will check the next char of s
            return dp[i][j] = fact(s,t,i-1,j,dp);
        }
    }

    int numDistinct(string s, string t) {
        
        int i = s.length() - 1;
        int j = t.length() - 1;

        vector<vector<int>> dp(s.length(), vector<int>(t.length(), -1));

        return fact(s, t, i, j, dp);
    }
};