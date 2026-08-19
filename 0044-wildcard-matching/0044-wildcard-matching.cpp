class Solution {
public:

    bool fact(const string& s, const string& p, int i, int j, vector<vector<int>>& dp){
        
        // Base Case        
        if(i < 0 && j < 0) {
            // Both have been traversed, so matching
            return true;
        }
        
        // Base Case
        if(i < 0 && j >= 0) {
            // s has been traversed without getting matched with p
            // Return true only if all remaining elements of p are '*'
            for(int n = 0; n <= j; n++) {
                if(p[n] != '*') {
                    return false;
                }
            }
            return true;
        }
        
        // Base Case
        if(i >= 0 && j < 0) {
            // p has been traversed without getting matched with s
            return false;
        }

        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        if(p[j] == s[i] || p[j] == '?') {
            return dp[i][j] = fact(s, p, i - 1, j - 1, dp);
        }

        else if(p[j] == '*') {
            return dp[i][j] = fact(s, p, i - 1, j, dp) |
                              fact(s, p, i, j - 1, dp);
        }

        // Else if string not matched && p[j] != '*' OR '?'
        // return false

        return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {
        int i = s.length() - 1;
        int j = p.length() - 1;

        vector<vector<int>> dp(s.length(), vector<int>(p.length(), -1));

        return fact(s, p, i, j, dp);
    }
};