class Solution {
public:
    int fact(int index1, int index2, const string& text1, const string& text2,
             vector<vector<int>>& dp) {

        // Base Case
        for (int i = 0; i <= index1; i++) {
            dp[i][0] = 0;
        }

        for (int j = 0; j <= index2; j++) {
            dp[0][j] = 0;
        }

        for (int i = 1; i <= index1; i++) {
            for (int j = 1; j <= index2; j++) {

                // Common character found and here indexes are sub by 1
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }

                // Common character NOT found
                // So checking if going back to each string one-by-one can
                // match another common or not
                else {
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }

        return dp[index1][index2];
    }

    int longestCommonSubsequence(string text1, string text2) {

        // Not same as memoization, coz we are not sub 1
        int index1 = text1.length();
        int index2 = text2.length();

        vector<vector<int>> dp(index1 + 1, vector<int>(index2 + 1, -1));

        return fact(index1, index2, text1, text2, dp);
    }
};