class Solution {
public:
    int palindrome(int i, int j, const string& s) {

        while (i <= j) {
            if (s[i] != s[j]) {
                return 0;
            }
            i++;
            j--;
        }

        return 1;
    }

    int fact(int i, const string& s, vector<int>& dp) {

        if (i == s.length()) {
            return 0;
        }

        if (dp[i] != -1) {
            return dp[i];
        }

        int m = INT_MAX;

        for (int j = i; j < s.length(); j++) {

            if (palindrome(i, j, s)) {
                int count = 1 + fact(j + 1, s, dp);
                m = min(count, m);
                // Keeping only minimum count
            }

        }

        return dp[i] = m;
    }

    int minCut(string s) {

        int n = s.length();

        vector<int> dp(n, -1);

        // -1 done because function adds an extra partition
        // at end of string

        return fact(0, s, dp) - 1;
    }
};