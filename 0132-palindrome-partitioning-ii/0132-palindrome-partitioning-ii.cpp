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

    int minCut(string s) {

        int n = s.length();

        // n + 1 size, because j is going till n
        vector<int> dp(n + 1, 0);

        // Base Case
        dp[n] = 0;

        // Memoization, i-> 0 till n-1
        // So tabulation, i-> n-1 till 0

        for (int i = n - 1; i >= 0; i--) {

            int m = INT_MAX;

            for (int j = i; j < s.length(); j++) {

                if (palindrome(i, j, s)) {
                    int count = 1 + dp[j + 1];
                    m = min(count, m);
                    // Keeping only minimum count
                }
            }

            dp[i] = m;
        }

        // -1 done because function adds an extra partition
        // at end of string
        return dp[0] - 1;
    }
};