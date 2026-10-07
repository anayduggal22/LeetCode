class Solution {
public:
    string longestPrefix(string s) {

        int n = s.size();

        int d = 256;
        long long q = 1000000007;

        long long p = 0;
        long long t = 0;
        long long h = 1;

        int ans = 0;

        for (int i = 0; i < n - 1; i++) {

            p = (d*p + s[i]) % q;

            t = (t + s[n-1-i]*h) % q;

            if (p == t) {
                ans = i+1;
            }

            h = (h * d) % q;
        }

        return s.substr(0,ans);
    }
};