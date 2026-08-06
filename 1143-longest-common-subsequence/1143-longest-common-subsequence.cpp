class Solution {
public:
    int fact(int index1, int index2, const string& text1, const string& text2) {

        vector<int> prev(index2 + 1, -1);

        // Base Case
        for (int i = 0; i <= index2; i++) {
            prev[i] = 0;
        }

        for (int i = 1; i <= index1; i++) {

            vector<int> curr(index2 + 1, -1);
            curr[0] = 0; // IMPORTANT

            for (int j = 1; j <= index2; j++) {

                // Common character found and here indexes are sub by 1
                if (text1[i - 1] == text2[j - 1]) {
                    curr[j] = 1 + prev[j - 1];
                }

                // Common character NOT found
                // So checking if going back to each string one-by-one can
                // match another common or not
                else {
                    curr[j] = max(curr[j - 1], prev[j]);
                }
            }

            prev = curr;
        }

        return prev[index2];
    }

    int longestCommonSubsequence(string text1, string text2) {

        // Not same as memoization, coz we are not sub 1
        int index1 = text1.length();
        int index2 = text2.length();

        return fact(index1, index2, text1, text2);
    }
};