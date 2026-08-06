class Solution {
public:
    int fact(int index1, int index2, const string& text1, const string& text2,
             vector<vector<int>>& dp) {

        // Base Case
        if (index1 < 0 || index2 < 0) {
            return 0; // Out of Bound
        }

        if (dp[index1][index2] != -1) {
            return dp[index1][index2];
        }

        // Common character found
        if (text1[index1] == text2[index2]) {
            return dp[index1][index2] = 1 + fact(index1 - 1, index2 - 1, text1, text2, dp);
        }

        // Common character NOT found
        // So checking if going back to each string one-by-one can
        // match another common or not
        else{
            return dp[index1][index2] = max(fact(index1, index2 - 1, text1, text2, dp), fact(index1 - 1, index2, text1, text2, dp));
        }
    }

    int longestCommonSubsequence(string text1, string text2) {

        int index1 = text1.length() -1;
        int index2 = text2.length() -1;

        vector<vector<int>> dp(index1 + 1, vector<int>(index2 + 1, -1));

        return fact(index1, index2, text1, text2, dp);
    }
};