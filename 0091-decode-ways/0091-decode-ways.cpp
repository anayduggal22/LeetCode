class Solution {
public:
    int fact(int i, vector<int>& dp, const string& s) {

        if (i == 0) {
            return s[0] != '0';
        }

        if (dp[i] != -1) {
            return dp[i];
        }

        int brk = 0;
        int notbrk = 0;

        if (s[i] != '0') {
            brk = fact(i - 1, dp, s);
        }

        if (i > 0 && s[i - 1] != '0' &&
            (s[i - 1] - '0') * 10 + (s[i] - '0') <= 26) {

            if (i == 1) {
                notbrk = 1;
            } else {
                notbrk = fact(i - 2, dp, s);
            }
        }

        return dp[i] = brk + notbrk;
    }

    int numDecodings(string s) {

        int n = s.size();

        vector<int> dp(n, -1);

        return fact(n - 1, dp, s);
    }
};