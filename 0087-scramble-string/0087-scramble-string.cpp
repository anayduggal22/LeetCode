class Solution {
public:
    bool fact(int i, int j, int len, const string& s1, const string& s2,
              vector<vector<vector<int>>>& dp) {

        if (len == 1) {
            return s1[i] == s2[j];
        }

        if (dp[i][j][len] != -1) {
            return dp[i][j][len];
        }

        for (int k = 1; k < len; k++) {

            // No swap
            bool noswap = fact(i, j, k, s1, s2, dp) &&
                          fact(i + k, j + k, len - k, s1, s2, dp);

            // Swap
            bool swap = fact(i, j + len - k, k, s1, s2, dp) &&
                        fact(i + k, j, len - k, s1, s2, dp);

            if (noswap || swap) {
                return dp[i][j][len] = true;
            }
        }

        return dp[i][j][len] = false;
    }

    bool isScramble(string s1, string s2) {

        if (s1.size() != s2.size()) {
            return false;
        }

        int n = s1.size();

        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(n, vector<int>(n + 1, -1)));

    //  return fact(i,j,len,s1,s2,dp);
        return fact(0, 0, n, s1, s2, dp);
    }
};